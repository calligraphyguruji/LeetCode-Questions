# Visual solution integration audit

Audit date: 2026-10-23. Baseline: `a58b929`, branch `main`. This report supersedes the earlier 257-folder / 251-image inventory. The checked-out baseline already contains the integration; this task verifies it and adds a persistent regression check. Graph tools were unavailable, so the audit used direct source and filesystem inspection.

## Repository inventory

- 264 existing problem folders in 11 topics; 264 problem READMEs.
- 273 solution files: 272 C++ and one Java.
- 290 source files: 276 supported images (266 JPG, 9 JPEG, 1 PNG) and 14 other files.
- 261 matched images covering 150 verified unique LeetCode problems; 15 unmatched images.
- Two additional filename IDs (#3863 and #3942) are unverified. Generic algorithm notes and unrelated images have no unique problem identity; no exact total is asserted for them.
- All original source files remain in place. Unmatched images are untouched; no problem folder was created, renamed or reclassified.

| Topic | Existing problem folders |
|---|---:|
| Arrays | 68 |
| Backtracking | 11 |
| BinarySearch | 9 |
| BitManipulation | 5 |
| DynamicProgramming | 30 |
| Graphs | 34 |
| Greedy | 1 |
| Heaps | 5 |
| Linked-List | 14 |
| Math | 16 |
| Trees | 71 |

## Automation audit

`organize.py` delegates to `scripts/organize.py`. The active pipeline merges incoming root problem folders, applies existing topic overrides, scans solution metadata, updates the root index and NeetCode tracker, integrates verified images, and optionally refreshes profile statistics. Legacy full-template README helpers are not called by this entry point. Incoming LeetHub problem descriptions retain their managed visual sections; guarded merges preserve image directories and reject conflicting bytes.

`scripts/visual_solutions.py` already provides exact ID matching, normalized titles, explicitly reviewed aliases, safe copying, deterministic collision names, SHA-256 verification, managed README sections, ordered multipart display, dry runs and unmatched reporting. Unknown identities and absent problem folders remain pending. The manifest supports checkouts without original matched source files. No production-script change was needed.

The sole workflow `.github/workflows/organize.yml` already watches source images, destination images, visual JSON metadata, solutions and READMEs. It runs tests before organization, stages generated files, checks for no changes, and uses a `[skip ci]` bot commit and ordinary non-force push. Existing permissions, default-branch restriction and concurrency remain unchanged. No workflow change was needed.

## Integration results

All rows below were already integrated at the audited baseline. Each row identifies the existing problem README and images directory. This run required zero image copies and zero problem README changes.

| LeetCode # | Problem / README | Actual topic | Images | Images directory | Status |
|---:|---|---|---:|---|---|
| 3 | [Longest Substring Without Repeating Characters](../Arrays/0003-longest-substring-without-repeating-characters/README.md) | Arrays | 1 | [images/](../Arrays/0003-longest-substring-without-repeating-characters/images/) | Verified |
| 5 | [Longest Palindromic Substring](../DynamicProgramming/0005-longest-palindromic-substring/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0005-longest-palindromic-substring/images/) | Verified |
| 14 | [Longest Common Prefix](../Arrays/0014-longest-common-prefix/README.md) | Arrays | 1 | [images/](../Arrays/0014-longest-common-prefix/images/) | Verified |
| 36 | [Valid Sudoku](../Arrays/0036-valid-sudoku/README.md) | Arrays | 2 | [images/](../Arrays/0036-valid-sudoku/images/) | Verified |
| 40 | [Combination Sum II](../Backtracking/0040-combination-sum-ii/README.md) | Backtracking | 2 | [images/](../Backtracking/0040-combination-sum-ii/images/) | Verified |
| 46 | [Permutations](../Backtracking/0046-permutations/README.md) | Backtracking | 1 | [images/](../Backtracking/0046-permutations/images/) | Verified |
| 49 | [Group Anagrams](../Arrays/0049-group-anagrams/README.md) | Arrays | 1 | [images/](../Arrays/0049-group-anagrams/images/) | Verified |
| 56 | [Merge Intervals](../Arrays/0056-merge-intervals/README.md) | Arrays | 1 | [images/](../Arrays/0056-merge-intervals/images/) | Verified |
| 62 | [Unique Paths](../DynamicProgramming/0062-unique-paths/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0062-unique-paths/images/) | Verified |
| 72 | [Edit Distance](../DynamicProgramming/0072-edit-distance/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0072-edit-distance/images/) | Verified |
| 73 | [Set Matrix Zeroes](../Arrays/0073-set-matrix-zeroes/README.md) | Arrays | 2 | [images/](../Arrays/0073-set-matrix-zeroes/images/) | Verified |
| 76 | [Minimum Window Substring](../Arrays/0076-minimum-window-substring/README.md) | Arrays | 3 | [images/](../Arrays/0076-minimum-window-substring/images/) | Verified |
| 78 | [Subsets](../Backtracking/0078-subsets/README.md) | Backtracking | 1 | [images/](../Backtracking/0078-subsets/images/) | Verified |
| 79 | [Word Search](../Backtracking/0079-word-search/README.md) | Backtracking | 2 | [images/](../Backtracking/0079-word-search/images/) | Verified |
| 90 | [Subsets II](../Backtracking/0090-subsets-ii/README.md) | Backtracking | 2 | [images/](../Backtracking/0090-subsets-ii/images/) | Verified |
| 92 | [Reverse Linked List II](../Linked-List/0092-reverse-linked-list-ii/README.md) | Linked-List | 1 | [images/](../Linked-List/0092-reverse-linked-list-ii/images/) | Verified |
| 96 | [Unique Binary Search Trees](../Trees/0096-unique-binary-search-trees/README.md) | Trees | 2 | [images/](../Trees/0096-unique-binary-search-trees/images/) | Verified |
| 98 | [Validate Binary Search Tree](../Trees/0098-validate-binary-search-tree/README.md) | Trees | 1 | [images/](../Trees/0098-validate-binary-search-tree/images/) | Verified |
| 99 | [Recover Binary Search Tree](../Trees/0099-recover-binary-search-tree/README.md) | Trees | 3 | [images/](../Trees/0099-recover-binary-search-tree/images/) | Verified |
| 100 | [Same Tree](../Trees/0100-same-tree/README.md) | Trees | 2 | [images/](../Trees/0100-same-tree/images/) | Verified |
| 101 | [Symmetric Tree](../Trees/0101-symmetric-tree/README.md) | Trees | 1 | [images/](../Trees/0101-symmetric-tree/images/) | Verified |
| 102 | [Binary Tree Level Order Traversal](../Trees/0102-binary-tree-level-order-traversal/README.md) | Trees | 1 | [images/](../Trees/0102-binary-tree-level-order-traversal/images/) | Verified |
| 103 | [Binary Tree Zigzag Level Order Traversal](../Trees/0103-binary-tree-zigzag-level-order-traversal/README.md) | Trees | 1 | [images/](../Trees/0103-binary-tree-zigzag-level-order-traversal/images/) | Verified |
| 105 | [Construct Binary Tree from Preorder and Inorder Traversal](../Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/README.md) | Trees | 2 | [images/](../Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/images/) | Verified |
| 106 | [Construct Binary Tree from Inorder and Postorder Traversal](../Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/README.md) | Trees | 1 | [images/](../Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/images/) | Verified |
| 108 | [Convert Sorted Array to Binary Search Tree](../Trees/0108-convert-sorted-array-to-binary-search-tree/README.md) | Trees | 1 | [images/](../Trees/0108-convert-sorted-array-to-binary-search-tree/images/) | Verified |
| 111 | [Minimum Depth of Binary Tree](../Trees/0111-minimum-depth-of-binary-tree/README.md) | Trees | 1 | [images/](../Trees/0111-minimum-depth-of-binary-tree/images/) | Verified |
| 112 | [Path Sum](../Trees/0112-path-sum/README.md) | Trees | 1 | [images/](../Trees/0112-path-sum/images/) | Verified |
| 113 | [Path Sum II](../Trees/0113-path-sum-ii/README.md) | Trees | 1 | [images/](../Trees/0113-path-sum-ii/images/) | Verified |
| 114 | [Flatten Binary Tree to Linked List](../Trees/0114-flatten-binary-tree-to-linked-list/README.md) | Trees | 2 | [images/](../Trees/0114-flatten-binary-tree-to-linked-list/images/) | Verified |
| 116 | [Populating Next Right Pointers in Each Node](../Trees/0116-populating-next-right-pointers-in-each-node/README.md) | Trees | 1 | [images/](../Trees/0116-populating-next-right-pointers-in-each-node/images/) | Verified |
| 122 | [Best Time to Buy and Sell Stock II](../DynamicProgramming/0122-best-time-to-buy-and-sell-stock-ii/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0122-best-time-to-buy-and-sell-stock-ii/images/) | Verified |
| 124 | [Binary Tree Maximum Path Sum](../Trees/0124-binary-tree-maximum-path-sum/README.md) | Trees | 2 | [images/](../Trees/0124-binary-tree-maximum-path-sum/images/) | Verified |
| 128 | [Longest Consecutive Sequence](../Arrays/0128-longest-consecutive-sequence/README.md) | Arrays | 1 | [images/](../Arrays/0128-longest-consecutive-sequence/images/) | Verified |
| 129 | [Sum Root to Leaf Numbers](../Trees/0129-sum-root-to-leaf-numbers/README.md) | Trees | 1 | [images/](../Trees/0129-sum-root-to-leaf-numbers/images/) | Verified |
| 132 | [Palindrome Partitioning II](../DynamicProgramming/0132-palindrome-partitioning-ii/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0132-palindrome-partitioning-ii/images/) | Verified |
| 133 | [Clone Graph](../Graphs/0133-clone-graph/README.md) | Graphs | 2 | [images/](../Graphs/0133-clone-graph/images/) | Verified |
| 144 | [Binary Tree Preorder Traversal](../Trees/0144-binary-tree-preorder-traversal/README.md) | Trees | 1 | [images/](../Trees/0144-binary-tree-preorder-traversal/images/) | Verified |
| 145 | [Binary Tree Postorder Traversal](../Trees/0145-binary-tree-postorder-traversal/README.md) | Trees | 1 | [images/](../Trees/0145-binary-tree-postorder-traversal/images/) | Verified |
| 167 | [Two Sum II - Input Array Is Sorted](../Arrays/0167-two-sum-ii-input-array-is-sorted/README.md) | Arrays | 1 | [images/](../Arrays/0167-two-sum-ii-input-array-is-sorted/images/) | Verified |
| 173 | [Binary Search Tree Iterator](../Trees/0173-binary-search-tree-iterator/README.md) | Trees | 2 | [images/](../Trees/0173-binary-search-tree-iterator/images/) | Verified |
| 198 | [House Robber](../DynamicProgramming/0198-house-robber/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0198-house-robber/images/) | Verified |
| 199 | [Binary Tree Right Side View](../Trees/0199-binary-tree-right-side-view/README.md) | Trees | 1 | [images/](../Trees/0199-binary-tree-right-side-view/images/) | Verified |
| 207 | [Course Schedule](../Graphs/0207-course-schedule/README.md) | Graphs | 1 | [images/](../Graphs/0207-course-schedule/images/) | Verified |
| 210 | [Course Schedule II](../Graphs/0210-course-schedule-ii/README.md) | Graphs | 1 | [images/](../Graphs/0210-course-schedule-ii/images/) | Verified |
| 213 | [House Robber II](../DynamicProgramming/0213-house-robber-ii/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0213-house-robber-ii/images/) | Verified |
| 215 | [Kth Largest Element in an Array](../Heaps/0215-kth-largest-element-in-an-array/README.md) | Heaps | 1 | [images/](../Heaps/0215-kth-largest-element-in-an-array/images/) | Verified |
| 222 | [Count Complete Tree Nodes](../Trees/0222-count-complete-tree-nodes/README.md) | Trees | 1 | [images/](../Trees/0222-count-complete-tree-nodes/images/) | Verified |
| 225 | [Implement Stack using Queues](../Arrays/0225-implement-stack-using-queues/README.md) | Arrays | 1 | [images/](../Arrays/0225-implement-stack-using-queues/images/) | Verified |
| 230 | [Kth Smallest Element in a BST](../Trees/0230-kth-smallest-element-in-a-bst/README.md) | Trees | 1 | [images/](../Trees/0230-kth-smallest-element-in-a-bst/images/) | Verified |
| 234 | [Palindrome Linked List](../Linked-List/0234-palindrome-linked-list/README.md) | Linked-List | 1 | [images/](../Linked-List/0234-palindrome-linked-list/images/) | Verified |
| 235 | [Lowest Common Ancestor of a Binary Search Tree](../Trees/0235-lowest-common-ancestor-of-a-binary-search-tree/README.md) | Trees | 1 | [images/](../Trees/0235-lowest-common-ancestor-of-a-binary-search-tree/images/) | Verified |
| 236 | [Lowest Common Ancestor of a Binary Tree](../Trees/0236-lowest-common-ancestor-of-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0236-lowest-common-ancestor-of-a-binary-tree/images/) | Verified |
| 239 | [Sliding Window Maximum](../Arrays/0239-sliding-window-maximum/README.md) | Arrays | 2 | [images/](../Arrays/0239-sliding-window-maximum/images/) | Verified |
| 242 | [Valid Anagram](../Arrays/0242-valid-anagram/README.md) | Arrays | 1 | [images/](../Arrays/0242-valid-anagram/images/) | Verified |
| 279 | [Perfect Squares](../DynamicProgramming/0279-perfect-squares/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0279-perfect-squares/images/) | Verified |
| 300 | [Longest Increasing Subsequence](../DynamicProgramming/0300-longest-increasing-subsequence/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0300-longest-increasing-subsequence/images/) | Verified |
| 322 | [Coin Change](../DynamicProgramming/0322-coin-change/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/0322-coin-change/images/) | Verified |
| 347 | [Top K Frequent Elements](../Heaps/0347-top-k-frequent-elements/README.md) | Heaps | 2 | [images/](../Heaps/0347-top-k-frequent-elements/images/) | Verified |
| 365 | [Water and Jug Problem](../Graphs/0365-water-and-jug-problem/README.md) | Graphs | 2 | [images/](../Graphs/0365-water-and-jug-problem/images/) | Verified |
| 368 | [Largest Divisible Subset](../DynamicProgramming/0368-largest-divisible-subset/README.md) | DynamicProgramming | 3 | [images/](../DynamicProgramming/0368-largest-divisible-subset/images/) | Verified |
| 371 | [Sum of Two Integers](../BitManipulation/0371-sum-of-two-integers/README.md) | BitManipulation | 2 | [images/](../BitManipulation/0371-sum-of-two-integers/images/) | Verified |
| 378 | [Kth Smallest Element in a Sorted Matrix](../Heaps/0378-kth-smallest-element-in-a-sorted-matrix/README.md) | Heaps | 1 | [images/](../Heaps/0378-kth-smallest-element-in-a-sorted-matrix/images/) | Verified |
| 387 | [First Unique Character in a String](../Arrays/0387-first-unique-character-in-a-string/README.md) | Arrays | 1 | [images/](../Arrays/0387-first-unique-character-in-a-string/images/) | Verified |
| 433 | [Minimum Genetic Mutation](../Graphs/0433-minimum-genetic-mutation/README.md) | Graphs | 2 | [images/](../Graphs/0433-minimum-genetic-mutation/images/) | Verified |
| 450 | [Delete Node in a BST](../Trees/0450-delete-node-in-a-bst/README.md) | Trees | 2 | [images/](../Trees/0450-delete-node-in-a-bst/images/) | Verified |
| 493 | [Reverse Pairs](../Arrays/0493-reverse-pairs/README.md) | Arrays | 3 | [images/](../Arrays/0493-reverse-pairs/images/) | Verified |
| 494 | [Target Sum](../Backtracking/0494-target-sum/README.md) | Backtracking | 2 | [images/](../Backtracking/0494-target-sum/images/) | Verified |
| 503 | [Next Greater Element II](../Arrays/0503-next-greater-element-ii/README.md) | Arrays | 1 | [images/](../Arrays/0503-next-greater-element-ii/images/) | Verified |
| 513 | [Find Bottom Left Tree Value](../Trees/0513-find-bottom-left-tree-value/README.md) | Trees | 1 | [images/](../Trees/0513-find-bottom-left-tree-value/images/) | Verified |
| 515 | [Find Largest Value in Each Tree Row](../Trees/0515-find-largest-value-in-each-tree-row/README.md) | Trees | 1 | [images/](../Trees/0515-find-largest-value-in-each-tree-row/images/) | Verified |
| 516 | [Longest Palindromic Subsequence](../DynamicProgramming/0516-longest-palindromic-subsequence/README.md) | DynamicProgramming | 1 | [images/](../DynamicProgramming/0516-longest-palindromic-subsequence/images/) | Verified |
| 542 | [01 Matrix](../Graphs/0542-01-matrix/README.md) | Graphs | 2 | [images/](../Graphs/0542-01-matrix/images/) | Verified |
| 543 | [Diameter of Binary Tree](../Trees/0543-diameter-of-binary-tree/README.md) | Trees | 3 | [images/](../Trees/0543-diameter-of-binary-tree/images/) | Verified |
| 560 | [Subarray Sum Equals K](../Arrays/0560-subarray-sum-equals-k/README.md) | Arrays | 2 | [images/](../Arrays/0560-subarray-sum-equals-k/images/) | Verified |
| 572 | [Subtree of Another Tree](../Trees/0572-subtree-of-another-tree/README.md) | Trees | 1 | [images/](../Trees/0572-subtree-of-another-tree/images/) | Verified |
| 623 | [Add One Row to Tree](../Trees/0623-add-one-row-to-tree/README.md) | Trees | 2 | [images/](../Trees/0623-add-one-row-to-tree/images/) | Verified |
| 652 | [Find Duplicate Subtrees](../Trees/0652-find-duplicate-subtrees/README.md) | Trees | 2 | [images/](../Trees/0652-find-duplicate-subtrees/images/) | Verified |
| 662 | [Maximum Width of Binary Tree](../Trees/0662-maximum-width-of-binary-tree/README.md) | Trees | 1 | [images/](../Trees/0662-maximum-width-of-binary-tree/images/) | Verified |
| 684 | [Redundant Connection](../Graphs/0684-redundant-connection/README.md) | Graphs | 2 | [images/](../Graphs/0684-redundant-connection/images/) | Verified |
| 703 | [Kth Largest Element in a Stream](../Heaps/0703-kth-largest-element-in-a-stream/README.md) | Heaps | 1 | [images/](../Heaps/0703-kth-largest-element-in-a-stream/images/) | Verified |
| 733 | [Flood Fill](../Graphs/0733-flood-fill/README.md) | Graphs | 1 | [images/](../Graphs/0733-flood-fill/images/) | Verified |
| 743 | [Network Delay Time](../Graphs/0743-network-delay-time/README.md) | Graphs | 2 | [images/](../Graphs/0743-network-delay-time/images/) | Verified |
| 783 | [Minimum Distance Between BST Nodes](../Trees/0783-minimum-distance-between-bst-nodes/README.md) | Trees | 1 | [images/](../Trees/0783-minimum-distance-between-bst-nodes/images/) | Verified |
| 785 | [Is Graph Bipartite?](../Graphs/0785-is-graph-bipartite/README.md) | Graphs | 1 | [images/](../Graphs/0785-is-graph-bipartite/images/) | Verified |
| 787 | [Cheapest Flights Within K Stops](../Graphs/0787-cheapest-flights-within-k-stops/README.md) | Graphs | 2 | [images/](../Graphs/0787-cheapest-flights-within-k-stops/images/) | Verified |
| 797 | [All Paths From Source to Target](../Graphs/0797-all-paths-from-source-to-target/README.md) | Graphs | 1 | [images/](../Graphs/0797-all-paths-from-source-to-target/images/) | Verified |
| 814 | [Binary Tree Pruning](../Trees/0814-binary-tree-pruning/README.md) | Trees | 2 | [images/](../Trees/0814-binary-tree-pruning/images/) | Verified |
| 841 | [Keys and Rooms](../Graphs/0841-keys-and-rooms/README.md) | Graphs | 1 | [images/](../Graphs/0841-keys-and-rooms/images/) | Verified |
| 863 | [All Nodes Distance K in Binary Tree](../Trees/0863-all-nodes-distance-k-in-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0863-all-nodes-distance-k-in-binary-tree/images/) | Verified |
| 872 | [Leaf-Similar Trees](../Trees/0872-leaf-similar-trees/README.md) | Trees | 1 | [images/](../Trees/0872-leaf-similar-trees/images/) | Verified |
| 886 | [Possible Bipartition](../Graphs/0886-possible-bipartition/README.md) | Graphs | 2 | [images/](../Graphs/0886-possible-bipartition/images/) | Verified |
| 947 | [Most Stones Removed with Same Row or Column](../Graphs/0947-most-stones-removed-with-same-row-or-column/README.md) | Graphs | 2 | [images/](../Graphs/0947-most-stones-removed-with-same-row-or-column/images/) | Verified |
| 951 | [Flip Equivalent Binary Trees](../Trees/0951-flip-equivalent-binary-trees/README.md) | Trees | 2 | [images/](../Trees/0951-flip-equivalent-binary-trees/images/) | Verified |
| 958 | [Check Completeness of a Binary Tree](../Trees/0958-check-completeness-of-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0958-check-completeness-of-a-binary-tree/images/) | Verified |
| 979 | [Distribute Coins in Binary Tree](../Trees/0979-distribute-coins-in-binary-tree/README.md) | Trees | 2 | [images/](../Trees/0979-distribute-coins-in-binary-tree/images/) | Verified |
| 988 | [Smallest String Starting From Leaf](../Trees/0988-smallest-string-starting-from-leaf/README.md) | Trees | 2 | [images/](../Trees/0988-smallest-string-starting-from-leaf/images/) | Verified |
| 990 | [Satisfiability of Equality Equations](../Graphs/0990-satisfiability-of-equality-equations/README.md) | Graphs | 1 | [images/](../Graphs/0990-satisfiability-of-equality-equations/images/) | Verified |
| 994 | [Rotting Oranges](../Graphs/0994-rotting-oranges/README.md) | Graphs | 2 | [images/](../Graphs/0994-rotting-oranges/images/) | Verified |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](../Trees/1008-construct-binary-search-tree-from-preorder-traversal/README.md) | Trees | 1 | [images/](../Trees/1008-construct-binary-search-tree-from-preorder-traversal/images/) | Verified |
| 1026 | [Maximum Difference Between Node and Ancestor](../Trees/1026-maximum-difference-between-node-and-ancestor/README.md) | Trees | 2 | [images/](../Trees/1026-maximum-difference-between-node-and-ancestor/images/) | Verified |
| 1038 | [Binary Search Tree to Greater Sum Tree](../Trees/1038-binary-search-tree-to-greater-sum-tree/README.md) | Trees | 1 | [images/](../Trees/1038-binary-search-tree-to-greater-sum-tree/images/) | Verified |
| 1048 | [Longest String Chain](../DynamicProgramming/1048-longest-string-chain/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1048-longest-string-chain/images/) | Verified |
| 1061 | [Lexicographically Smallest Equivalent String](../Graphs/1061-lexicographically-smallest-equivalent-string/README.md) | Graphs | 2 | [images/](../Graphs/1061-lexicographically-smallest-equivalent-string/images/) | Verified |
| 1091 | [Shortest Path in Binary Matrix](../Graphs/1091-shortest-path-in-binary-matrix/README.md) | Graphs | 3 | [images/](../Graphs/1091-shortest-path-in-binary-matrix/images/) | Verified |
| 1092 | [Shortest Common Supersequence](../DynamicProgramming/1092-shortest-common-supersequence/README.md) | DynamicProgramming | 3 | [images/](../DynamicProgramming/1092-shortest-common-supersequence/images/) | Verified |
| 1110 | [Delete Nodes And Return Forest](../Trees/1110-delete-nodes-and-return-forest/README.md) | Trees | 2 | [images/](../Trees/1110-delete-nodes-and-return-forest/images/) | Verified |
| 1161 | [Maximum Level Sum of a Binary Tree](../Trees/1161-maximum-level-sum-of-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1161-maximum-level-sum-of-a-binary-tree/images/) | Verified |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](../Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/README.md) | Backtracking | 2 | [images/](../Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/images/) | Verified |
| 1261 | [Find Elements in a Contaminated Binary Tree](../Trees/1261-find-elements-in-a-contaminated-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1261-find-elements-in-a-contaminated-binary-tree/images/) | Verified |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](../DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/images/) | Verified |
| 1319 | [Number of Operations to Make Network Connected](../Graphs/1319-number-of-operations-to-make-network-connected/README.md) | Graphs | 2 | [images/](../Graphs/1319-number-of-operations-to-make-network-connected/images/) | Verified |
| 1325 | [Delete Leaves With a Given Value](../Trees/1325-delete-leaves-with-a-given-value/README.md) | Trees | 2 | [images/](../Trees/1325-delete-leaves-with-a-given-value/images/) | Verified |
| 1334 | [Find the City With the Smallest Number of Neighbors at a Threshold Distance](../Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/README.md) | Graphs | 2 | [images/](../Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/images/) | Verified |
| 1335 | [Minimum Difficulty of a Job Schedule](../DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/images/) | Verified |
| 1339 | [Maximum Product of Splitted Binary Tree](../Trees/1339-maximum-product-of-splitted-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1339-maximum-product-of-splitted-binary-tree/images/) | Verified |
| 1361 | [Validate Binary Tree Nodes](../Trees/1361-validate-binary-tree-nodes/README.md) | Trees | 2 | [images/](../Trees/1361-validate-binary-tree-nodes/images/) | Verified |
| 1367 | [Linked List in Binary Tree](../Trees/1367-linked-list-in-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1367-linked-list-in-binary-tree/images/) | Verified |
| 1392 | [Longest Happy Prefix](../Arrays/1392-longest-happy-prefix/README.md) | Arrays | 2 | [images/](../Arrays/1392-longest-happy-prefix/images/) | Verified |
| 1420 | [Build Array Where You Can Find The Maximum Exactly K Comparisons](../DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/images/) | Verified |
| 1443 | [Minimum Time to Collect All Apples in a Tree](../Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/README.md) | Trees | 3 | [images/](../Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/images/) | Verified |
| 1457 | [Pseudo-Palindromic Paths in a Binary Tree](../Trees/1457-pseudo-palindromic-paths-in-a-binary-tree/README.md) | Trees | 2 | [images/](../Trees/1457-pseudo-palindromic-paths-in-a-binary-tree/images/) | Verified |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](../Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/README.md) | Trees | 2 | [images/](../Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/images/) | Verified |
| 1547 | [Minimum Cost to Cut a Stick](../DynamicProgramming/1547-minimum-cost-to-cut-a-stick/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1547-minimum-cost-to-cut-a-stick/images/) | Verified |
| 1569 | [Number of Ways to Reorder Array to Get Same BST](../Trees/1569-number-of-ways-to-reorder-array-to-get-same-bst/README.md) | Trees | 3 | [images/](../Trees/1569-number-of-ways-to-reorder-array-to-get-same-bst/images/) | Verified |
| 1594 | [Maximum Non Negative Product in a Matrix](../DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/images/) | Verified |
| 1609 | [Even Odd Tree](../Trees/1609-even-odd-tree/README.md) | Trees | 2 | [images/](../Trees/1609-even-odd-tree/images/) | Verified |
| 1631 | [Path With Minimum Effort](../Graphs/1631-path-with-minimum-effort/README.md) | Graphs | 3 | [images/](../Graphs/1631-path-with-minimum-effort/images/) | Verified |
| 1911 | [Maximum Alternating Subsequence Sum](../DynamicProgramming/1911-maximum-alternating-subsequence-sum/README.md) | DynamicProgramming | 2 | [images/](../DynamicProgramming/1911-maximum-alternating-subsequence-sum/images/) | Verified |
| 1926 | [Nearest Exit from Entrance in Maze](../Graphs/1926-nearest-exit-from-entrance-in-maze/README.md) | Graphs | 1 | [images/](../Graphs/1926-nearest-exit-from-entrance-in-maze/images/) | Verified |
| 1932 | [Merge BSTs to Create Single BST](../Trees/1932-merge-bsts-to-create-single-bst/README.md) | Trees | 3 | [images/](../Trees/1932-merge-bsts-to-create-single-bst/images/) | Verified |
| 1971 | [Find if Path Exists in Graph](../Graphs/1971-find-if-path-exists-in-graph/README.md) | Graphs | 2 | [images/](../Graphs/1971-find-if-path-exists-in-graph/images/) | Verified |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](../DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/README.md) | DynamicProgramming | 3 | [images/](../DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/images/) | Verified |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](../BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/README.md) | BinarySearch | 2 | [images/](../BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/images/) | Verified |
| 2196 | [Create Binary Tree From Descriptions](../Trees/2196-create-binary-tree-from-descriptions/README.md) | Trees | 2 | [images/](../Trees/2196-create-binary-tree-from-descriptions/images/) | Verified |
| 2246 | [Longest Path With Different Adjacent Characters](../Trees/2246-longest-path-with-different-adjacent-characters/README.md) | Trees | 2 | [images/](../Trees/2246-longest-path-with-different-adjacent-characters/images/) | Verified |
| 2265 | [Count Nodes Equal to Average of Subtree](../Trees/2265-count-nodes-equal-to-average-of-subtree/README.md) | Trees | 2 | [images/](../Trees/2265-count-nodes-equal-to-average-of-subtree/images/) | Verified |
| 2316 | [Count Unreachable Pairs of Nodes in an Undirected Graph](../Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/README.md) | Graphs | 2 | [images/](../Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/images/) | Verified |
| 2359 | [Find Closest Node to Given Two Nodes](../Graphs/2359-find-closest-node-to-given-two-nodes/README.md) | Graphs | 2 | [images/](../Graphs/2359-find-closest-node-to-given-two-nodes/images/) | Verified |
| 2385 | [Amount of Time for Binary Tree to Be Infected](../Trees/2385-amount-of-time-for-binary-tree-to-be-infected/README.md) | Trees | 2 | [images/](../Trees/2385-amount-of-time-for-binary-tree-to-be-infected/images/) | Verified |
| 2415 | [Reverse Odd Levels of Binary Tree](../Trees/2415-reverse-odd-levels-of-binary-tree/README.md) | Trees | 2 | [images/](../Trees/2415-reverse-odd-levels-of-binary-tree/images/) | Verified |
| 2421 | [Number of Good Paths](../Graphs/2421-number-of-good-paths/README.md) | Graphs | 3 | [images/](../Graphs/2421-number-of-good-paths/images/) | Verified |
| 2458 | [Height of Binary Tree After Subtree Removal Queries](../Trees/2458-height-of-binary-tree-after-subtree-removal-queries/README.md) | Trees | 3 | [images/](../Trees/2458-height-of-binary-tree-after-subtree-removal-queries/images/) | Verified |
| 2471 | [Minimum Number of Operations to Sort a Binary Tree by Level](../Trees/2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level/README.md) | Trees | 2 | [images/](../Trees/2471-minimum-number-of-operations-to-sort-a-binary-tree-by-level/images/) | Verified |
| 2492 | [Minimum Score of a Path Between Two Cities](../Graphs/2492-minimum-score-of-a-path-between-two-cities/README.md) | Graphs | 2 | [images/](../Graphs/2492-minimum-score-of-a-path-between-two-cities/images/) | Verified |
| 2596 | [Check Knight Tour Configuration](../Graphs/2596-check-knight-tour-configuration/README.md) | Graphs | 1 | [images/](../Graphs/2596-check-knight-tour-configuration/images/) | Verified |
| 2916 | [Subarrays Distinct Element Sum of Squares II](../Trees/2916-subarrays-distinct-element-sum-of-squares-ii/README.md) | Trees | 3 | [images/](../Trees/2916-subarrays-distinct-element-sum-of-squares-ii/images/) | Verified |
| 3286 | [Find a Safe Walk Through a Grid](../Graphs/3286-find-a-safe-walk-through-a-grid/README.md) | Graphs | 2 | [images/](../Graphs/3286-find-a-safe-walk-through-a-grid/images/) | Verified |
| 3551 | [Minimum Swaps to Sort by Digit Sum](../Arrays/3551-minimum-swaps-to-sort-by-digit-sum/README.md) | Arrays | 2 | [images/](../Arrays/3551-minimum-swaps-to-sort-by-digit-sum/images/) | Verified |
| 3886 | [Sum of Sortable Integers](../Math/3886-sum-of-sortable-integers/README.md) | Math | 4 | [images/](../Math/3886-sum-of-sortable-integers/images/) | Verified |

