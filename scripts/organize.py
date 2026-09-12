#!/usr/bin/env python3
"""
Automated LeetCode Question Organizer
- Detects newly pushed questions at the root of the repository (format: \d{4}-*)
- Classifies them into the appropriate topic folder using LeetCode GraphQL / README tags
- Reorganizes directories using git mv
- Dynamically updates README.md (Dashboard, Repository Structure, and Problem Index)
- Updates stats.json
"""

import os
import re
import sys
import json
import shutil
import urllib.request
import subprocess

BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

TOPIC_CONFIG = [
    # (Folder, Display Name, Icon, Tag keywords)
    ("BinarySearch", "Binary Search", "🔍", ["binary search"]),
    ("Backtracking", "Backtracking", "🔄", ["backtracking"]),
    ("Trees", "Trees & Binary Search Trees", "🌳", ["tree", "binary tree", "binary search tree", "trie", "tree traversal"]),
    ("Graphs", "Graphs & BFS/DFS", "🕸️", [
        "graph", "breadth-first search", "depth-first search", "union find", 
        "union-find", "disjoint set", "topological sort", "shortest path", 
        "bipartite", "eulerian circuit", "minimum spanning tree"
    ]),
    ("DynamicProgramming", "Dynamic Programming", "🧩", ["dynamic programming", "memoization", "knapsack"]),
    ("Heaps", "Heaps & Priority Queues", "⛰️", ["heap (priority queue)", "heap", "priority queue", "quickselect"]),
    ("Greedy", "Greedy Algorithms", "💡", ["greedy"]),
    ("BitManipulation", "Bit Manipulation", "⚡", ["bit manipulation", "bitmask"]),
    ("Math", "Math & Number Theory", "🔢", ["math", "number theory", "combinatorics", "geometry", "probability and statistics"]),
    ("Arrays", "Arrays & Hashing", "📦", [
        "array", "hash table", "matrix", "two pointers", "sliding window", 
        "prefix sum", "sorting", "counting", "string"
    ]),
]

