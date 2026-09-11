#!/usr/bin/env python3
"""
Automated LeetCode Question Organizer
- Detects newly pushed questions at the root of the repository (format: \d{4}-*)
- Classifies them into the appropriate topic folder using LeetCode GraphQL / README tags
- Reorganizes directories using git mv
- Dynamically updates README.md (Dashboard, Repository Structure, and Problem Index)
- Updates stats.json
"""

import os
import re
import sys
import json
import shutil
import urllib.request
import subprocess

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

TOPIC_CONFIG = [
    # (Folder, Display Name, Icon, Tag keywords)
    ("BinarySearch", "Binary Search", "🔍", ["binary search"]),
    ("Backtracking", "Backtracking", "🔄", ["backtracking"]),
    ("Trees", "Trees & Binary Search Trees", "🌳", ["tree", "binary tree", "binary search tree", "trie", "tree traversal"]),
    ("Graphs", "Graphs & BFS/DFS", "🕸️", [
        "graph", "breadth-first search", "depth-first search", "union find", 
        "union-find", "disjoint set", "topological sort", "shortest path", 
        "bipartite", "eulerian circuit", "minimum spanning tree"
    ]),
    ("DynamicProgramming", "Dynamic Programming", "🧩", ["dynamic programming", "memoization", "knapsack"]),
    ("Heaps", "Heaps & Priority Queues", "⛰️", ["heap (priority queue)", "heap", "priority queue", "quickselect"]),
    ("Greedy", "Greedy Algorithms", "💡", ["greedy"]),
    ("BitManipulation", "Bit Manipulation", "⚡", ["bit manipulation", "bitmask"]),
    ("Math", "Math & Number Theory", "🔢", ["math", "number theory", "combinatorics", "geometry", "probability and statistics"]),
    ("Arrays", "Arrays & Hashing", "📦", [
        "array", "hash table", "matrix", "two pointers", "sliding window", 
        "prefix sum", "sorting", "counting", "string"
    ]),
]

