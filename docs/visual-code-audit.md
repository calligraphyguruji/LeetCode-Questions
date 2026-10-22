# Visual explanations above source code — implementation audit

Validation date: 2026-10-23. This report covers the combined README viewer change; the earlier image-migration report remains historical.

## Repository audit

- Inspected the root entry point, `scripts/organize.py`, `scripts/visual_solutions.py`, all problem README/source inventories, the visual manifest and reviewed aliases, existing tests, and `.github/workflows/organize.yml`.
- Found 264 stored problem identities, 273 recognized solution files, 272 C++ files, and 265 README.md files including the repository root. The image inbox contains 276 supported images; 261 already have verified published destinations across 150 problems.
- Graph tools were unavailable in this session. Discovery and validation used direct filesystem/source inspection, the existing repository scanner, Git tracked-file inventories, and SHA-256 comparisons.
- LeetHub submits numbered root folders. The existing organizer moves/merges them into topics, preserves managed README content during resubmission, scans identities using folder numbers and canonical problem URLs, then calls the image integrator. The root dashboard/tracker and profile synchronizer remain separate existing responsibilities.
- Existing image matching requires agreement between problem number and verified title/alias. Exact reviewed title matches cover unnumbered filenames. No aliases or problem identities were changed.

## Result

- Updated **150 problem READMEs**, integrating **261 images**, followed by **156 complete C++ implementations** across 149 problems.
- Problem **#3, Longest Substring Without Repeating Characters**, has only Java. Its README displays its complete original Java implementation and source link. No C++ implementation was invented.
- Every one of the **272 original .cpp files remains byte-for-byte unchanged**, verified against pre-change SHA-256 hashes.
- Existing problem content outside each managed block is byte-for-byte unchanged, including examples, constraints and any manual suffix. Other problem READMEs remain unchanged.
- Existing visual blocks migrated in place to `AUTO-GENERATED-SOLUTION-START/END`. Images precede code; explicit comment metadata is quoted rather than inferred. Multiple C++ files have individual links and code blocks.
- Unrelated untracked inbox files and original source images remain untouched and excluded from staging.

## Synchronization and workflow