PATTERN_CATEGORIES = [
    {
        "id": "two-pointers",
        "keywords": ['two pointers', 'two pointer'],
        "title": "Two Pointers (Converging & Parallel)",
        "icon": "👉👈",
        "concept": "Navigating sequences from opposite ends or at varying offsets to eliminate quadratic search spaces into $O(n)$ time with $O(1)$ auxiliary space.",
        "when_to_use": "Sorted arrays, palindrome verification, partition pivots (Dutch National Flag), and in-place reversal/compression.",
        "questions": [
            ("0001-two-sum", "Hash map complement lookup or sorted two-pointer sweep"),
            ("0015-3sum", "Sorting array + fixing first element + converging two-pointer scan with duplicate pruning"),
            ("0018-4sum", "Generalized k-sum: two fixed loops + inner two-pointer converging search"),
            ("0031-next-permutation", "Identify first decreasing pivot from right, swap with successor, reverse suffix via two pointers"),
            ("0075-sort-colors", "Dutch National Flag algorithm: 3-pointer partition (low, mid, high) in a single pass"),
            ("0088-merge-sorted-array", "Three pointers placing largest elements backwards from the end"),
            ("0125-valid-palindrome", "Left and right pointers converging inward while skipping non-alphanumeric characters"),
            ("0151-reverse-words-in-a-string", "Two-pointer string token reversal and in-place whitespace compaction"),
            ("0344-reverse-string", "Left and right pointers swapping mirror elements towards the center"),
            ("0443-string-compression", "Read/write two-pointer technique for in-place run-length encoding")
        ]
    },
    {
        "id": "sliding-window",
        "keywords": ['sliding window'],
        "title": "Sliding Window (Fixed & Minimum Window)",
        "icon": "🪟",
        "concept": "Maintaining a continuous window $[L, R]$ across an array or string. Expand the right boundary to satisfy target criteria, and shrink the left boundary to optimize or find the minimum feasible window.",
        "when_to_use": "Contiguous subarray/substring problems looking for maximum/minimum length, exact count, or minimum window satisfying character frequencies.",
        "questions": [
            ("0003-longest-substring-without-repeating-characters", "Dynamic window tracking character last-seen positions with hash map / frequency array"),
            ("0076-minimum-window-substring", "Classic minimum window sliding: expand $R$ until all characters match, then greedily contract $L$ to minimize window size"),
            ("0239-sliding-window-maximum", "Sliding window maintained by a monotonic decreasing deque for $O(1)$ window maximum retrieval"),
            ("0567-permutation-in-string", "Fixed-size sliding window of length $|s1|$ checking character frequency vector equality")
        ]
    },
    {
        "id": "fast-slow-pointers",
        "keywords": ['fast & slow', 'slow & fast', 'tortoise'],
        "title": "Fast & Slow Pointers (Floyd's Cycle Finding)",
        "icon": "🐢🐇",
        "concept": "Two pointers traversing sequences at different speeds ($1x$ vs $2x$). The relative distance between them changes by 1 each step, guaranteeing rendezvous if a cycle exists.",
        "when_to_use": "Detecting cycles in linked lists/arrays, finding loop entry points, determining linked list middle nodes without calculating length beforehand.",
        "questions": [
            ("0141-linked-list-cycle", "Floyd's cycle detection: fast and slow pointers meet if a cycle exists"),
            ("0142-linked-list-cycle-ii", "Meeting point reset: reset one pointer to head to find exact cycle origin node"),
            ("0234-palindrome-linked-list", "Fast/slow pointers to find list midpoint + reverse second half in-place + compare"),
            ("0287-find-the-duplicate-number", "Treating array indices and values as linked list nodes ($i \\to nums[i]$) to detect cycle entrance"),
            ("0876-middle-of-the-linked-list", "Fast pointer steps twice as fast; slow pointer lands on exact middle node")
        ]
    },
    {
        "id": "prefix-sum",
        "keywords": ['prefix sum', 'hash table', 'hash map'],
        "title": "Prefix Sum & Frequency Maps",
        "icon": "📊",
        "concept": "Precomputing cumulative prefixes or tracking element frequencies in hash maps to answer range queries and detect subarray conditions in $O(1)$ amortized time.",
        "when_to_use": "Subarray sum equals $k$, range sum caching, anagram grouping, frequency parity checks, and majority voting.",
        "questions": [
            ("0049-group-anagrams", "Categorize strings by canonical sorted key or 26-character frequency signature"),
            ("0169-majority-element", "Boyer-Moore Voting Algorithm: tracking candidate and net score in $O(1)$ auxiliary space"),
            ("0242-valid-anagram", "Fixed 26-character frequency count matching between two strings"),
            ("0387-first-unique-character-in-a-string", "Two-pass frequency mapping to detect first element with frequency 1"),
            ("0560-subarray-sum-equals-k", "Prefix sum array paired with hash map of prefix frequencies: find count of $(prefix - k)$ in $O(n)$"),
            ("1594-maximum-non-negative-product-in-a-matrix", "Prefix state matrix tracking both minimum (negative) and maximum products"),
            ("2965-find-missing-and-repeated-values", "Frequency array / mathematical sum and square-sum formulas to pinpoint missing and duplicate numbers")
        ]
    },
    {
        "id": "monotonic-stack-queue",
        "keywords": ['monotonic stack', 'monotonic queue', 'next greater'],
        "title": "Monotonic Stack & Monotonic Queue",
        "icon": "🥞",
        "concept": "Maintaining elements in strictly ascending or descending order within a stack or deque. Eliminates sub-optimal candidates upon element arrival, resolving range bounds in amortized $O(n)$ total time.",
        "when_to_use": "Next/Previous Greater or Smaller elements, largest rectangular areas in histograms, sliding window maximums.",
        "questions": [
            ("0084-largest-rectangle-in-histogram", "Monotonic increasing stack tracking left and right boundaries for every bar in $O(n)$"),
            ("0496-next-greater-element-i", "Monotonic decreasing stack caching next greater element for each array value"),
            ("0503-next-greater-element-ii", "Simulating circular array traversal via double pass with monotonic decreasing stack"),
            ("0901-online-stock-span", "Monotonic stack storing consecutive lower prices and cumulative span weights")
        ]
    },
    {
        "id": "binary-search",
        "keywords": ['binary search'],
        "title": "Binary Search & Search Space Reduction",
        "icon": "🔍",
        "concept": "Dividing search space in half at each step in $O(\\log n)$. Extends beyond simple sorted array lookups to 'Binary Search on Answer' over monotonic predicate functions.",
        "when_to_use": "Sorted or rotated arrays, 2D matrix searches, finding boundaries, minimax/maximin allocation optimization.",
        "questions": [
            ("0033-search-in-rotated-sorted-array", "Identifying which half is sorted to discard the other half in $O(\\log n)$"),
            ("0074-search-a-2d-matrix", "Standard binary search treating row-major 2D matrix as virtual flattened 1D array"),
            ("0240-search-a-2d-matrix-ii", "Pruning search space starting from top-right corner using matrix row/col monotonicity"),
            ("0378-kth-smallest-element-in-a-sorted-matrix", "Binary search on value range with $O(n)$ row/col monotonic count subroutine"),
            ("0410-split-array-largest-sum", "Binary search on answer domain $[\\max(nums), \\sum(nums)]$ with greedy chunk validator"),
            ("0493-reverse-pairs", "Modified merge sort divide & conquer with cross-half two-pointer reverse pair counting"),
            ("0540-single-element-in-a-sorted-array", "Binary search checking parity invariants of identical element pairs"),
            ("0704-binary-search", "Canonical binary search template with safe midpoint calculation `left + (right - left) / 2`"),
            ("0852-peak-index-in-a-mountain-array", "Binary search on gradient slope checking $nums[mid] < nums[mid + 1]$"),
            ("2064-minimized-maximum-of-products-distributed-to-any-store", "Binary search on answer for minimum store product distribution quota")
        ]
    },
    {
        "id": "backtracking",
        "keywords": ['backtracking'],
        "title": "Backtracking & State-Space Search",
        "icon": "🔄",
        "concept": "Exhaustive exploration of decision trees with early pruning. Constructs candidate states step-by-step and rolls back (backtracks) state immediately when constraints are violated.",
        "when_to_use": "Permutations, combinations, subsets, constraint satisfaction (Sudoku, N-Queens), and grid word searches.",
        "questions": [
            ("0037-sudoku-solver", "Row, column, and 3x3 box constraint validation with recursive digit placement and rollback"),
            ("0039-combination-sum", "Unbounded element reuse backtracking to match exact remaining sum"),
            ("0040-combination-sum-ii", "Sorted array backtracking with duplicate sibling branch pruning for unique combinations"),
            ("0046-permutations", "Generating all $n!$ permutations using visited markers or in-place element swaps"),
            ("0051-n-queens", "Bitmask / boolean set tracking of safe columns and 45° / 135° diagonals"),
            ("0078-subsets", "Power set generation via cascading pick / don't pick binary decision tree"),
            ("0079-word-search", "2D grid DFS matching characters with in-place cell masking and unmasking"),
            ("0090-subsets-ii", "Generating unique subsets from arrays with duplicates by sorting and skipping identical elements"),
            ("0131-palindrome-partitioning", "Backtracking substring partitions with palindrome validation memoization"),
            ("0494-target-sum", "Branching $+/-$ decision tree transformed to 0-1 knapsack subset sum"),
            ("1239-maximum-length-of-a-concatenated-string-with-unique-characters", "Bitmask tracking of unique characters across recursive subset combinations"),
            ("2596-check-knight-tour-configuration", "Sequential coordinate step validation verifying knight move deltas")
        ]
    },
    {
        "id": "tree-traversals",
        "keywords": ['tree', 'binary tree', 'binary search tree', 'trie'],
        "title": "Tree Traversals, Construction & Tree DP",
        "icon": "🌳",
        "concept": "Recursive DFS (preorder, inorder, postorder) and BFS (level-order) on hierarchical structures. Aggregating subtree heights, diameters, and validating BST invariants.",
        "when_to_use": "Binary trees, BST queries/mutations, lowest common ancestor, path sum maximizations, and tree diameter.",
        "questions": [
            ("0014-longest-common-prefix", "Trie / vertical character scanning across string array"),
            ("0094-binary-tree-inorder-traversal", "Left-root-right DFS traversal with recursion and iterative stack"),
            ("0096-unique-binary-search-trees", "Catalan number dynamic programming for count of unique BST shapes"),
            ("0098-validate-binary-search-tree", "Inorder strict ascending check or propagating $(minVal, maxVal)$ ranges down subtrees"),
            ("0099-recover-binary-search-tree", "Detecting two swapped nodes using inorder traversal pointers in $O(1)$ space"),
            ("0100-same-tree", "Simultaneous structural and value equivalence check via recursive DFS"),
            ("0101-symmetric-tree", "Mirror reflection check comparing opposite outer and inner child subtrees"),
            ("0102-binary-tree-level-order-traversal", "Queue-based level-by-level BFS collecting node values per depth"),
            ("0103-binary-tree-zigzag-level-order-traversal", "Alternating direction level-order traversal using double-ended queues"),
            ("0105-construct-binary-tree-from-preorder-and-inorder-traversal", "Preorder identifies root; inorder split gives left and right subtree sizes"),
            ("0106-construct-binary-tree-from-inorder-and-postorder-traversal", "Postorder identifies root; inorder split gives subtree boundaries recursively"),
            ("0108-convert-sorted-array-to-binary-search-tree", "Midpoint divide-and-conquer to build height-balanced BST"),
            ("0110-balanced-binary-tree", "Bottom-up height calculation with early $-1$ exit on subtree height differential $> 1$"),
            ("0114-flatten-binary-tree-to-linked-list", "Rewiring right pointers to preorder sequence with Morris-like constant space traversal"),
            ("0116-populating-next-right-pointers-in-each-node", "Using established upper-level next pointers for $O(1)$ auxiliary space linkage"),
            ("0124-binary-tree-maximum-path-sum", "Postorder tree DP computing maximum non-negative branch gain and updating global sum"),
            ("0144-binary-tree-preorder-traversal", "Root-left-right recursive and iterative stack traversal"),
            ("0145-binary-tree-postorder-traversal", "Left-right-root postorder traversal with stack"),
            ("0173-binary-search-tree-iterator", "Controlled inorder traversal with push-all-left stack in $O(h)$ memory"),
            ("0199-binary-tree-right-side-view", "Level-order BFS picking last node or right-first DFS"),
            ("0230-kth-smallest-element-in-a-bst", "Inorder traversal stopping at $k$-th visited element"),
            ("0235-lowest-common-ancestor-of-a-binary-search-tree", "BST navigation branching based on split across node value"),
            ("0236-lowest-common-ancestor-of-a-binary-tree", "Postorder search bubbling up target nodes to first shared ancestor"),
            ("0450-delete-node-in-a-bst", "BST search and successor splicing upon removing two-child nodes"),
            ("0543-diameter-of-binary-tree", "Postorder depth calculation updating maximum left+right path"),
            ("0572-subtree-of-another-tree", "Recursive root matching with exact tree equivalence subroutine"),
            ("0662-maximum-width-of-binary-tree", "Zero-indexed heap-like coordinate tagging per level to prevent overflow"),
            ("0783-minimum-distance-between-bst-nodes", "Inorder traversal tracking running minimum difference between neighbors"),
            ("1008-construct-binary-search-tree-from-preorder-traversal", "Monotonic upper-bound recursive BST reconstruction in $O(n)$"),
            ("1038-binary-search-tree-to-greater-sum-tree", "Reverse inorder traversal (right-root-left) accumulating suffix sum"),
            ("1161-maximum-level-sum-of-a-binary-tree", "BFS level summation tracking index with maximum aggregate sum"),
            ("1443-minimum-time-to-collect-all-apples-in-a-tree", "Bottom-up DFS summing round-trip edge costs for apple-bearing subtrees"),
            ("1519-number-of-nodes-in-the-sub-tree-with-the-same-label", "Postorder 26-length frequency array merging from child subtrees"),
            ("1932-merge-bsts-to-create-single-bst", "BST root-leaf matching, cycle check, and global BST inorder validation"),
            ("2246-longest-path-with-different-adjacent-characters", "Tree DP returning longest branch and updating top-2 branch sum")
        ]
    },
    {
        "id": "graph-bfs",
        "keywords": ['breadth-first search'],
        "title": "Graph BFS & Multi-Source BFS",
        "icon": "🕸️",
        "concept": "Layer-by-layer exploration guaranteeing shortest paths in unweighted graphs or simulating simultaneous multi-source wave propagation.",
        "when_to_use": "Shortest path in unweighted graphs/grids, minimum step conversions, and simultaneous multi-point spread (fire, rot, infection).",
        "questions": [
            ("0433-minimum-genetic-mutation", "State graph BFS transforming gene strings one mutation at a time"),
            ("0542-01-matrix", "Multi-source BFS initialized with all zero cells computing distance outward"),
            ("0733-flood-fill", "Grid flood fill updating connected pixels of identical original color"),
            ("0994-rotting-oranges", "Multi-source BFS spreading rot layer-by-layer to adjacent fresh oranges"),
            ("1091-shortest-path-in-binary-matrix", "8-directional BFS in binary grid to find shortest path to bottom-right"),
            ("1926-nearest-exit-from-entrance-in-maze", "Queue BFS stepping through open cells to nearest perimeter boundary")
        ]
    },
    {
        "id": "graph-dfs",
        "keywords": ['depth-first search'],
        "title": "Graph DFS, Connectivity & Bipartite Graphs",
        "icon": "🗺️",
        "concept": "Deep recursive traversal across edges to discover connected components, cycle existence, and 2-colorability (bipartite graphs).",
        "when_to_use": "Connected components counting, island problems, graph coloring, all-paths enumeration.",
        "questions": [
            ("0133-clone-graph", "DFS/BFS with hash map mapping original nodes to cloned counterparts"),
            ("0200-number-of-islands", "Grid DFS sinking visited land components ('1' to '0')"),
            ("0785-is-graph-bipartite", "2-coloring graph using alternating color DFS to detect odd-length cycles"),
            ("0797-all-paths-from-source-to-target", "DAG DFS path tracking from source 0 to target $n-1$"),
            ("0841-keys-and-rooms", "DFS/BFS room reachability check starting from room 0"),
            ("0886-possible-bipartition", "Modeling dislikes as graph edges and checking 2-colorability"),
            ("1971-find-if-path-exists-in-graph", "BFS/DFS or DSU to verify path between source and destination")
        ]
    },
    {
        "id": "topological-sort",
        "keywords": ['topological sort'],
        "title": "Topological Sort (DAG Dependency Resolution)",
        "icon": "🧭",
        "concept": "Linearly ordering vertices of a Directed Acyclic Graph such that every directed edge $u \\to v$ has $u$ before $v$. Detects cycles when ordering is incomplete.",
        "when_to_use": "Course prerequisites, task compilation schedules, and cycle detection in directed graphs.",
        "questions": [
            ("0207-course-schedule", "Detecting directed cycles via Kahn's algorithm (in-degree queue) or 3-color DFS"),
            ("0210-course-schedule-ii", "Returning valid dependency resolution sequence via topological sort")
        ]
    },
    {
        "id": "disjoint-set-union",
        "keywords": ['union find', 'disjoint set', 'union-find'],
        "title": "Disjoint Set Union (DSU / Union-Find) & MST",
        "icon": "🔗",
        "concept": "Near $O(1)$ amortized operations (`find` with path compression, `union` by rank) to manage dynamic connectivity and find Minimum Spanning Trees (MST).",
        "when_to_use": "Dynamic connected components, cycle detection in undirected graphs, Kruskal's MST algorithm.",
        "questions": [
            ("0547-number-of-provinces", "Union-Find grouping directly connected cities into provinces"),
            ("0684-redundant-connection", "Finding edge whose endpoints already belong to same connected component"),
            ("0947-most-stones-removed-with-same-row-or-column", "Unifying stone rows and columns to count connected components"),
            ("0990-satisfiability-of-equality-equations", "Unifying equal variables and validating inequalities against components"),
            ("1061-lexicographically-smallest-equivalent-string", "DSU with root representing lexicographically smallest character"),
            ("1319-number-of-operations-to-make-network-connected", "Counting surplus edges vs number of disconnected components"),
            ("1584-min-cost-to-connect-all-points", "Kruskal's MST with DSU / Prim's greedy algorithm on complete graph"),
            ("2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph", "DSU component size calculation to compute non-connected node pairs"),
            ("2421-number-of-good-paths", "Sorting nodes by value and merging components with DSU incrementally")
        ]
    },
    {
        "id": "shortest-paths",
        "keywords": ['shortest path', 'dijkstra'],
        "title": "Shortest Paths in Weighted Graphs (Dijkstra & Relaxation)",
        "icon": "🚀",
        "concept": "Finding lowest-cost paths in non-negatively weighted graphs using priority queue relaxation (Dijkstra) or step-constrained relaxation (Bellman-Ford).",
        "when_to_use": "Minimum latency, lowest flight fare with stopover limits, minimum effort paths in elevation grids.",
        "questions": [
            ("0743-network-delay-time", "Standard Dijkstra algorithm using min-heap for single-source shortest paths"),
            ("0787-cheapest-flights-within-k-stops", "Bellman-Ford / layer-by-layer BFS with at most $k$ edge relaxations"),
            ("1631-path-with-minimum-effort", "Dijkstra on grid minimizing maximum adjacent height difference"),
            ("1976-number-of-ways-to-arrive-at-destination", "Dijkstra tracking shortest distances and DP path counts modulo $10^9+7$")
        ]
    },
    {
        "id": "dynamic-programming",
        "keywords": ['dynamic programming', 'memoization'],
        "title": "Dynamic Programming (1D, 2D Grid, String, Intervals & Partition)",
        "icon": "🧩",
        "concept": "Formulating recursive optimal substructure and caching overlapping subproblems. Transforms exponential brute-force searches into polynomial time.",
        "when_to_use": "Knapsack problems, longest common subsequences, minimum edit operations, matrix paths, partition optimization.",
        "questions": [
            ("0042-trapping-rain-water", "Prefix max and suffix max arrays or two-pointer space optimization"),
            ("0053-maximum-subarray", "Kadane's algorithm deciding whether to extend or start new subarray sum"),
            ("0062-unique-paths", "2D grid combinations $dp[i][j] = dp[i-1][j] + dp[i][j-1]$"),
            ("0063-unique-paths-ii", "Grid DP setting obstacle cells to 0 paths"),
            ("0072-edit-distance", "Levenshtein distance 2D DP for insert, delete, and replace operations"),
            ("0121-best-time-to-buy-and-sell-stock", "Single pass tracking running minimum price and maximum profit"),
            ("0132-palindrome-partitioning-ii", "1D DP for minimum cuts utilizing 2D palindrome lookup table"),
            ("0198-house-robber", "State transition $dp[i] = \\max(dp[i-1], dp[i-2] + nums[i])$"),
            ("0213-house-robber-ii", "Running House Robber I twice (excluding first or last house) for circularity"),
            ("0264-ugly-number-ii", "Generating ugly numbers in order via three pointers $(2, 3, 5)$"),
            ("0279-perfect-squares", "Unbounded knapsack style 1D DP or Lagrange's four-square theorem"),
            ("0300-longest-increasing-subsequence", "Classic $O(n^2)$ DP or $O(n \\log n)$ patience sorting with binary search"),
            ("0322-coin-change", "Unbounded knapsack DP computing minimum coins for amount"),
            ("0509-fibonacci-number", "Base recurrence with rolling variables for $O(1)$ space"),
            ("0516-longest-palindromic-subsequence", "2D interval DP comparing endpoints $s[i]$ and $s[j]$"),
            ("0646-maximum-length-of-pair-chain", "Sorting by end coordinates + greedy interval selection or LIS DP"),
            ("1143-longest-common-subsequence", "2D grid state tracking matched characters between two strings"),
            ("1335-minimum-difficulty-of-a-job-schedule", "Partition DP splitting tasks into $d$ contiguous daily intervals"),
            ("1547-minimum-cost-to-cut-a-stick", "Matrix Chain Multiplication / interval DP on sorted cut positions"),
            ("1911-maximum-alternating-subsequence-sum", "Two-state DP tracking maximum sum in even/odd position states"),
            ("2035-partition-array-into-two-arrays-to-minimize-sum-difference", "Meet-in-the-middle subset generation + binary search lower bound")
        ]
    },
    {
        "id": "greedy-intervals",
        "keywords": ['greedy', 'interval'],
        "title": "Greedy Algorithms & Interval Scheduling",
        "icon": "💡",
        "concept": "Making locally optimal decisions at every step that prove to yield a globally optimal solution.",
        "when_to_use": "Interval merging, activity selection, stock trading with unlimited transactions, circular fuel balance.",
        "questions": [
            ("0056-merge-intervals", "Sorting intervals by start time and extending merged boundaries"),
            ("0122-best-time-to-buy-and-sell-stock-ii", "Greedily summing all positive consecutive price differentials"),
            ("0134-gas-station", "Maintaining total balance and resetting start station on negative tank")
        ]
    },
    {
        "id": "heaps-priority-queues",
        "keywords": ['heap (priority queue)', 'heap', 'priority queue'],
        "title": "Heaps, Priority Queues & Top-K Elements",
        "icon": "⛰️",
        "concept": "Dynamically maintaining sorted extremes (min or max) in $O(\\log k)$ time, avoiding full array sorting.",
        "when_to_use": "Finding $k$-th largest/smallest elements, streaming median, continuous ranking.",
        "questions": [
            ("0215-kth-largest-element-in-an-array", "Min-heap of size $k$ or Quickselect for $O(n)$ average selection"),
            ("0347-top-k-frequent-elements", "Frequency map + min-heap or $O(n)$ bucket sort on counts"),
            ("0703-kth-largest-element-in-a-stream", "Min-heap storing top $k$ elements; root holds $k$-th largest"),
            ("0912-sort-an-array", "Max-heap sort / divide-and-conquer sorting algorithms")
        ]
    },
    {
        "id": "linked-list-manipulation",
        "keywords": ['linked list'],
        "title": "Linked List Pointer Surgery & In-Place Reversal",
        "icon": "🪢",
        "concept": "Carefully manipulating node pointers (`next`, `prev`), dummy heads, and local segment reversals with zero node copying in $O(1)$ memory.",
        "when_to_use": "In-place list reversal, k-group reversal, cycle redirection, LRU cache memory structures.",
        "questions": [
            ("0021-merge-two-sorted-lists", "Dummy head pointer splicing two sorted lists iteratively"),
            ("0024-swap-nodes-in-pairs", "Pairwise next-pointer swap using pre-node tracker"),
            ("0025-reverse-nodes-in-k-group", "Reversing groups of $k$ nodes in-place while keeping remaining list intact"),
            ("0061-rotate-list", "Forming circle by connecting tail to head, then cutting at $(len - k \\% len)$"),
            ("0092-reverse-linked-list-ii", "In-place pointer reversal for subsegment between positions left and right"),
            ("0138-copy-list-with-random-pointer", "Interweaving cloned nodes between originals for $O(1)$ extra space copy"),
            ("0146-lru-cache", "Doubly linked list (for $O(1)$ eviction) coupled with hash map lookup"),
            ("0206-reverse-linked-list", "Canonical 3-pointer (`prev`, `curr`, `next`) list reversal"),
            ("0430-flatten-a-multilevel-doubly-linked-list", "DFS traversal splicing child doubly linked lists between current and next")
        ]
    },
    {
        "id": "matrix-manipulation",
        "keywords": ['matrix'],
        "title": "Matrix Traversal & In-Place State Manipulation",
        "icon": "🔲",
        "concept": "Simulating 2D boundary contractions and utilizing grid cells themselves as state markers for $O(1)$ auxiliary space.",
        "when_to_use": "Layer-by-layer spiral peeling, in-place matrix zeroing without additional memory arrays.",
        "questions": [
            ("0054-spiral-matrix", "4-boundary pointer shrinkage (top, bottom, left, right) peeling matrix layers in clockwise order"),
            ("0073-set-matrix-zeroes", "Using first row and column as in-place $O(1)$ memory zero-marker flags")
        ]
    },
    {
        "id": "bit-manipulation-math",
        "keywords": ['bit manipulation', 'math', 'number theory'],
        "title": "Bit Manipulation, Stacks & Mathematical Simulation",
        "icon": "⚡",
        "concept": "Bitwise masks, arithmetic simulation, LIFO stack matching, and number-theoretic properties.",
        "when_to_use": "Binary bit checking, power-of-two tests, binary exponentiation, arithmetic without library tricks.",
        "questions": [
            ("0002-add-two-numbers", "Simulating elementary grade-school addition with carry across linked lists"),
            ("0020-valid-parentheses", "Stack LIFO bracket matching for opening and closing symbols"),
            ("0050-powx-n", "Binary exponentiation reducing power calculation to $O(\\log n)$"),
            ("0155-min-stack", "Stack paired with secondary min-tracking stack for $O(1)$ getMin"),
            ("0225-implement-stack-using-queues", "Simulating LIFO behavior using queue rotations"),
            ("0231-power-of-two", "Bitwise check `n > 0 && (n & (n - 1)) == 0`"),
            ("0232-implement-queue-using-stacks", "FIFO queue simulation with input and output stacks amortized $O(1)$"),
            ("0263-ugly-number", "Repeated trial division by prime factors 2, 3, and 5"),
            ("0326-power-of-three", "Trial division or max integer power of three modulo check"),
            ("0342-power-of-four", "Power of two check combined with bit position mask `0x55555555`"),
            ("1392-longest-happy-prefix", "KMP Longest Proper Prefix which is also Suffix (LPS array) computation"),
            ("1910-remove-all-occurrences-of-a-substring", "Stack-based or string buffer matching and popping target substring"),
            ("2073-time-needed-to-buy-tickets", "Direct single-pass calculation of tickets processed before position $k$")
        ]
    }
]

