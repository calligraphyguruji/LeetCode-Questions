#!/usr/bin/env python3
"""Conservative, offline visual-solution migration; no third-party dependencies."""
from __future__ import annotations

import argparse
from collections import defaultdict
from dataclasses import dataclass
import hashlib
import html
import json
from pathlib import Path
import re
import shutil
from urllib.parse import quote, unquote

SOURCE = 'LeetCode-Img-Soln'
MANIFEST = 'docs/visual-solutions.json'
ALIASES = 'docs/visual-title-aliases.json'
EXTENSIONS = {'.jpg', '.jpeg', '.png', '.gif', '.webp', '.svg', '.avif', '.bmp'}
START = '<!-- visual-solutions:start -->'
END = '<!-- visual-solutions:end -->'
HEADING = '## 🧠 Visual Solution & Explanation'
ROMAN = {'i': 1, 'ii': 2, 'iii': 3, 'iv': 4, 'v': 5, 'vi': 6,
         'vii': 7, 'viii': 8, 'ix': 9, 'x': 10}


def digest(path: Path) -> str:
    sha = hashlib.sha256()
    with path.open('rb') as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b''):
            sha.update(chunk)
    return sha.hexdigest()


def normalize_problem_title(title: str) -> str:
    words = re.findall(r'[a-z0-9]+', html.unescape(title).casefold())
    expansions = {'bt': 'binary tree', 'bst': 'binary search tree',
                  'min': 'minimum', 'max': 'maximum', 'seq': 'sequence',
                  'chars': 'characters', 'src': 'source', 'int': 'integer',
                  'dfs': 'depth first search', 'bfs': 'breadth first search'}
    return ''.join(expansions.get(word, word).replace(' ', '') for word in words)


@dataclass(frozen=True)
class ImageName:
    number: int | None
    title: str
    part: int | None


def parse_image_name(filename: str) -> ImageName:
    stem = Path(filename).stem.strip()
    part = None
    match = re.search(r'(?i)[\s_-]+part[\s_-]*([0-9]+|VIII|VII|III|VI|IV|IX|II|V|X|I)$', stem)
    if match:
        value = match[1].lower()
        part = int(value) if value.isdecimal() else ROMAN[value]
        if part < 1:
            raise ValueError(f'Invalid image part: {filename}')
        stem = stem[:match.start()].strip(' _-')
    # "01 Matrix" is a title, not LeetCode #1 (Two Sum).
    if normalize_problem_title(stem) == '01matrix':
        return ImageName(None, stem, part)
    match = re.match(r'^(\d{1,5})[\s_.-]+(.+)$', stem)
    if match:
        return ImageName(int(match[1]), match[2], part)
    match = re.search(r'[\s_-]+(\d{1,5})$', stem)
    if match:
        return ImageName(int(match[1]), stem[:match.start()].strip(), part)
    return ImageName(None, stem, part)


def extract_problem_number(filename: str) -> int | None:
    return parse_image_name(filename).number


def safe_path(root: Path, relative: str) -> Path:
    path = root / relative
    if Path(relative).is_absolute() or '..' in Path(relative).parts:
        raise ValueError(f'Unsafe relative path: {relative}')
    if not path.resolve().is_relative_to(root.resolve()):
        raise ValueError(f'Path escapes repository: {relative}')
    if any(parent.is_symlink() for parent in [path, *path.parents] if parent != root.parent):
        raise ValueError(f'Symlink is not supported: {relative}')
    return path


def read_json(path: Path, default):
    return json.loads(path.read_text(encoding='utf-8')) if path.exists() else default


def write_if_changed(path: Path, content: str) -> bool:
    data = content.encode('utf-8')
    if path.exists() and path.read_bytes() == data:
        return False
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(data)
    return True


