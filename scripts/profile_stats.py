"""Refresh only the profile dashboard; repository inventories stay independent.

The public calendar measures submission activity, not accepted-only solves or
Daily Challenge completion. Never interpret its longest streak as current.
"""
from __future__ import annotations

from datetime import datetime, timedelta, timezone
import json
import os
from pathlib import Path
import re
import socket
import sys
import time
from urllib.error import HTTPError, URLError
from urllib.request import Request, urlopen

ENDPOINT = 'https://leetcode.com/graphql/'
QUERY = '''query Dashboard($username: String!, $year: Int!, $previousYear: Int!) {
  matchedUser(username: $username) {
    username
    submitStatsGlobal { acSubmissionNum { difficulty count } }
    userCalendar(year: $year) { totalActiveDays submissionCalendar }
    previousCalendar: userCalendar(year: $previousYear) { submissionCalendar }
  }
}'''


class StatsError(ValueError):
    """Unverified data must not replace the dashboard."""


def count(value, name):
    if type(value) is not int or value < 0:
        raise StatsError(f'{name} must be a nonnegative integer')
    return value


def calendar_days(calendar, year, today):
    if not isinstance(calendar, dict):
        raise StatsError('Missing submission calendar')
    encoded = calendar.get('submissionCalendar')
    if not isinstance(encoded, str):
        raise StatsError('submissionCalendar must be a JSON string')
    entries = json.loads(encoded)
    if not isinstance(entries, dict):
        raise StatsError('Invalid submission calendar')
    days = set()
    for timestamp, submissions in entries.items():
        if not isinstance(timestamp, str) or not re.fullmatch(r'\d+', timestamp):
            raise StatsError('Invalid calendar timestamp')
        day = datetime.fromtimestamp(int(timestamp), timezone.utc).date()
        if day.year != year or day > today:
            raise StatsError('Calendar date outside requested year or in the future')
        if count(submissions, 'submission count'):
            days.add(day)
    return days


def parse_profile(payload, username, now):
    if not isinstance(payload, dict) or payload.get('errors'):
        raise StatsError('GraphQL returned errors or an invalid response')
    user = payload['data']['matchedUser']
    if not isinstance(user, dict) or user.get('username', '').casefold() != username.casefold():
        raise StatsError('Profile missing or username mismatch')
    rows = user['submitStatsGlobal']['acSubmissionNum']
    counts = {}
    for row in rows:
        name = row['difficulty']
        if name in counts or name not in {'All', 'Easy', 'Medium', 'Hard'}:
            raise StatsError('Duplicate or unexpected difficulty')
        counts[name] = count(row['count'], name)
    if set(counts) != {'All', 'Easy', 'Medium', 'Hard'}:
        raise StatsError('Missing difficulty counts')
    if sum(counts[k] for k in ('Easy', 'Medium', 'Hard')) != counts['All']:
        raise StatsError('Difficulty counts do not sum to total solved')

    today = now.astimezone(timezone.utc).date()
    current = calendar_days(user['userCalendar'], today.year, today)
    previous = calendar_days(user['previousCalendar'], today.year - 1, today)
    active = count(user['userCalendar']['totalActiveDays'], 'totalActiveDays')
    if active != len(current):
        raise StatsError('Active-day total disagrees with the requested annual calendar')
    days = current | previous
    day = today if today in days else today - timedelta(days=1)
    streak = 0
    while day in days:
        streak += 1
        day -= timedelta(days=1)
    # A run reaching the start of both returned years is truncated, not exact.
    if day.year < today.year - 1:
        raise StatsError('Current streak exceeds available calendar coverage')
    return {
        'username': username, 'calendar_year': today.year,
        'easy': counts['Easy'], 'medium': counts['Medium'], 'hard': counts['Hard'],
        'solved': counts['All'], 'current_streak': streak, 'active_days': active,
        'streak_basis': 'consecutive public submission-calendar days (UTC)',
        'active_days_basis': 'LeetCode totalActiveDays for the current UTC year',
    }


def fetch_profile(username, now, endpoint=ENDPOINT, timeout=10):
    body = json.dumps({'query': QUERY, 'variables': {
        'username': username, 'year': now.year, 'previousYear': now.year - 1,
    }}).encode('utf-8')
    request = Request(endpoint, data=body, headers={
        'Content-Type': 'application/json',
        'User-Agent': 'LeetCode-Questions-dashboard/1.0',
    })
    for attempt in range(2):
        try:
            with urlopen(request, timeout=timeout) as response:
                raw = response.read(2_000_001)
                if len(raw) > 2_000_000:
                    raise StatsError('Profile response exceeds size limit')
                payload = json.loads(raw.decode('utf-8'))
            return parse_profile(payload, username, now)
        except HTTPError as exc:
            if attempt == 0 and exc.code in {429, 502, 503, 504}:
                retry_after = exc.headers.get('Retry-After', '1') if exc.headers else '1'
                time.sleep(min(5, int(retry_after)) if retry_after.isdigit() else 1)
                continue
            raise StatsError(f'LeetCode HTTP {exc.code}') from exc
        except (URLError, TimeoutError, socket.timeout) as exc:
            raise StatsError(f'LeetCode connection failed ({type(exc).__name__})') from exc