def build_curation_section():
    return """## 🎯 Intentional Curation: Why These Aren't Random Questions

> **"Don't practice until you get it right. Practice until you can't get it wrong."**

Many developers approach LeetCode as a brute numbers game, indiscriminately grinding hundreds of arbitrary problems without developing transferable intuition. **This repository follows an intentional, blueprint-driven strategy.**

### 🔍 The Core Philosophy: Pattern Recognition > Rote Memorization
Technical interviews at top-tier product engineering companies (FAANG/MANG, unicorns, high-frequency trading firms) evaluate **underlying algorithmic intuition**, not your ability to recall a specific question's gimmick.

Every problem in this repository has been hand-selected from battle-tested technical interview roadmaps—most notably **NeetCode 150**, **Striver's SDE Sheet**, **Blind 75**, and **Grind 75**. These problems were deliberately chosen because they serve as **canonical archetypes**:

| Architectural Pillar | Implementation & Philosophy in this Repository |
|:---|:---|
| 🧱 **Foundational Archetypes** | Each question establishes a fundamental mental model (e.g., shrinking/expanding window invariants, monotonic boundary elimination, tree state bubbling, bipartite 2-coloring). Mastering one archetype unlocks an entire family of 20+ interview variations. |
| 🔄 **Multi-Approach Progression** | Solutions are not just single accepted snippets. Where instructional, solutions explore progressive evolution: **Brute Force $\\to$ Better $\\to$ Optimal Time/Space**, explicitly analyzing algorithmic tradeoffs and runtime complexities. |
| 🛡️ **Edge-Case Hardening** | Every implementation is tested and documented against edge cases: zero/single element structures, integer overflow boundaries ($2^{31}-1$), negative coordinates, cyclic dependencies, and disjoint graphs. |
| 📈 **High-Yield Retention** | Deeply mastering ~170 core pattern archetypes produces drastically higher problem-solving speed, confidence, and adaptability than shallowly skimming 1,000+ random problems. |

---"""

