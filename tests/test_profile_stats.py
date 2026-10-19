"""Synthetic profile contracts; none of these numbers are live verification."""
from datetime import datetime, timedelta, timezone
import io
import json
import os
from pathlib import Path
import socket
import tempfile
import threading
import unittest
from unittest.mock import patch
from urllib.error import HTTPError, URLError
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer

from scripts import organize, profile_stats as profile

ROOT = Path(__file__).resolve().parents[1]
NOW = datetime(2026, 10, 19, 12, tzinfo=timezone.utc)
USERNAME = 'calligraphyguruji'


def payload(updated=True):
    today = NOW.date()
    days = [today - timedelta(days=i) for i in range(95)] if updated else [today - timedelta(days=i) for i in range(1, 95)]
    days += [(NOW.replace(month=1, day=1) + timedelta(days=i)).date() for i in range(114)]
    calendar = {str(int(datetime(d.year, d.month, d.day, tzinfo=timezone.utc).timestamp())): 1 for d in days}
    return {'data': {'matchedUser': {
        'username': USERNAME,
        'submitStatsGlobal': {'acSubmissionNum': [
            {'difficulty': 'All', 'count': 257 if updated else 256},
            {'difficulty': 'Easy', 'count': 80},
            {'difficulty': 'Medium', 'count': 153 if updated else 152},
            {'difficulty': 'Hard', 'count': 24},
        ]},
        'userCalendar': {'totalActiveDays': len(calendar), 'submissionCalendar': json.dumps(calendar), 'streak': 114},
        'previousCalendar': {'submissionCalendar': '{}'},
    }}}


def response(data):
    return io.BytesIO(json.dumps(data).encode())