def build_problem_index(root: Path, scan) -> dict:
    """Only a verified existing solution folder with a README is eligible."""
    index = {}
    for number, solutions in scan.solutions.items():
        identity = scan.identities[number]
        folders = {path.parent for path in solutions if path.parent != Path('.')}
        eligible = []
        for folder in sorted(folders):
            path = safe_path(root, folder.as_posix())
            match = re.fullmatch(r'(\d+)[-_](.+)', path.name)
            if (match and int(match[1]) == number
                    and normalize_problem_title(match[2]) == normalize_problem_title(identity.slug)
                    and (path / 'README.md').is_file()
                    and not any(note.startswith(folder.as_posix() + ':')
                                or note.startswith(folder.as_posix() + '/') for note in scan.ambiguous)):
                eligible.append(folder.as_posix())
        index[number] = {'number': number, 'title': identity.title,
                         'slug': identity.slug, 'folders': eligible}
    return index


def find_matching_problem(filename: str, index: dict, aliases: dict, identities: dict) -> tuple[dict | None, str]:
    parsed = parse_image_name(filename)
    title = normalize_problem_title(parsed.title)
    candidates = set()
    for number, identity in identities.items():
        if title in {normalize_problem_title(identity.title), normalize_problem_title(identity.slug)}:
            candidates.add(number)
    alias = aliases.get(title)
    if alias:
        # Reviewed aliases are pinned to both ID and canonical slug, never fuzzy.
        identity = identities.get(alias['number'])
        if identity and identity.slug == alias['slug']:
            candidates.add(alias['number'])
    # A visually reviewed exception is scoped to its complete original filename.
    # In particular, 113-Path-Sum-Part-II is #113, not a second page for #112.
    reviewed = aliases.get('filename:' + filename)
    if reviewed:
        identity = identities.get(reviewed['number'])
        if (identity and identity.slug == reviewed['slug']
                and parsed.number in {None, reviewed['number']}):
            candidates = {reviewed['number']}
    if parsed.number is not None:
        if candidates and candidates != {parsed.number}:
            return None, f'Number/title conflict: filename #{parsed.number}; title identifies {sorted(candidates)}'
        if not candidates:
            return None, f'Unverified abbreviated title for #{parsed.number}; manual review required'
        number = parsed.number
    elif len(candidates) == 1:
        number = next(iter(candidates))
    else:
        return None, 'No unique exact or reviewed title match; manual review required'
    problem = index.get(number)
    if not problem or not problem['folders']:
        return None, f'LeetCode #{number}: no verified existing solution folder with README'
    if len(problem['folders']) != 1:
        return None, f'LeetCode #{number}: multiple eligible folders; manual review required'
    return problem, 'Exact number and verified title' if parsed.number is not None else 'Unique exact/reviewed title'


def visual_block(text: str) -> str:
    if text.count(START) != text.count(END) or text.count(START) > 1:
        raise ValueError('Malformed or duplicate visual solution markers')
    if START not in text:
        return ''
    start, end = text.index(START), text.index(END)
    if end < start:
        raise ValueError('Reversed visual solution markers')
    return text[start:end + len(END)]


def preserve_visual_section(incoming: str, existing: str) -> str:
    """A fresh LeetHub README must retain the destination's visual block."""
    old = visual_block(existing)
    new = visual_block(incoming)
    if old and not new:
        if HEADING in incoming:
            raise ValueError('Unmanaged visual section needs manual review before README merge')
        return incoming + ('\n' if incoming.endswith('\n\n') else '\n\n') + old + '\n'
    if old and new and old != new:
        raise ValueError('Conflicting visual sections; preserved both READMEs for review')
    return incoming


def plan_readme(original: str, entries: list[dict], title: str) -> str:
    current = visual_block(original)
    outside = original.replace(current, '') if current else original
    if HEADING in outside:
        raise ValueError('Unmanaged visual heading already exists; manual review required')
    links = [f'./images/{quote(Path(entry["destination"]).name)}' for entry in entries]
    if any(link in outside for link in links):
        raise ValueError('Image already embedded outside managed section; manual review required')
    lines = [START, '---', '', HEADING, '']
    # Preserve explicit part numbers, even if Part I is missing (e.g. Coin Change).
    multipart = len(entries) > 1 or entries[0]['part'] is not None
    clean_title = re.sub(r'[\[\]\n\r]', '', title)
    for entry, link in zip(entries, links):
        part = entry['part']
        label = f'Part {part}' if part is not None else 'Visual Solution'
        if multipart:
            lines.extend([f'### {label}', ''])
        lines.extend([f'![{clean_title} — {label}]({link})', ''])
    lines.append(END)
    block = '\n'.join(lines)
    if current:
        return original.replace(current, block)
    return original + ('\n' if original.endswith('\n\n') else '\n\n') + block + '\n'