def build_approaches_section(q_map, old_readme=""):
    parts = []
    parts.append("## 🧩 Algorithmic Approaches & Patterns Directory\n")
    parts.append("To make revision structured and interview preparation fast, every question is indexed below according to its **underlying algorithmic approach and technique** (such as Two Pointers, Minimum Window Sliding, Fast & Slow Pointers, Monotonic Stack, etc.).\n")
    
    # Quick nav
    nav_links = []
    for cat in PATTERN_CATEGORIES:
        nav_links.append(f"[{cat['icon']} {cat['title'].split('(')[0].strip()}](#-{cat['id']})")
    parts.append("> **Quick Navigation:** " + " • ".join(nav_links) + "\n")
    
    # Track all questions already curated in static definitions
    curated_assigned = set()
    for cat in PATTERN_CATEGORIES:
        for q_dir, _ in cat.get("questions", []):
            curated_assigned.add(q_dir)

    # Dynamic classification for newly added questions
    dynamic_additions = {cat["id"]: [] for cat in PATTERN_CATEGORIES}
    folder_to_cat = {
        "binarysearch": "binary-search",
        "backtracking": "backtracking",
        "trees": "tree-traversals",
        "graphs": "graph-dfs",
        "dynamicprogramming": "dynamic-programming",
        "heaps": "heaps-priority-queues",
        "greedy": "greedy-intervals",
        "bitmanipulation": "bit-manipulation-math",
        "math": "bit-manipulation-math",
        "arrays": "two-pointers"
    }

    for q_dir, q_info in q_map.items():
        if q_dir not in curated_assigned:
            target_cat_id = None
            q_tags = get_tags_from_readme(q_dir, old_readme)
            tags_str = " ".join(q_tags).lower()
            for cat in PATTERN_CATEGORIES:
                kws = cat.get("keywords", [])
                if any(kw in tags_str for kw in kws):
                    target_cat_id = cat["id"]
                    break
            if not target_cat_id:
                target_cat_id = folder_to_cat.get(q_info.get("topic_folder", "").lower(), "two-pointers")
            
            dynamic_additions[target_cat_id].append((q_dir, f"Canonical {q_info.get('topic_display', 'DSA')} problem"))

    for cat in PATTERN_CATEGORIES:
        parts.append(f"<a id=\"-{cat['id']}\"></a>")
        parts.append(f"### {cat['icon']} {cat['title']}\n")
        parts.append(f"- **Core Intuition:** {cat['concept']}")
        parts.append(f"- **When to Apply:** {cat['when_to_use']}\n")
        parts.append("| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |")
        parts.append("|:---:|:---|:---:|:---|:---|")
        
        all_items = list(cat.get("questions", [])) + dynamic_additions.get(cat["id"], [])
        all_items.sort(key=lambda item: int(item[0].split("-")[0]) if item[0].split("-")[0].isdigit() else 9999)

        for q_dir, takeaway in all_items:
            q_info = q_map.get(q_dir)
            if not q_info:
                continue
            diff = q_info["difficulty"]
            if diff == "Easy":
                diff_badge = "🟢 `Easy`"
            elif diff == "Medium":
                diff_badge = "🟡 `Medium`"
            else:
                diff_badge = "🔴 `Hard`"
            parts.append(f"| {q_info['num']} | [{q_info['title']}]({q_info['lc_url']}) | {diff_badge} | {q_info['solution_link']} | {takeaway} |")
        parts.append("")
        
    return "\n".join(parts)