class ProfileTests(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        self.root = Path(temp.name)
        self.readme = self.root / 'README.md'
        self.readme.write_bytes((ROOT / 'README.md').read_bytes())
        self.readme.write_text(profile.render_dashboard(self.readme.read_text(), profile.parse_profile(payload(False), USERNAME, NOW)))
        (self.root / 'neetcode150.json').write_bytes((ROOT / 'neetcode150.json').read_bytes())

    def refresh(self, data=None, now=NOW):
        with patch.object(profile, 'urlopen', return_value=response(payload() if data is None else data)):
            return profile.refresh_dashboard(self.root, now=now)

    def test_solved_256_to_257_and_difficulty_consistency(self):
        self.assertTrue(self.refresh()['verified'])
        text = self.readme.read_text()
        self.assertIn('Problems_Solved-257-', text)
        self.assertIn('| 🎯 **Total Solved** | **257** |', text)
        self.assertIn('| 🟡 **Medium** | 153 | 59.5% |', text)
        stats = json.loads((self.root / 'leetcode-profile.json').read_text())['stats']
        self.assertEqual(stats['easy'] + stats['medium'] + stats['hard'], stats['solved'])

    def test_streak_94_to_95_and_active_days(self):
        self.refresh()
        text = self.readme.read_text()
        self.assertIn('Current_Streak-95_Days-', text)
        self.assertIn('| 🔥 **Current Streak** | **95 Days** |', text)
        self.assertIn('Active_Days-209_Days-', text)
        self.assertIn('| 📅 **Total Active Days** | **209 Days** |', text)

    def test_streak_can_update_without_solved_count_changing(self):
        data = payload()
        data['data']['matchedUser']['submitStatsGlobal'] = payload(False)['data']['matchedUser']['submitStatsGlobal']
        self.assertTrue(self.refresh(data)['changed'])
        text = self.readme.read_text()
        self.assertIn('Problems_Solved-256-', text)
        self.assertIn('Current_Streak-95_Days-', text)

    def test_longest_calendar_streak_is_not_current(self):
        stats = profile.parse_profile(payload(), USERNAME, NOW)
        self.assertEqual(stats['current_streak'], 95)
        self.assertNotEqual(stats['current_streak'], 114)

    def test_unchanged_values_do_not_rewrite_readme(self):
        before = self.readme.read_bytes()
        mtime = self.readme.stat().st_mtime_ns
        self.assertFalse(self.refresh(payload(False))['changed'])
        self.assertEqual(before, self.readme.read_bytes())
        self.assertEqual(mtime, self.readme.stat().st_mtime_ns)

    def test_two_runs_identical_including_snapshot_timestamp(self):
        self.refresh()
        files = [self.readme, self.root / 'leetcode-profile.json']
        before = [(p.read_bytes(), p.stat().st_mtime_ns) for p in files]
        self.assertFalse(self.refresh(now=NOW + timedelta(minutes=1))['changed'])
        self.assertEqual(before, [(p.read_bytes(), p.stat().st_mtime_ns) for p in files])

    def test_corrupt_snapshot_can_be_recovered_from_valid_source(self):
        path = self.root / 'leetcode-profile.json'
        path.write_text('{invalid')
        self.assertTrue(self.refresh()['verified'])
        self.assertEqual(json.loads(path.read_text())['stats']['solved'], 257)

    def test_api_unavailable_preserves_verified_files(self):
        self.refresh()
        files = [self.readme, self.root / 'leetcode-profile.json']
        before = [p.read_bytes() for p in files]
        with patch.object(profile, 'urlopen', side_effect=URLError('offline')):
            self.assertFalse(profile.refresh_dashboard(self.root, now=NOW)['verified'])
        self.assertEqual(before, [p.read_bytes() for p in files])

    def test_timeout_preserves_readme(self):
        before = self.readme.read_bytes()
        with patch.object(profile, 'urlopen', side_effect=socket.timeout()):
            self.assertFalse(profile.refresh_dashboard(self.root, now=NOW)['verified'])
        self.assertEqual(before, self.readme.read_bytes())

    def test_inconsistent_counts_missing_fields_and_wrong_users_rejected(self):
        bad = []
        x = payload(); x['data']['matchedUser']['submitStatsGlobal']['acSubmissionNum'][0]['count'] = 999; bad.append(x)
        x = payload(); x['data']['matchedUser']['username'] = 'someone-else'; bad.append(x)
        x = payload(); x['data']['matchedUser']['userCalendar']['totalActiveDays'] = 999; bad.append(x)
        x = payload(); x['data']['matchedUser']['submitStatsGlobal']['acSubmissionNum'][0]['count'] = True; bad.append(x)
        x = payload(); x['data']['matchedUser']['submitStatsGlobal']['acSubmissionNum'].pop(); bad.append(x)
        x = payload(); x['data']['matchedUser'] = None; bad.append(x)
        bad.extend([{'errors': [{'message': 'rate limited'}]}, {}, []])
        before = self.readme.read_bytes()
        for item in bad:
            with self.subTest(item=item):
                self.assertFalse(self.refresh(item)['verified'])
                self.assertEqual(before, self.readme.read_bytes())
                self.assertFalse((self.root / 'leetcode-profile.json').exists())

    def test_html_response_and_invalid_json(self):
        before = self.readme.read_bytes()
        with patch.object(profile, 'urlopen', return_value=io.BytesIO(b'<html>Unavailable</html>')):
            self.assertFalse(profile.refresh_dashboard(self.root, now=NOW)['verified'])
        self.assertEqual(before, self.readme.read_bytes())

    def test_http_429_retries_once(self):
        failure = HTTPError(profile.ENDPOINT, 429, 'rate limited', {'Retry-After': '0'}, None)
        with patch.object(profile, 'urlopen', side_effect=[failure, response(payload())]) as request, patch.object(profile.time, 'sleep'):
            self.assertTrue(profile.refresh_dashboard(self.root, now=NOW)['verified'])
        self.assertEqual(request.call_count, 2)

    def test_http_403_does_not_retry_or_zero_counts(self):
        before = self.readme.read_bytes()
        with patch.object(profile, 'urlopen', side_effect=HTTPError(profile.ENDPOINT, 403, 'Forbidden', {}, None)) as request:
            self.assertFalse(profile.refresh_dashboard(self.root, now=NOW)['verified'])
        self.assertEqual(request.call_count, 1)
        self.assertEqual(before, self.readme.read_bytes())

    def test_real_request_contract_and_single_request(self):
        with patch.object(profile, 'urlopen', return_value=response(payload())) as request:
            profile.refresh_dashboard(self.root, endpoint='http://127.0.0.1:4900/leetcode/graphql/', now=NOW)
        self.assertEqual(request.call_count, 1)
        req = request.call_args[0][0]
        self.assertEqual(req.get_method(), 'POST')
        body = json.loads(req.data)
        self.assertEqual(body['variables'], {'username': USERNAME, 'year': 2026, 'previousYear': 2025})
        self.assertIn('submitStatsGlobal', body['query'])
        self.assertIn('previousCalendar', body['query'])

    def test_all_unrelated_readme_sections_preserved(self):
        before = self.readme.read_text()
        self.refresh()
        after = self.readme.read_text()
        start = before.index('## 📊 Progress Dashboard')
        end = before.index('## 🎯 Intentional Curation')
        self.assertEqual(before[:start], after[:start])
        self.assertEqual(before[end:], after[after.index('## 🎯 Intentional Curation'):])
        self.assertEqual(after.count('## 📊 Progress Dashboard'), 1)
        self.assertEqual(after.count(organize.TRACKER_START), 1)

    def test_duplicate_or_missing_dashboard_refuses_partial_updates(self):
        for content in ('# No dashboard', self.readme.read_text() * 2):
            self.readme.write_text(content)
            self.assertFalse(self.refresh()['verified'])
            self.assertEqual(content, self.readme.read_text())

    def test_valid_zero_values_are_not_treated_as_fetch_failures(self):
        data = payload()
        user = data['data']['matchedUser']
        for row in user['submitStatsGlobal']['acSubmissionNum']: row['count'] = 0
        user['userCalendar'] = {'totalActiveDays': 0, 'submissionCalendar': '{}'}
        self.assertTrue(self.refresh(data)['verified'])
        self.assertIn('Problems_Solved-0-', self.readme.read_text())
        self.assertIn('Current_Streak-0_Days-', self.readme.read_text())

    def test_year_boundary_uses_previous_calendar(self):
        now = datetime(2026, 1, 2, tzinfo=timezone.utc)
        data = payload()
        user = data['data']['matchedUser']
        def encode(dates):
            return json.dumps({str(int(d.timestamp())): 1 for d in dates})
        user['userCalendar'] = {'totalActiveDays': 1, 'submissionCalendar': encode([now - timedelta(days=1)])}
        user['previousCalendar'] = {'submissionCalendar': encode([now - timedelta(days=2), now - timedelta(days=3)])}
        stats = profile.parse_profile(data, USERNAME, now)
        self.assertEqual(stats['current_streak'], 3)
        self.assertEqual(stats['active_days'], 1)

    def test_broken_streak_becomes_zero(self):
        stats = profile.parse_profile(payload(), USERNAME, NOW + timedelta(days=2))
        self.assertEqual(stats['current_streak'], 0)

    def test_leethub_push_and_repeated_problem_keep_single_tracker_entry(self):
        p = self.root / '0001-two-sum' / 'solution.cpp'
        p.parent.mkdir()
        p.write_text('int twoSum() { return 1; }')
        organize.scan_and_reorganize(self.root)
        organize.update_tracking(self.root)
        self.refresh()
        data = organize.load_neetcode_data(self.root / 'neetcode150.json')
        scan = organize.scan_repository(self.root, data)
        self.assertEqual(len(scan.solutions), 1)
        before = self.readme.read_bytes()
        organize.scan_and_reorganize(self.root)
        organize.update_tracking(self.root)
        self.assertFalse(self.refresh()['changed'])
        self.assertEqual(before, self.readme.read_bytes())
        self.assertEqual(self.readme.read_text().count('| [LeetCode #1]'), 1)

    def test_schedule_and_manual_share_same_complete_pipeline(self):
        workflow = (ROOT / '.github/workflows/organize.yml').read_text()
        self.assertIn('  schedule:', workflow)
        self.assertIn('  workflow_dispatch:', workflow)
        self.assertIn('  push:', workflow)
        self.assertIn('run: python3 organize.py', workflow)
        self.assertIn('contents: write', workflow)
        self.assertNotIn("github.actor != 'github-actions[bot]'", workflow)
        self.assertNotIn('git diff > changes.patch', workflow)

    def test_main_entrypoint_refreshes_and_writes_actions_summary(self):
        summary = self.root / 'summary.txt'
        real_refresh = profile.refresh_dashboard
        with patch.object(organize, 'BASE_DIR', str(self.root)), \
                patch('sys.argv', ['organize.py']), \
                patch.dict(os.environ, {'GITHUB_STEP_SUMMARY': str(summary)}), \
                patch.object(profile, 'urlopen', return_value=response(payload())), \
                patch.object(profile, 'refresh_dashboard', side_effect=lambda root: real_refresh(root, now=NOW)) as refresh:
            self.assertEqual(organize.main(), 0)
        refresh.assert_called_once()
        self.assertIn('Problems_Solved-257-', self.readme.read_text())
        self.assertIn('Live profile verified: True', summary.read_text())

    def test_offline_entrypoint_never_requests_profile(self):
        with patch.object(organize, 'BASE_DIR', str(self.root)), \
                patch('sys.argv', ['organize.py', '--offline']), \
                patch.object(profile, 'urlopen', side_effect=AssertionError('Network forbidden')):
            self.assertEqual(organize.main(), 0)
        self.assertIn('Problems_Solved-256-', self.readme.read_text())


class HTTPIntegrationTests(unittest.TestCase):
    """Run the real HTTP client when the environment permits loopback servers."""
    setUp = ProfileTests.setUp
    @classmethod
    def setUpClass(cls):
        class Handler(BaseHTTPRequestHandler):
            def do_POST(self):
                cls.received.append(json.loads(self.rfile.read(int(self.headers['Content-Length']))))
                self.send_response(cls.status)
                self.send_header('Content-Type', 'application/json')
                self.end_headers()
                self.wfile.write(json.dumps(cls.body).encode())
            def log_message(self, *args):
                pass
        try:
            cls.server = ThreadingHTTPServer(('127.0.0.1', 0), Handler)
        except PermissionError as exc:
            raise unittest.SkipTest(f'Loopback server blocked by environment: {exc}')
        cls.thread = threading.Thread(target=cls.server.serve_forever, daemon=True)
        cls.thread.start()

    @classmethod
    def tearDownClass(cls):
        cls.server.shutdown()
        cls.server.server_close()
        cls.thread.join()

    def test_http_success_and_failure(self):
        cls = type(self)
        cls.status, cls.body, cls.received = 200, payload(), []
        endpoint = f'http://127.0.0.1:{self.server.server_port}/graphql/'
        self.assertTrue(profile.refresh_dashboard(self.root, endpoint=endpoint, now=NOW)['verified'])
        before = self.readme.read_bytes()
        cls.status = 500
        self.assertFalse(profile.refresh_dashboard(self.root, endpoint=endpoint, now=NOW)['verified'])
        self.assertEqual(before, self.readme.read_bytes())
        self.assertEqual(len(cls.received), 2)


if __name__ == '__main__':
    unittest.main()