- `python3 organize.py` invokes the extended existing integrator after organizing submissions. `python3 -m scripts.visual_solutions` refreshes only the visual/code presentation and image manifest.
- Each run reads complete current source bytes as UTF-8 without normalizing line endings. Fences use `cpp` (or `java` for #3), and grow when source comments contain backtick fences. A closing-fence delimiter newline is added for sources without a terminal newline; source content itself is unchanged.
- New verified inbox images are imported and sorted by numeric/roman part. Images added directly under a verified problem’s `images/` directory are included in numeric part order.
- Published problem-local images are authoritative. Deleting one removes its reference; manifest `removed_sources` prevents leftover inbox originals from restoring it. Removing an inbox original alone does not unpublish its existing destination, since historical originals are mostly absent from Git. See maintenance notes for deliberate reimport.
- Removing the last image removes the generated visual heading but keeps existing generated source links/code. Problems that never had images retain their existing READMEs.
- The workflow now generates before testing, so legitimate C++ updates and image deletions are reconciled before published-content assertions. Failed tests prevent committing. Existing path triggers include source code, image additions/removals, READMEs and manifest changes.
- Existing default-branch restriction, concurrency, no-change commit guard, GitHub token behavior, `[skip ci]` commit message, and ordinary non-force pushes remain in place.

## Validation

- **85 tests run: PASS, one pre-existing optional live-network test skipped.**
- Tests cover strict identity matching, #112/#113 separation, ambiguous titles, multipart order, exact code bytes including CRLF/trailing whitespace/missing final newline, delimiter collisions, metadata omission, multiple C++ implementations, Java fallback, marker migration, new images and submissions, code refresh, deleted images, resubmission preservation, and idempotency.
- Real-repository assertions validate manifest identities and SHA-256 hashes, image destinations, ordered references, generated content, source links and complete code.
- Independent pre-change comparison confirms all 150 problem descriptions/outside-marker content and all 272 C++ files are intact. All 261 image references resolve and occur before code.
- Full offline organizer executed repeatedly without further changes. A separate temporary copy containing only tracked files passed the test suite and two full organizer runs; the second run changed neither bytes nor modification times.
- Workflow YAML parsed successfully using Ruby Psych; step structure and generation-before-validation ordering checked. A live Actions execution could not be verified.
- Changed automation, tests, workflow and maintenance documentation pass `git diff --check`. Embedded code retains original trailing whitespace intentionally; repository-wide whitespace warnings on copied code are expected.
- CodeRabbit CLI is installed but signed out, so a CodeRabbit service review could not run. Local source/diff review and regression validation completed.

## Deployment status

Implementation is complete locally. Staging failed because this session grants read-only access to `.git`: Git could not create `.git/index.lock` (`Operation not permitted`). Consequently no commit was created and no changes were pushed. Remote access also failed with `Could not resolve host: github.com`, and the web fetch failed. Remote presentation and live Actions execution remain unverified. A task-scoped publishing helper and a complete patch are available in `/tmp/publish-leetcode-readmes.py` and `/tmp/leetcode-visual-readmes.patch`.

## Unmatched images (15)

These remain unattached. The last two are unrelated images and remain untracked; no contents were inspected or published.

| Filename | Reason |
|:---|:---|
| 3863-Min-Op-to-Sort-String-Part-I.jpg | Unverified abbreviated title for #3863; manual review required |
| 3863-Min-Op-to-Sort-String-Part-II.jpg | Unverified abbreviated title for #3863; manual review required |
| 3942-Min-Op-to-Sort-Nums-Part-I.jpg | Unverified abbreviated title for #3942; manual review required |
| 3942-Min-Op-to-Sort-Nums-Part-II.jpg | Unverified abbreviated title for #3942; manual review required |
| Dijkstra's Algorithm.jpg | No unique exact or reviewed title match; manual review required |
| Heap Sort Part-I.jpg | No unique exact or reviewed title match; manual review required |
| Heap Sort Part-II.jpg | No unique exact or reviewed title match; manual review required |
| IMG_20260619_123722.jpg | No unique exact or reviewed title match; manual review required |
| Merge Sort Part-I.jpg | No unique exact or reviewed title match; manual review required |
| Merge Sort Part-II.jpg | No unique exact or reviewed title match; manual review required |
| Prim's Agorithm Part-II.jpg | No unique exact or reviewed title match; manual review required |
| Prim's Algorithm Part-I.jpg | No unique exact or reviewed title match; manual review required |
| Prim's Algorithm Part-III.jpg | No unique exact or reviewed title match; manual review required |
| Resume Aman.png | No unique exact or reviewed title match; manual review required |
| SessClassDiagram.jpeg | No unique exact or reviewed title match; manual review required |

## Modified problem README files (150)

- [Arrays/0003-longest-substring-without-repeating-characters/README.md](../Arrays/0003-longest-substring-without-repeating-characters/README.md)
- [Arrays/0014-longest-common-prefix/README.md](../Arrays/0014-longest-common-prefix/README.md)
- [Arrays/0036-valid-sudoku/README.md](../Arrays/0036-valid-sudoku/README.md)
- [Arrays/0049-group-anagrams/README.md](../Arrays/0049-group-anagrams/README.md)
- [Arrays/0056-merge-intervals/README.md](../Arrays/0056-merge-intervals/README.md)
- [Arrays/0073-set-matrix-zeroes/README.md](../Arrays/0073-set-matrix-zeroes/README.md)
- [Arrays/0076-minimum-window-substring/README.md](../Arrays/0076-minimum-window-substring/README.md)
- [Arrays/0128-longest-consecutive-sequence/README.md](../Arrays/0128-longest-consecutive-sequence/README.md)
- [Arrays/0167-two-sum-ii-input-array-is-sorted/README.md](../Arrays/0167-two-sum-ii-input-array-is-sorted/README.md)
- [Arrays/0225-implement-stack-using-queues/README.md](../Arrays/0225-implement-stack-using-queues/README.md)
- [Arrays/0239-sliding-window-maximum/README.md](../Arrays/0239-sliding-window-maximum/README.md)
- [Arrays/0242-valid-anagram/README.md](../Arrays/0242-valid-anagram/README.md)
- [Arrays/0387-first-unique-character-in-a-string/README.md](../Arrays/0387-first-unique-character-in-a-string/README.md)
- [Arrays/0493-reverse-pairs/README.md](../Arrays/0493-reverse-pairs/README.md)
- [Arrays/0503-next-greater-element-ii/README.md](../Arrays/0503-next-greater-element-ii/README.md)
- [Arrays/0560-subarray-sum-equals-k/README.md](../Arrays/0560-subarray-sum-equals-k/README.md)
- [Arrays/1392-longest-happy-prefix/README.md](../Arrays/1392-longest-happy-prefix/README.md)
- [Arrays/3551-minimum-swaps-to-sort-by-digit-sum/README.md](../Arrays/3551-minimum-swaps-to-sort-by-digit-sum/README.md)
- [Backtracking/0040-combination-sum-ii/README.md](../Backtracking/0040-combination-sum-ii/README.md)
- [Backtracking/0046-permutations/README.md](../Backtracking/0046-permutations/README.md)
- [Backtracking/0078-subsets/README.md](../Backtracking/0078-subsets/README.md)
- [Backtracking/0079-word-search/README.md](../Backtracking/0079-word-search/README.md)
- [Backtracking/0090-subsets-ii/README.md](../Backtracking/0090-subsets-ii/README.md)
- [Backtracking/0494-target-sum/README.md](../Backtracking/0494-target-sum/README.md)
- [Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/README.md](../Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/README.md)
- [BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/README.md](../BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/README.md)
- [BitManipulation/0371-sum-of-two-integers/README.md](../BitManipulation/0371-sum-of-two-integers/README.md)
- [DynamicProgramming/0005-longest-palindromic-substring/README.md](../DynamicProgramming/0005-longest-palindromic-substring/README.md)
- [DynamicProgramming/0062-unique-paths/README.md](../DynamicProgramming/0062-unique-paths/README.md)
- [DynamicProgramming/0072-edit-distance/README.md](../DynamicProgramming/0072-edit-distance/README.md)
- [DynamicProgramming/0122-best-time-to-buy-and-sell-stock-ii/README.md](../DynamicProgramming/0122-best-time-to-buy-and-sell-stock-ii/README.md)
- [DynamicProgramming/0132-palindrome-partitioning-ii/README.md](../DynamicProgramming/0132-palindrome-partitioning-ii/README.md)
- [DynamicProgramming/0198-house-robber/README.md](../DynamicProgramming/0198-house-robber/README.md)
- [DynamicProgramming/0213-house-robber-ii/README.md](../DynamicProgramming/0213-house-robber-ii/README.md)
- [DynamicProgramming/0279-perfect-squares/README.md](../DynamicProgramming/0279-perfect-squares/README.md)
- [DynamicProgramming/0300-longest-increasing-subsequence/README.md](../DynamicProgramming/0300-longest-increasing-subsequence/README.md)
- [DynamicProgramming/0322-coin-change/README.md](../DynamicProgramming/0322-coin-change/README.md)
- [DynamicProgramming/0368-largest-divisible-subset/README.md](../DynamicProgramming/0368-largest-divisible-subset/README.md)
- [DynamicProgramming/0516-longest-palindromic-subsequence/README.md](../DynamicProgramming/0516-longest-palindromic-subsequence/README.md)
- [DynamicProgramming/1048-longest-string-chain/README.md](../DynamicProgramming/1048-longest-string-chain/README.md)
- [DynamicProgramming/1092-shortest-common-supersequence/README.md](../DynamicProgramming/1092-shortest-common-supersequence/README.md)
- [DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/README.md](../DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/README.md)
- [DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/README.md](../DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/README.md)
- [DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/README.md](../DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/README.md)
- [DynamicProgramming/1547-minimum-cost-to-cut-a-stick/README.md](../DynamicProgramming/1547-minimum-cost-to-cut-a-stick/README.md)
- [DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/README.md](../DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/README.md)
- [DynamicProgramming/1911-maximum-alternating-subsequence-sum/README.md](../DynamicProgramming/1911-maximum-alternating-subsequence-sum/README.md)
- [DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/README.md](../DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/README.md)
- [Graphs/0133-clone-graph/README.md](../Graphs/0133-clone-graph/README.md)
- [Graphs/0207-course-schedule/README.md](../Graphs/0207-course-schedule/README.md)
- [Graphs/0210-course-schedule-ii/README.md](../Graphs/0210-course-schedule-ii/README.md)
- [Graphs/0365-water-and-jug-problem/README.md](../Graphs/0365-water-and-jug-problem/README.md)
- [Graphs/0433-minimum-genetic-mutation/README.md](../Graphs/0433-minimum-genetic-mutation/README.md)
- [Graphs/0542-01-matrix/README.md](../Graphs/0542-01-matrix/README.md)
- [Graphs/0684-redundant-connection/README.md](../Graphs/0684-redundant-connection/README.md)
- [Graphs/0733-flood-fill/README.md](../Graphs/0733-flood-fill/README.md)
- [Graphs/0743-network-delay-time/README.md](../Graphs/0743-network-delay-time/README.md)
- [Graphs/0785-is-graph-bipartite/README.md](../Graphs/0785-is-graph-bipartite/README.md)
- [Graphs/0787-cheapest-flights-within-k-stops/README.md](../Graphs/0787-cheapest-flights-within-k-stops/README.md)
- [Graphs/0797-all-paths-from-source-to-target/README.md](../Graphs/0797-all-paths-from-source-to-target/README.md)
- [Graphs/0841-keys-and-rooms/README.md](../Graphs/0841-keys-and-rooms/README.md)
- [Graphs/0886-possible-bipartition/README.md](../Graphs/0886-possible-bipartition/README.md)
- [Graphs/0947-most-stones-removed-with-same-row-or-column/README.md](../Graphs/0947-most-stones-removed-with-same-row-or-column/README.md)
- [Graphs/0990-satisfiability-of-equality-equations/README.md](../Graphs/0990-satisfiability-of-equality-equations/README.md)
- [Graphs/0994-rotting-oranges/README.md](../Graphs/0994-rotting-oranges/README.md)
- [Graphs/1061-lexicographically-smallest-equivalent-string/README.md](../Graphs/1061-lexicographically-smallest-equivalent-string/README.md)
- [Graphs/1091-shortest-path-in-binary-matrix/README.md](../Graphs/1091-shortest-path-in-binary-matrix/README.md)
- [Graphs/1319-number-of-operations-to-make-network-connected/README.md](../Graphs/1319-number-of-operations-to-make-network-connected/README.md)
- [Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/README.md](../Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/README.md)
- [Graphs/1631-path-with-minimum-effort/README.md](../Graphs/1631-path-with-minimum-effort/README.md)
- [Graphs/1926-nearest-exit-from-entrance-in-maze/README.md](../Graphs/1926-nearest-exit-from-entrance-in-maze/README.md)
- [Graphs/1971-find-if-path-exists-in-graph/README.md](../Graphs/1971-find-if-path-exists-in-graph/README.md)
- [Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/README.md](../Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/README.md)
- [Graphs/2359-find-closest-node-to-given-two-nodes/README.md](../Graphs/2359-find-closest-node-to-given-two-nodes/README.md)
- [Graphs/2421-number-of-good-paths/README.md](../Graphs/2421-number-of-good-paths/README.md)
- [Graphs/2492-minimum-score-of-a-path-between-two-cities/README.md](../Graphs/2492-minimum-score-of-a-path-between-two-cities/README.md)
- [Graphs/2596-check-knight-tour-configuration/README.md](../Graphs/2596-check-knight-tour-configuration/README.md)
- [Graphs/3286-find-a-safe-walk-through-a-grid/README.md](../Graphs/3286-find-a-safe-walk-through-a-grid/README.md)
- [Heaps/0215-kth-largest-element-in-an-array/README.md](../Heaps/0215-kth-largest-element-in-an-array/README.md)
- [Heaps/0347-top-k-frequent-elements/README.md](../Heaps/0347-top-k-frequent-elements/README.md)
- [Heaps/0378-kth-smallest-element-in-a-sorted-matrix/README.md](../Heaps/0378-kth-smallest-element-in-a-sorted-matrix/README.md)
- [Heaps/0703-kth-largest-element-in-a-stream/README.md](../Heaps/0703-kth-largest-element-in-a-stream/README.md)
- [Linked-List/0092-reverse-linked-list-ii/README.md](../Linked-List/0092-reverse-linked-list-ii/README.md)
- [Linked-List/0234-palindrome-linked-list/README.md](../Linked-List/0234-palindrome-linked-list/README.md)
- [Math/3886-sum-of-sortable-integers/README.md](../Math/3886-sum-of-sortable-integers/README.md)
- [Trees/0096-unique-binary-search-trees/README.md](../Trees/0096-unique-binary-search-trees/README.md)
- [Trees/0098-validate-binary-search-tree/README.md](../Trees/0098-validate-binary-search-tree/README.md)
- [Trees/0099-recover-binary-search-tree/README.md](../Trees/0099-recover-binary-search-tree/README.md)
- [Trees/0100-same-tree/README.md](../Trees/0100-same-tree/README.md)
- [Trees/0101-symmetric-tree/README.md](../Trees/0101-symmetric-tree/README.md)
- [Trees/0102-binary-tree-level-order-traversal/README.md](../Trees/0102-binary-tree-level-order-traversal/README.md)
- [Trees/0103-binary-tree-zigzag-level-order-traversal/README.md](../Trees/0103-binary-tree-zigzag-level-order-traversal/README.md)
- [Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/README.md](../Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/README.md)
- [Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/README.md](../Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/README.md)
- [Trees/0108-convert-sorted-array-to-binary-search-tree/README.md](../Trees/0108-convert-sorted-array-to-binary-search-tree/README.md)
- [Trees/0111-minimum-depth-of-binary-tree/README.md](../Trees/0111-minimum-depth-of-binary-tree/README.md)
- [Trees/0112-path-sum/README.md](../Trees/0112-path-sum/README.md)
- [Trees/0113-path-sum-ii/README.md](../Trees/0113-path-sum-ii/README.md)
- [Trees/0114-flatten-binary-tree-to-linked-list/README.md](../Trees/0114-flatten-binary-tree-to-linked-list/README.md)
- [Trees/0116-populating-next-right-pointers-in-each-node/README.md](../Trees/0116-populating-next-right-pointers-in-each-node/README.md)
- [Trees/0124-binary-tree-maximum-path-sum/README.md](../Trees/0124-binary-tree-maximum-path-sum/README.md)
- [Trees/0129-sum-root-to-leaf-numbers/README.md](../Trees/0129-sum-root-to-leaf-numbers/README.md)
- [Trees/0144-binary-tree-preorder-traversal/README.md](../Trees/0144-binary-tree-preorder-traversal/README.md)
- [Trees/0145-binary-tree-postorder-traversal/README.md](../Trees/0145-binary-tree-postorder-traversal/README.md)
- [Trees/0173-binary-search-tree-iterator/README.md](../Trees/0173-binary-search-tree-iterator/README.md)
- [Trees/0199-binary-tree-right-side-view/README.md](../Trees/0199-binary-tree-right-side-view/README.md)
- [Trees/0222-count-complete-tree-nodes/README.md](../Trees/0222-count-complete-tree-nodes/README.md)
- [Trees/0230-kth-smallest-element-in-a-bst/README.md](../Trees/0230-kth-smallest-element-in-a-bst/README.md)
- [Trees/0235-lowest-common-ancestor-of-a-binary-search-tree/README.md](../Trees/0235-lowest-common-ancestor-of-a-binary-search-tree/README.md)
- [Trees/0236-lowest-common-ancestor-of-a-binary-tree/README.md](../Trees/0236-lowest-common-ancestor-of-a-binary-tree/README.md)
- [Trees/0450-delete-node-in-a-bst/README.md](../Trees/0450-delete-node-in-a-bst/README.md)
- [Trees/0513-find-bottom-left-tree-value/README.md](../Trees/0513-find-bottom-left-tree-value/README.md)
- [Trees/0515-find-largest-value-in-each-tree-row/README.md](../Trees/0515-find-largest-value-in-each-tree-row/README.md)
- [Trees/0543-diameter-of-binary-tree/README.md](../Trees/0543-diameter-of-binary-tree/README.md)
- [Trees/0572-subtree-of-another-tree/README.md](../Trees/0572-subtree-of-another-tree/README.md)
- [Trees/0623-add-one-row-to-tree/README.md](../Trees/0623-add-one-row-to-tree/README.md)
- [Trees/0652-find-duplicate-subtrees/README.md](../Trees/0652-find-duplicate-subtrees/README.md)
- [Trees/0662-maximum-width-of-binary-tree/README.md](../Trees/0662-maximum-width-of-binary-tree/README.md)
- [Trees/0783-minimum-distance-between-bst-nodes/README.md](../Trees/0783-minimum-distance-between-bst-nodes/README.md)
- [Trees/0814-binary-tree-pruning/README.md](../Trees/0814-binary-tree-pruning/README.md)
- [Trees/0863-all-nodes-distance-k-in-binary-tree/README.md](../Trees/0863-all-nodes-distance-k-in-binary-tree/README.md)
- [Trees/0872-leaf-similar-trees/README.md](../Trees/0872-leaf-similar-trees/README.md)
- [Trees/0951-flip-equivalent-binary-trees/README.md](../Trees/0951-flip-equivalent-binary-trees/README.md)
- [Trees/0958-check-completeness-of-a-binary-tree/README.md](../Trees/0958-check-completeness-of-a-binary-tree/README.md)
- [Trees/0979-distribute-coins-in-binary-tree/README.md](../Trees/0979-distribute-coins-in-binary-tree/README.md)
- [Trees/0988-smallest-string-starting-from-leaf/README.md](../Trees/0988-smallest-string-starting-from-leaf/README.md)
- [Trees/1008-construct-binary-search-tree-from-preorder-traversal/README.md](../Trees/1008-construct-binary-search-tree-from-preorder-traversal/README.md)
- [Trees/1026-maximum-difference-between-node-and-ancestor/README.md](../Trees/1026-maximum-difference-between-node-and-ancestor/README.md)
- [Trees/1038-binary-search-tree-to-greater-sum-tree/README.md](../Trees/1038-binary-search-tree-to-greater-sum-tree/README.md)
- [Trees/1110-delete-nodes-and-return-forest/README.md](../Trees/1110-delete-nodes-and-return-forest/README.md)
- [Trees/1161-maximum-level-sum-of-a-binary-tree/README.md](../Trees/1161-maximum-level-sum-of-a-binary-tree/README.md)
- [Trees/1261-find-elements-in-a-contaminated-binary-tree/README.md](../Trees/1261-find-elements-in-a-contaminated-binary-tree/README.md)
- [Trees/1325-delete-leaves-with-a-given-value/README.md](../Trees/1325-delete-leaves-with-a-given-value/README.md)
- [Trees/1339-maximum-product-of-splitted-binary-tree/README.md](../Trees/1339-maximum-product-of-splitted-binary-tree/README.md)
- [Trees/1361-validate-binary-tree-nodes/README.md](../Trees/1361-validate-binary-tree-nodes/README.md)
- [Trees/1367-linked-list-in-binary-tree/README.md](../Trees/1367-linked-list-in-binary-tree/README.md)
- [Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/README.md](../Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/README.md)
- [Trees/1457-pseudo-palindromic-paths-in-a-binary-tree/README.md](../Trees/1457-pseudo-palindromic-paths-in-a-binary-tree/README.md)
- [Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/README.md](../Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/README.md)
- [Trees/1569-number-of-ways-to-reorder-array-to-get-same-bst/README.md](../Trees/1569-number-of-ways-to-reorder-array-to-get-same-bst/README.md)
- [Trees/1609-even-odd-tree/README.md](../Trees/1609-even-odd-tree/README.md)
- [Trees/1932-merge-bsts-to-create-single-bst/README.md](../Trees/1932-merge-bsts-to-create-single-bst/README.md)
- [Trees/2196-create-binary-tree-from-descriptions/README.md](../Trees/2196-create-binary-tree-from-descriptions/README.md)
- [Trees/2246-longest-path-with-different-adjacent-characters/README.md](../Trees/2246-longest-path-with-different-adjacent-characters/README.md)
- [Trees/2265-count-nodes-equal-to-average-of-subtree/README.md](../Trees/2265-count-nodes-equal-to-average-of-subtree/README.md)
- [Trees/2385-amount-of-time-for-binary-tree-to-be-infected/README.md](../Trees/2385-amount-of-time-for-binary-tree-to-be-infected/README.md)
- [Trees/2415-reverse-odd-levels-of-binary-tree/README.md](../Trees/2415-reverse-odd-levels-of-binary-tree/README.md)
- [Trees/2458-height-of-binary-tree-after-subtree-removal-queries/README.md](../Trees/2458-height-of-binary-tree-after-subtree-removal-queries/README.md)
- [Trees/2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level/README.md](../Trees/2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level/README.md)
- [Trees/2916-subarrays-distinct-element-sum-of-squares-ii/README.md](../Trees/2916-subarrays-distinct-element-sum-of-squares-ii/README.md)

## Supporting files changed

- `scripts/visual_solutions.py`
- `tests/test_visual_solutions.py`
- `.github/workflows/organize.yml`
- `docs/visual-solutions.json` (adds the empty removal ledger; image mappings unchanged)
- `docs/visual-solutions-maintenance.md`
- `docs/visual-code-audit.md` (this report)
