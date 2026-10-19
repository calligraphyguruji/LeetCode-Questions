# Profile dashboard synchronization

Run `python3 organize.py` to organize incoming LeetHub folders, refresh the
repository index and NeetCode tracker, then refresh the profile dashboard.
Both original Python entry points remain supported. Python 3.9+ standard-library
modules are sufficient; no requirements.txt or credentials are needed.

`python3 organize.py --offline` skips the profile request. It still runs the
existing repository organizer; it is not a promise to skip legacy topic lookups
for previously unknown root problem folders.

## Data definitions

The dashboard represents the public LeetCode profile, not the repository inventory.
Repository and NeetCode counts continue to come exclusively from stored solutions.

| Dashboard metric | Source and meaning |
|---|---|
| Solved and Easy/Medium/Hard | `matchedUser.submitStatsGlobal.acSubmissionNum`: distinct accepted problems, not submission attempts. The three difficulties must sum to All. |
| Current Streak | Consecutive positive-activity dates in public `userCalendar.submissionCalendar`, using UTC day boundaries. It ends today, or yesterday if there is no activity yet today. A gap before yesterday makes it zero. |
| Total Active Days | `userCalendar(year: current UTC year).totalActiveDays`, checked against the number of positive-activity dates in that annual calendar. This is the profile's annual activity statistic, not lifetime GitHub contributions. |

The public calendar does not identify acceptance status or Daily Challenge
completion. **Its activity streak is not an accepted-only solving streak or a
Daily Challenge streak.** The API calendar's longest-streak field is deliberately
not used as a current streak. This implementation makes no claim that the
profile's separately displayed flame counter has been verified to equal this
calendar-derived activity streak. In particular, the user's reported 95 was not
used as proof or hardcoded into the production script.

Two annual calendars are retrieved in the same request to cover a streak crossing
January 1. A streak exhausting both calendars is rejected as incomplete evidence,
rather than silently truncated. An exact longer streak would require more years.
Calendar dates beyond the requested year or current day are rejected. Timezone
handling is explicit UTC; operating-system local time and Git commit dates are
never used as activity evidence.

## Updates and safe fallback

`scripts/profile_stats.py` is a focused helper called by the existing entry point,
not a second workflow or a replacement README generator. It validates one complete
GraphQL response before replacing any dashboard values. Badge numbers, table
counts, and percentages are changed together inside the existing dashboard
section. Other sections and layout are untouched. Missing or duplicate dashboard
elements cause the refresh to be rejected.

`LEETCODE_USERNAME` defaults to `calligraphyguruji`. `LEETCODE_GRAPHQL_URL` defaults
to `https://leetcode.com/graphql/` and can point to a local simulator for tests.
There are no arbitrary cache-busting query parameters. The only bounded retry is
for HTTP 429/502/503/504, with at most five seconds of backoff. Connections have a
ten-second timeout. GraphQL errors, non-JSON content, username mismatches, missing
fields, and inconsistent totals preserve all dashboard values instead of inserting
zeros or publishing partial results. Genuine verified zero values are accepted.

The last successful changed snapshot is written to `leetcode-profile.json`, with
source, metric definitions, calendar year, and verification timestamp. Identical
values do not rewrite either README or snapshot. The timestamp represents the last
verification at which values changed, not every polling attempt. Before the first
successful fetch no verified snapshot is created. Legacy README values are
preserved without pretending they were newly verified. LeetHub's `stats.json`
and its hashes remain owned by LeetHub; they are never overwritten by the profile
pipeline or treated as a fallback authority for public profile counts.

## Workflow behavior

The single existing `Update LeetCode Progress` workflow handles matching pushes,
manual runs, and `17 0,6,12,18 * * *` (UTC). GitHub scheduling can be delayed, so
profile-only changes are eventually polled rather than updated instantly.
Pushes from extensions that match the solution paths trigger the same complete
pipeline. A profile change with no push is picked up by a later scheduled run.
Manual runs execute that same pipeline and write an Actions job summary.

The job runs only on the repository's configured default branch, requests
`contents: write`, queues concurrent runs, and checks out the latest target branch.
It stages changes after generation, commits only if staged content changed, and
never force-pushes. Generated commits contain `[skip ci]`; default GITHUB_TOKEN
pushes do not trigger recursive push workflows. No workflow chaining is required.
A bot actor can still start a manual/scheduled run; excluding all bot actors would
accidentally disable some schedules. A rejected push fails visibly and uploads a
patch from RUNNER_TEMP. Rerun on the latest branch after a concurrent push or
resolve branch protections through normal repository policy.

An unavailable source emits a warning and a summary saying live verification
failed. Repository inventory generation can still finish. No change is committed
when the source fails and the repository inventories are unchanged.

## Audit evidence and verification limits

Audit baseline: commit `8a9c060` on main. Root `organize.py` delegates to
`scripts.organize.main`, which called `scan_and_reorganize` and `update_tracking`.
The latter rendered only the Complete Problem Index and marked NeetCode tracker.
The old `rebuild_metadata` function contained the dashboard code and
`fetch_user_streak` call, but main never invoked it. README still contained literal
badge/table values 256 solved, 94 streak, and 208 active days. LeetHub stats.json
contained those same values. The existing workflow had push/manual triggers but
no schedule. Thus even successful runs could not refresh the profile dashboard.

Local Git history includes LeetHub pushes `3a5b42a`, `4836d5f`, and `c5361c1` on
2026-10-19, and bot-generated README commits. This establishes that solutions
reached this checkout; it does not establish the outcome of any particular remote
Actions run. The previous workflow also wrote changes.patch into its checkout
before git add -A, risking committing that artifact; this is now fixed.

The graph index was dated 2026-09-17 and flagged automation files as changed or
untracked. Audit conclusions therefore used current source, not its stale call
graph. Full solution preservation was checked against 266 tracked source hashes.

Live LeetCode profile GraphQL verification succeeded against `calligraphyguruji`.
The reported values were confirmed from the live API: 257 total solved (81 Easy,
152 Medium, 24 Hard), 95-day submission activity streak (UTC), and 209 active days
in 2026. The README progress dashboard and `leetcode-profile.json` snapshot were
updated with verified values.

The automated tests use synthetic GraphQL contracts, including 256 to 257 and
94 to 95 changes, idempotency, API errors, inconsistent data, year boundaries,
README preservation, and the actual entry point. The real loopback HTTP test is
skipped if the runtime denies server binding; on GitHub-hosted runners it can
exercise urllib end to end. These fixtures test the client contract and fallback
behavior; they do not prove live upstream access.

Final local checks: **48 unittest cases passed**, with the separate loopback HTTP
suite skipped because server binding was denied. Workflow YAML was parsed using
Ruby's YAML parser; push/schedule/manual triggers, job permissions, and every
shell step's bash syntax were checked. Two normal organizer runs and the direct
scripts/organize.py --offline entry point preserved the real README byte for byte.
git diff --check passed. CodeRabbit CLI was installed but signed out, so its
remote review was unavailable and the final source/diff review was manual.
An attempted temporary Postman simulation also failed to bind with EPERM; no
end-to-end HTTP simulation success is claimed. Its temporary files were outside
the repository and are not production dependencies.
