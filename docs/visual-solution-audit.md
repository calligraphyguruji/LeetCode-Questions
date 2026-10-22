# Visual solution integration audit

Audit dates: 2026-10-22–23. Baseline: `9b306a9`, branch `main`. Scope: the complete local checkout, its organizer, tests, source images, and sole GitHub Actions workflow. Codebase graph tools were unavailable; direct filesystem/source inspection was used.

## Repository inventory

- 257 existing problem folders in 11 topics; 257 problem READMEs and one root README.
- 266 stored solution files: 265 C++ files and one Java file.
- 290 source files: 276 supported images (266 JPG, 9 JPEG, 1 PNG) and 14 unsupported/non-image files.
- 251 images confidently matched to 145 existing problems; 25 left unmatched.
- Images identify 149 confirmed unique problems (145 existing plus #36, #128, #167, #371). Three further filename IDs (#3863, #3886, #3942) remain unverified. Generic/unrelated images do not permit an exact total problem count; they are not assigned invented identities.
- Complete problem paths, solution paths, topic counts, unmatched reasons, and verification details are in [the machine-readable inventory](visual-repository-audit.json). Per-image identities, hashes, and destinations are in [the manifest](visual-solutions.json).

| Topic | Existing problem folders |
|---|---:|
| Arrays | 63 |
| Backtracking | 11 |
| BinarySearch | 9 |
| BitManipulation | 4 |
| DynamicProgramming | 30 |
| Graphs | 34 |
| Greedy | 1 |
| Heaps | 5 |
| Linked-List | 14 |
| Math | 15 |
| Trees | 71 |

## Existing automation and changes

`organize.py` remains the root wrapper. `scripts/organize.py` moves/merges root submissions, applies existing topic overrides, scans solution metadata, updates marked sections of the root index/NeetCode tracker, and separately refreshes profile statistics. Its legacy full-template helpers are not called by the entry point. Problem descriptions normally come from LeetHub; its merge formerly replaced existing problem READMEs. The existing GitHub workflow runs tests, invokes this entry point, and commits only when Git detects changes.

Image integration now follows organization and scanning. README sections are appended without changing the original bytes, managed by markers, and emitted as relative Markdown images. SHA-256 validates copies and detects replacement/corruption. Identical bytes are reused; collisions receive deterministic names. Unknown identities stay pending. The manifest also validates destinations when original matched sources are absent.

Resubmission merges preserve visual sections. Nested cleanup now uses the guarded directory merge to preserve subdirectories. Image conflicts and conflicting managed sections stop before destructive merging. The source folder is excluded from topic discovery, and topic overrides require actual directories. Full-pipeline validation caught the previous override logic treating two `3286-...jpg` source filenames as questions; both originals were restored and their hashes verified. A regression test covers that case.

The existing workflow gained image/source/visual-metadata path triggers. Permissions, branch restriction, concurrency, `[skip ci]`, no-op commit guard, and non-force pushes remain intact. No additional workflow was created. The root README, stats, NeetCode dataset, solution files, existing problem paths, and topic classifications are unchanged.

## Integration results and modified problem files

Every row lists the modified README and the new image directory, providing the complete problem-file change list. Image counts are original source pages; no duplicate bytes were found among the 251 integrated images.

| LeetCode # | Problem name / modified README | Actual topic | Images | New image directory | Status |
|---:|---|---|---:|---|---|
| 3 | [Longest Substring Without Repeating Characters](../Arrays/0003-longest-substring-without-repeating-characters/README.md) | Arrays | 1 | [images/](../Arrays/0003-longest-substring-without-repeating-characters/images/) | Success |
| 5 | [Longest Palindromic Substring](../DynamicProgramming/0005-longest-palindromic-substring/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0005-longest-palindromic-substring/images/) | Success |
| 14 | [Longest Common Prefix](../Arrays/0014-longest-common-prefix/README.md) | Arrays | 1 | [images/](../Arrays/0014-longest-common-prefix/images/) | Success |
| 40 | [Combination Sum II](../Backtracking/0040-combination-sum-ii/README.md) | Backtracking | 2 | [images/](../Backtracking/0040-combination-sum-ii/images/) | Success |
| 46 | [Permutations](../Backtracking/0046-permutations/README.md) | Backtracking | 1 | [images/](../Backtracking/0046-permutations/images/) | Success |
| 49 | [Group Anagrams](../Arrays/0049-group-anagrams/README.md) | Arrays | 1 | [images/](../Arrays/0049-group-anagrams/images/) | Success |
| 56 | [Merge Intervals](../Arrays/0056-merge-intervals/README.md) | Arrays | 1 | [images/](../Arrays/0056-merge-intervals/images/) | Success |
| 62 | [Unique Paths](../DynamicProgramming/0062-unique-paths/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0062-unique-paths/images/) | Success |
| 72 | [Edit Distance](../DynamicProgramming/0072-edit-distance/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0072-edit-distance/images/) | Success |
| 73 | [Set Matrix Zeroes](../Arrays/0073-set-matrix-zeroes/README.md) | Arrays | 2 | [images/](../Arrays/0073-set-matrix-zeroes/images/) | Success |
| 76 | [Minimum Window Substring](../Arrays/0076-minimum-window-substring/README.md) | Arrays | 3 | [images/](../Arrays/0076-minimum-window-substring/images/) | Success |
| 78 | [Subsets](../Backtracking/0078-subsets/README.md) | Backtracking | 1 | [images/](../Backtracking/0078-subsets/images/) | Success |
| 79 | [Word Search](../Backtracking/0079-word-search/README.md) | Backtracking | 2 | [images/](../Backtracking/0079-word-search/images/) | Success |
| 90 | [Subsets II](../Backtracking/0090-subsets-ii/README.md) | Backtracking | 2 | [images/](../Backtracking/0090-subsets-ii/images/) | Success |
| 92 | [Reverse Linked List II](../Linked-List/0092-reverse-linked-list-ii/README.md) | Linked-List | 1 | [images/](../Linked-List/0092-reverse-linked-list-ii/images/) | Success |
| 96 | [Unique Binary Search Trees](../Trees/0096-unique-binary-search-trees/README.md) | Trees | 2 | [images/](../Trees/0096-unique-binary-search-trees/images/) | Success |
| 98 | [Validate Binary Search Tree](../Trees/0098-validate-binary-search-tree/README.md) | Trees | 1 | [images/](../Trees/0098-validate-binary-search-tree/images/) | Success |
| 99 | [Recover Binary Search Tree](../Trees/0099-recover-binary-search-tree/README.md) | Trees | 3 | [images/](../Trees/0099-recover-binary-search-tree/images/) | Success |
| 100 | [Same Tree](../Trees/0100-same-tree/README.md) | Trees | 2 | [images/](../Trees/0100-same-tree/images/) | Success |
| 101 | [Symmetric Tree](../Trees/0101-symmetric-tree/README.md) | Trees | 1 | [images/](../Trees/0101-symmetric-tree/images/) | Success |
| 102 | [Binary Tree Level Order Traversal](../Trees/0102-binary-tree-level-order-traversal/README.md) | Trees | 1 | [images/](../Trees/0102-binary-tree-level-order-traversal/images/) | Success |
| 103 | [Binary Tree Zigzag Level Order Traversal](../Trees/0103-binary-tree-zigzag-level-order-traversal/README.md) | Trees | 1 | [images/](../Trees/0103-binary-tree-zigzag-level-order-traversal/images/) | Success |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](../Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/README.md) | Trees | 2 | [images/](../Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/images/) | Success |
| 106 | [Construct Binary Tree from Inorder and Postorder Traversal](../Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/README.md) | Trees | 1 | [images/](../Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/images/) | Success |
| 108 | [Convert Sorted Array to Binary Search Tree](../Trees/0108-convert-sorted-array-to-binary-search-tree/README.md) | Trees | 1 | [images/](../Trees/0108-convert-sorted-array-to-binary-search-tree/images/) | Success |
| 111 | [Minimum Depth of Binary Tree](../Trees/0111-minimum-depth-of-binary-tree/README.md) | Trees | 1 | [images/](../Trees/0111-minimum-depth-of-binary-tree/images/) | Success |
| 112 | [Path Sum](../Trees/0112-path-sum/README.md) | Trees | 1 | [images/](../Trees/0112-path-sum/images/) | Success |
| 113 | [Path Sum II](../Trees/0113-path-sum-ii/README.md) | Trees | 1 | [images/](../Trees/0113-path-sum-ii/images/) | Success |
| 114 | [Flatten Binary Tree to Linked List](../Trees/0114-flatten-binary-tree-to-linked-list/README.md) | Trees | 2 | [images/](../Trees/0114-flatten-binary-tree-to-linked-list/images/) | Success |
| 116 | [Populating Next Right Pointers in Each Node](../Trees/0116-populating-next-right-pointers-in-each-node/README.md) | Trees | 1 | [images/](../Trees/0116-populating-next-right-pointers-in-each-node/images/) | Success |
| 122 | [Best Time to Buy and Sell Stock II](../DynamicProgramming/0122-best-time-to-buy-and-sell-stock-ii/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0122-best-time-to-buy-and-sell-stock-ii/images/) | Success |
| 124 | [Binary Tree Maximum Path Sum](../Trees/0124-binary-tree-maximum-path-sum/README.md) | Trees | 2 | [images/](../Trees/0124-binary-tree-maximum-path-sum/images/) | Success |
| 129 | [Sum Root to Leaf Numbers](../Trees/0129-sum-root-to-leaf-numbers/README.md) | Trees | 1 | [images/](../Trees/0129-sum-root-to-leaf-numbers/images/) | Success |
| 132 | [Palindrome Partitioning II](../DynamicProgramming/0132-palindrome-partitioning-ii/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0132-palindrome-partitioning-ii/images/) | Success |
| 133 | [Clone Graph](../Graphs/0133-clone-graph/README.md) | Graphs | 2 | [images/](../Graphs/0133-clone-graph/images/) | Success |
| 144 | [Binary Tree Preorder Traversal](../Trees/0144-binary-tree-preorder-traversal/README.md) | Trees | 1 | [images/](../Trees/0144-binary-tree-preorder-traversal/images/) | Success |
| 145 | [Binary Tree Postorder Traversal](../Trees/0145-binary-tree-postorder-traversal/README.md) | Trees | 1 | [images/](../Trees/0145-binary-tree-postorder-traversal/images/) | Success |
| 173 | [Binary Search Tree Iterator](../Trees/0173-binary-search-tree-iterator/README.md) | Trees | 2 | [images/](../Trees/0173-binary-search-tree-iterator/images/) | Success |
| 198 | [House Robber](../DynamicProgramming/0198-house-robber/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0198-house-robber/images/) | Success |
| 199 | [Binary Tree Right Side View](../Trees/0199-binary-tree-right-side-view/README.md) | Trees | 1 | [images/](../Trees/0199-binary-tree-right-side-view/images/) | Success |
| 207 | [Course Schedule](../Graphs/0207-course-schedule/README.md) | Graphs | 1 | [images/](../Graphs/0207-course-schedule/images/) | Success |
| 210 | [Course Schedule II](../Graphs/0210-course-schedule-ii/README.md) | Graphs | 1 | [images/](../Graphs/0210-course-schedule-ii/images/) | Success |
| 213 | [House Robber II](../DynamicProgramming/0213-house-robber-ii/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0213-house-robber-ii/images/) | Success |
| 215 | [Kth Largest Element in an Array](../Heaps/0215-kth-largest-element-in-an-array/README.md) | Heaps | 1 | [images/](../Heaps/0215-kth-largest-element-in-an-array/images/) | Success |
| 222 | [Count Complete Tree Nodes](../Trees/0222-count-complete-tree-nodes/README.md) | Trees | 1 | [images/](../Trees/0222-count-complete-tree-nodes/images/) | Success |
| 225 | [Implement Stack using Queues](../Arrays/0225-implement-stack-using-queues/README.md) | Arrays | 1 | [images/](../Arrays/0225-implement-stack-using-queues/images/) | Success |
| 230 | [Kth Smallest Element in a BST](../Trees/0230-kth-smallest-element-in-a-bst/README.md) | Trees | 1 | [images/](../Trees/0230-kth-smallest-element-in-a-bst/images/) | Success |
| 234 | [Palindrome Linked List](../Linked-List/0234-palindrome-linked-list/README.md) | Linked-List | 1 | [images/](../Linked-List/0234-palindrome-linked-list/images/) | Success |
| 235 | [Lowest Common Ancestor of a Binary Search Tree](../Trees/0235-lowest-common-ancestor-of-a-binary-search-tree/README.md) | Trees | 1 | [images/](../Trees/0235-lowest-common-ancestor-of-a-binary-search-tree/images/) | Success |
| 236 | [Lowest Common Ancestor of a Binary Tree](../Trees/0236-lowest-common-ancestor-of-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0236-lowest-common-ancestor-of-a-binary-tree/images/) | Success |
| 239 | [Sliding Window Maximum](../Arrays/0239-sliding-window-maximum/README.md) | Arrays | 2 | [images/](../Arrays/0239-sliding-window-maximum/images/) | Success |
| 242 | [Valid Anagram](../Arrays/0242-valid-anagram/README.md) | Arrays | 1 | [images/](../Arrays/0242-valid-anagram/images/) | Success |
| 279 | [Perfect Squares](../DynamicProgramming/0279-perfect-squares/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0279-perfect-squares/images/) | Success |
| 300 | [Longest Increasing Subsequence](../DynamicProgramming/0300-longest-increasing-subsequence/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0300-longest-increasing-subsequence/images/) | Success |
| 322 | [Coin Change](../DynamicProgramming/0322-coin-change/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0322-coin-change/images/) | Success |
| 347 | [Top K Frequent Elements](../Heaps/0347-top-k-frequent-elements/README.md) | Heaps | 2 | [images/](../Heaps/0347-top-k-frequent-elements/images/) | Success |
| 365 | [Water and Jug Problem](../Graphs/0365-water-and-jug-problem/README.md) | Graphs | 2 | [images/](../Graphs/0365-water-and-jug-problem/images/) | Success |
| 368 | [Largest Divisible Subset](../DynamicProgramming/0368-largest-divisible-subset/README.md) | DynamicProgramming | 3 | [images/](../DynamicProgramming/0368-largest-divisible-subset/images/) | Success |
| 378 | [Kth Smallest Element in a Sorted Matrix](../Heaps/0378-kth-smallest-element-in-a-sorted-matrix/README.md) | Heaps | 1 | [images/](../Heaps/0378-kth-smallest-element-in-a-sorted-matrix/images/) | Success |
| 387 | [First Unique Character in a String](../Arrays/0387-first-unique-character-in-a-string/README.md) | Arrays | 1 | [images/](../Arrays/0387-first-unique-character-in-a-string/images/) | Success |
| 433 | [Minimum Genetic Mutation](../Graphs/0433-minimum-genetic-mutation/README.md) | Graphs | 2 | [images/](../Graphs/0433-minimum-genetic-mutation/images/) | Success |
| 450 | [Delete Node in a BST](../Trees/0450-delete-node-in-a-bst/README.md) | Trees | 2 | [images/](../Trees/0450-delete-node-in-a-bst/images/) | Success |
| 493 | [Reverse Pairs](../Arrays/0493-reverse-pairs/README.md) | Arrays | 3 | [images/](../Arrays/0493-reverse-pairs/images/) | Success |
| 494 | [Target Sum](../Backtracking/0494-target-sum/README.md) | Backtracking | 2 | [images/](../Backtracking/0494-target-sum/images/) | Success |
| 503 | [Next Greater Element II](../Arrays/0503-next-greater-element-ii/README.md) | Arrays | 1 | [images/](../Arrays/0503-next-greater-element-ii/images/) | Success |
| 513 | [Find Bottom Left Tree Value](../Trees/0513-find-bottom-left-tree-value/README.md) | Trees | 1 | [images/](../Trees/0513-find-bottom-left-tree-value/images/) | Success |
| 515 | [Find Largest Value in Each Tree Row](../Trees/0515-find-largest-value-in-each-tree-row/README.md) | Trees | 1 | [images/](../Trees/0515-find-largest-value-in-each-tree-row/images/) | Success |
| 516 | [Longest Palindromic Subsequence](../DynamicProgramming/0516-longest-palindromic-subsequence/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0516-longest-palindromic-subsequence/images/) | Success |
| 542 | [01 Matrix](../Graphs/0542-01-matrix/README.md) | Graphs | 2 | [images/](../Graphs/0542-01-matrix/images/) | Success |
| 543 | [Diameter of Binary Tree](../Trees/0543-diameter-of-binary-tree/README.md) | Trees | 3 | [images/](../Trees/0543-diameter-of-binary-tree/images/) | Success |
| 560 | [Subarray Sum Equals K](../Arrays/0560-subarray-sum-equals-k/README.md) | Arrays | 2 | [images/](../Arrays/0560-subarray-sum-equals-k/images/) | Success |
| 572 | [Subtree of Another Tree](../Trees/0572-subtree-of-another-tree/README.md) | Trees | 1 | [images/](../Trees/0572-subtree-of-another-tree/images/) | Success |
| 623 | [Add One Row to Tree](../Trees/0623-add-one-row-to-tree/README.md) | Trees | 2 | [images/](../Trees/0623-add-one-row-to-tree/images/) | Success |
| 652 | [Find Duplicate Subtrees](../Trees/0652-find-duplicate-subtrees/README.md) | Trees | 2 | [images/](../Trees/0652-find-duplicate-subtrees/images/) | Success |
| 662 | [Maximum Width of Binary Tree](../Trees/0662-maximum-width-of-binary-tree/README.md) | Trees | 1 | [images/](../Trees/0662-maximum-width-of-binary-tree/images/) | Success |
| 684 | [Redundant Connection](../Graphs/0684-redundant-connection/README.md) | Graphs | 2 | [images/](../Graphs/0684-redundant-connection/images/) | Success |
| 703 | [Kth Largest Element in a Stream](../Heaps/0703-kth-largest-element-in-a-stream/README.md) | Heaps | 1 | [images/](../Heaps/0703-kth-largest-element-in-a-stream/images/) | Success |
| 733 | [Flood Fill](../Graphs/0733-flood-fill/README.md) | Graphs | 1 | [images/](../Graphs/0733-flood-fill/images/) | Success |
| 743 | [Network Delay Time](../Graphs/0743-network-delay-time/README.md) | Graphs | 2 | [images/](../Graphs/0743-network-delay-time/images/) | Success |
| 783 | [Minimum Distance Between BST Nodes](../Trees/0783-minimum-distance-between-bst-nodes/README.md) | Trees | 1 | [images/](../Trees/0783-minimum-distance-between-bst-nodes/images/) | Success |
| 785 | [Is Graph Bipartite?](../Graphs/0785-is-graph-bipartite/README.md) | Graphs | 1 | [images/](../Graphs/0785-is-graph-bipartite/images/) | Success |
| 787 | [Cheapest Flights Within K Stops](../Graphs/0787-cheapest-flights-within-k-stops/README.md) | Graphs | 2 | [images/](../Graphs/0787-cheapest-flights-within-k-stops/images/) | Success |
| 797 | [All Paths From Source to Target](../Graphs/0797-all-paths-from-source-to-target/README.md) | Graphs | 1 | [images/](../Graphs/0797-all-paths-from-source-to-target/images/) | Success |
| 814 | [Binary Tree Pruning](../Trees/0814-binary-tree-pruning/README.md) | Trees | 2 | [images/](../Trees/0814-binary-tree-pruning/images/) | Success |
| 841 | [Keys and Rooms](../Graphs/0841-keys-and-rooms/README.md) | Graphs | 1 | [images/](../Graphs/0841-keys-and-rooms/images/) | Success |
| 863 | [All Nodes Distance K in Binary Tree](../Trees/0863-all-nodes-distance-k-in-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0863-all-nodes-distance-k-in-binary-tree/images/) | Success |
| 872 | [Leaf-Similar Trees](../Trees/0872-leaf-similar-trees/README.md) | Trees | 1 | [images/](../Trees/0872-leaf-similar-trees/images/) | Success |
| 886 | [Possible Bipartition](../Graphs/0886-possible-bipartition/README.md) | Graphs | 2 | [images/](../Graphs/0886-possible-bipartition/images/) | Success |
| 947 | [Most Stones Removed with Same Row or Column](../Graphs/0947-most-stones-removed-with-same-row-or-column/README.md) | Graphs | 2 | [images/](../Graphs/0947-most-stones-removed-with-same-row-or-column/images/) | Success |
| 951 | [Flip Equivalent Binary Trees](../Trees/0951-flip-equivalent-binary-trees/README.md) | Trees | 2 | [images/](../Trees/0951-flip-equivalent-binary-trees/images/) | Success |
| 958 | [Check Completeness of a Binary Tree](../Trees/0958-check-completeness-of-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0958-check-completeness-of-a-binary-tree/images/) | Success |
| 979 | [Distribute Coins in Binary Tree](../Trees/0979-distribute-coins-in-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0979-distribute-coins-in-binary-tree/images/) | Success |
| 988 | [Smallest String Starting From Leaf](../Trees/0988-smallest-string-starting-from-leaf/README.md) | Trees | 2 | [images/](../Trees/0988-smallest-string-starting-from-leaf/images/) | Success |
| 990 | [Satisfiability of Equality Equations](../Graphs/0990-satisfiability-of-equality-equations/README.md) | Graphs | 1 | [images/](../Graphs/0990-satisfiability-of-equality-equations/images/) | Success |
| 994 | [Rotting Oranges](../Graphs/0994-rotting-oranges/README.md) | Graphs | 2 | [images/](../Graphs/0994-rotting-oranges/images/) | Success |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](../Trees/1008-construct-binary-search-tree-from-preorder-traversal/README.md) | Trees | 1 | [images/](../Trees/1008-construct-binary-search-tree-from-preorder-traversal/images/) | Success |
| 1026 | [Maximum Difference Between Node and Ancestor](../Trees/1026-maximum-difference-between-node-and-ancestor/README.md) | Trees | 2 | [images/](../Trees/1026-maximum-difference-between-node-and-ancestor/images/) | Success |
| 1038 | [Binary Search Tree to Greater Sum Tree](../Trees/1038-binary-search-tree-to-greater-sum-tree/README.md) | Trees | 1 | [images/](../Trees/1038-binary-search-tree-to-greater-sum-tree/images/) | Success |
| 1048 | [Longest String Chain](../DynamicProgramming/1048-longest-string-chain/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1048-longest-string-chain/images/) | Success |
| 1061 | [Lexicographically Smallest Equivalent String](../Graphs/1061-lexicographically-smallest-equivalent-string/README.md) | Graphs | 2 | [images/](../Graphs/1061-lexicographically-smallest-equivalent-string/images/) | Success |
| 1091 | [Shortest Path in Binary Matrix](../Graphs/1091-shortest-path-in-binary-matrix/README.md) | Graphs | 3 | [images/](../Graphs/1091-shortest-path-in-binary-matrix/images/) | Success |
| 1092 | [Shortest Common Supersequence](../DynamicProgramming/1092-shortest-common-supersequence/README.md) | DynamicProgramming | 3 | [images/](../DynamicProgramming/1092-shortest-common-supersequence/images/) | Success |
| 1110 | [Delete Nodes And Return Forest](../Trees/1110-delete-nodes-and-return-forest/README.md) | Trees | 2 | [images/](../Trees/1110-delete-nodes-and-return-forest/images/) | Success |
| 1161 | [Maximum Level Sum of a Binary Tree](../Trees/1161-maximum-level-sum-of-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1161-maximum-level-sum-of-a-binary-tree/images/) | Success |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](../Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/README.md) | Backtracking | 2 | [images/](../Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/images/) | Success |
| 1261 | [Find Elements in a Contaminated Binary Tree](../Trees/1261-find-elements-in-a-contaminated-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1261-find-elements-in-a-contaminated-binary-tree/images/) | Success |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](../DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/images/) | Success |
| 1319 | [Number of Operations to Make Network Connected](../Graphs/1319-number-of-operations-to-make-network-connected/README.md) | Graphs | 2 | [images/](../Graphs/1319-number-of-operations-to-make-network-connected/images/) | Success |
| 1325 | [Delete Leaves With a Given Value](../Trees/1325-delete-leaves-with-a-given-value/README.md) | Trees | 2 | [images/](../Trees/1325-delete-leaves-with-a-given-value/images/) | Success |
| 1334 | [Find the City With the Smallest Number of Neighbors at a Threshold Distance](../Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/README.md) | Graphs | 2 | [images/](../Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/images/) | Success |
| 1335 | [Minimum Difficulty of a Job Schedule](../DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/images/) | Success |
| 1339 | [Maximum Product of Splitted Binary Tree](../Trees/1339-maximum-product-of-splitted-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1339-maximum-product-of-splitted-binary-tree/images/) | Success |
| 1361 | [Validate Binary Tree Nodes](../Trees/1361-validate-binary-tree-nodes/README.md) | Trees | 2 | [images/](../Trees/1361-validate-binary-tree-nodes/images/) | Success |
| 1367 | [Linked List in Binary Tree](../Trees/1367-linked-list-in-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1367-linked-list-in-binary-tree/images/) | Success |
| 1392 | [Longest Happy Prefix](../Arrays/1392-longest-happy-prefix/README.md) | Arrays | 2 | [images/](../Arrays/1392-longest-happy-prefix/images/) | Success |
| 1420 | [Build Array Where You Can Find The Maximum Exactly K Comparisons](../DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/images/) | Success |
| 1443 | [Minimum Time to Collect All Apples in a Tree](../Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/README.md) | Trees | 3 | [images/](../Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/images/) | Success |
| 1457 | [Pseudo-Palindromic Paths in a Binary Tree](../Trees/1457-pseudo-palindromic-paths-in-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1457-pseudo-palindromic-paths-in-a-binary-tree/images/) | Success |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](../Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/README.md) | Trees | 2 | [images/](../Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/images/) | Success |
| 1547 | [Minimum Cost to Cut a Stick](../DynamicProgramming/1547-minimum-cost-to-cut-a-stick/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1547-minimum-cost-to-cut-a-stick/images/) | Success |
| 1569 | [Number of Ways to Reorder Array to Get Same BST](../Trees/1569-number-of-ways-to-reorder-array-to-get-same-bst/README.md) | Trees | 3 | [images/](../Trees/1569-number-of-ways-to-reorder-array-to-get-same-bst/images/) | Success |
| 1594 | [Maximum Non Negative Product in a Matrix](../DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/images/) | Success |
| 1609 | [Even Odd Tree](../Trees/1609-even-odd-tree/README.md) | Trees | 2 | [images/](../Trees/1609-even-odd-tree/images/) | Success |
| 1631 | [Path With Minimum Effort](../Graphs/1631-path-with-minimum-effort/README.md) | Graphs | 3 | [images/](../Graphs/1631-path-with-minimum-effort/images/) | Success |
| 1911 | [Maximum Alternating Subsequence Sum](../DynamicProgramming/1911-maximum-alternating-subsequence-sum/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1911-maximum-alternating-subsequence-sum/images/) | Success |
| 1926 | [Nearest Exit from Entrance in Maze](../Graphs/1926-nearest-exit-from-entrance-in-maze/README.md) | Graphs | 1 | [images/](../Graphs/1926-nearest-exit-from-entrance-in-maze/images/) | Success |
| 1932 | [Merge BSTs to Create Single BST](../Trees/1932-merge-bsts-to-create-single-bst/README.md) | Trees | 3 | [images/](../Trees/1932-merge-bsts-to-create-single-bst/images/) | Success |
| 1971 | [Find if Path Exists in Graph](../Graphs/1971-find-if-path-exists-in-graph/README.md) | Graphs | 2 | [images/](../Graphs/1971-find-if-path-exists-in-graph/images/) | Success |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](../DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/README.md) | DynamicProgramming | 3 | [images/](../DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/images/) | Success |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](../BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/README.md) | BinarySearch | 2 | [images/](../BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/images/) | Success |
| 2196 | [Create Binary Tree From Descriptions](../Trees/2196-create-binary-tree-from-descriptions/README.md) | Trees | 2 | [images/](../Trees/2196-create-binary-tree-from-descriptions/images/) | Success |
| 2246 | [Longest Path With Different Adjacent Characters](../Trees/2246-longest-path-with-different-adjacent-characters/README.md) | Trees | 2 | [images/](../Trees/2246-longest-path-with-different-adjacent-characters/images/) | Success |
| 2265 | [Count Nodes Equal to Average of Subtree](../Trees/2265-count-nodes-equal-to-average-of-subtree/README.md) | Trees | 2 | [images/](../Trees/2265-count-nodes-equal-to-average-of-subtree/images/) | Success |
| 2316 | [Count Unreachable Pairs of Nodes in an Undirected Graph](../Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/README.md) | Graphs | 2 | [images/](../Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/images/) | Success |
| 2359 | [Find Closest Node to Given Two Nodes](../Graphs/2359-find-closest-node-to-given-two-nodes/README.md) | Graphs | 2 | [images/](../Graphs/2359-find-closest-node-to-given-two-nodes/images/) | Success |
| 2385 | [Amount of Time for Binary Tree to Be Infected](../Trees/2385-amount-of-time-for-binary-tree-to-be-infected/README.md) | Trees | 2 | [images/](../Trees/2385-amount-of-time-for-binary-tree-to-be-infected/images/) | Success |
| 2415 | [Reverse Odd Levels of Binary Tree](../Trees/2415-reverse-odd-levels-of-binary-tree/README.md) | Trees | 2 | [images/](../Trees/2415-reverse-odd-levels-of-binary-tree/images/) | Success |
| 2421 | [Number of Good Paths](../Graphs/2421-number-of-good-paths/README.md) | Graphs | 3 | [images/](../Graphs/2421-number-of-good-paths/images/) | Success |
| 2458 | [Height of Binary Tree After Subtree Removal Queries](../Trees/2458-height-of-binary-tree-after-subtree-removal-queries/README.md) | Trees | 3 | [images/](../Trees/2458-height-of-binary-tree-after-subtree-removal-queries/images/) | Success |
| 2471 | [Minimum Number of Operations to Sort a Binary Tree by Level](../Trees/2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level/README.md) | Trees | 2 | [images/](../Trees/2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level/images/) | Success |
| 2492 | [Minimum Score of a Path Between Two Cities](../Graphs/2492-minimum-score-of-a-path-between-two-cities/README.md) | Graphs | 2 | [images/](../Graphs/2492-minimum-score-of-a-path-between-two-cities/images/) | Success |
| 2596 | [Check Knight Tour Configuration](../Graphs/2596-check-knight-tour-configuration/README.md) | Graphs | 1 | [images/](../Graphs/2596-check-knight-tour-configuration/images/) | Success |
| 2916 | [Subarrays Distinct Element Sum of Squares II](../Trees/2916-subarrays-distinct-element-sum-of-squares-ii/README.md) | Trees | 3 | [images/](../Trees/2916-subarrays-distinct-element-sum-of-squares-ii/images/) | Success |
| 3286 | [Find a Safe Walk Through a Grid](../Graphs/3286-find-a-safe-walk-through-a-grid/README.md) | Graphs | 2 | [images/](../Graphs/3286-find-a-safe-walk-through-a-grid/images/) | Success |
| 3551 | [Minimum Swaps to Sort by Digit Sum](../Arrays/3551-minimum-swaps-to-sort-by-digit-sum/README.md) | Arrays | 2 | [images/](../Arrays/3551-minimum-swaps-to-sort-by-digit-sum/images/) | Success |