## Unmatched images

These remain in the source folder and are never attached by similarity. The four numbered pages require title/identity review and have no verified existing eligible folder. General algorithm notes and unrelated images have no unique LeetCode identity.

| Source filename | Reason |
|---|---|
| `3863-Min-Op-to-Sort-String-Part-I.jpg` | Unverified abbreviated title for #3863; manual review required |
| `3863-Min-Op-to-Sort-String-Part-II.jpg` | Unverified abbreviated title for #3863; manual review required |
| `3942-Min-Op-to-Sort-Nums-Part-I.jpg` | Unverified abbreviated title for #3942; manual review required |
| `3942-Min-Op-to-Sort-Nums-Part-II.jpg` | Unverified abbreviated title for #3942; manual review required |
| `Dijkstra's Algorithm.jpg` | No unique exact or reviewed title match; manual review required |
| `Heap Sort Part-I.jpg` | No unique exact or reviewed title match; manual review required |
| `Heap Sort Part-II.jpg` | No unique exact or reviewed title match; manual review required |
| `IMG_20260619_123722.jpg` | No unique exact or reviewed title match; manual review required |
| `Merge Sort Part-I.jpg` | No unique exact or reviewed title match; manual review required |
| `Merge Sort Part-II.jpg` | No unique exact or reviewed title match; manual review required |
| `Prim's Agorithm Part-II.jpg` | No unique exact or reviewed title match; manual review required |
| `Prim's Algorithm Part-I.jpg` | No unique exact or reviewed title match; manual review required |
| `Prim's Algorithm Part-III.jpg` | No unique exact or reviewed title match; manual review required |
| `Resume Aman.png` | No unique exact or reviewed title match; manual review required |
| `SessClassDiagram.jpeg` | No unique exact or reviewed title match; manual review required |