def fetch_leetcode_tags(title_slug):
    """Fetch official topic tags from LeetCode GraphQL API."""
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        topicTags {
          name
          slug
        }
      }
    }
    """
    url = "https://leetcode.com/graphql"
    payload = json.dumps({"query": query, "variables": {"titleSlug": title_slug}}).encode("utf-8")
    req = urllib.request.Request(
        url,
        data=payload,
        headers={"Content-Type": "application/json", "User-Agent": "Mozilla/5.0"}
    )
    try:
        with urllib.request.urlopen(req, timeout=8) as response:
            data = json.loads(response.read().decode("utf-8"))
            tags = [t["name"].lower() for t in data.get("data", {}).get("question", {}).get("topicTags", [])]
            return tags
    except Exception as e:
        print(f"[Warning] Failed to fetch tags for {title_slug} from LeetCode API: {e}")
        return []

def get_tags_from_readme(q_dir_name, old_readme):
    """Fallback: extract topic tags from LeetHub table in root README.md."""
    topics = []
    current_topic = None
    for line in old_readme.splitlines():
        if line.startswith("## "):
            current_topic = line[3:].strip().lower()
        elif q_dir_name in line and current_topic:
            topics.append(current_topic)
    return topics

MULTI_APPROACH = os.getenv("MULTI_APPROACH", "true").lower() in ("true", "1", "yes")

CODE_EXTENSIONS = {
    ".cpp": "C++",
    ".cc": "C++",
    ".cxx": "C++",
    ".c": "C",
    ".py": "Python",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
    ".kt": "Kotlin",
    ".cs": "C#",
    ".swift": "Swift",
    ".rb": "Ruby",
    ".scala": "Scala",
    ".php": "PHP",
}

def extract_approach_title(code_content):
    """Extract approach description/title from comments in code."""
    if not code_content:
        return None
    patterns = [
        r"(?i)(?://|#)\s*(?:approach|solution|method|strategy)(?:[\s\-_]*(?:\d+))?\s*[:\-–—]\s*([^\r\n]+)",
        r"(?i)/\*\s*(?:approach|solution|method|strategy)(?:[\s\-_]*(?:\d+))?\s*[:\-–—]\s*(.+?)\*/",
    ]
    for pat in patterns:
        m = re.search(pat, code_content)
        if m:
            raw = m.group(1).strip()
            raw = re.sub(r"[\*\r\n]", "", raw).strip()
            raw = raw.strip("-:; ")
            if raw:
                return raw
    return None

def extract_approach_num(code_content):
    """Extract explicit approach number (e.g. Approach-1, Approach 2) if specified in code comments."""
    if not code_content:
        return None
    m = re.search(r"(?i)(?://|#|/\*)\s*(?:approach|solution|method|strategy)[\s\-_]*(\d+)", code_content)
    if m:
        return int(m.group(1))
    return None

def slugify_approach(approach_title, max_words=3, max_chars=24):
    """Convert an approach title to a safe, clean hyphenated slug."""
    if not approach_title:
        return ""
    cleaned = approach_title.replace("'", "")
    cleaned_no_paren = re.sub(r"\(.*?\)", "", cleaned).strip()
    if cleaned_no_paren:
        cleaned = cleaned_no_paren
    slug = re.sub(r"[^a-zA-Z0-9]+", "-", cleaned).strip("-").lower()
    parts = [p for p in slug.split("-") if p]
    if len(parts) > max_words:
        parts = parts[:max_words]
    slug = "-".join(parts)
    if len(slug) > max_chars:
        slug = slug[:max_chars].rstrip("-")
    return slug

def is_content_identical(content1, content2):
    """Compare two code contents ignoring leading/trailing whitespace and CRLF."""
    c1 = content1.replace("\r\n", "\n").strip()
    c2 = content2.replace("\r\n", "\n").strip()
    return c1 == c2

def get_solution_files(q_dir_path):
    """Return sorted list of code solution files in problem directory."""
    if not os.path.exists(q_dir_path) or not os.path.isdir(q_dir_path):
        return []
    files = []
    q_dir_name = os.path.basename(q_dir_path)
    for f in os.listdir(q_dir_path):
        f_path = os.path.join(q_dir_path, f)
        if not os.path.isfile(f_path):
            continue
        ext = os.path.splitext(f)[1].lower()
        if ext in CODE_EXTENSIONS:
            files.append(f)
            
    def sort_key(filename):
        base, _ = os.path.splitext(filename)
        if base == q_dir_name:
            return (1, 1, filename)
        m = re.search(r"-approach-?(\d+)", base, re.IGNORECASE)
        if m:
            return (2, int(m.group(1)), filename)
        m2 = re.search(r"-(\d+)$", base)
        if m2:
            return (3, int(m2.group(1)), filename)
        return (4, 999, filename)
        
    return sorted(files, key=sort_key)

def get_next_approach_filename(dst_dir, filename, code_content):
    """Generate a distinct filename for a new approach in dst_dir."""
    _, ext = os.path.splitext(filename)
    clean_base = os.path.basename(dst_dir)
    
    approach_title = extract_approach_title(code_content)
    approach_slug = slugify_approach(approach_title) if approach_title else ""
    explicit_num = extract_approach_num(code_content)
    
    existing_files = get_solution_files(dst_dir)
    existing_indices = []
    for f in existing_files:
        f_base, _ = os.path.splitext(f)
        m = re.search(r"-approach-?(\d+)", f_base, re.IGNORECASE)
        if m:
            existing_indices.append(int(m.group(1)))
        elif re.search(r"-(\d+)$", f_base):
            m2 = re.search(r"-(\d+)$", f_base)
            existing_indices.append(int(m2.group(1)))
        elif f == f"{clean_base}{ext}":
            existing_indices.append(1)
            
    if explicit_num and explicit_num not in existing_indices:
        next_index = explicit_num
    else:
        next_index = max(existing_indices, default=1) + 1
    
    while True:
        if approach_slug:
            candidate = f"{clean_base}-approach-{next_index}-{approach_slug}{ext}"
        else:
            candidate = f"{clean_base}-approach-{next_index}{ext}"
            
        if not os.path.exists(os.path.join(dst_dir, candidate)):
            return candidate
        next_index += 1

def format_solution_links(solutions):
    """Format markdown links for solutions in problem tables."""
    if not solutions:
        return "—"
    if len(solutions) == 1:
        sol = solutions[0]
        return f"[{sol['lang']}]({sol['rel_path']})"
    
    links = []
    for sol in solutions:
        num = sol["approach_num"]
        label = f"Approach {num}" if len(solutions) <= 2 else f"App {num}"
        title = sol.get("approach_title")
        if title:
            clean_title = re.sub(r'["\r\n]', '', title).strip()
            links.append(f"[{label}]({sol['rel_path']} \"{clean_title}\")")
        else:
            links.append(f"[{label}]({sol['rel_path']})")
    return " · ".join(links)

def update_question_readme(q_dir_path, solutions):
    """If multiple approaches exist, add/update an Approaches section in question README.md."""
    if len(solutions) <= 1:
        return
    q_readme_path = os.path.join(q_dir_path, "README.md")
    if not os.path.exists(q_readme_path):
        return
    try:
        with open(q_readme_path, "r", encoding="utf-8") as f:
            content = f.read()
            
        lines = ["\n<!---LeetCode Approaches Start-->", "<hr>", "<h3>💡 Solutions & Approaches</h3>\n"]
        for sol in solutions:
            title_desc = f" — *{sol['approach_title']}*" if sol.get("approach_title") else ""
            lines.append(f"- [Approach {sol['approach_num']} ({sol['lang']})]({sol['filename']}){title_desc}")
        lines.append("\n<!---LeetCode Approaches End-->\n")
        section_text = "\n".join(lines)
        
        if "<!---LeetCode Approaches Start-->" in content:
            content = re.sub(
                r"<!---LeetCode Approaches Start-->.*?<!---LeetCode Approaches End-->",
                section_text.strip(),
                content,
                flags=re.DOTALL
            )
        else:
            content = content.rstrip() + section_text
            
        with open(q_readme_path, "w", encoding="utf-8") as f:
            f.write(content)
    except Exception as e:
        print(f"[Warning] Failed to update {q_readme_path}: {e}")

def classify_topic(title_slug, q_dir_name, old_readme=""):
    """Classify question into a target topic folder."""
    tags = fetch_leetcode_tags(title_slug)
    if not tags and old_readme:
        tags = get_tags_from_readme(q_dir_name, old_readme)
    
    # Check against topic configuration
    for folder, _, _, keywords in TOPIC_CONFIG:
        for kw in keywords:
            if any(kw in tag for tag in tags):
                return folder
            
    # Default fallback
    return "Arrays"

def find_existing_topic(q_dir_name):
    """Check if question already exists in any topic folder."""
    for item in os.listdir(BASE_DIR):
        topic_path = os.path.join(BASE_DIR, item)
        if not os.path.isdir(topic_path) or item.startswith(".") or item in ["scripts", ".github"]:
            continue
        candidate = os.path.join(topic_path, q_dir_name)
        if os.path.isdir(candidate):
            return item
    return None

def clean_nested_directories():
    """Find and flatten any accidental nested question directories (e.g. Topic/Q/Q)."""
    cleaned_any = False
    for item in os.listdir(BASE_DIR):
        topic_path = os.path.join(BASE_DIR, item)
        if not os.path.isdir(topic_path) or item.startswith(".") or item in ["scripts", ".github"]:
            continue
        for q_dir in os.listdir(topic_path):
            q_path = os.path.join(topic_path, q_dir)
            if not os.path.isdir(q_path) or not re.match(r"^\d+-", q_dir):
                continue
            nested_q = os.path.join(q_path, q_dir)
            if os.path.isdir(nested_q):
                print(f"[Cleanup] Found nested directory '{nested_q}', flattening...")
                for f in os.listdir(nested_q):
                    src_f = os.path.join(nested_q, f)
                    dst_f = os.path.join(q_path, f)
                    if os.path.isfile(src_f):
                        ext = os.path.splitext(f)[1].lower()
                        if ext in CODE_EXTENSIONS and os.path.exists(dst_f):
                            try:
                                with open(src_f, "r", encoding="utf-8", errors="ignore") as sf:
                                    src_content = sf.read()
                            except Exception:
                                src_content = ""
                            is_dup = False
                            for ex_f in get_solution_files(q_path):
                                ex_path = os.path.join(q_path, ex_f)
                                try:
                                    with open(ex_path, "r", encoding="utf-8", errors="ignore") as ef:
                                        if is_content_identical(src_content, ef.read()):
                                            is_dup = True
                                            break
                                except Exception:
                                    pass
                            if not is_dup:
                                new_name = get_next_approach_filename(q_path, f, src_content)
                                shutil.copy2(src_f, os.path.join(q_path, new_name))
                        elif not os.path.exists(dst_f) or os.path.getsize(src_f) > 0:
                            shutil.copy2(src_f, dst_f)
                shutil.rmtree(nested_q)
                try:
                    subprocess.run(["git", "rm", "-r", "--cached", "--ignore-unmatch", os.path.relpath(nested_q, BASE_DIR)],
                                   cwd=BASE_DIR, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                except Exception:
                    pass
                cleaned_any = True
    return cleaned_any

def move_or_merge_question(src, dst):
    """Move directory, or merge files if dst already exists (handling multiple approaches)."""
    if os.path.exists(dst):
        print(f"Destination '{dst}' already exists. Merging updated files from resubmission...")
        for item in os.listdir(src):
            src_item = os.path.join(src, item)
            dst_item = os.path.join(dst, item)
            if os.path.isfile(src_item):
                ext = os.path.splitext(item)[1].lower()
                if ext in CODE_EXTENSIONS and MULTI_APPROACH:
                    try:
                        with open(src_item, "r", encoding="utf-8", errors="ignore") as f:
                            src_content = f.read()
                    except Exception as e:
                        print(f"[Warning] Could not read '{src_item}': {e}")
                        src_content = ""
                        
                    # Check if identical solution already exists in dst
                    is_dup = False
                    for ex_f in get_solution_files(dst):
                        ex_path = os.path.join(dst, ex_f)
                        try:
                            with open(ex_path, "r", encoding="utf-8", errors="ignore") as ef:
                                if is_content_identical(src_content, ef.read()):
                                    print(f"[Multi-Approach] Incoming '{item}' matches existing '{ex_f}'. Skipping duplicate.")
                                    is_dup = True
                                    break
                        except Exception:
                            pass
                    if is_dup:
                        continue
                        
                    if not os.path.exists(dst_item):
                        shutil.copy2(src_item, dst_item)
                        print(f"[Multi-Approach] Copied initial solution '{item}' -> '{dst_item}'")
                    else:
                        new_name = get_next_approach_filename(dst, item, src_content)
                        new_dst_path = os.path.join(dst, new_name)
                        shutil.copy2(src_item, new_dst_path)
                        print(f"[Multi-Approach] Saved new approach: '{item}' -> '{new_name}' in '{dst}'")
                        try:
                            subprocess.run(["git", "add", new_dst_path], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                        except Exception:
                            pass
                else:
                    shutil.copy2(src_item, dst_item)
            elif os.path.isdir(src_item) and not re.match(r"^\d+-", item):
                shutil.copytree(src_item, dst_item, dirs_exist_ok=True)
        shutil.rmtree(src)
        try:
            subprocess.run(["git", "rm", "-r", "--cached", "--ignore-unmatch", os.path.relpath(src, BASE_DIR)],
                           cwd=BASE_DIR, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except Exception:
            pass
        try:
            subprocess.run(["git", "add", dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except Exception:
            pass
    else:
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        try:
            subprocess.run(["git", "mv", src, dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except (subprocess.CalledProcessError, FileNotFoundError):
            shutil.move(src, dst)
            try:
                subprocess.run(["git", "add", dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            except Exception:
                pass

def scan_and_reorganize():
    """Find any unorganized question directories at repo root and move/merge them."""
    clean_nested_directories()

    root_entries = [
        d for d in os.listdir(BASE_DIR)
        if os.path.isdir(os.path.join(BASE_DIR, d)) and re.match(r"^\d+-", d)
    ]
    
    if not root_entries:
        print("No unorganized questions found at repository root.")
        return False
    
    old_readme = ""
    readme_path = os.path.join(BASE_DIR, "README.md")
    if os.path.exists(readme_path):
        with open(readme_path, "r", encoding="utf-8") as f:
            old_readme = f.read()
            
    moved_any = False
    for q_dir in sorted(root_entries):
        existing_topic = find_existing_topic(q_dir)
        if existing_topic:
            topic_folder = existing_topic
            print(f"Problem '{q_dir}' already exists in topic '{topic_folder}' (resubmission).")
        else:
            parts = q_dir.split("-", 1)
            slug = parts[1] if len(parts) > 1 else parts[0]
            topic_folder = classify_topic(slug, q_dir, old_readme)
        
        src = os.path.join(BASE_DIR, q_dir)
        dst = os.path.join(BASE_DIR, topic_folder, q_dir)
        
        print(f"Organizing '{q_dir}' -> '{topic_folder}/{q_dir}'")
        move_or_merge_question(src, dst)
        moved_any = True
        
    return moved_any

def rebuild_metadata():
    """Scan all topic folders, rebuild README.md and update stats.json."""
    known_topic_folders = {t[0]: t for t in TOPIC_CONFIG}
    
    questions = []
    path_map = {}
    
    # Scan all directories
    for item in sorted(os.listdir(BASE_DIR)):
        topic_path = os.path.join(BASE_DIR, item)
        if not os.path.isdir(topic_path) or item.startswith(".") or item in ["scripts", ".github"]:
            continue
        
        # Check if this folder is a topic folder
        if item in known_topic_folders:
            folder, display_name, icon, _ = known_topic_folders[item]
        else:
            folder, display_name, icon = item, item, "📁"
            
        for q_dir in sorted(os.listdir(topic_path)):
            full_q_path = os.path.join(topic_path, q_dir)
            if not os.path.isdir(full_q_path) or not re.match(r"^\d+-", q_dir):
                continue
                
            parts = q_dir.split("-", 1)
            num = parts[0]
            slug = parts[1] if len(parts) > 1 else num
            readme_file = "README.md"
            
            title = slug.replace("-", " ").title()
            difficulty = "Medium"
            lc_url = f"https://leetcode.com/problems/{slug}/"
            
            q_readme_path = os.path.join(full_q_path, readme_file)
            if os.path.exists(q_readme_path):
                with open(q_readme_path, "r", encoding="utf-8") as rf:
                    content = rf.read()
                    m_title = re.search(r'<h2><a href="([^"]+)">([^<]+)</a></h2>', content)
                    if m_title:
                        lc_url = m_title.group(1).strip()
                        raw_title = m_title.group(2).strip()
                        title = re.sub(r"^\d+\.\s*", "", raw_title)
                    m_diff = re.search(r"<h3>(Easy|Medium|Hard)</h3>", content)
                    if m_diff:
                        difficulty = m_diff.group(1).strip()
                        
            rel_dir = f"{folder}/{q_dir}"
            path_map[q_dir] = rel_dir
            
            # Find all solution files in directory
            sol_files = get_solution_files(full_q_path)
            solutions = []
            for idx, sf in enumerate(sol_files, start=1):
                sf_path = os.path.join(full_q_path, sf)
                code_text = ""
                try:
                    with open(sf_path, "r", encoding="utf-8", errors="ignore") as scf:
                        code_text = scf.read()
                except Exception:
                    pass
                
                app_title = extract_approach_title(code_text)
                ext = os.path.splitext(sf)[1].lower()
                lang = CODE_EXTENSIONS.get(ext, "Code")
                
                m = re.search(r"-approach-?(\d+)", sf, re.IGNORECASE)
                if m:
                    app_num = int(m.group(1))
                else:
                    m2 = re.search(r"-(\d+)\.", sf)
                    if m2:
                        app_num = int(m2.group(1))
                    else:
                        app_num = idx
                        
                solutions.append({
                    "filename": sf,
                    "rel_path": f"{folder}/{q_dir}/{sf}",
                    "approach_num": app_num,
                    "approach_title": app_title,
                    "lang": lang
                })
                
            # Update the question's README.md if multiple approaches exist
            if len(solutions) > 1:
                update_question_readme(full_q_path, solutions)
                
            primary_cpp = sol_files[0] if sol_files else f"{q_dir}.cpp"
            rel_cpp = f"{folder}/{q_dir}/{primary_cpp}"
            solution_link = format_solution_links(solutions)
            
            questions.append({
                "num": num,
                "title": title,
                "difficulty": difficulty,
                "topic_folder": folder,
                "topic_display": display_name,
                "topic_icon": icon,
                "q_dir": q_dir,
                "cpp_file": primary_cpp,
                "rel_dir": rel_dir,
                "rel_cpp": rel_cpp,
                "lc_url": lc_url,
                "solutions": solutions,
                "solution_link": solution_link
            })

    questions.sort(key=lambda x: int(x["num"]))
    
    # Counts
    easy_count = sum(1 for q in questions if q["difficulty"] == "Easy")
    med_count = sum(1 for q in questions if q["difficulty"] == "Medium")
    hard_count = sum(1 for q in questions if q["difficulty"] == "Hard")
    total_count = len(questions)
    
    pct_easy = f"{(easy_count / total_count * 100):.1f}%" if total_count else "0%"
    pct_med = f"{(med_count / total_count * 100):.1f}%" if total_count else "0%"
    pct_hard = f"{(hard_count / total_count * 100):.1f}%" if total_count else "0%"
    
    # Update stats.json
    stats_path = os.path.join(BASE_DIR, "stats.json")
    if os.path.exists(stats_path):
        try:
            with open(stats_path, "r", encoding="utf-8") as f:
                stats_data = json.load(f)
            stats_data.setdefault("leetcode", {})
            stats_data["leetcode"]["easy"] = easy_count
            stats_data["leetcode"]["medium"] = med_count
            stats_data["leetcode"]["hard"] = hard_count
            stats_data["leetcode"]["solved"] = total_count
            
            # Ensure shas has difficulty for all questions
            shas = stats_data["leetcode"].setdefault("shas", {})
            for q in questions:
                if q["q_dir"] in shas:
                    shas[q["q_dir"]]["difficulty"] = q["difficulty"].lower()
            with open(stats_path, "w", encoding="utf-8") as f:
                json.dump(stats_data, f, indent=2)
            print(f"Updated stats.json (Solved: {total_count})")
        except Exception as e:
            print(f"[Warning] Failed to update stats.json: {e}")

    # Read existing README for LeetHub block
    readme_path = os.path.join(BASE_DIR, "README.md")
    old_readme = ""
    if os.path.exists(readme_path):
        with open(readme_path, "r", encoding="utf-8") as f:
            old_readme = f.read()
            
    topics_block_match = re.search(r"(<!---LeetCode Topics Start-->.*?<!---LeetCode Topics End-->)", old_readme, re.DOTALL)
    if topics_block_match:
        old_topics_block = topics_block_match.group(1)
        def replace_link(m):
            q_name = m.group(1)
            if q_name in path_map:
                return f"[{q_name}](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/{path_map[q_name]})"
            return m.group(0)
        new_topics_block = re.sub(
            r"\[([0-9]{4}-[a-z0-9-]+)\]\(https://github.com/calligraphyguruji/LeetCode-Questions/tree/(?:master|main)/[0-9]{4}-[a-z0-9-]+\)",
            replace_link,
            old_topics_block
        )
    else:
        new_topics_block = ""
        
    def get_diff_badge(diff):
        if diff == "Easy":
            return "🟢 `Easy`"
        elif diff == "Medium":
            return "🟡 `Medium`"
        else:
            return "🔴 `Hard`"
            
    # Build Table
    table_rows = []
    for q in questions:
        diff_badge = get_diff_badge(q["difficulty"])
        topic_str = f"[{q['topic_icon']} {q['topic_display']}]({q['topic_folder']}/)"
        problem_link = f"[Problem]({q['rel_dir']}/)"
        table_rows.append(f"| {q['num']} | [{q['title']}]({q['lc_url']}) | {diff_badge} | {topic_str} | {problem_link} | {q['solution_link']} |")
    table_content = "\n".join(table_rows)

    # Build Topic-wise Breakdown
    topic_breakdown_parts = []
    for folder, topic_name, icon, _ in TOPIC_CONFIG:
        topic_qs = [q for q in questions if q["topic_folder"] == folder]
        if not topic_qs:
            continue
        topic_breakdown_parts.append(f"### {icon} [{topic_name}]({folder}/) ({len(topic_qs)})\n")
        topic_breakdown_parts.append("| # | Problem Name | Difficulty | Problem Details | Solution |")
        topic_breakdown_parts.append("|:---:|:---|:---:|:---:|:---:|")
        for q in topic_qs:
            diff_badge = get_diff_badge(q["difficulty"])
            topic_breakdown_parts.append(f"| {q['num']} | [{q['title']}]({q['lc_url']}) | {diff_badge} | [Problem Notes]({q['rel_dir']}/) | {q['solution_link']} |")
        topic_breakdown_parts.append("")

    topic_breakdown_content = "\n".join(topic_breakdown_parts)

    # Generate tree diagram dynamically
    tree_lines = ["LeetCode-Questions/", "│"]
    for folder, topic_name, icon, _ in TOPIC_CONFIG:
        topic_qs = [q for q in questions if q["topic_folder"] == folder]
        if not topic_qs:
            continue
        tree_lines.append(f"├── {folder}/")
        for q in topic_qs[:2]:
            tree_lines.append(f"│   ├── {q['q_dir']}/")
        if len(topic_qs) > 2:
            tree_lines.append(f"│   └── ... ({len(topic_qs)} problems)")
    tree_diagram = "\n".join(tree_lines)

    new_readme_text = f"""# 📚 LeetCode Solutions

