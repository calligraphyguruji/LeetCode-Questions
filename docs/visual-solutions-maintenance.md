# Maintaining visual LeetCode solutions

Add solution images to `LeetCode-Img-Soln/`, preferably named
`36-valid-sudoku-part-I.jpg`, `36-valid-sudoku-part-II.jpg`, etc.
Commit the newly added source images. The existing GitHub Actions workflow runs
`python3 organize.py`, organizes incoming solutions first, then attaches verified
images to existing problem folders and updates their READMEs with images followed
by the complete original C++ code and a link to each source file. All `.cpp` files
remain separate and are never edited by the README generator. Explicit approach
and time/space complexity labels in code comments are quoted verbatim; absent
metadata is omitted. Multiple C++ implementations are shown separately, with the
primary filename first. Problem #3 currently has only Java, so its original
Java code and link are displayed with Java syntax highlighting. GitHub renders the README when a problem folder is opened.

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
versioned. Published copies can be verified and README blocks regenerated even when
original matched source images are absent from a checkout. Original files are
never automatically deleted. The initial migration retains all originals locally;
only the 13 unresolved solution images are versioned in the source folder, so they
can be retried when a matching question is solved. Verified originals are not
stored twice in Git. Unrelated source files are left untracked and untouched.

The test suite checks every committed manifest entry against the current problem
identity, destination hash, README image links and multipart ordering. It also
checks original source hashes when those files are available locally. The audit
currently verifies 261 images across 150 problems; see
[`visual-solution-audit.md`](visual-solution-audit.md) for the complete mapping and
15 unmatched images (13 solution/algorithm pages and two unrelated images).

Matching never creates a problem folder or reclassifies a question. Files with
unknown/conflicting identities, absent folders, duplicate candidate folders, or
unmanaged existing visual sections are reported for review. Unsupported source
files are ignored. New pending images are retried on each organizer execution.

The managed README section uses these exact HTML comments:

```html
<!-- AUTO-GENERATED-SOLUTION-START -->
<!-- AUTO-GENERATED-SOLUTION-END -->
```

Existing `visual-solutions:start/end` blocks are migrated in place on the first
run. Every byte outside the block stays intact, including problem statements,
examples, constraints, and manual notes after the block. Subsequent runs replace
only the block. The complete C++ content is read without newline normalization; a
Markdown delimiter newline is added when the source has no final newline. A fence
longer than any backticks in the source prevents comments from breaking rendering. Each image is embedded
with a GitHub-compatible relative Markdown link; URLs are escaped when necessary.
Do not put additional handwritten notes inside the managed section, since it is
regenerated. Malformed markers or conflicting managed sections stop processing.

The published `problem/images/` directory is authoritative after import. You may
also add images directly to a verified problem folder's `images/` directory;
placement explicitly identifies that problem. Name multipart pages
`solution-part-1.jpg`, `solution-part-2.jpg`, etc. Images in other problem folders
are never borrowed. Removing a published image removes its generated reference
on the next run. For imported images, `removed_sources` in the manifest prevents
leftover inbox originals from silently restoring a deleted page. To reimport one,
remove its source path from that list deliberately, or restore the published image.
Deleting an inbox original alone does not unpublish an existing destination image;
most historical originals are not tracked in Git. If all images are removed, the
existing managed block retains current C++ links/code but no visual heading.
A problem that never had images keeps its README unchanged.

Source and destination hashes must agree. Identical image content within one
problem is reused and linked once. Conflicting filenames receive a deterministic
hash suffix; existing files are never silently overwritten. Changed previously
integrated source files or corrupted destination files stop automation for review.
Keep both copies and explicitly reconcile the manifest after verifying a deliberate
replacement; do not delete the manifest to bypass verification.

Every organizer run rereads the current C++ files, so changed implementations
refresh embedded code automatically. Resubmitted LeetHub descriptions retain the
existing managed section until it is regenerated from the merged source files. Nested
problem cleanup preserves image subdirectories. Incoming image conflicts or
incompatible visual sections stop merging while preserving both folders.
The organizer excludes the source-image folder from topic discovery, and topic
overrides operate only on directories.

The single existing workflow watches source images, destination images, and visual
JSON metadata as well as solution submissions. Generation runs before tests so legitimate source updates and image deletions
are synchronized before published-asset assertions. Failed validation prevents
committing. Its permissions, default-branch
restriction, concurrency, guarded commits, `[skip ci]` message, and ordinary
non-force push behavior are preserved. Unmatched images appear as `[Image review]`
lines in the organizer log; resolve their identity instead of attaching them by
similarity. Local YAML/configuration validation does not substitute for a live
GitHub Actions run or rendered GitHub verification.