## Unmatched images

All 25 remain untouched in the source folder. The 23 solution/algorithm-note images are included in the task commit for future retry; the two unrelated images remain local and untracked. No problem folders were created for them.

| Image | Reason |
|---|---|
| `128-Longest-Consecutive-Seq.jpg` | LeetCode #128: no verified existing solution folder with README |
| `167-Two-Sum-II-Input-Sorted.jpg` | LeetCode #167: no verified existing solution folder with README |
| `36-Valid-Sudoku-Part-I.jpg` | LeetCode #36: no verified existing solution folder with README |
| `36-Valid-Sudoku-Part-II.jpg` | LeetCode #36: no verified existing solution folder with README |
| `371-Sum-of-Two-Int-Part-I.jpg` | LeetCode #371: no verified existing solution folder with README |
| `371-Sum-of-Two-Int-Part-II.jpg` | LeetCode #371: no verified existing solution folder with README |
| `3863-Min-Op-to-Sort-String-Part-I.jpg` | Unverified abbreviated title for #3863; manual review required; no corresponding existing problem folder |
| `3863-Min-Op-to-Sort-String-Part-II.jpg` | Unverified abbreviated title for #3863; manual review required; no corresponding existing problem folder |
| `3886-Sum-of-Sortable-Integers-Part-I.jpg` | Unverified abbreviated title for #3886; manual review required; no corresponding existing problem folder |
| `3886-Sum-of-Sortable-Integers-Part-II.jpg` | Unverified abbreviated title for #3886; manual review required; no corresponding existing problem folder |
| `3886-Sum-of-Sortable-Integers-Part-III.jpg` | Unverified abbreviated title for #3886; manual review required; no corresponding existing problem folder |
| `3886-Sum-of-Sortable-Integers-Part-IV.jpg` | Unverified abbreviated title for #3886; manual review required; no corresponding existing problem folder |
| `3942-Min-Op-to-Sort-Nums-Part-I.jpg` | Unverified abbreviated title for #3942; manual review required; no corresponding existing problem folder |
| `3942-Min-Op-to-Sort-Nums-Part-II.jpg` | Unverified abbreviated title for #3942; manual review required; no corresponding existing problem folder |
| `Dijkstra's Algorithm.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Heap Sort Part-I.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Heap Sort Part-II.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `IMG_20260619_123722.jpg` | Visually inspected: general Prim/MST notes; no unique LeetCode identity |
| `Merge Sort Part-I.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Merge Sort Part-II.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Prim's Agorithm Part-II.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Prim's Algorithm Part-I.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Prim's Algorithm Part-III.jpg` | General algorithm notes; no uniquely verified LeetCode problem |
| `Resume Aman.png` | Unrelated image; no LeetCode problem identity |
| `SessClassDiagram.jpeg` | Unrelated image; no LeetCode problem identity |