def render_dashboard(readme, stats):
    heading = '## 📊 Progress Dashboard'
    if readme.count(heading) != 1:
        raise StatsError('Missing or duplicate Progress Dashboard heading')
    start = readme.index(heading)
    following = re.search(r'^## ', readme[start + len(heading):], re.M)
    end = start + len(heading) + following.start() if following else len(readme)
    block = readme[start:end]

    def replace(pattern, replacement):
        nonlocal block
        block, matches = re.subn(pattern, replacement, block, flags=re.M)
        if matches != 1:
            raise StatsError('Dashboard shape changed; refusing a partial update')

    for badge, value, suffix in (
        ('Current_Streak', stats['current_streak'], '_Days'),
        ('Active_Days', stats['active_days'], '_Days'),
        ('Problems_Solved', stats['solved'], ''),
    ):
        replace(r'(' + re.escape('/badge/' + badge + '-') + r')\d+' + suffix,
                lambda m, v=value, s=suffix: m[1] + str(v) + s)
    for label in ('Easy', 'Medium', 'Hard'):
        value = stats[label.lower()]
        percent = f'{value / stats["solved"] * 100:.1f}%' if stats['solved'] else '0.0%'
        replace(r'^(\| [^|\n]*\*\*' + label + r'\*\* \| )[^|\n]*(\| )[^|\n]*(\|)$',
                lambda m, v=value, p=percent: f'{m[1]}{v} {m[2]}{p} {m[3]}')
    for label, value in (
        ('Total Solved', str(stats['solved'])),
        ('Current Streak', f'{stats["current_streak"]} Days'),
        ('Total Active Days', f'{stats["active_days"]} Days'),
    ):
        replace(r'^(\| [^|\n]*\*\*' + label + r'\*\* \| )\*\*[^*\n]+\*\*',
                lambda m, v=value: f'{m[1]}**{v}**')
    return readme[:start] + block + readme[end:]


def refresh_dashboard(root, username=None, endpoint=None, now=None):
    """Validate one complete profile snapshot before writing any dashboard data.

    Returns a result for CLI/Actions summaries. Source failures leave README and
    the last verified snapshot untouched. Identical values do not rewrite files.
    """
    root = Path(root)
    now = (now or datetime.now(timezone.utc)).astimezone(timezone.utc)
    username = username or os.environ.get('LEETCODE_USERNAME', 'calligraphyguruji')
    endpoint = endpoint or os.environ.get('LEETCODE_GRAPHQL_URL', ENDPOINT)
    try:
        stats = fetch_profile(username, now, endpoint)
        path = root / 'README.md'
        original = path.read_bytes().decode('utf-8')
        updated = render_dashboard(original, stats)
        cache_path = root / 'leetcode-profile.json'
        try:
            cached = json.loads(cache_path.read_text()) if cache_path.exists() else {}
        except (OSError, ValueError):
            # A damaged local snapshot cannot invalidate a fresh valid response.
            cached = {}
        if not isinstance(cached, dict):
            cached = {}
        if cached.get('stats') != stats:
            snapshot = {'source': endpoint, 'last_verified_at': now.isoformat(), 'stats': stats}
            # Atomic replacement prevents a truncated snapshot on interruption.
            temp = cache_path.with_suffix('.json.tmp')
            temp.write_text(json.dumps(snapshot, indent=2) + '\n', encoding='utf-8')
            temp.replace(cache_path)
        if updated != original:
            temp = path.with_suffix('.md.tmp')
            temp.write_bytes(updated.encode('utf-8'))
            temp.replace(path)
        message = (f'LeetCode profile: {stats["solved"]} solved '
                   f'({stats["easy"]} Easy, {stats["medium"]} Medium, {stats["hard"]} Hard); '
                   f'current submission-activity streak {stats["current_streak"]} days (UTC); '
                   f'{stats["active_days"]} active days in {stats["calendar_year"]}.')
        print(message)
        return {'verified': True, 'changed': updated != original, 'message': message}
    except (StatsError, OSError, ValueError, KeyError, TypeError, AttributeError, OverflowError) as exc:
        # Do not print response bodies or request headers: they may contain data
        # unrelated to the public dashboard. No credentials are required.
        message = f'Profile refresh unavailable ({type(exc).__name__}): {exc}. Dashboard and verified snapshot preserved.'
        print(f'[Warning] {message}', file=sys.stderr)
        return {'verified': False, 'changed': False, 'message': message}
