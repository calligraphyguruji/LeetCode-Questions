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

def git_move(src, dst):
    """Move directory using git mv if inside git repo, fallback to shutil.move."""
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    try:
        subprocess.run(["git", "mv", src, dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    except subprocess.CalledProcessError:
        shutil.move(src, dst)
        try:
            subprocess.run(["git", "add", dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except Exception:
            pass

def scan_and_reorganize():
    """Find any unorganized question directories at repo root and move them."""
    root_entries = [
        d for d in os.listdir(BASE_DIR)
        if os.path.isdir(os.path.join(BASE_DIR, d)) and re.match(r"^\d{4}-", d)
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
        parts = q_dir.split("-", 1)
        slug = parts[1] if len(parts) > 1 else parts[0]
        topic_folder = classify_topic(slug, q_dir, old_readme)
        
        src = os.path.join(BASE_DIR, q_dir)
        dst = os.path.join(BASE_DIR, topic_folder, q_dir)
        
        print(f"Moving '{q_dir}' -> '{topic_folder}/{q_dir}'")
        git_move(src, dst)
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
            if not os.path.isdir(full_q_path) or not re.match(r"^\d{4}-", q_dir):
                continue
                
            parts = q_dir.split("-", 1)
            num = parts[0]
            slug = parts[1] if len(parts) > 1 else num
            cpp_file = f"{q_dir}.cpp"
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
            rel_cpp = f"{folder}/{q_dir}/{cpp_file}"
            path_map[q_dir] = rel_dir
            
            questions.append({
                "num": num,
                "title": title,
                "difficulty": difficulty,
                "topic_folder": folder,
                "topic_display": display_name,
                "topic_icon": icon,
                "q_dir": q_dir,
                "cpp_file": cpp_file,
                "rel_dir": rel_dir,
                "rel_cpp": rel_cpp,
                "lc_url": lc_url
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
        solution_link = f"[C++]({q['rel_cpp']})"
        table_rows.append(f"| {q['num']} | [{q['title']}]({q['lc_url']}) | {diff_badge} | {topic_str} | {problem_link} | {solution_link} |")
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
            topic_breakdown_parts.append(f"| {q['num']} | [{q['title']}]({q['lc_url']}) | {diff_badge} | [Problem Notes]({q['rel_dir']}/) | [C++]({q['rel_cpp']}) |")
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
- `README.md` — Problem description, examples, and constraints.
- `<problem-name>.cpp` — Clean C++ solution with complexity notes.

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