def validate_image_references(problem_dir: Path) -> int:
    text = (problem_dir / 'README.md').read_bytes().decode('utf-8')
    block = visual_block(text)
    links = re.findall(r'!\[[^\]]*\]\((\./images/[^)]+)\)', block)
    if block and not links:
        raise ValueError(f'Visual block contains no image links: {problem_dir}')
    if len(links) != len(set(links)):
        raise ValueError(f'Duplicate visual links: {problem_dir}')
    for link in links:
        if not safe_path(problem_dir, unquote(link)).is_file():
            raise ValueError(f'Missing image: {problem_dir / link}')
    return len(links)


def integrate_images(root: Path, scan, *, dry_run: bool = False) -> dict:
    root = root.resolve()
    index = build_problem_index(root, scan)
    aliases = read_json(root / ALIASES, {})
    manifest = read_json(root / MANIFEST, {'schema_version': 1, 'images': []})
    if manifest.get('schema_version') != 1:
        raise ValueError('Unsupported visual manifest schema')
    existing = manifest['images']
    entries = {entry['source']: dict(entry) for entry in existing}
    if len(entries) != len(existing):
        raise ValueError('Duplicate source paths in visual manifest')
    source_dir = safe_path(root, SOURCE)
    images = sorted(p for p in source_dir.rglob('*') if p.is_file()
                    and p.suffix.lower() in EXTENSIONS) if source_dir.exists() else []
    unmatched, copies = [], []
    # Hash each source once; content identity, not names, controls deduplication.
    hashes = {}
    existing_image_hashes = {}
    for path in images:
        relative = path.relative_to(root).as_posix()
        safe_path(root, relative)
        problem, reason = find_matching_problem(path.name, index, aliases, scan.identities)
        if not problem:
            if relative in entries:
                raise ValueError(f'Previously integrated source no longer matches: {relative}: {reason}')
            unmatched.append({'source': relative, 'reason': reason})
            continue
        sha = digest(path)
        hashes[relative] = sha
        parsed = parse_image_name(path.name)
        previous = entries.get(relative)
        if previous:
            if previous['sha256'] != sha or previous['number'] != problem['number']:
                raise ValueError(f'Previously integrated source changed; review required: {relative}')
            continue
        folder = problem['folders'][0]
        # Reuse any byte-identical image already attached to this problem.
        duplicate = next((e for e in entries.values()
                          if e['number'] == problem['number'] and e['sha256'] == sha), None)
        if duplicate:
            destination = duplicate['destination']
            part = duplicate['part']
        else:
            part = parsed.part
            base = f'solution-part-{part}' if part is not None else 'solution'
            destination = f'{folder}/images/{base}{path.suffix.lower()}'
            if folder not in existing_image_hashes:
                image_dir = safe_path(root, folder + '/images')
                existing_image_hashes[folder] = {
                    digest(safe_path(root, p.relative_to(root).as_posix())):
                    p.relative_to(root).as_posix()
                    for p in sorted(image_dir.rglob('*'))
                    if p.is_file() and p.suffix.lower() in EXTENSIONS
                } if image_dir.exists() else {}
            destination = existing_image_hashes[folder].get(sha, destination)
            dst = safe_path(root, destination)
            if (dst.exists() and digest(dst) != sha) or any(
                    e['destination'] == destination and e['sha256'] != sha for e in entries.values()):
                destination = f'{folder}/images/{base}-{sha[:12]}{path.suffix.lower()}'
        entries[relative] = {'source': relative, 'number': problem['number'],
                             'title': problem['title'], 'slug': problem['slug'],
                             'part': part, 'destination': destination, 'sha256': sha,
                             'evidence': reason}
    grouped = defaultdict(dict)
    owners = {}
    # Preflight the entire migration before writing any image or README.
    for entry in entries.values():
        problem = index.get(entry['number'])
        if not problem or len(problem['folders']) != 1 or problem['slug'] != entry['slug']:
            raise ValueError(f'Manifest identity no longer has one verified folder: {entry["source"]}')
        expected = Path(problem['folders'][0]) / 'images'
        if Path(entry['destination']).parent != expected:
            # Topic relocation moves the whole folder; remap only within the verified identity.
            entry['destination'] = (expected / Path(entry['destination']).name).as_posix()
        owner = owners.setdefault(entry['sha256'], entry['number'])
        if owner != entry['number']:
            raise ValueError(f'Identical image assigned to different problems: {entry["source"]}')
        destination = safe_path(root, entry['destination'])
        if destination.exists():
            if digest(destination) != entry['sha256']:
                raise ValueError(f'Destination image differs; refusing overwrite: {entry["destination"]}')
        else:
            source = safe_path(root, entry['source'])
            if not source.is_file() or (hashes[entry['source']] if entry['source'] in hashes
                                       else digest(source)) != entry['sha256']:
                raise ValueError(f'Cannot restore missing image: {entry["destination"]}')
            if not any(dst == destination for _, dst in copies):
                copies.append((source, destination))
        grouped[problem['folders'][0]][entry['destination']] = entry
    readmes = []
    for folder, destinations in sorted(grouped.items()):
        selected = sorted(destinations.values(), key=lambda e: (
            e['part'] if e['part'] is not None else 0, e['destination']))
        path = safe_path(root, folder + '/README.md')
        original = path.read_bytes().decode('utf-8')
        updated = plan_readme(original, selected, selected[0]['title'])
        if updated != original:
            readmes.append((path, updated))
    serialized = json.dumps({'schema_version': 1, 'images': sorted(entries.values(),
                            key=lambda e: (e['number'], e['source']))}, indent=2, ensure_ascii=False) + '\n'
    if not dry_run:
        for src, dst in copies:
            dst.parent.mkdir(parents=True, exist_ok=True)
            # Exclusive creation prevents accidental replacement, including races.
            with src.open('rb') as incoming, dst.open('xb') as outgoing:
                shutil.copyfileobj(incoming, outgoing)
            if digest(src) != digest(dst):
                raise ValueError(f'Image copy failed hash validation: {dst}')
        for path, content in readmes:
            write_if_changed(path, content)
        if entries or (root / MANIFEST).exists():
            write_if_changed(root / MANIFEST, serialized)
        for folder in grouped:
            validate_image_references(root / folder)
    return {'discovered': len(images), 'matched': len(images) - len(unmatched),
            'unmatched': unmatched, 'problems': len(grouped), 'copied': len(copies),
            'readmes_updated': len(readmes), 'entries': sorted(entries.values(),
                                                              key=lambda e: (e['number'], e['source']))}


def print_result(result: dict) -> None:
    print(f'Visual solutions: {result["matched"]}/{result["discovered"]} source images matched; '
          f'{result["problems"]} problems; {result["copied"]} copies; '
          f'{result["readmes_updated"]} README updates.')
    for item in result['unmatched']:
        print(f'[Image review] {item["source"]}: {item["reason"]}')


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--dry-run', action='store_true', help='Audit without writing files')
    parser.add_argument('--report', type=Path, help='Write a JSON audit (outside the source folder)')
    args = parser.parse_args()
    from .organize import scan_repository, load_neetcode_data
    root = Path(__file__).resolve().parents[1]
    try:
        scan = scan_repository(root, load_neetcode_data(root / 'neetcode150.json'))
        result = integrate_images(root, scan, dry_run=args.dry_run)
        print_result(result)
        if args.report:
            write_if_changed(args.report, json.dumps(result, indent=2, ensure_ascii=False) + '\n')
    except (OSError, ValueError, KeyError, TypeError) as exc:
        print(f'[Image error] {exc}')
        return 1
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
