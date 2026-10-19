# Maintaining the NeetCode 150 tracker

Run from the repository root:

```sh
python3 organize.py
python3 organize.py --offline  # file inventories only; no profile fetch
python3 -m unittest discover -s tests -v
```

Python 3.9+ and its standard library are sufficient. GitHub Actions uses Python
3.11. Both `python3 organize.py` and the original `python3 scripts/organize.py`
entry points run the same implementation in `scripts/organize.py`.

## What is generated

The script updates the README block between `<!-- NEETCODE150:START -->` and
`<!-- NEETCODE150:END -->`, and the table under the existing **Complete Problem
Index** heading. The latter includes non-NeetCode problems. Other README prose,
curated pattern directories, topic breakdowns, `stats.json`, problem statements
and solution code are preserved. The Progress Dashboard is refreshed separately
from the public LeetCode profile; see [profile synchronization](profile-dashboard.md).
Other curated sections are not regenerated. The maintained
Complete Problem Index and NeetCode tracker are the current file-based inventories.

Existing folder-moving/merging logic handles new LeetHub problem folders before
the index is refreshed. Existing topic folders are retained for repeat submissions.
The legacy full-template README rebuild is not called: it would overwrite curated
content and mix repository counts with profile statistics.

The profile refresh makes one public GraphQL request in the normal successful
path; --offline disables that request. The organizer can move new root problem
folders using its existing logic. It never commits or pushes locally.
Identical output does not rewrite the README. Malformed/duplicate
tracker markers stop generation before writing anything.

## Identifying solutions

The scan recurses through the repository, excluding infrastructure directories
(`scripts`, `tests`, `.github`, `.git`, virtual environments, dependency/build
folders and hidden folders). It does not follow symlinks. It supports the language
extensions listed in `CODE_EXTENSIONS`, including C++ and Python. Empty and
comment-only files do not count.

Evidence includes numeric filename/folder prefixes, normalized exact titles,
canonical LeetCode URLs in source, explicit `LeetCode 123` or `Problem ID: 123`
comments, labeled title comments, and adjacent problem README headings. Filename
examples: `1-two-sum.cpp`, `Two_Sum.cpp`, `two-sum.cpp`, `0001_Two_Sum.cpp`.
Generic source names such as `solution.cpp` work inside identifiable problem
folders. Explicit `-approach-2` suffixes are supported. Several files identifying
the same problem produce multiple links but count once.

Conflicting signals are printed as `[Review]` and excluded from solved counts;
unidentified files are also printed. Matching is conservative, with no fuzzy
substring/title matching. To resolve a file, use a canonical numeric folder/name
or add an explicit LeetCode URL/ID comment, then rerun. Numeric IDs and known
canonical titles/URLs must agree. Arbitrary bare titles outside the pinned list
need a numeric identifier or existing local metadata. Documentation alone cannot
mark a question solved. Source presence is evidence of a stored solution, not a
claim that the code has been executed or accepted by LeetCode.

Some historical LeetHub README headings use LeetCode internal database IDs rather
than public problem numbers. When the numeric folder and canonical URL agree,
the folder number wins; the script reports how many such headings it resolved.
The initial audit found 104 such problem headings (for example, the README for
public problem 876 says 908). No source or problem README is edited to fix these.

## Verified roadmap snapshot

`neetcode150.json` is an explicitly pinned snapshot verified on **2026-10-18**.
It includes precisely 150 questions, 18 topics, global sequence numbers, exact
NeetCode display titles, official difficulty, public LeetCode IDs, canonical
LeetCode titles and LeetCode URLs. Display-title capitalization/punctuation can
differ from LeetCode; both titles are stored to avoid silently changing either.

Primary sources:

- [Official roadmap](https://neetcode.io/roadmap)
- [Official practice page](https://neetcode.io/practice)
- [LeetCode problem catalog](https://leetcode.com/api/problems/all/)

The pages are JavaScript applications; text-only browser extraction returned a
shell. Verification therefore examined the JavaScript bundles deployed by the
actual official site, rather than adopting a third-party list:

1. Read the roadmap HTML's `main.*.js` and `runtime.*.js` asset URLs.
2. Extract only question objects explicitly flagged `neetcode150:!0` from the
   main bundle. Exactly 150 were present; `blind75` and `neetcode250` flags were
   not used for membership.
3. Read the official `A4`/`PATTERN_LIST` topic array and shared
   `initAllLists` implementation. That implementation groups questions in source
   order, iterates the topic array, and filters each group by `neetcode150`.
4. Inspect the roadmap and practice route bundles: the roadmap is a dependency
   graph, with no unique linear traversal; the practice view supplies the linear
   topic order used here. Both use the shared question list.
5. Cross-check all 150 slugs, public `frontend_question_id` values and difficulty
   levels against the LeetCode catalog. Preserve NeetCode titles and store the
   corresponding canonical LeetCode titles separately. All IDs and difficulties
   agreed.

The snapshot intentionally differs from older lists: Binary Search and Linked
List precede Stack, Backtracking precedes Heap / Priority Queue, and Bit
Manipulation precedes Math & Geometry. Generate Parentheses is in Backtracking,
so Stack contains six questions and Backtracking contains ten. This reflects the
verified current site, not the illustrative ordering in older guides.

The dataset records source URLs and SHA-256 hashes of the five inspected source
responses. Asset filenames can change after deployments; hashes identify this
verification's evidence, not permanent asset availability. Refresh is manual and
explicit: repeat the extraction and cross-checks, review any membership/order
changes, update the provenance and verification date, run the tests and regenerate
the README. Normal runs never refresh roadmap data or hardcode solved status.

## GitHub Actions

The existing `.github/workflows/organize.yml` is the only workflow. It runs for
supported solution extensions, problem/primary README changes, the dataset, and
its own configuration and LeetHub stats.json updates. A six-hour schedule refreshes
profile changes even without a push. It also supports **Actions → Update LeetCode Progress →
Run workflow**. The write job runs only on the repository's configured default
branch, so branch renames require no hardcoded `main` update. Manual runs must
select that default branch.

The job checks out the latest branch, sets up Python, runs the offline tests,
generates the README, and commits generated changes (including organized folders
and the verified profile snapshot) only when something changed. Per-branch
concurrency queues runs. Generated commits include
`[skip ci]`, and commits made with `GITHUB_TOKEN` do not start recursive push
workflows. No third-party service or additional secret is needed.

Only the generator job requests `contents: write`; other workflow permissions are
read-only. Repository/organization settings must allow GitHub Actions and honor
this token's write request. Branch protection/rulesets still apply: if they block
direct bot pushes, permit this workflow through your chosen ruleset or apply the
generated patch through your normal reviewed PR process. The workflow does not
bypass protection or request PR/admin permissions.

A rejected push (protection, token policy or a concurrent branch update) fails
visibly and uploads `leetcode-update.patch` as an artifact. The patch is created
outside the checkout so it cannot accidentally be staged and committed. No force push or rebase
is used. Resolve the policy or rerun on the latest branch for a race. There is no
claim that remote permissions are enabled until an actual GitHub run succeeds.

## Initial local verification

The repository contained 259 C++ files and one Java solution, identifying 251
unique LeetCode problems. NeetCode progress was 74/150 (49.3%), with 76 remaining.
All 260 original solution files were checked against pre-change SHA-256 hashes.
No current solution had an unresolved identity; the 104 historical heading-ID
discrepancies were resolved using canonical URL and folder evidence.

Tests use temporary directories outside the repository and cover additions,
non-NeetCode problems, duplicates, filename formats, conflicting evidence,
comment-only placeholders, offline operation, URL encoding, marker errors,
README preservation and idempotency. They do not run or judge the algorithms.

Final verification passed **21 unittest cases**, including all six requested
scenarios. Two consecutive generator runs made no further changes. An independent
folder-number audit agreed with the scanner's 251 unique problems and 74 roadmap
matches. All 150 dataset rows were compared again with the downloaded primary
sources, including topic/question order; all generated tracker solution links
resolved locally. Every original README section outside the regenerated index
was checked for exact preservation.

Workflow verification parsed the YAML, checked push/manual triggers, default
branch and bot guards, permission scope, concurrency, README-only staging and
failure-artifact handling, and ran `bash -n` on every shell step. `git diff --check`
passed. This is local configuration validation, not a remote workflow execution.
CodeRabbit CLI 0.7.6 was present but signed out, so no CodeRabbit review was run;
source and diff review were performed locally. No commits or pushes were made.

Before publication, remote commits through `a9518fb` were integrated and the
README regenerated from that latest content. The combined audit found **265
solution files, 256 unique problems and 75/150 NeetCode questions solved (50.0%)**,
with 75 remaining and no unresolved matches. All 265 remote solution files were
verified unchanged, and all 21 tests passed again after integration. Earlier
counts in this document describe the initial local snapshot.