def fetch_leetcode_tags(title_slug):
    """Fetch official topic tags from LeetCode GraphQL API."""
    query = """
    query questionData($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        topicTags {
          name
          slug
        }
      }
    }
    """
    url = "https://leetcode.com/graphql"
    payload = json.dumps({"query": query, "variables": {"titleSlug": title_slug}}).encode("utf-8")
    req = urllib.request.Request(
        url,
        data=payload,
        headers={"Content-Type": "application/json", "User-Agent": "Mozilla/5.0"}
    )
    try:
        with urllib.request.urlopen(req, timeout=8) as response:
            data = json.loads(response.read().decode("utf-8"))
            tags = [t["name"].lower() for t in data.get("data", {}).get("question", {}).get("topicTags", [])]
            return tags
    except Exception as e:
        print(f"[Warning] Failed to fetch tags for {title_slug} from LeetCode API: {e}")
        return []

def get_tags_from_readme(q_dir_name, old_readme):
    """Fallback: extract topic tags from LeetHub table in root README.md."""
    topics = []
    current_topic = None
    for line in old_readme.splitlines():
        if line.startswith("## "):
            current_topic = line[3:].strip().lower()
        elif q_dir_name in line and current_topic:
            topics.append(current_topic)
    return topics

MULTI_APPROACH = os.getenv("MULTI_APPROACH", "true").lower() in ("true", "1", "yes")

CODE_EXTENSIONS = {
    ".cpp": "C++",
    ".cc": "C++",
    ".cxx": "C++",
    ".c": "C",
    ".py": "Python",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
    ".kt": "Kotlin",
    ".cs": "C#",
    ".swift": "Swift",
    ".rb": "Ruby",
    ".scala": "Scala",
    ".php": "PHP",
}

def extract_approach_title(code_content):
    """Extract approach description/title from comments in code."""
    if not code_content:
        return None
    patterns = [
        r"(?i)(?://|#)\s*(?:approach|solution|method|strategy)(?:[\s\-_]*(?:\d+))?\s*[:\-–—]\s*([^\r\n]+)",
        r"(?i)/\*\s*(?:approach|solution|method|strategy)(?:[\s\-_]*(?:\d+))?\s*[:\-–—]\s*(.+?)\*/",
    ]
    for pat in patterns:
        m = re.search(pat, code_content)
        if m:
            raw = m.group(1).strip()
            raw = re.sub(r"[\*\r\n]", "", raw).strip()
            raw = raw.strip("-:; ")
            if raw:
                return raw
    return None

def extract_approach_num(code_content):
    """Extract explicit approach number (e.g. Approach-1, Approach 2, Method-2) if specified in code comments."""
    if not code_content:
        return None
    m = re.search(r"(?i)(?://|#|/\*)\s*(?:approach|solution|method|strategy)[\s\-_:]*(\d+)", code_content)
    if m:
        return int(m.group(1))
    return None

def slugify_approach(approach_title, max_words=3, max_chars=24):
    """Convert an approach title to a safe, clean hyphenated slug."""
    if not approach_title:
        return ""
    cleaned = approach_title.replace("'", "")
    cleaned_no_paren = re.sub(r"\(.*?\)", "", cleaned).strip()
    if cleaned_no_paren:
        cleaned = cleaned_no_paren
    slug = re.sub(r"[^a-zA-Z0-9]+", "-", cleaned).strip("-").lower()
    parts = [p for p in slug.split("-") if p]
    if len(parts) > max_words:
        parts = parts[:max_words]
    slug = "-".join(parts)
    if len(slug) > max_chars:
        slug = slug[:max_chars].rstrip("-")
    return slug

def is_content_identical(content1, content2):
    """Compare two code contents ignoring leading/trailing whitespace and CRLF."""
    c1 = content1.replace("\r\n", "\n").strip()
    c2 = content2.replace("\r\n", "\n").strip()
    return c1 == c2

def get_solution_files(q_dir_path):
    """Return sorted list of code solution files in problem directory."""
    if not os.path.exists(q_dir_path) or not os.path.isdir(q_dir_path):
        return []
    files = []
    q_dir_name = os.path.basename(q_dir_path)
    for f in os.listdir(q_dir_path):
        f_path = os.path.join(q_dir_path, f)
        if not os.path.isfile(f_path):
            continue
        ext = os.path.splitext(f)[1].lower()
        if ext in CODE_EXTENSIONS:
            files.append(f)
            
    def sort_key(filename):
        base, _ = os.path.splitext(filename)
        if base == q_dir_name:
            return (1, 1, filename)
        m = re.search(r"-approach-?(\d+)", base, re.IGNORECASE)
        if m:
            return (2, int(m.group(1)), filename)
        m2 = re.search(r"-(\d+)$", base)
        if m2:
            return (3, int(m2.group(1)), filename)
        return (4, 999, filename)
        
    return sorted(files, key=sort_key)

