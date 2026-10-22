# Maintaining visual LeetCode solutions

Add solution images to `LeetCode-Img-Soln/`, preferably named
`36-valid-sudoku-part-I.jpg`, `36-valid-sudoku-part-II.jpg`, etc.
Commit the newly added source images. The existing GitHub Actions workflow runs
`python3 organize.py`, organizes incoming solutions first, then attaches verified
images to existing problem folders and updates their READMEs.

Local commands (Python 3.9+; no dependencies):

```sh
python3 -m scripts.visual_solutions --dry-run
python3 -m scripts.visual_solutions
python3 organize.py --offline
python3 -m unittest discover -s tests -v
```

`--offline` skips the existing profile refresh; image matching is always offline.
The standalone image command leaves the root progress dashboard and classifications
alone. `--report /tmp/visual-audit.json` optionally saves its detailed JSON result.

The exact LeetCode number takes priority, and the title must also be verified.
Case, punctuation, separators, and common abbreviations (`BT`, `BST`, `min`, `max`,
`BFS`, `DFS`) are normalized. Unnumbered files require a unique exact or reviewed
title match. `01 Matrix` is a title for #542, not an ID for #1. Only an explicit
`Part-I`/`Part_II`/`Part-3` suffix denotes page order; `House Robber-II` remains a
problem-series title. Missing part numbers are retained rather than renumbered.

Shortened or misspelled titles that cannot match exactly require a deliberate
entry in `docs/visual-title-aliases.json`. Each reviewed alias pins both an ID and
canonical LeetCode URL slug; confirm against the problem README, source metadata,
and image contents when ambiguous. Never add an alias just to silence a conflict.
The exception `filename:113-Path-Sum-Part-II.jpg` is restricted to that exact
visually reviewed filename: the page explicitly says #113 / Path Sum II.
A differently named #113 image labeled only “Path Sum” stays unresolved.

Other visually reviewed cases in this migration:

- `Next Greater Element.jpeg` explicitly says Q.503 and uses a circular array.
- `Build Array LIS Hard Part-I.jpg` explicitly says #1420 and describes search cost.
- `Coin change part-II.jpg` minimizes coin count (#322), not the number of combinations.
- `Lowest Common Ancestor Part-I.jpg` uses the #236 non-BST example.
- `Flatten BST to LinkedList` uses preorder flattening and the #114 example and
  algorithm, despite its handwritten BST wording; both pages were inspected.
- `IMG_20260619_123722.jpg` contains general Prim/MST notes and has no verified
  unique LeetCode identity, so it remains unmatched.

`docs/visual-solutions.json` records every integrated source path, problem ID,
canonical slug, source SHA-256, explicit part, and destination. Keep this manifest
versioned. Published copies can be verified and READMEs restored even when
original matched source images are absent from a checkout. Original files are
never automatically deleted. The initial migration retains all originals locally;
only the 23 unresolved solution images are versioned in the source folder, so they
can be retried when a matching question is solved. Verified originals are not
stored twice in Git. Unrelated source files are left untracked and untouched.

Matching never creates a problem folder or reclassifies a question. Files with
unknown/conflicting identities, absent folders, duplicate candidate folders, or
unmanaged existing visual sections are reported for review. Unsupported source
files are ignored. New pending images are retried on each organizer execution.

The managed README section uses `visual-solutions:start/end` HTML comments.
All preceding problem content remains byte-for-byte intact. Each image is embedded
with a GitHub-compatible relative Markdown link; URLs are escaped when necessary.
Do not put additional handwritten notes inside the managed section, since it is
regenerated. Malformed markers or conflicting managed sections stop processing.

Source and destination hashes must agree. Identical image content within one
problem is reused and linked once. Conflicting filenames receive a deterministic
hash suffix; existing files are never silently overwritten. Changed previously
integrated source files or corrupted destination files stop automation for review.
Keep both copies and explicitly reconcile the manifest after verifying a deliberate
replacement; do not delete the manifest to bypass verification.

Resubmitted LeetHub descriptions retain the existing visual section. Nested
problem cleanup preserves image subdirectories. Incoming image conflicts or
incompatible visual sections stop merging while preserving both folders.
The organizer excludes the source-image folder from topic discovery, and topic
overrides operate only on directories.

The single existing workflow watches source images, destination images, and visual
JSON metadata as well as solution submissions. Its permissions, default-branch
restriction, concurrency, guarded commits, `[skip ci]` message, and ordinary
non-force push behavior are preserved. Unmatched images appear as `[Image review]`
lines in the organizer log; resolve their identity instead of attaching them by
similarity. Local YAML/configuration validation does not substitute for a live
GitHub Actions run or rendered GitHub verification.