## Changes in this task

- `tests/test_visual_solutions.py`: adds a real-repository regression check for all manifest identities, source/destination hashes, destination ownership, README links, duplicate headings and multipart order. The test works when original matched sources are absent in CI.
- `docs/visual-repository-audit.json`: refreshed complete inventory, paths, counts and validation evidence.
- `docs/visual-solution-audit.md`: refreshed report with all 150 problem mappings and 15 unmatched filenames.
- `docs/visual-solutions-maintenance.md`: corrected pending-source counts and documented the new regression check.
- Modified problem READMEs: none. New image directories: none. Production Python scripts: unchanged. GitHub Actions workflows: unchanged. Existing manifest and aliases: unchanged.

## Verification results

| Check | Result / executed evidence |
|---|---|
| Image matching | PASS: 261 published images agree with folder IDs, canonical README URLs, filenames and reviewed title mappings |
| Readme links | PASS: 261 relative embedded image links resolve |
| Multipart ordering | PASS: every published block matches sorted explicit part numbers; Roman and numeric fixtures executed |
| No duplicate images | PASS: 261 unique SHA-256 values and destinations |
| Existing cpp files preserved | PASS: all 272 tracked C++ files match baseline bytes and paths |
| Existing readme content preserved | PASS: all 265 tracked README files match baseline bytes |
| Idempotency | PASS: two full organizer --offline runs preserved all 1109 non-cache repository file bytes, paths and mtimes; 0 copies and README updates |
| Image integrity | PASS: all 261 source, destination and manifest SHA-256 values agree |
| Future automation | PASS: fixture tests for new images, pending images before future problems, resubmission preservation, deduplication and full organizer execution |
| Github actions validation | PASS locally: Ruby YAML parser and explicit assertions of triggers, permissions, concurrency, branch, no-op/loop guards and non-force push. Live run NOT VERIFIED |
| Regression tests | 77 passed; 1 existing loopback test skipped (sandbox prohibits socket binding); 78 discovered |
| Coderabbit review | NOT RUN: CLI 0.7.6 signed out; manual source review completed |
| Github rendering | NOT VERIFIED: local relative links and hashes validated; current GitHub rendering not established |

