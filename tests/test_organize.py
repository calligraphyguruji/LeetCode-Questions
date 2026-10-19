"""Offline integration fixtures; never add simulated solutions to the repository."""
import copy
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from scripts import organize as tracker

ROOT = Path(__file__).resolve().parents[1]
DATA = tracker.load_neetcode_data(ROOT / 'neetcode150.json')


class TrackerTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'neetcode150.json').write_text(json.dumps(DATA))
        (self.root / 'README.md').write_text('# My practice\n\nKeep this [link](https://example.org).\n')

    def add(self, name, code='class Solution { public: int answer() { return 1; } };'):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(code)
        return path

    def scan(self):
        return tracker.scan_repository(self.root, DATA)

    def test_verified_dataset(self):
        self.assertEqual(len(DATA['questions']), 150)
        self.assertEqual(len(DATA['topics']), 18)
        self.assertEqual([q['sequence'] for q in DATA['questions']], list(range(1, 151)))
        self.assertEqual(DATA['questions'][0]['title'], 'Contains Duplicate')
        self.assertEqual(DATA['questions'][-1]['title'], 'Detect Squares')
        self.assertEqual(next(q['topic'] for q in DATA['questions'] if q['leetcode_id'] == 22), 'Backtracking')

    def test_invalid_dataset_rejected(self):
        mutations = [lambda d: d['questions'].pop(),
                     lambda d: d['questions'][0].update(url='https://example.org'),
                     lambda d: d['questions'][0].update(leetcode_id=242),
                     lambda d: d['questions'][0].update(difficulty='Extreme'),
                     lambda d: d['questions'][0].update(topic='Trees'),
                     lambda d: d['questions'][0].update(sequence=2)]
        for mutate in mutations:
            data = copy.deepcopy(DATA)
            mutate(data)
            path = self.root / 'bad.json'
            path.write_text(json.dumps(data))
            with self.assertRaises(ValueError):
                tracker.load_neetcode_data(path)

    def test_filename_variations(self):
        for name in ['1-two-sum.cpp', 'Two_Sum.cpp', 'two-sum.cpp', '0001_Two_Sum.cpp', '1.cpp']:
            with self.subTest(name=name):
                path = self.add(name)
                self.assertEqual(set(self.scan().solutions), {1})
                path.unlink()

    def test_new_neetcode_solution(self):
        _, initial, _ = tracker.update_tracking(self.root)
        self.assertFalse(initial.solutions)
        self.add('new/0003-longest-substring-without-repeating-characters/solution.py', 'def lengthOfLongestSubstring(s):\n    return len(s)\n')
        _, scan, changed = tracker.update_tracking(self.root)
        self.assertTrue(changed)
        readme = (self.root / 'README.md').read_text()
        self.assertEqual(set(scan.solutions), {3})
        self.assertIn('**Solved Questions:** 1', readme)
        self.assertIn('**Remaining Questions:** 149', readme)
        self.assertIn('Sliding Window — 1/6 Solved (16.7%)', readme)
        self.assertIn('✅ Yes | [Solution](new/0003-', readme)

    def test_non_neetcode_does_not_change_tracker(self):
        tracker.update_tracking(self.root)
        before = (self.root / 'README.md').read_bytes()
        self.add('509-fibonacci-number.cpp')
        scan = self.scan()
        self.assertIn(509, scan.solutions)
        tracker.update_tracking(self.root)
        self.assertEqual(before, (self.root / 'README.md').read_bytes())

    def test_duplicate_solutions_count_once(self):
        self.add('0001-two-sum/one.cpp')
        self.add('0001-two-sum/two.py', 'def twoSum(nums, target):\n    return [0, 1]\n')
        _, scan, _ = tracker.update_tracking(self.root)
        self.assertEqual(len(scan.solutions[1]), 2)
        self.assertIn('**Solved Questions:** 1', (self.root / 'README.md').read_text())

    def test_idempotency_and_no_network(self):
        self.add('two-sum.cpp')
        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            tracker.update_tracking(self.root)
            before = (self.root / 'README.md').stat().st_mtime_ns
            _, _, changed = tracker.update_tracking(self.root)
            self.assertFalse(changed)
            self.assertEqual(before, (self.root / 'README.md').stat().st_mtime_ns)

    def test_unrelated_readme_preserved(self):
        original = (self.root / 'README.md').read_bytes()
        tracker.update_tracking(self.root)
        first = (self.root / 'README.md').read_text()
        first += '\n## Personal notes\nKeep these too.\n'
        (self.root / 'README.md').write_text(first)
        self.add('two-sum.cpp')
        tracker.update_tracking(self.root)
        final = (self.root / 'README.md').read_bytes()
        self.assertTrue(final.startswith(original))
        self.assertTrue(final.endswith(b'\n## Personal notes\nKeep these too.\n'))
        self.assertEqual(final.count(tracker.TRACKER_START.encode()), 1)

    def test_documentation_is_not_a_solution(self):
        self.add('0001-two-sum/README.md', 'Two Sum https://leetcode.com/problems/two-sum/')
        self.add('two-sum.cpp', '// TODO: solve Two Sum\n')
        self.assertFalse(self.scan().solutions)

    def test_conflicts_are_reported(self):
        self.add('0001-two-sum/0242-valid-anagram.cpp')
        scan = self.scan()
        self.assertFalse(scan.solutions)
        self.assertEqual(len(scan.ambiguous), 1)

    def test_unknown_files_are_reported(self):
        self.add('mystery.cpp')
        scan = self.scan()
        self.assertFalse(scan.solutions)
        self.assertEqual(scan.unidentified, ['mystery.cpp'])

    def test_source_url_and_comments(self):
        self.add('answer.cpp', '// https://leetcode.com/problems/two-sum/\nint answer() { return 1; }')
        self.add('other.cpp', '// LeetCode 242\nint answer() { return 2; }')
        self.assertEqual(set(self.scan().solutions), {1, 242})

    def test_historical_internal_readme_id(self):
        self.add('0876-middle-of-the-linked-list/README.md', '<h2><a href="https://leetcode.com/problems/middle-of-the-linked-list/">908. Middle of the Linked List</a></h2><h3>Easy</h3>')
        self.add('0876-middle-of-the-linked-list/solution.cpp')
        scan = self.scan()
        self.assertEqual(set(scan.solutions), {876})
        self.assertEqual(len(scan.metadata_notes), 1)

    def test_url_conflict(self):
        self.add('0001-two-sum/README.md', '<h2><a href="https://leetcode.com/problems/valid-anagram/">242. Valid Anagram</a></h2>')
        self.add('0001-two-sum/solution.cpp')
        self.assertFalse(self.scan().solutions)
        self.assertTrue(self.scan().ambiguous)

    def test_links_are_encoded_and_exist(self):
        self.add('my solutions/0001-two-sum/approach (1).cpp')
        _, scan, _ = tracker.update_tracking(self.root)
        self.assertIn('my%20solutions/0001-two-sum/approach%20%281%29.cpp', tracker.render_tracker(DATA, scan))
        for paths in scan.solutions.values():
            for path in paths:
                self.assertTrue((self.root / path).is_file())

    def test_bad_markers_fail_without_writing(self):
        path = self.root / 'README.md'
        for text in [tracker.TRACKER_START, tracker.TRACKER_END + tracker.TRACKER_START,
                     (tracker.TRACKER_START + tracker.TRACKER_END) * 2]:
            path.write_text(text)
            with self.assertRaises(ValueError):
                tracker.update_tracking(self.root)
            self.assertEqual(path.read_text(), text)

    def test_non_neetcode_updates_existing_index(self):
        path = self.root / 'README.md'
        path.write_text('# Notes\n\n## 📋 Complete Problem Index\n\n| # | Problem |\n|---|---|\n\n---\n\n## Personal notes\nKeep.\n')
        self.add('509-fibonacci-number.cpp')
        tracker.update_tracking(self.root)
        text = path.read_text()
        self.assertIn('| 0509 |', text)
        self.assertIn('## Personal notes\nKeep.', text)
        self.assertIn('**Solved Questions:** 0', text)

    def test_scanner_excludes_infrastructure(self):
        self.add('tests/1-two-sum.py', 'assert True')
        self.add('.venv/242-valid-anagram.py', 'pass')
        self.assertFalse(self.scan().solutions)

    def test_category_folder_is_not_a_problem(self):
        self.add('BinarySearch/mystery.cpp')
        self.assertFalse(self.scan().solutions)
        self.assertEqual(self.scan().unidentified, ['BinarySearch/mystery.cpp'])

    def test_solution_bytes_and_locations_preserved(self):
        path = self.add('0001-two-sum/solution.cpp')
        before = path.read_bytes()
        tracker.update_tracking(self.root)
        self.assertEqual(path.read_bytes(), before)

    def test_real_repository(self):
        scan = tracker.scan_repository(ROOT, DATA)
        self.assertFalse(scan.ambiguous)
        self.assertFalse(scan.unidentified)
        self.assertGreater(len(scan.solutions), 0)
        rendered = tracker.render_tracker(DATA, scan)
        self.assertEqual(rendered.count('| [LeetCode #'), 150)
        self.assertEqual(rendered.count('\n### '), 18)
        self.assertEqual(rendered.count('✅ Yes'), sum(q['leetcode_id'] in scan.solutions for q in DATA['questions']))

    def test_scan_and_reorganize_moves_root_solution(self):
        # Simulate LeetHub pushing a new problem folder to root
        root_problem = self.root / '0001-two-sum'
        root_problem.mkdir(parents=True, exist_ok=True)
        (root_problem / 'solution.py').write_text('def twoSum(): pass\n')
        (root_problem / 'README.md').write_text('# 1. Two Sum\n')

        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            tracker.scan_and_reorganize(base_dir=self.root)

        # Should move to Arrays/0001-two-sum
        target_dir = self.root / 'Arrays' / '0001-two-sum'
        self.assertTrue(target_dir.is_dir())
        self.assertTrue((target_dir / 'solution.py').is_file())
        self.assertFalse(root_problem.exists())

    def test_classify_topic_offline_neetcode(self):
        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            # Problem 1 is Two Sum -> Arrays & Hashing -> Arrays
            topic = tracker.classify_topic('two-sum', 1, base_dir=self.root)
            self.assertEqual(topic, 'Arrays')
            # Problem 206 is Reverse Linked List -> Linked List -> Linked-List
            topic = tracker.classify_topic('reverse-linked-list', 206, base_dir=self.root)
            self.assertEqual(topic, 'Linked-List')
            # Problem 704 is Binary Search -> Binary Search -> BinarySearch
            topic = tracker.classify_topic('binary-search', 704, base_dir=self.root)
            self.assertEqual(topic, 'BinarySearch')

    def test_leethub_topics_marker_ensured(self):
        path = self.root / 'README.md'
        path.write_text('# My repo\n\n' + tracker.TRACKER_START + '\nold\n' + tracker.TRACKER_END)
        tracker.update_tracking(self.root)
        content = path.read_text()
        self.assertIn(tracker.LEETHUB_TOPICS_START, content)
        self.assertIn(tracker.LEETHUB_TOPICS_END, content)
        self.assertTrue(content.index(tracker.LEETHUB_TOPICS_START) < content.index(tracker.TRACKER_START))

    def test_full_pipeline_idempotency(self):
        # Set up a root problem and run both steps
        root_problem = self.root / '0001-two-sum'
        root_problem.mkdir(parents=True, exist_ok=True)
        (root_problem / 'solution.py').write_text('def twoSum(): pass\n')

        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            tracker.scan_and_reorganize(base_dir=self.root)
            tracker.update_tracking(self.root)

        # Snapshot file state
        readme_mtime = (self.root / 'README.md').stat().st_mtime_ns
        readme_content = (self.root / 'README.md').read_text()

        # Second run should do nothing
        with patch('urllib.request.urlopen', side_effect=AssertionError('Network forbidden')):
            tracker.scan_and_reorganize(base_dir=self.root)
            _, _, changed = tracker.update_tracking(self.root)

        self.assertFalse(changed)
        self.assertEqual(readme_content, (self.root / 'README.md').read_text())


if __name__ == '__main__':
    unittest.main()
