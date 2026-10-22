"""Offline safety and lifecycle tests for visual solution integration."""
import json
from collections import defaultdict
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from scripts import organize as o
from scripts import visual_solutions as v

ROOT = Path(__file__).resolve().parents[1]
DATA = o.load_neetcode_data(ROOT / 'neetcode150.json')


class PublishedVisualTests(unittest.TestCase):
    def test_repository_manifest_identity_hashes_and_readmes(self):
        """Validate published assets even in CI without the original source images."""
        scan = o.scan_repository(ROOT, DATA)
        index = v.build_problem_index(ROOT, scan)
        # CI tests run before organization. A root LeetHub resubmission must not
        # make its already published topic folder appear ambiguous here.
        for problem in index.values():
            problem['folders'] = [folder for folder in problem['folders']
                                  if len(Path(folder).parts) > 1]
        manifest = json.loads((ROOT / v.MANIFEST).read_text(encoding='utf-8'))
        aliases = json.loads((ROOT / v.ALIASES).read_text(encoding='utf-8'))
        self.assertEqual(manifest['schema_version'], 1)
        sources, destinations, owners = set(), {}, {}
        grouped = defaultdict(dict)
        for entry in manifest['images']:
            with self.subTest(source=entry['source']):
                self.assertNotIn(entry['source'], sources)
                sources.add(entry['source'])
                problem, reason = v.find_matching_problem(
                    Path(entry['source']).name, index, aliases, scan.identities)
                self.assertIsNotNone(problem, reason)
                self.assertEqual(entry['number'], problem['number'])
                self.assertEqual(entry['slug'], problem['slug'])
                folder = problem['folders'][0]
                self.assertEqual(Path(entry['destination']).parent, Path(folder) / 'images')
                destination = v.safe_path(ROOT, entry['destination'])
                self.assertEqual(v.digest(destination), entry['sha256'])
                source = v.safe_path(ROOT, entry['source'])
                if source.exists():
                    self.assertEqual(v.digest(source), entry['sha256'])
                self.assertEqual(owners.setdefault(entry['sha256'], entry['number']), entry['number'])
                self.assertEqual(destinations.setdefault(entry['destination'], entry['sha256']), entry['sha256'])
                grouped[folder][entry['destination']] = entry
        for folder, entries in grouped.items():
            with self.subTest(folder=folder):
                problem = next(p for p in index.values() if folder in p['folders'])
                # Folder-local images may be added without an inbox/manifest entry.
                for image in (ROOT / folder / 'images').iterdir():
                    if image.is_file() and image.suffix.lower() in v.EXTENSIONS:
                        relative = image.relative_to(ROOT).as_posix()
                        entries.setdefault(relative, {
                            'destination': relative, 'part': v.parse_image_name(image.name).part,
                            'title': problem['title']})
                selected = sorted(entries.values(), key=lambda e: (
                    e['part'] if e['part'] is not None else 0, e['destination']))
                original = (ROOT / folder / 'README.md').read_bytes().decode('utf-8')
                self.assertEqual(original.count(v.HEADING), 1)
                self.assertTrue(v.visual_block(original))
                self.assertEqual(v.validate_image_references(ROOT / folder), len(selected))
                # A regenerated block must preserve exactly the published links and order.
                self.assertEqual(v.plan_readme(original, selected, selected[0]['title'],
                                               v.problem_solutions(ROOT, scan, problem['number'], folder)), original)


class VisualTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name).resolve()
        (self.root / 'neetcode150.json').write_text(json.dumps(DATA))
        (self.root / 'README.md').write_text('# Repository\n')
        self.problem(1, 'two-sum', 'Two Sum')
        self.problem(112, 'path-sum', 'Path Sum', 'Trees')
        self.problem(113, 'path-sum-ii', 'Path Sum II', 'Trees')
        (self.root / 'docs').mkdir()
        (self.root / v.ALIASES).write_bytes((ROOT / v.ALIASES).read_bytes())

    def problem(self, number, slug, title, topic='Arrays'):
        path = self.root / topic / f'{number:04d}-{slug}'
        path.mkdir(parents=True, exist_ok=True)
        (path / 'README.md').write_text(
            f'<h2><a href="https://leetcode.com/problems/{slug}/">{number}. {title}</a></h2>'
            '<h3>Medium</h3>\n\nKeep statement, examples, constraints and [code](solution.cpp).\n')
        (path / 'solution.cpp').write_text('class Solution { public: int answer() { return 1; } };\n')
        return path

    def image(self, name, content=b'\xff\xd8\xffexample-jpeg-bytes'):
        path = self.root / v.SOURCE / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(content)
        return path

    def run_images(self, dry_run=False):
        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            scan = o.scan_repository(self.root, DATA)
            return v.integrate_images(self.root, scan, dry_run=dry_run)

    def snapshot(self):
        return {p.relative_to(self.root).as_posix(): (p.read_bytes(), p.stat().st_mtime_ns)
                for p in self.root.rglob('*') if p.is_file()}

    def test_number_and_title_disagreement(self):
        self.image('112-Two-Sum.jpg')
        result = self.run_images()
        self.assertEqual(result['matched'], 0)
        self.assertIn('conflict', result['unmatched'][0]['reason'])
        self.assertFalse(list(self.root.rglob('images')))

    def test_path_sum_problems_stay_separate(self):
        self.image('112-Path-Sum-Part-I.jpg', b'112')
        self.image('113-Path-Sum-Part-II.jpg', b'113')
        result = self.run_images()
        self.assertEqual([e['number'] for e in result['entries']], [112, 113])
        for entry in result['entries']:
            self.assertIn(f'{entry["number"]:04d}-', entry['destination'])
            self.assertEqual(v.digest(self.root / entry['source']), v.digest(self.root / entry['destination']))

    def test_unreviewed_path_sum_number_conflict(self):
        self.image('113-Path-Sum-Part-I.jpg')
        self.assertEqual(self.run_images()['matched'], 0)

    def test_exact_title_and_abbreviation(self):
        self.problem(111, 'minimum-depth-of-binary-tree', 'Minimum Depth of Binary Tree', 'Trees')
        self.image('111-Min-Depth-of-BT.jpg')
        self.assertEqual(self.run_images()['entries'][0]['number'], 111)

    def test_title_only_and_trailing_id(self):
        self.problem(122, 'best-time-to-buy-and-sell-stock-ii', 'Best Time to Buy and Sell Stock II')
        self.image('Two Sum.png', b'1')
        self.image('Best time to buy sell stocks -122.jpg', b'122')
        self.assertEqual([e['number'] for e in self.run_images()['entries']], [1, 122])

    def test_01_matrix_is_not_problem_one(self):
        self.image('01 Matrix Part-I.jpg')
        self.assertEqual(self.run_images()['matched'], 0)
        self.problem(542, '01-matrix', '01 Matrix', 'Graphs')
        self.assertEqual(self.run_images()['entries'][0]['number'], 542)

    def test_roman_and_numeric_part_order(self):
        for part in ['III', 'I', '10', 'II', 'IV']:
            self.image(f'1-Two-Sum-Part-{part}.jpg', part.encode())
        self.run_images()
        text = (self.root / 'Arrays/0001-two-sum/README.md').read_text()
        positions = [text.index(f'### Part {part}\n') for part in [1, 2, 3, 4, 10]]
        self.assertEqual(positions, sorted(positions))
        self.assertEqual(v.validate_image_references(self.root / 'Arrays/0001-two-sum'), 5)

    def test_dry_run_writes_nothing(self):
        self.image('1-Two-Sum.jpg')
        before = self.snapshot()
        self.assertEqual(self.run_images(dry_run=True)['copied'], 1)
        self.assertEqual(before, self.snapshot())

    def test_idempotency_preserves_mtimes_and_original_content(self):
        source = self.image('1-Two-Sum.jpg')
        readme = self.root / 'Arrays/0001-two-sum/README.md'
        original = readme.read_bytes()
        cpp = readme.parent / 'solution.cpp'
        code = cpp.read_bytes()
        self.run_images()
        before = self.snapshot()
        second = self.run_images()
        self.assertEqual(second['copied'], 0)
        self.assertEqual(second['readmes_updated'], 0)
        self.assertEqual(before, self.snapshot())
        self.assertTrue(readme.read_bytes().startswith(original))
        self.assertEqual(cpp.read_bytes(), code)
        self.assertTrue(source.is_file())

    def test_future_image_then_future_problem(self):
        self.image('36-Valid-Sudoku-Part-I.jpg')
        self.assertEqual(self.run_images()['matched'], 0)
        self.assertFalse(list(self.root.rglob('0036-*')))
        self.problem(36, 'valid-sudoku', 'Valid Sudoku')
        self.assertEqual(self.run_images()['matched'], 1)
        self.image('36-Valid-Sudoku-Part-II.jpg', b'new-page')
        self.assertEqual(self.run_images()['copied'], 1)
        self.assertEqual(v.validate_image_references(self.root / 'Arrays/0036-valid-sudoku'), 2)

    def test_duplicate_bytes_one_destination_and_one_reference(self):
        self.image('1-Two-Sum-Part-I.jpg')
        self.image('1-Two-Sum-Part-II.jpg')
        result = self.run_images()
        self.assertEqual(len({e['destination'] for e in result['entries']}), 1)
        self.assertEqual(v.validate_image_references(self.root / 'Arrays/0001-two-sum'), 1)

    def test_preexisting_identical_image_reused(self):
        src = self.image('1-Two-Sum.jpg')
        path = self.root / 'Arrays/0001-two-sum/images/original photo.jpg'
        path.parent.mkdir()
        path.write_bytes(src.read_bytes())
        result = self.run_images()
        self.assertEqual(result['copied'], 0)
        self.assertEqual(result['entries'][0]['destination'], path.relative_to(self.root).as_posix())
        self.assertIn('original%20photo.jpg', (path.parent.parent / 'README.md').read_text())
        self.assertEqual(v.validate_image_references(path.parent.parent), 1)

    def test_conflicting_existing_filename_never_overwritten(self):
        self.image('1-Two-Sum.jpg')
        path = self.root / 'Arrays/0001-two-sum/images/solution.jpg'
        path.parent.mkdir()
        path.write_bytes(b'keep')
        result = self.run_images()
        self.assertEqual(path.read_bytes(), b'keep')
        self.assertNotEqual(result['entries'][0]['destination'], path.relative_to(self.root).as_posix())
        self.assertEqual(self.run_images()['copied'], 0)

    def test_missing_sources_supported_and_corruption_detected(self):
        src = self.image('1-Two-Sum.jpg')
        result = self.run_images()
        src.unlink()
        before = self.snapshot()
        self.run_images()
        self.assertEqual(before, self.snapshot())
        dst = self.root / result['entries'][0]['destination']
        dst.write_bytes(b'corrupted')
        with self.assertRaisesRegex(ValueError, 'refusing overwrite'):
            self.run_images()
        self.assertEqual(dst.read_bytes(), b'corrupted')

    def test_changed_source_fails_without_overwriting(self):
        src = self.image('1-Two-Sum.jpg')
        self.run_images()
        src.write_bytes(b'replacement')
        before = self.snapshot()
        with self.assertRaisesRegex(ValueError, 'source changed'):
            self.run_images()
        self.assertEqual(before, self.snapshot())

    def test_unknown_and_unsupported_files_untouched(self):
        self.image('mystery.jpg')
        self.image('not-a-solution.txt', b'leave alone')
        before = self.snapshot()
        result = self.run_images()
        self.assertEqual(result['discovered'], 1)
        self.assertEqual(len(result['unmatched']), 1)
        self.assertEqual(before, self.snapshot())

    def test_preflight_bad_readme_prevents_all_copies(self):
        self.image('1-Two-Sum.jpg')
        path = self.root / 'Arrays/0001-two-sum/README.md'
        path.write_text(path.read_text() + v.START)
        before = self.snapshot()
        with self.assertRaisesRegex(ValueError, 'markers'):
            self.run_images()
        self.assertEqual(before, self.snapshot())

    def test_unmanaged_visual_section_not_duplicated(self):
        self.image('1-Two-Sum.jpg')
        path = self.root / 'Arrays/0001-two-sum/README.md'
        path.write_text(path.read_text() + '\n' + v.HEADING)
        with self.assertRaisesRegex(ValueError, 'Unmanaged'):
            self.run_images()
        self.assertFalse((path.parent / 'images').exists())

    def test_ambiguous_existing_folders_not_chosen(self):
        self.problem(1, 'two-sum', 'Two Sum', 'Other')
        self.image('1-Two-Sum.jpg')
        result = self.run_images()
        self.assertEqual(result['matched'], 0)
        self.assertIn('multiple', result['unmatched'][0]['reason'])

    def test_identical_bytes_across_different_problems_fail(self):
        self.image('1-Two-Sum.jpg')
        self.image('112-Path-Sum.jpg')
        with self.assertRaisesRegex(ValueError, 'different problems'):
            self.run_images()
        self.assertFalse(list(self.root.rglob('images')))

    def test_resubmitted_readme_keeps_visuals_without_source(self):
        src_image = self.image('1-Two-Sum.jpg')
        self.run_images()
        src_image.unlink()
        dst = self.root / 'Arrays/0001-two-sum'
        block = v.visual_block((dst / 'README.md').read_text())
        incoming = self.problem(1, 'two-sum', 'Two Sum', '.')
        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            o.scan_and_reorganize(base_dir=self.root)
        self.assertFalse(incoming.exists())
        self.assertIn(block, (dst / 'README.md').read_text())
        self.run_images()
        self.assertEqual(v.validate_image_references(dst), 1)

    def test_nested_cleanup_preserves_image_subdirectories(self):
        dst = self.root / 'Arrays/0001-two-sum'
        nested = dst / dst.name
        (nested / 'images').mkdir(parents=True)
        (nested / 'images/notes.jpg').write_bytes(b'preserve nested image')
        with patch('subprocess.run'):
            o.clean_nested_directories(self.root)
        self.assertFalse(nested.exists())
        self.assertEqual((dst / 'images/notes.jpg').read_bytes(), b'preserve nested image')

    def test_resubmission_image_conflict_preserves_both_folders(self):
        src_image = self.image('1-Two-Sum.jpg')
        self.run_images()
        src = self.problem(1, 'two-sum', 'Two Sum', '.')
        (src / 'images').mkdir()
        (src / 'images/solution.jpg').write_bytes(b'different image')
        before = self.snapshot()
        with self.assertRaisesRegex(ValueError, 'Conflicting incoming image'):
            o.move_or_merge_question(str(src), str(self.root / 'Arrays/0001-two-sum'), self.root)
        self.assertEqual(before, self.snapshot())
        self.assertTrue(src_image.exists())

    def test_different_managed_readme_sections_require_review(self):
        old = v.START + '\n![Old](./images/old.jpg)\n' + v.END
        new = v.START + '\n![New](./images/new.jpg)\n' + v.END
        with self.assertRaisesRegex(ValueError, 'Conflicting visual sections'):
            v.preserve_visual_section(new, old)

    def test_symlink_source_rejected_without_writes(self):
        src = self.image('1-Two-Sum.jpg')
        target = self.root / 'external.jpg'
        src.rename(target)
        src.symlink_to(target)
        with self.assertRaisesRegex(ValueError, 'Symlink'):
            self.run_images()
        self.assertFalse(list(self.root.rglob('images')))

    def test_full_organizer_pipeline_integrates_after_move(self):
        src = self.problem(36, 'valid-sudoku', 'Valid Sudoku', '.')
        self.image('36-Valid-Sudoku-Part-I.jpg')
        with patch.object(o, 'BASE_DIR', str(self.root)), patch('sys.argv', ['organize.py', '--offline']):
            self.assertEqual(o.main(), 0)
        self.assertFalse(src.exists())
        before = self.snapshot()
        with patch.object(o, 'BASE_DIR', str(self.root)), patch('sys.argv', ['organize.py', '--offline']):
            self.assertEqual(o.main(), 0)
        self.assertEqual(before, self.snapshot())

    def test_broken_relative_link_detected(self):
        self.image('1-Two-Sum.jpg')
        result = self.run_images()
        (self.root / result['entries'][0]['destination']).unlink()
        with self.assertRaisesRegex(ValueError, 'Missing image'):
            v.validate_image_references(self.root / 'Arrays/0001-two-sum')

    def test_topic_override_does_not_move_source_images_or_loose_images(self):
        source = self.image('3286-Find-Safe-Walk-Grid-Part-I.jpg')
        loose = self.root / 'Graphs/3286-Find-Safe-Walk-Grid-Part-II.jpg'
        loose.parent.mkdir()
        loose.write_bytes(b'leave loose files alone')
        before = self.snapshot()
        with patch('subprocess.run') as git:
            o.scan_and_reorganize(base_dir=self.root)
        git.assert_not_called()
        self.assertTrue(source.is_file())
        self.assertTrue(loose.is_file())
        self.assertEqual(before, self.snapshot())

    def test_exact_code_refresh_and_outside_content_preserved(self):
        self.image('1-Two-Sum.jpg')
        folder = self.root / 'Arrays/0001-two-sum'
        cpp, readme = folder / 'solution.cpp', folder / 'README.md'
        # Preserve CRLF, Unicode, trailing spaces and a missing terminal newline.
        source = '// Approach: Hashing\r\n// Time Complexity = O(n)\r\n// Space Complexity: O(n)\r\nclass Solution { /* π ``` */ };  '
        cpp.write_bytes(source.encode())
        description = readme.read_bytes()
        self.run_images()
        text = readme.read_bytes().decode()
        self.assertTrue(text.startswith(description.decode()))
        self.assertIn(v.fenced(source, 'cpp'), text)
        self.assertIn('[View Original C++ File](./solution.cpp)', text)
        self.assertLess(text.index('![Two Sum'), text.index('## 💻 C++ Solution'))
        self.assertIn('## 💡 Approach', text)
        self.assertIn('## ⏱️ Complexity Analysis', text)
        readme.write_bytes((text + '\nManual notes after generated block.\n').encode())
        outside = lambda t: t.replace(v.visual_block(t), '', 1)
        previous = readme.read_bytes().decode()
        changed = source + '\r\n// Updated implementation'
        cpp.write_bytes(changed.encode())
        self.assertEqual(self.run_images()['readmes_updated'], 1)
        updated = readme.read_bytes().decode()
        self.assertEqual(outside(previous), outside(updated))
        self.assertIn(v.fenced(changed, 'cpp'), updated)
        self.assertNotIn(v.fenced(source, 'cpp'), updated)
        self.assertEqual(cpp.read_bytes(), changed.encode())
        self.assertEqual(self.run_images()['readmes_updated'], 0)

    def test_no_invented_metadata_or_readme_for_no_images(self):
        readme = self.root / 'Arrays/0001-two-sum/README.md'
        before = readme.read_bytes()
        self.run_images()
        self.assertEqual(readme.read_bytes(), before)
        self.image('1-Two-Sum.jpg')
        self.run_images()
        text = readme.read_text()
        self.assertNotIn('## 💡 Approach', text)
        self.assertNotIn('## ⏱️ Complexity Analysis', text)
        self.assertIn('```cpp', text)
        self.assertEqual(v.comment_metadata('const char *s = "// Approach: fake";'), ([], []))
        self.assertEqual(v.comment_metadata('auto s = R"tag(\n// Approach: fake\n/* Time Complexity: fake */\n)tag";'), ([], []))

    def test_migration_changes_only_legacy_block(self):
        readme = self.root / 'Arrays/0001-two-sum/README.md'
        legacy = v.LEGACY_START + '\n' + v.LEGACY_HEADING + '\n' + v.LEGACY_END
        original = readme.read_text() + legacy + '\nManual suffix\n'
        readme.write_text(original)
        self.image('1-Two-Sum.jpg')
        self.run_images()
        updated = readme.read_text()
        self.assertEqual(original.replace(legacy, ''), updated.replace(v.visual_block(updated), ''))
        self.assertNotIn(v.LEGACY_START, updated)
        self.assertEqual(updated.count(v.START), 1)

    def test_direct_images_added_removed_and_last_image_removed(self):
        folder = self.root / 'Arrays/0001-two-sum'
        images = folder / 'images'
        images.mkdir()
        for part in [10, 2, 1]:
            (images / f'solution-part-{part}.jpg').write_bytes(str(part).encode())
        self.run_images()
        text = (folder / 'README.md').read_text()
        self.assertLess(text.index('### Part 2\n'), text.index('### Part 10\n'))
        (images / 'solution-part-2.jpg').unlink()
        self.run_images()
        self.assertNotIn('solution-part-2.jpg', (folder / 'README.md').read_text())
        for image in images.iterdir():
            image.unlink()
        self.run_images()
        text = (folder / 'README.md').read_text()
        self.assertNotIn(v.HEADING, text)
        self.assertIn('```cpp', text)
        self.assertEqual(self.run_images()['readmes_updated'], 0)

    def test_deleted_imported_image_not_restored_from_local_original(self):
        self.image('1-Two-Sum.jpg')
        result = self.run_images()
        destination = self.root / result['entries'][0]['destination']
        destination.unlink()
        self.run_images()
        before = self.snapshot()
        result = self.run_images()
        self.assertEqual(before, self.snapshot())
        self.assertFalse(destination.exists())
        self.assertNotIn('![', (destination.parent.parent / 'README.md').read_text())
        self.assertFalse(result['entries'])

    def test_multiple_cpp_implementations_embedded_exactly(self):
        self.image('1-Two-Sum.jpg')
        folder = self.root / 'Arrays/0001-two-sum'
        second = folder / '0001-two-sum-approach-2.cpp'
        second.write_text('// Approach: Second algorithm\nclass Solution { public: int answer() { return 2; } };')
        self.run_images()
        text = (folder / 'README.md').read_text()
        for cpp in folder.glob('*.cpp'):
            self.assertIn(v.fenced(cpp.read_text(), 'cpp'), text)
            self.assertIn(f'[View Original C++ File](./{cpp.name})', text)
        self.assertEqual(text.count('## 💻 C++ Solution'), 1)

    def test_java_only_problem_uses_existing_source(self):
        folder = self.root / 'Arrays/0001-two-sum'
        (folder / 'solution.cpp').unlink()
        code = 'class Solution { public int answer() { return 1; } }'
        (folder / 'solution.java').write_text(code)
        self.image('1-Two-Sum.jpg')
        self.run_images()
        text = (folder / 'README.md').read_text()
        self.assertIn('## 💻 Java Solution', text)
        self.assertIn(v.fenced(code, 'java'), text)
        self.assertIn('[View Original Java File](./solution.java)', text)
        self.assertNotIn('C++', text)

    def test_part_parser_does_not_strip_problem_series(self):
        for name, title, part in [('House Robber-II.jpg', 'House Robber-II', None),
                                  ('Subsets_II_Part_I.jpeg', 'Subsets_II', 1),
                                  ('SubArray Sum Equals K Part_II.jpeg', 'SubArray Sum Equals K', 2)]:
            parsed = v.parse_image_name(name)
            self.assertEqual((parsed.title, parsed.part), (title, part))


if __name__ == '__main__':
    unittest.main()