The full suite exercised strict #112/#113 separation, number/title conflicts, 01 Matrix handling, missing folders, future images, parts I/II/III/IV/10, missing initial parts, hash collisions, corrupt destinations, changed sources, preserved statements, resubmission, nested cleanup and source-folder exclusions. No simulated problem or image remains in the repository. A second isolated checkout containing only tracked files (no retained matched source originals) and a pending root #112 resubmission passed all 30 visual-integration tests. This checks compatibility with the workflow running tests before organization.

## Git and publication

Only the four task files listed above are included in the follow-up commit.
At audit time, Git reported 277 retained untracked files, all under
`LeetCode-Img-Soln/`. They comprise 261 already-integrated originals, 14 unsupported
files and two unrelated images, and are excluded from staging. Thirteen unmatched
solution images are already tracked. All originals remain local; duplicate
originals are not added to Git. After committing, expected status is zero tracked
changes and these 277 retained untracked source files.

The regular `git push origin HEAD:main` failed with
`Could not resolve host: github.com`. A follow-up `git fetch origin main` and
independent DNS lookup also failed. The follow-up commit is local only. Final
Git status has zero tracked changes and 277 intentionally retained untracked
source files; `main` is one commit ahead of its locally cached `origin/main`.
Remote reconciliation, successful publication, a live Actions run and current
rendered GitHub READMEs remain unverified. The web fetch returned an older cached
repository page, which is insufficient for live verification. No force push or
bypass of remote safeguards was used. Once DNS access is restored, fetch and
inspect the remote branch, reconcile any new work, rerun validation if needed,
and push normally.