Welcome to my personal collection of **LeetCode problem solutions**, written primarily in **C++**. This repository serves as a structured log of my journey to strengthen my **Data Structures and Algorithms (DSA)** skills through consistent, hands-on practice.

**🔗 Profile & Handwritten Solutions:** [https://leetcode.com/u/calligraphyguruji/](https://leetcode.com/u/calligraphyguruji/)

---

## 📌 About This Repository

This repository contains my solutions to various LeetCode problems, organized by topic and difficulty. It is structured for rapid reference, revision, and technical interview preparation. Each solution includes:
- Clear algorithmic approach and methodology
- Time and Space complexity analysis
- Clean, optimal C++ code implementation
- Full problem statements and constraints

The goal is simple: **practice daily, think deeply, and get better at solving problems one step at a time.**

---

## 📊 Progress Dashboard

<div align="center">

| Metric | Count | Percentage |
|:---|:---:|:---:|
| 🟢 **Easy** | {easy_count} | {pct_easy} |
| 🟡 **Medium** | {med_count} | {pct_med} |
| 🔴 **Hard** | {hard_count} | {pct_hard} |
| 🎯 **Total Solved** | **{total_count}** | **100%** |

</div>

---

## 🎯 What I'm Learning

Through this repository, I'm actively working on:

- Understanding core **Data Structures** (Arrays, Linked Lists, Trees, Graphs, Stacks, Queues, Hash Maps)
- Applying **Algorithmic techniques** (Recursion, Backtracking, DP, Greedy, Binary Search)
- Improving my ability to **analyze time and space complexity**
- Learning to identify patterns and choose the right approach for a problem
- Building the problem-solving mindset needed for **technical interviews**

---

## 🗂️ Repository Structure

Solutions are organized into dedicated topic directories matching standard DSA categories:

```
{tree_diagram}
```

Each problem folder contains:
- `README.md` — Problem description, examples, constraints, and approach index.
- `<problem-name>.cpp` — Primary C++ solution with complexity notes.
- `<problem-name>-approach-*.cpp` — Alternative approaches and optimizations for the same problem.

---

## 🧠 Solution Format

Each solution file follows a clear, structured template:

```cpp
// Problem: Two Sum
// Approach: Hash Map (Optimal)
// Explanation: Store each number's index in a map while iterating.
// For every element, check if its complement already exists in the map.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {{
public:
    vector<int> twoSum(vector<int>& nums, int target) {{
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {{
            int complement = target - nums[i];
            if (seen.count(complement))
                return {{seen[complement], i}};
            seen[nums[i]] = i;
        }}
        return {{}};
    }}
}};
```

---

## 📋 Complete Problem Index

| # | Problem Name | Difficulty | Primary Topic | Problem Details | Solution |
|:---:|:---|:---:|:---|:---:|:---:|
{table_content}

---

## 📂 Topic-wise Problem Breakdown

{topic_breakdown_content}
---

## 🎯 Goals

- 🏗️ Build strong DSA fundamentals from the ground up
- 🧩 Improve problem-solving speed and accuracy
- 💼 Prepare for coding interviews and campus placements
- 📅 Maintain consistent, long-term LeetCode practice

---

## 🔗 My LeetCode Profile

**[https://leetcode.com/u/calligraphyguruji/](https://leetcode.com/u/calligraphyguruji/)**

---

## ⚠️ Disclaimer

This repository is created **purely for learning and educational purposes**. The solutions reflect my personal understanding and problem-solving approach at the time of writing, and may be updated or optimized as I continue to learn.

---

⭐ If you find this repository helpful for your own DSA practice, feel free to star it! A collection of LeetCode questions to ace the coding interview! - Created using [LeetHub v2](https://github.com/arunbhardwaj/LeetHub-2.0)

{new_topics_block}
"""

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(new_readme_text)
    print("Updated README.md successfully.")

def main():
    moved = scan_and_reorganize()
    rebuild_metadata()
    if moved:
        print("[Done] Repository restructured and index updated.")
    else:
        print("[Done] All questions are already organized.")

if __name__ == "__main__":
    main()