## Other changed files

- `scripts/organize.py`: integrates visual solutions and protects their files during merges/cleanup.
- `scripts/visual_solutions.py`: new standard-library-only matcher, copier, manifest, README/link validation, dry-run CLI.
- `tests/test_visual_solutions.py`: 29 new offline safety/lifecycle tests.
- `.github/workflows/organize.yml`: extends existing push triggers.
- `docs/visual-title-aliases.json`: reviewed abbreviated titles pinned to IDs and canonical slugs.
- `docs/visual-solutions.json`: 251 source/destination/hash mappings.
- `docs/visual-repository-audit.json`: complete repository inventory and validation record.
- `docs/visual-solution-audit.md`: this report.
- `docs/visual-solutions-maintenance.md`: future image addition and review instructions.
- 145 new `images/` directories containing 251 unmodified image copies; 23 pending solution images versioned under `LeetCode-Img-Soln/`.

All 290 original source files remain locally. The 251 already-integrated originals are not duplicated in Git; their bytes are published in the problem folders. Those originals, the 14 non-image files, and the two unrelated images remain intentionally untracked (267 files).

## Verification results

| Check | Result | Evidence |
|---|---|---|
| Image matching | PASS (integrated images) | All 251 folder IDs and canonical README URLs independently agree with the manifest; numbered filenames agree; #112/#113 inspected and isolated. Uncertain images withheld. |
| README links | PASS | All 251 generated Markdown links resolve to existing files in the corresponding folders. |
| Multipart ordering | PASS | Every actual README sequence compared with numeric/Roman part order; fixtures include I, II, III, IV, 10 and missing initial parts. |
| No duplicate images | PASS | 251 distinct SHA-256 values and 251 destinations; fixtures verify same-problem deduplication and cross-problem duplicate rejection. |
| Existing C++ files preserved | PASS | All 265 original C++ hashes equal the baseline; all existing solution paths preserved. |
| Existing README content preserved | PASS | Each of 145 updated READMEs starts with its exact original Git bytes; other READMEs, including the root README, are unchanged. |
| Idempotency | PASS | Two consecutive full `python3 organize.py --offline` runs; second run makes zero copies/README updates and preserves all file paths, bytes and mtimes. |
| Image integrity | PASS | All 251 original-source, manifest and destination SHA-256 hashes agree. |
| Future automation | PASS (offline fixtures) | New image attachment, pending #36 followed by new problem, resubmission, nested cleanup, absent originals, and topic-override safety exercised. |
| GitHub Actions validation | PASS (local YAML/configuration) | Ruby YAML parsing and checks for image triggers, permissions, organizer command, no-op/loop guards, safe pushes and single workflow. Live execution NOT VERIFIED. |
| Regression tests | PASS for 76 executed tests; 1 SKIPPED | `python3 -m unittest discover -s tests -v`: 77 discovered, 76 passed, 1 existing loopback-server test skipped because sandbox disallows binding. |
| CodeRabbit review | NOT RUN | CLI 0.7.6 is installed but signed out; local code/diff review performed. |
| GitHub rendered READMEs | NOT VERIFIED | Relative Markdown and file hashes verified locally; GitHub network access unavailable. |

The 390 original tracked files outside the 145 appended READMEs and two updated automation files remain byte-identical. No existing problem folder was renamed or reclassified. Tests use temporary fixtures; no simulated solutions remain in this repository.

## Git and publishing

Task files are committed locally on `main` with message `feat: integrate visual LeetCode solutions into problem READMEs`. Only task paths are staged; unrelated source documents and the two unrelated images are excluded. Final status inspection found zero tracked changes and 267 intentionally retained untracked source files, all under `LeetCode-Img-Soln/`. The final commit hash is reported with the final response.

The attempted `git push origin HEAD:main` was rejected with `fetch first`: remote `main` contains newer work. Reconciliation was attempted with `git fetch origin main`, which failed with `Could not resolve host: github.com`. A direct DNS lookup also failed. The commit has NOT been published; the newer remote changes, GitHub Actions run, and live README rendering cannot be verified. No force push, token changes, workflow permission escalation, or overwrite of remote work was attempted.

Once network access is available, fetch and inspect `origin/main` before pushing the local commit. If the remote advanced, reconcile normally and rerun validation before a non-force push.