def get_next_approach_filename(dst_dir, filename, code_content):
    """Generate a distinct filename for a new approach in dst_dir."""
    _, ext = os.path.splitext(filename)
    clean_base = os.path.basename(dst_dir)
    
    approach_title = extract_approach_title(code_content)
    approach_slug = slugify_approach(approach_title) if approach_title else ""
    explicit_num = extract_approach_num(code_content)
    
    existing_files = get_solution_files(dst_dir)
    existing_indices = []
    for f in existing_files:
        f_base, _ = os.path.splitext(f)
        m = re.search(r"-approach-?(\d+)", f_base, re.IGNORECASE)
        if m:
            existing_indices.append(int(m.group(1)))
        elif re.search(r"-(\d+)$", f_base):
            m2 = re.search(r"-(\d+)$", f_base)
            existing_indices.append(int(m2.group(1)))
        elif f == f"{clean_base}{ext}":
            existing_indices.append(1)
            
    if explicit_num and explicit_num not in existing_indices:
        next_index = explicit_num
    else:
        next_index = max(existing_indices, default=1) + 1
    
    while True:
        if approach_slug:
            candidate = f"{clean_base}-approach-{next_index}-{approach_slug}{ext}"
        else:
            candidate = f"{clean_base}-approach-{next_index}{ext}"
            
        if not os.path.exists(os.path.join(dst_dir, candidate)):
            return candidate
        next_index += 1

def format_solution_links(solutions):
    """Format markdown links for solutions in problem tables."""
    if not solutions:
        return "—"
    if len(solutions) == 1:
        sol = solutions[0]
        return f"[{sol['lang']}]({sol['rel_path']})"
    
    links = []
    for sol in solutions:
        num = sol["approach_num"]
        label = f"Approach {num}" if len(solutions) <= 2 else f"App {num}"
        title = sol.get("approach_title")
        if title:
            clean_title = re.sub(r'["\r\n]', '', title).strip()
            links.append(f"[{label}]({sol['rel_path']} \"{clean_title}\")")
        else:
            links.append(f"[{label}]({sol['rel_path']})")
    return " · ".join(links)

def update_question_readme(q_dir_path, solutions):
    """If multiple approaches exist, add/update an Approaches section in question README.md."""
    if len(solutions) <= 1:
        return
    q_readme_path = os.path.join(q_dir_path, "README.md")
    if not os.path.exists(q_readme_path):
        return
    try:
        with open(q_readme_path, "r", encoding="utf-8") as f:
            content = f.read()
            
        lines = ["\n<!---LeetCode Approaches Start-->", "<hr>", "<h3>💡 Solutions & Approaches</h3>\n"]
        for sol in solutions:
            title_desc = f" — *{sol['approach_title']}*" if sol.get("approach_title") else ""
            lines.append(f"- [Approach {sol['approach_num']} ({sol['lang']})]({sol['filename']}){title_desc}")
        lines.append("\n<!---LeetCode Approaches End-->\n")
        section_text = "\n".join(lines)
        
        if "<!---LeetCode Approaches Start-->" in content:
            content = re.sub(
                r"<!---LeetCode Approaches Start-->.*?<!---LeetCode Approaches End-->",
                section_text.strip(),
                content,
                flags=re.DOTALL
            )
        else:
            content = content.rstrip() + section_text
            
        with open(q_readme_path, "w", encoding="utf-8") as f:
            f.write(content)
    except Exception as e:
        print(f"[Warning] Failed to update {q_readme_path}: {e}")

def classify_topic(title_slug, q_dir_name, old_readme=""):
    """Classify question into a target topic folder."""
    tags = fetch_leetcode_tags(title_slug)
    if not tags and old_readme:
        tags = get_tags_from_readme(q_dir_name, old_readme)
    
    # Check against topic configuration
    for folder, _, _, keywords in TOPIC_CONFIG:
        for kw in keywords:
            if any(kw in tag for tag in tags):
                return folder
            
    # Default fallback
    return "Arrays"

def find_existing_topic(q_dir_name):
    """Check if question already exists in any topic folder."""
    for item in os.listdir(BASE_DIR):
        topic_path = os.path.join(BASE_DIR, item)
        if not os.path.isdir(topic_path) or item.startswith(".") or item in ["scripts", ".github"]:
            continue
        candidate = os.path.join(topic_path, q_dir_name)
        if os.path.isdir(candidate):
            return item
    return None

def clean_nested_directories():
    """Find and flatten any accidental nested question directories (e.g. Topic/Q/Q)."""
    cleaned_any = False
    for item in os.listdir(BASE_DIR):
        topic_path = os.path.join(BASE_DIR, item)
        if not os.path.isdir(topic_path) or item.startswith(".") or item in ["scripts", ".github"]:
            continue
        for q_dir in os.listdir(topic_path):
            q_path = os.path.join(topic_path, q_dir)
            if not os.path.isdir(q_path) or not re.match(r"^\d+-", q_dir):
                continue
            nested_q = os.path.join(q_path, q_dir)
            if os.path.isdir(nested_q):
                print(f"[Cleanup] Found nested directory '{nested_q}', flattening...")
                for f in os.listdir(nested_q):
                    src_f = os.path.join(nested_q, f)
                    dst_f = os.path.join(q_path, f)
                    if os.path.isfile(src_f):
                        ext = os.path.splitext(f)[1].lower()
                        if ext in CODE_EXTENSIONS and os.path.exists(dst_f):
                            try:
                                with open(src_f, "r", encoding="utf-8", errors="ignore") as sf:
                                    src_content = sf.read()
                            except Exception:
                                src_content = ""
                            is_dup = False
                            for ex_f in get_solution_files(q_path):
                                ex_path = os.path.join(q_path, ex_f)
                                try:
                                    with open(ex_path, "r", encoding="utf-8", errors="ignore") as ef:
                                        if is_content_identical(src_content, ef.read()):
                                            is_dup = True
                                            break
                                except Exception:
                                    pass
                            if not is_dup:
                                app_num = extract_approach_num(src_content)
                                if app_num is not None and app_num >= 2:
                                    new_name = get_next_approach_filename(q_path, f, src_content)
                                    shutil.copy2(src_f, os.path.join(q_path, new_name))
                                else:
                                    shutil.copy2(src_f, dst_f)
                        elif not os.path.exists(dst_f) or os.path.getsize(src_f) > 0:
                            shutil.copy2(src_f, dst_f)
                shutil.rmtree(nested_q)
                try:
                    subprocess.run(["git", "rm", "-r", "--cached", "--ignore-unmatch", os.path.relpath(nested_q, BASE_DIR)],
                                   cwd=BASE_DIR, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                except Exception:
                    pass
                cleaned_any = True
    return cleaned_any

def move_or_merge_question(src, dst):
    """Move directory, or merge files if dst already exists (handling multiple approaches)."""
    if os.path.exists(dst):
        print(f"Destination '{dst}' already exists. Merging updated files from resubmission...")
        for item in os.listdir(src):
            src_item = os.path.join(src, item)
            dst_item = os.path.join(dst, item)
            if os.path.isfile(src_item):
                ext = os.path.splitext(item)[1].lower()
                if ext in CODE_EXTENSIONS and MULTI_APPROACH:
                    try:
                        with open(src_item, "r", encoding="utf-8", errors="ignore") as f:
                            src_content = f.read()
                    except Exception as e:
                        print(f"[Warning] Could not read '{src_item}': {e}")
                        src_content = ""
                        
                    # Check if identical solution already exists in dst
                    is_dup = False
                    for ex_f in get_solution_files(dst):
                        ex_path = os.path.join(dst, ex_f)
                        try:
                            with open(ex_path, "r", encoding="utf-8", errors="ignore") as ef:
                                if is_content_identical(src_content, ef.read()):
                                    print(f"[Multi-Approach] Incoming '{item}' matches existing '{ex_f}'. Skipping duplicate.")
                                    is_dup = True
                                    break
                        except Exception:
                            pass
                    if is_dup:
                        continue
                        
                    if not os.path.exists(dst_item):
                        shutil.copy2(src_item, dst_item)
                        print(f"[Multi-Approach] Copied initial solution '{item}' -> '{dst_item}'")
                    else:
                        app_num = extract_approach_num(src_content)
                        if app_num is not None and app_num >= 2:
                            new_name = get_next_approach_filename(dst, item, src_content)
                            new_dst_path = os.path.join(dst, new_name)
                            shutil.copy2(src_item, new_dst_path)
                            print(f"[Multi-Approach] Detected Approach-{app_num}/Method-{app_num} in comments. Saved new approach: '{item}' -> '{new_name}' in '{dst}'")
                            try:
                                subprocess.run(["git", "add", new_dst_path], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                            except Exception:
                                pass
                        else:
                            shutil.copy2(src_item, dst_item)
                            print(f"[Multi-Approach] Updating primary solution '{dst_item}' (no approach-2/method-2 heading comment detected).")
                            try:
                                subprocess.run(["git", "add", dst_item], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
                            except Exception:
                                pass
                else:
                    shutil.copy2(src_item, dst_item)
            elif os.path.isdir(src_item) and not re.match(r"^\d+-", item):
                shutil.copytree(src_item, dst_item, dirs_exist_ok=True)
        shutil.rmtree(src)
        try:
            subprocess.run(["git", "rm", "-r", "--cached", "--ignore-unmatch", os.path.relpath(src, BASE_DIR)],
                           cwd=BASE_DIR, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except Exception:
            pass
        try:
            subprocess.run(["git", "add", dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except Exception:
            pass
    else:
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        try:
            subprocess.run(["git", "mv", src, dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        except (subprocess.CalledProcessError, FileNotFoundError):
            shutil.move(src, dst)
            try:
                subprocess.run(["git", "add", dst], cwd=BASE_DIR, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            except Exception:
                pass

def scan_and_reorganize():
    """Find any unorganized question directories at repo root and move/merge them."""
    clean_nested_directories()

    root_entries = [
        d for d in os.listdir(BASE_DIR)
        if os.path.isdir(os.path.join(BASE_DIR, d)) and re.match(r"^\d+-", d)
    ]
    
    if not root_entries:
        print("No unorganized questions found at repository root.")
        return False
    
    old_readme = ""
    readme_path = os.path.join(BASE_DIR, "README.md")
    if os.path.exists(readme_path):
        with open(readme_path, "r", encoding="utf-8") as f:
            old_readme = f.read()
            
    moved_any = False
    for q_dir in sorted(root_entries):
        existing_topic = find_existing_topic(q_dir)
        if existing_topic:
            topic_folder = existing_topic
            print(f"Problem '{q_dir}' already exists in topic '{topic_folder}' (resubmission).")
        else:
            parts = q_dir.split("-", 1)
            slug = parts[1] if len(parts) > 1 else parts[0]
            topic_folder = classify_topic(slug, q_dir, old_readme)
        
        src = os.path.join(BASE_DIR, q_dir)
        dst = os.path.join(BASE_DIR, topic_folder, q_dir)
        
        print(f"Organizing '{q_dir}' -> '{topic_folder}/{q_dir}'")
        move_or_merge_question(src, dst)
        moved_any = True
        
    return moved_any

def rebuild_metadata():
    """Scan all topic folders, rebuild README.md and update stats.json."""
    known_topic_folders = {t[0]: t for t in TOPIC_CONFIG}
    
    questions = []
    path_map = {}
    
    # Scan all directories
    for item in sorted(os.listdir(BASE_DIR)):
        topic_path = os.path.join(BASE_DIR, item)
        if not os.path.isdir(topic_path) or item.startswith(".") or item in ["scripts", ".github"]:
            continue
        
        # Check if this folder is a topic folder
        if item in known_topic_folders:
            folder, display_name, icon, _ = known_topic_folders[item]
        else:
            folder, display_name, icon = item, item, "📁"
            
        for q_dir in sorted(os.listdir(topic_path)):
            full_q_path = os.path.join(topic_path, q_dir)
            if not os.path.isdir(full_q_path) or not re.match(r"^\d+-", q_dir):
                continue
                
            parts = q_dir.split("-", 1)
            num = parts[0]
            slug = parts[1] if len(parts) > 1 else num
            readme_file = "README.md"
            
            title = slug.replace("-", " ").title()
            difficulty = "Medium"
            lc_url = f"https://leetcode.com/problems/{slug}/"
            
            q_readme_path = os.path.join(full_q_path, readme_file)
            if os.path.exists(q_readme_path):
                with open(q_readme_path, "r", encoding="utf-8") as rf:
                    content = rf.read()
                    m_title = re.search(r'<h2><a href="([^"]+)">([^<]+)</a></h2>', content)
                    if m_title:
                        lc_url = m_title.group(1).strip()
                        raw_title = m_title.group(2).strip()
                        title = re.sub(r"^\d+\.\s*", "", raw_title)
                    m_diff = re.search(r"<h3>(Easy|Medium|Hard)</h3>", content)
                    if m_diff:
                        difficulty = m_diff.group(1).strip()
                        
            rel_dir = f"{folder}/{q_dir}"
            path_map[q_dir] = rel_dir
            
            # Find all solution files in directory
            sol_files = get_solution_files(full_q_path)
            solutions = []
            for idx, sf in enumerate(sol_files, start=1):
                sf_path = os.path.join(full_q_path, sf)
                code_text = ""
                try:
                    with open(sf_path, "r", encoding="utf-8", errors="ignore") as scf:
                        code_text = scf.read()
                except Exception:
                    pass
                
                app_title = extract_approach_title(code_text)
                ext = os.path.splitext(sf)[1].lower()
                lang = CODE_EXTENSIONS.get(ext, "Code")
                
                m = re.search(r"-approach-?(\d+)", sf, re.IGNORECASE)
                if m:
                    app_num = int(m.group(1))
                else:
                    m2 = re.search(r"-(\d+)\.", sf)
                    if m2:
                        app_num = int(m2.group(1))
                    else:
                        app_num = idx
                        
                solutions.append({
                    "filename": sf,
                    "rel_path": f"{folder}/{q_dir}/{sf}",
                    "approach_num": app_num,
                    "approach_title": app_title,
                    "lang": lang
                })
                
            # Update the question's README.md if multiple approaches exist
            if len(solutions) > 1:
                update_question_readme(full_q_path, solutions)
                
            primary_cpp = sol_files[0] if sol_files else f"{q_dir}.cpp"
            rel_cpp = f"{folder}/{q_dir}/{primary_cpp}"
            solution_link = format_solution_links(solutions)
            
            questions.append({
                "num": num,
                "title": title,
                "difficulty": difficulty,
                "topic_folder": folder,
                "topic_display": display_name,
                "topic_icon": icon,
                "q_dir": q_dir,
                "cpp_file": primary_cpp,
                "rel_dir": rel_dir,
                "rel_cpp": rel_cpp,
                "lc_url": lc_url,
                "solutions": solutions,
                "solution_link": solution_link
            })

    questions.sort(key=lambda x: int(x["num"]))
    
    # Counts
    easy_count = sum(1 for q in questions if q["difficulty"] == "Easy")
    med_count = sum(1 for q in questions if q["difficulty"] == "Medium")
    hard_count = sum(1 for q in questions if q["difficulty"] == "Hard")
    total_count = len(questions)
    
    pct_easy = f"{(easy_count / total_count * 100):.1f}%" if total_count else "0%"
    pct_med = f"{(med_count / total_count * 100):.1f}%" if total_count else "0%"
    pct_hard = f"{(hard_count / total_count * 100):.1f}%" if total_count else "0%"
    
    # Update stats.json
    stats_path = os.path.join(BASE_DIR, "stats.json")
    if os.path.exists(stats_path):
        try:
            with open(stats_path, "r", encoding="utf-8") as f:
                stats_data = json.load(f)
            stats_data.setdefault("leetcode", {})
            stats_data["leetcode"]["easy"] = easy_count
            stats_data["leetcode"]["medium"] = med_count
            stats_data["leetcode"]["hard"] = hard_count
            stats_data["leetcode"]["solved"] = total_count
            
            # Ensure shas has difficulty for all questions
            shas = stats_data["leetcode"].setdefault("shas", {})
            for q in questions:
                if q["q_dir"] in shas:
                    shas[q["q_dir"]]["difficulty"] = q["difficulty"].lower()
            with open(stats_path, "w", encoding="utf-8") as f:
                json.dump(stats_data, f, indent=2)
            print(f"Updated stats.json (Solved: {total_count})")
        except Exception as e:
            print(f"[Warning] Failed to update stats.json: {e}")

    # Read existing README for LeetHub block
    readme_path = os.path.join(BASE_DIR, "README.md")
    old_readme = ""
    if os.path.exists(readme_path):
        with open(readme_path, "r", encoding="utf-8") as f:
            old_readme = f.read()
            
    topics_block_match = re.search(r"(<!---LeetCode Topics Start-->.*?<!---LeetCode Topics End-->)", old_readme, re.DOTALL)
    if topics_block_match:
        old_topics_block = topics_block_match.group(1)
        def replace_link(m):
            q_name = m.group(1)
            if q_name in path_map:
                return f"[{q_name}](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/{path_map[q_name]})"
            return m.group(0)
        new_topics_block = re.sub(
            r"\[([0-9]{4}-[a-z0-9-]+)\]\(https://github.com/calligraphyguruji/LeetCode-Questions/tree/(?:master|main)/[0-9]{4}-[a-z0-9-]+\)",
            replace_link,
            old_topics_block
        )
    else:
        new_topics_block = ""
        
    def get_diff_badge(diff):
        if diff == "Easy":
            return "🟢 `Easy`"
        elif diff == "Medium":
            return "🟡 `Medium`"
        else:
            return "🔴 `Hard`"
            
    # Build Table
    table_rows = []
    for q in questions:
        diff_badge = get_diff_badge(q["difficulty"])
        topic_str = f"[{q['topic_icon']} {q['topic_display']}]({q['topic_folder']}/)"
        problem_link = f"[Problem]({q['rel_dir']}/)"
        table_rows.append(f"| {q['num']} | [{q['title']}]({q['lc_url']}) | {diff_badge} | {topic_str} | {problem_link} | {q['solution_link']} |")
    table_content = "\n".join(table_rows)

    # Build Topic-wise Breakdown
    topic_breakdown_parts = []
    for folder, topic_name, icon, _ in TOPIC_CONFIG:
        topic_qs = [q for q in questions if q["topic_folder"] == folder]
        if not topic_qs:
            continue
        topic_breakdown_parts.append(f"### {icon} [{topic_name}]({folder}/) ({len(topic_qs)})\n")
        topic_breakdown_parts.append("| # | Problem Name | Difficulty | Problem Details | Solution |")
        topic_breakdown_parts.append("|:---:|:---|:---:|:---:|:---:|")
        for q in topic_qs:
            diff_badge = get_diff_badge(q["difficulty"])
            topic_breakdown_parts.append(f"| {q['num']} | [{q['title']}]({q['lc_url']}) | {diff_badge} | [Problem Notes]({q['rel_dir']}/) | {q['solution_link']} |")
        topic_breakdown_parts.append("")


    q_map = {q["q_dir"]: q for q in questions}
    curation_section_content = build_curation_section()
    approaches_section_content = build_approaches_section(q_map, old_readme)

    topic_breakdown_content = "\n".join(topic_breakdown_parts)

    # Generate tree diagram dynamically
    tree_lines = ["LeetCode-Questions/", "│"]
    for folder, topic_name, icon, _ in TOPIC_CONFIG:
        topic_qs = [q for q in questions if q["topic_folder"] == folder]
        if not topic_qs:
            continue
        tree_lines.append(f"├── {folder}/")
        for q in topic_qs[:2]:
            tree_lines.append(f"│   ├── {q['q_dir']}/")
        if len(topic_qs) > 2:
            tree_lines.append(f"│   └── ... ({len(topic_qs)} problems)")
    tree_diagram = "\n".join(tree_lines)

    new_readme_text = f"""# 📚 LeetCode Solutions

Welcome to my personal collection of **LeetCode problem solutions**, written primarily in **C++**. This repository serves as a structured log of my journey to strengthen my **Data Structures and Algorithms (DSA)** skills through consistent, hands-on practice.

**🔗 Profile & Handwritten Solutions:** [https://leetcode.com/u/calligraphyguruji/](https://leetcode.com/u/calligraphyguruji/)

---

## 📌 About This Repository

This repository contains my solutions to various LeetCode problems, organized by topic and difficulty. It is structured for rapid reference, revision, and technical interview preparation. Each solution includes:
- Clear algorithmic approach and methodology
- Time and Space complexity analysis
- Clean, optimal C++ code implementation
- Full problem statements and constraints

The goal is simple: **practice daily, think deeply, and get better at solving problems one step at a time.**

---

## 📊 Progress Dashboard

<div align="center">

| Metric | Count | Percentage |
|:---|:---:|:---:|
| 🟢 **Easy** | {easy_count} | {pct_easy} |
| 🟡 **Medium** | {med_count} | {pct_med} |
| 🔴 **Hard** | {hard_count} | {pct_hard} |
| 🎯 **Total Solved** | **{total_count}** | **100%** |

</div>

---

{curation_section_content}

{approaches_section_content}

---

## 🎯 What I'm Learning

Through this repository, I'm actively working on:

- Understanding core **Data Structures** (Arrays, Linked Lists, Trees, Graphs, Stacks, Queues, Hash Maps)
- Applying **Algorithmic techniques** (Recursion, Backtracking, DP, Greedy, Binary Search)
- Improving my ability to **analyze time and space complexity**
- Learning to identify patterns and choose the right approach for a problem
- Building the problem-solving mindset needed for **technical interviews**

---

## 🗂️ Repository Structure

Solutions are organized into dedicated topic directories matching standard DSA categories:

```
{tree_diagram}
```

Each problem folder contains:
- `README.md` — Problem description, examples, constraints, and approach index.
- `<problem-name>.cpp` — Primary C++ solution with complexity notes.
- `<problem-name>-approach-*.cpp` — Alternative approaches and optimizations for the same problem.

---

## 🧠 Solution Format

Each solution file follows a clear, structured template:

```cpp
// Problem: Two Sum
// Approach: Hash Map (Optimal)
// Explanation: Store each number's index in a map while iterating.
// For every element, check if its complement already exists in the map.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {{
public:
    vector<int> twoSum(vector<int>& nums, int target) {{
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {{
            int complement = target - nums[i];
            if (seen.count(complement))
                return {{seen[complement], i}};
            seen[nums[i]] = i;
        }}
        return {{}};
    }}
}};
```

---

## 📋 Complete Problem Index

| # | Problem Name | Difficulty | Primary Topic | Problem Details | Solution |
|:---:|:---|:---:|:---|:---:|:---:|
{table_content}

---

## 📂 Topic-wise Problem Breakdown

{topic_breakdown_content}
---

## 🎯 Goals

- 🏗️ Build strong DSA fundamentals from the ground up
- 🧩 Improve problem-solving speed and accuracy
- 💼 Prepare for coding interviews and campus placements
- 📅 Maintain consistent, long-term LeetCode practice

---

## 🔗 My LeetCode Profile

**[https://leetcode.com/u/calligraphyguruji/](https://leetcode.com/u/calligraphyguruji/)**

---

## ⚠️ Disclaimer

This repository is created **purely for learning and educational purposes**. The solutions reflect my personal understanding and problem-solving approach at the time of writing, and may be updated or optimized as I continue to learn.

---

⭐ If you find this repository helpful for your own DSA practice, feel free to star it! A collection of LeetCode questions to ace the coding interview!

{new_topics_block}
"""

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(new_readme_text)
    print("Updated README.md successfully.")

def main():
    moved = scan_and_reorganize()
    rebuild_metadata()
    if moved:
        print("[Done] Repository restructured and index updated.")
    else:
        print("[Done] All questions are already organized.")

if __name__ == "__main__":
    main()
