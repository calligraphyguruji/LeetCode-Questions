# 📚 LeetCode Solutions

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

<p align="center">
  <a href="https://leetcode.com/u/calligraphyguruji/">
    <img src="https://img.shields.io/badge/Current_Streak-65_Days-orange?style=for-the-badge&logo=leetcode&logoColor=white" alt="LeetCode Streak" />
  </a>&nbsp;&nbsp;
  <a href="https://leetcode.com/u/calligraphyguruji/">
    <img src="https://img.shields.io/badge/Active_Days-179_Days-blue?style=for-the-badge&logo=calendar&logoColor=white" alt="Active Days" />
  </a>&nbsp;&nbsp;
  <a href="https://leetcode.com/u/calligraphyguruji/">
    <img src="https://img.shields.io/badge/Problems_Solved-194-2ecc71?style=for-the-badge&logo=codeforces&logoColor=white" alt="Solved" />
  </a>
</p>

| Metric | Count | Percentage |
|:---|:---:|:---:|
| 🟢 **Easy** | 42 | 21.6% |
| 🟡 **Medium** | 131 | 67.5% |
| 🔴 **Hard** | 21 | 10.8% |
| 🎯 **Total Solved** | **194** | **100%** |
| 🔥 **Current Streak** | **65 Days** | — |
| 📅 **Total Active Days** | **179 Days** | — |

</div>

---

## 🎯 Intentional Curation: Why These Aren't Random Questions

> **"Don't practice until you get it right. Practice until you can't get it wrong."**

Many developers approach LeetCode as a brute numbers game, indiscriminately grinding hundreds of arbitrary problems without developing transferable intuition. **This repository follows an intentional, blueprint-driven strategy.**

### 🔍 The Core Philosophy: Pattern Recognition > Rote Memorization
Technical interviews at top-tier product engineering companies (FAANG/MANG, unicorns, high-frequency trading firms) evaluate **underlying algorithmic intuition**, not your ability to recall a specific question's gimmick.

Every problem in this repository has been hand-selected from battle-tested technical interview roadmaps—most notably **NeetCode 150**, **Striver's SDE Sheet**, **Blind 75**, and **Grind 75**. These problems were deliberately chosen because they serve as **canonical archetypes**:

| Architectural Pillar | Implementation & Philosophy in this Repository |
|:---|:---|
| 🧱 **Foundational Archetypes** | Each question establishes a fundamental mental model (e.g., shrinking/expanding window invariants, monotonic boundary elimination, tree state bubbling, bipartite 2-coloring). Mastering one archetype unlocks an entire family of 20+ interview variations. |
| 🔄 **Multi-Approach Progression** | Solutions are not just single accepted snippets. Where instructional, solutions explore progressive evolution: **Brute Force $\to$ Better $\to$ Optimal Time/Space**, explicitly analyzing algorithmic tradeoffs and runtime complexities. |
| 🛡️ **Edge-Case Hardening** | Every implementation is tested and documented against edge cases: zero/single element structures, integer overflow boundaries ($2^{31}-1$), negative coordinates, cyclic dependencies, and disjoint graphs. |
| 📈 **High-Yield Retention** | Deeply mastering ~170 core pattern archetypes produces drastically higher problem-solving speed, confidence, and adaptability than shallowly skimming 1,000+ random problems. |

---

## 🧩 Algorithmic Approaches & Patterns Directory

To make revision structured and interview preparation fast, every question is indexed below according to its **underlying algorithmic approach and technique** (such as Two Pointers, Minimum Window Sliding, Fast & Slow Pointers, Monotonic Stack, etc.).

> **Quick Navigation:** [👉👈 Two Pointers](#-two-pointers) • [🪟 Sliding Window](#-sliding-window) • [🐢🐇 Fast & Slow Pointers](#-fast-slow-pointers) • [📊 Prefix Sum & Frequency Maps](#-prefix-sum) • [🥞 Monotonic Stack & Monotonic Queue](#-monotonic-stack-queue) • [🔍 Binary Search & Search Space Reduction](#-binary-search) • [🔄 Backtracking & State-Space Search](#-backtracking) • [🌳 Tree Traversals, Construction & Tree DP](#-tree-traversals) • [🕸️ Graph BFS & Multi-Source BFS](#-graph-bfs) • [🗺️ Graph DFS, Connectivity & Bipartite Graphs](#-graph-dfs) • [🧭 Topological Sort](#-topological-sort) • [🔗 Disjoint Set Union](#-disjoint-set-union) • [🚀 Shortest Paths in Weighted Graphs](#-shortest-paths) • [🧩 Dynamic Programming](#-dynamic-programming) • [💡 Greedy Algorithms & Interval Scheduling](#-greedy-intervals) • [⛰️ Heaps, Priority Queues & Top-K Elements](#-heaps-priority-queues) • [🪢 Linked List Pointer Surgery & In-Place Reversal](#-linked-list-manipulation) • [🔲 Matrix Traversal & In-Place State Manipulation](#-matrix-manipulation) • [⚡ Bit Manipulation, Stacks & Mathematical Simulation](#-bit-manipulation-math)

<a id="-two-pointers"></a>
### 👉👈 Two Pointers (Converging & Parallel)

- **Core Intuition:** Navigating sequences from opposite ends or at varying offsets to eliminate quadratic search spaces into $O(n)$ time with $O(1)$ auxiliary space.
- **When to Apply:** Sorted arrays, palindrome verification, partition pivots (Dutch National Flag), and in-place reversal/compression.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum) | 🟢 `Easy` | [C++](Arrays/0001-two-sum/0001-two-sum.cpp) | Hash map complement lookup or sorted two-pointer sweep |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 `Medium` | [C++](Arrays/0015-3sum/0015-3sum.cpp) | Sorting array + fixing first element + converging two-pointer scan with duplicate pruning |
| 0018 | [4Sum](https://leetcode.com/problems/4sum) | 🟡 `Medium` | [C++](Arrays/0018-4sum/0018-4sum.cpp) | Generalized k-sum: two fixed loops + inner two-pointer converging search |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation) | 🟡 `Medium` | [C++](Arrays/0031-next-permutation/0031-next-permutation.cpp) | Identify first decreasing pivot from right, swap with successor, reverse suffix via two pointers |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 `Medium` | [C++](Arrays/0075-sort-colors/0075-sort-colors.cpp) | Dutch National Flag algorithm: 3-pointer partition (low, mid, high) in a single pass |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 `Easy` | [C++](Arrays/0088-merge-sorted-array/0088-merge-sorted-array.cpp) | Three pointers placing largest elements backwards from the end |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 `Easy` | [C++](Arrays/0125-valid-palindrome/0125-valid-palindrome.cpp) | Left and right pointers converging inward while skipping non-alphanumeric characters |
| 0151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string) | 🟡 `Medium` | [C++](Arrays/0151-reverse-words-in-a-string/0151-reverse-words-in-a-string.cpp) | Two-pointer string token reversal and in-place whitespace compaction |
| 0238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self) | 🟡 `Medium` | [C++](Arrays/0238-product-of-array-except-self/0238-product-of-array-except-self.cpp) | Optimal Arrays & Hashing approach with clean asymptotic complexity |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 `Easy` | [C++](Arrays/0344-reverse-string/0344-reverse-string.cpp) | Left and right pointers swapping mirror elements towards the center |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression) | 🟡 `Medium` | [C++](Arrays/0443-string-compression/0443-string-compression.cpp) | Read/write two-pointer technique for in-place run-length encoding |

<a id="-sliding-window"></a>
### 🪟 Sliding Window (Fixed & Minimum Window)

- **Core Intuition:** Maintaining a continuous window $[L, R]$ across an array or string. Expand the right boundary to satisfy target criteria, and shrink the left boundary to optimize or find the minimum feasible window.
- **When to Apply:** Contiguous subarray/substring problems looking for maximum/minimum length, exact count, or minimum window satisfying character frequencies.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) | 🟡 `Medium` | [Java](Arrays/0003-longest-substring-without-repeating-characters/0003-longest-substring-without-repeating-characters.java) | Dynamic window tracking character last-seen positions with hash map / frequency array |
| 0076 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) | 🔴 `Hard` | [C++](Arrays/0076-minimum-window-substring/0076-minimum-window-substring.cpp) | Classic minimum window sliding: expand $R$ until all characters match, then greedily contract $L$ to minimize window size |
| 0239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) | 🔴 `Hard` | [C++](Heaps/0239-sliding-window-maximum/0239-sliding-window-maximum.cpp) | Sliding window maintained by a monotonic decreasing deque for $O(1)$ window maximum retrieval |
| 0567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string) | 🟡 `Medium` | [C++](Arrays/0567-permutation-in-string/0567-permutation-in-string.cpp) | Fixed-size sliding window of length $|s1|$ checking character frequency vector equality |

<a id="-fast-slow-pointers"></a>
### 🐢🐇 Fast & Slow Pointers (Floyd's Cycle Finding)

- **Core Intuition:** Two pointers traversing sequences at different speeds ($1x$ vs $2x$). The relative distance between them changes by 1 each step, guaranteeing rendezvous if a cycle exists.
- **When to Apply:** Detecting cycles in linked lists/arrays, finding loop entry points, determining linked list middle nodes without calculating length beforehand.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 `Easy` | [C++](Arrays/0141-linked-list-cycle/0141-linked-list-cycle.cpp) | Floyd's cycle detection: fast and slow pointers meet if a cycle exists |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 `Medium` | [C++](Arrays/0142-linked-list-cycle-ii/0142-linked-list-cycle-ii.cpp) | Meeting point reset: reset one pointer to head to find exact cycle origin node |
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 `Easy` | [C++](Arrays/0234-palindrome-linked-list/0234-palindrome-linked-list.cpp) | Fast/slow pointers to find list midpoint + reverse second half in-place + compare |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 `Medium` | [C++](BinarySearch/0287-find-the-duplicate-number/0287-find-the-duplicate-number.cpp) | Treating array indices and values as linked list nodes ($i \to nums[i]$) to detect cycle entrance |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 `Easy` | [C++](Arrays/0876-middle-of-the-linked-list/0876-middle-of-the-linked-list.cpp) | Fast pointer steps twice as fast; slow pointer lands on exact middle node |

<a id="-prefix-sum"></a>
### 📊 Prefix Sum & Frequency Maps

- **Core Intuition:** Precomputing cumulative prefixes or tracking element frequencies in hash maps to answer range queries and detect subarray conditions in $O(1)$ amortized time.
- **When to Apply:** Subarray sum equals $k$, range sum caching, anagram grouping, frequency parity checks, and majority voting.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0049 | [Group Anagrams](https://leetcode.com/problems/group-anagrams) | 🟡 `Medium` | [C++](Arrays/0049-group-anagrams/0049-group-anagrams.cpp) | Categorize strings by canonical sorted key or 26-character frequency signature |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) | Boyer-Moore Voting Algorithm: tracking candidate and net score in $O(1)$ auxiliary space |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 `Easy` | [C++](Arrays/0242-valid-anagram/0242-valid-anagram.cpp) | Fixed 26-character frequency count matching between two strings |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 `Easy` | [C++](Arrays/0387-first-unique-character-in-a-string/0387-first-unique-character-in-a-string.cpp) | Two-pass frequency mapping to detect first element with frequency 1 |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 `Medium` | [C++](Arrays/0560-subarray-sum-equals-k/0560-subarray-sum-equals-k.cpp) | Prefix sum array paired with hash map of prefix frequencies: find count of $(prefix - k)$ in $O(n)$ |
| 0652 | [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees) | 🟡 `Medium` | [C++](Trees/0652-find-duplicate-subtrees/0652-find-duplicate-subtrees.cpp) | Postorder DFS + Subtree Serialization using Unique IDs + HashMap Frequency Counting in $O(n \log n)$ time |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) | Prefix state matrix tracking both minimum (negative) and maximum products |
| 2965 | [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values) | 🟢 `Easy` | [C++](Math/2965-find-missing-and-repeated-values/2965-find-missing-and-repeated-values.cpp) | Frequency array / mathematical sum and square-sum formulas to pinpoint missing and duplicate numbers |

<a id="-monotonic-stack-queue"></a>
### 🥞 Monotonic Stack & Monotonic Queue

- **Core Intuition:** Maintaining elements in strictly ascending or descending order within a stack or deque. Eliminates sub-optimal candidates upon element arrival, resolving range bounds in amortized $O(n)$ total time.
- **When to Apply:** Next/Previous Greater or Smaller elements, largest rectangular areas in histograms, sliding window maximums.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0084 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram) | 🔴 `Hard` | [C++](Arrays/0084-largest-rectangle-in-histogram/0084-largest-rectangle-in-histogram.cpp) | Monotonic increasing stack tracking left and right boundaries for every bar in $O(n)$ |
| 0496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) | 🟢 `Easy` | [C++](Arrays/0496-next-greater-element-i/0496-next-greater-element-i.cpp) | Monotonic decreasing stack caching next greater element for each array value |
| 0503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) | 🟡 `Medium` | [C++](Arrays/0503-next-greater-element-ii/0503-next-greater-element-ii.cpp) | Simulating circular array traversal via double pass with monotonic decreasing stack |
| 0901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span) | 🟡 `Medium` | [C++](Arrays/0901-online-stock-span/0901-online-stock-span.cpp) | Monotonic stack storing consecutive lower prices and cumulative span weights |

<a id="-binary-search"></a>
### 🔍 Binary Search & Search Space Reduction

- **Core Intuition:** Dividing search space in half at each step in $O(\log n)$. Extends beyond simple sorted array lookups to 'Binary Search on Answer' over monotonic predicate functions.
- **When to Apply:** Sorted or rotated arrays, 2D matrix searches, finding boundaries, minimax/maximin allocation optimization.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) | Identifying which half is sorted to discard the other half in $O(\log n)$ |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 `Medium` | [C++](BinarySearch/0074-search-a-2d-matrix/0074-search-a-2d-matrix.cpp) | Standard binary search treating row-major 2D matrix as virtual flattened 1D array |
| 0222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟡 `Medium` | [C++](BinarySearch/0222-count-complete-tree-nodes/0222-count-complete-tree-nodes.cpp) | Binary Tree Height + Divide and Conquer: compare left and right subtree heights to prune half the tree in $O(\log^2 n)$ |
| 0240 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii) | 🟡 `Medium` | [C++](BinarySearch/0240-search-a-2d-matrix-ii/0240-search-a-2d-matrix-ii.cpp) | Pruning search space starting from top-right corner using matrix row/col monotonicity |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix) | 🟡 `Medium` | [C++](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/0378-kth-smallest-element-in-a-sorted-matrix.cpp) | Binary search on value range with $O(n)$ row/col monotonic count subroutine |
| 0410 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum) | 🔴 `Hard` | [C++](BinarySearch/0410-split-array-largest-sum/0410-split-array-largest-sum.cpp) | Binary search on answer domain $[\max(nums), \sum(nums)]$ with greedy chunk validator |
| 0493 | [Reverse Pairs](https://leetcode.com/problems/reverse-pairs) | 🔴 `Hard` | [C++](BinarySearch/0493-reverse-pairs/0493-reverse-pairs.cpp) | Modified merge sort divide & conquer with cross-half two-pointer reverse pair counting |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | 🟡 `Medium` | [C++](BinarySearch/0540-single-element-in-a-sorted-array/0540-single-element-in-a-sorted-array.cpp) | Binary search checking parity invariants of identical element pairs |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search) | 🟢 `Easy` | [C++](BinarySearch/0704-binary-search/0704-binary-search.cpp) | Canonical binary search template with safe midpoint calculation `left + (right - left) / 2` |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 `Medium` | [C++](BinarySearch/0852-peak-index-in-a-mountain-array/0852-peak-index-in-a-mountain-array.cpp) | Binary search on gradient slope checking $nums[mid] < nums[mid + 1]$ |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) | 🟡 `Medium` | [C++](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/2064-minimized-maximum-of-products-distributed-to-any-store.cpp) | Binary search on answer for minimum store product distribution quota |

<a id="-backtracking"></a>
### 🔄 Backtracking & State-Space Search

- **Core Intuition:** Exhaustive exploration of decision trees with early pruning. Constructs candidate states step-by-step and rolls back (backtracks) state immediately when constraints are violated.
- **When to Apply:** Permutations, combinations, subsets, constraint satisfaction (Sudoku, N-Queens), and grid word searches.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0037 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver) | 🔴 `Hard` | [C++](Backtracking/0037-sudoku-solver/0037-sudoku-solver.cpp) | Row, column, and 3x3 box constraint validation with recursive digit placement and rollback |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum) | 🟡 `Medium` | [C++](Backtracking/0039-combination-sum/0039-combination-sum.cpp) | Unbounded element reuse backtracking to match exact remaining sum |
| 0040 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii) | 🟡 `Medium` | [C++](Backtracking/0040-combination-sum-ii/0040-combination-sum-ii.cpp) | Sorted array backtracking with duplicate sibling branch pruning for unique combinations |
| 0046 | [Permutations](https://leetcode.com/problems/permutations) | 🟡 `Medium` | [C++](Backtracking/0046-permutations/0046-permutations.cpp) | Generating all $n!$ permutations using visited markers or in-place element swaps |
| 0051 | [N-Queens](https://leetcode.com/problems/n-queens) | 🔴 `Hard` | [C++](Backtracking/0051-n-queens/0051-n-queens.cpp) | Bitmask / boolean set tracking of safe columns and 45° / 135° diagonals |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 `Medium` | [C++](Backtracking/0078-subsets/0078-subsets.cpp) | Power set generation via cascading pick / don't pick binary decision tree |
| 0079 | [Word Search](https://leetcode.com/problems/word-search) | 🟡 `Medium` | [C++](Backtracking/0079-word-search/0079-word-search.cpp) | 2D grid DFS matching characters with in-place cell masking and unmasking |
| 0090 | [Subsets II](https://leetcode.com/problems/subsets-ii) | 🟡 `Medium` | [C++](Backtracking/0090-subsets-ii/0090-subsets-ii.cpp) | Generating unique subsets from arrays with duplicates by sorting and skipping identical elements |
| 0113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | 🟡 `Medium` | [C++](Backtracking/0113-path-sum-ii/0113-path-sum-ii.cpp) | Backtracking DFS tracking current root-to-leaf path and collecting valid paths matching target sum |
| 0131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning) | 🟡 `Medium` | [C++](Backtracking/0131-palindrome-partitioning/0131-palindrome-partitioning.cpp) | Backtracking substring partitions with palindrome validation memoization |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum) | 🟡 `Medium` | [C++](Backtracking/0494-target-sum/0494-target-sum.cpp) | Branching $+/-$ decision tree transformed to 0-1 knapsack subset sum |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) | Bitmask tracking of unique characters across recursive subset combinations |
| 2596 | [Check Knight Tour Configuration](https://leetcode.com/problems/check-knight-tour-configuration) | 🟡 `Medium` | [C++](Graphs/2596-check-knight-tour-configuration/2596-check-knight-tour-configuration.cpp) | Sequential coordinate step validation verifying knight move deltas |

<a id="-tree-traversals"></a>
### 🌳 Tree Traversals, Construction & Tree DP

- **Core Intuition:** Recursive DFS (preorder, inorder, postorder) and BFS (level-order) on hierarchical structures. Aggregating subtree heights, diameters, and validating BST invariants.
- **When to Apply:** Binary trees, BST queries/mutations, lowest common ancestor, path sum maximizations, and tree diameter.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 `Easy` | [C++](Trees/0014-longest-common-prefix/0014-longest-common-prefix.cpp) | Trie / vertical character scanning across string array |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) | Left-root-right DFS traversal with recursion and iterative stack |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) | Catalan number dynamic programming for count of unique BST shapes |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | 🟡 `Medium` | [C++](BinarySearch/0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp) | Inorder strict ascending check or propagating $(minVal, maxVal)$ ranges down subtrees |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree) | 🟡 `Medium` | [C++](BinarySearch/0099-recover-binary-search-tree/0099-recover-binary-search-tree.cpp) | Detecting two swapped nodes using inorder traversal pointers in $O(1)$ space |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree) | 🟢 `Easy` | [C++](Trees/0100-same-tree/0100-same-tree.cpp) | Simultaneous structural and value equivalence check via recursive DFS |
| 0101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree) | 🟢 `Easy` | [C++](Trees/0101-symmetric-tree/0101-symmetric-tree.cpp) | Mirror reflection check comparing opposite outer and inner child subtrees |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) | 🟡 `Medium` | [C++](Trees/0102-binary-tree-level-order-traversal/0102-binary-tree-level-order-traversal.cpp) | Queue-based level-by-level BFS collecting node values per depth |
| 0103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal) | 🟡 `Medium` | [C++](Trees/0103-binary-tree-zigzag-level-order-traversal/0103-binary-tree-zigzag-level-order-traversal.cpp) | Alternating direction level-order traversal using double-ended queues |
| 0105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal) | 🟡 `Medium` | [C++](Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/0105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp) | Preorder identifies root; inorder split gives left and right subtree sizes |
| 0106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) | 🟡 `Medium` | [C++](Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/0106-construct-binary-tree-from-inorder-and-postorder-traversal.cpp) | Postorder identifies root; inorder split gives subtree boundaries recursively |
| 0108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 `Easy` | [C++](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/0108-convert-sorted-array-to-binary-search-tree.cpp) | Midpoint divide-and-conquer to build height-balanced BST |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree) | 🟢 `Easy` | [C++](Trees/0110-balanced-binary-tree/0110-balanced-binary-tree.cpp) | Bottom-up height calculation with early $-1$ exit on subtree height differential $> 1$ |
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 `Easy` | [C++](Trees/0111-minimum-depth-of-binary-tree/0111-minimum-depth-of-binary-tree.cpp) | BFS (Level Order Traversal) in $O(n)$ time |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum) | 🟢 `Easy` | [C++](Trees/0112-path-sum/0112-path-sum.cpp) | DFS recursion subtracting node values along root-to-leaf paths until target sum is 0 at a leaf |
| 0114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list) | 🟡 `Medium` | [C++](Trees/0114-flatten-binary-tree-to-linked-list/0114-flatten-binary-tree-to-linked-list.cpp) | Rewiring right pointers to preorder sequence with Morris-like constant space traversal |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) | Using established upper-level next pointers for $O(1)$ auxiliary space linkage |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 `Hard` | [C++](Trees/0124-binary-tree-maximum-path-sum/0124-binary-tree-maximum-path-sum.cpp) | Postorder tree DP computing maximum non-negative branch gain and updating global sum |
| 0129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | 🟡 `Medium` | [C++](Trees/0129-sum-root-to-leaf-numbers/0129-sum-root-to-leaf-numbers.cpp) | Top-Down DFS (Root-to-Leaf DFS) + Running Number in $O(n)$ time |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) | Root-left-right recursive and iterative stack traversal |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) | Left-right-root postorder traversal with stack |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | 🟡 `Medium` | [C++](BinarySearch/0173-binary-search-tree-iterator/0173-binary-search-tree-iterator.cpp) | Controlled inorder traversal with push-all-left stack in $O(h)$ memory |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view) | 🟡 `Medium` | [App 1](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view.cpp) · [App 2](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view-approach-2-bfs.cpp "BFS(Level Order Traversal)") · [App 3](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view-approach-3-dfs.cpp "DFS(Preorder Traversal)") | Level-order BFS picking last node or right-first DFS |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 `Medium` | [C++](BinarySearch/0230-kth-smallest-element-in-a-bst/0230-kth-smallest-element-in-a-bst.cpp) | Inorder traversal stopping at $k$-th visited element |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟡 `Medium` | [C++](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/0235-lowest-common-ancestor-of-a-binary-search-tree.cpp) | BST navigation branching based on split across node value |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 `Medium` | [C++](Trees/0236-lowest-common-ancestor-of-a-binary-tree/0236-lowest-common-ancestor-of-a-binary-tree.cpp) | Postorder search bubbling up target nodes to first shared ancestor |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) | BST search and successor splicing upon removing two-child nodes |
| 0515 | [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row) | 🟡 `Medium` | [C++](Trees/0515-find-largest-value-in-each-tree-row/0515-find-largest-value-in-each-tree-row.cpp) | Level-order BFS queue traversal processing tree nodes by depth |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree) | 🟢 `Easy` | [C++](Trees/0543-diameter-of-binary-tree/0543-diameter-of-binary-tree.cpp) | Postorder depth calculation updating maximum left+right path |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 `Easy` | [C++](Trees/0572-subtree-of-another-tree/0572-subtree-of-another-tree.cpp) | Recursive root matching with exact tree equivalence subroutine |
| 0623 | [Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree) | 🟡 `Medium` | [C++](Trees/0623-add-one-row-to-tree/0623-add-one-row-to-tree.cpp) | Level-order BFS traversing to depth - 1 to splice new row nodes between parent and children |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree) | 🟡 `Medium` | [C++](Trees/0662-maximum-width-of-binary-tree/0662-maximum-width-of-binary-tree.cpp) | Zero-indexed heap-like coordinate tagging per level to prevent overflow |
| 0783 | [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) | 🟢 `Easy` | [C++](BinarySearch/0783-minimum-distance-between-bst-nodes/0783-minimum-distance-between-bst-nodes.cpp) | Inorder traversal tracking running minimum difference between neighbors |
| 0814 | [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning) | 🟡 `Medium` | [C++](Trees/0814-binary-tree-pruning/0814-binary-tree-pruning.cpp) | Bottom-up postorder DFS recursively removing subtrees that do not contain a 1 |
| 0863 | [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) | 🟡 `Medium` | [C++](Trees/0863-all-nodes-distance-k-in-binary-tree/0863-all-nodes-distance-k-in-binary-tree.cpp) | Parent Mapping (DFS) + BFS (Level Order Traversal) in $O(n)$ time |
| 0872 | [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees) | 🟢 `Easy` | [C++](Trees/0872-leaf-similar-trees/0872-leaf-similar-trees.cpp) | DFS leaf-node collection comparing leaf value sequences of both binary trees |
| 0958 | [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree) | 🟡 `Medium` | [C++](Trees/0958-check-completeness-of-a-binary-tree/0958-check-completeness-of-a-binary-tree.cpp) | Level-order BFS verifying no non-null node appears after the first null node is encountered |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal) | 🟡 `Medium` | [C++](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/1008-construct-binary-search-tree-from-preorder-traversal.cpp) | Monotonic upper-bound recursive BST reconstruction in $O(n)$ |
| 1026 | [Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/) | 🟡 `Medium` | [Approach 1](Trees/1026-maximum-difference-between-node-and-ancestor/1026-maximum-difference-between-node-and-ancestor.cpp "Brute Force(Using two separate DFS)") · [Approach 2](Trees/1026-maximum-difference-between-node-and-ancestor/1026-maximum-difference-between-node-and-ancestor-approach-2-optimal.cpp "Optimal(DFS + Min/Max on Current Path)") | Brute Force (Using two separate DFS) in $O(n * n)$ time |
| 1038 | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree) | 🟡 `Medium` | [C++](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/1038-binary-search-tree-to-greater-sum-tree.cpp) | Reverse inorder traversal (right-root-left) accumulating suffix sum |
| 1110 | [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest) | 🟡 `Medium` | [C++](Trees/1110-delete-nodes-and-return-forest/1110-delete-nodes-and-return-forest.cpp) | Postorder DFS disconnecting deleted nodes with hash set lookup and adding non-null children as new tree roots |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 `Medium` | [C++](Trees/1161-maximum-level-sum-of-a-binary-tree/1161-maximum-level-sum-of-a-binary-tree.cpp) | BFS level summation tracking index with maximum aggregate sum |
| 1339 | [Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree) | 🟡 `Medium` | [C++](Trees/1339-maximum-product-of-splitted-binary-tree/1339-maximum-product-of-splitted-binary-tree.cpp) | Subtree Sum + Complement Sum in $O(n)$ time |
| 1361 | [Validate Binary Tree Nodes](https://leetcode.com/problems/validate-binary-tree-nodes) | 🟡 `Medium` | [C++](Trees/1361-validate-binary-tree-nodes/1361-validate-binary-tree-nodes.cpp) | Parent Count + Root Detection + DFS Connectivity in $O(n)$ time |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) | Bottom-up DFS summing round-trip edge costs for apple-bearing subtrees |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) | Postorder 26-length frequency array merging from child subtrees |
| 1932 | [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst) | 🔴 `Hard` | [C++](BinarySearch/1932-merge-bsts-to-create-single-bst/1932-merge-bsts-to-create-single-bst.cpp) | BST root-leaf matching, cycle check, and global BST inorder validation |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) | Tree DP returning longest branch and updating top-2 branch sum |

<a id="-graph-bfs"></a>
### 🕸️ Graph BFS & Multi-Source BFS

- **Core Intuition:** Layer-by-layer exploration guaranteeing shortest paths in unweighted graphs or simulating simultaneous multi-source wave propagation.
- **When to Apply:** Shortest path in unweighted graphs/grids, minimum step conversions, and simultaneous multi-point spread (fire, rot, infection).

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0365 | [Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/) | 🟡 `Medium` | [C++](Graphs/0365-water-and-jug-problem/0365-water-and-jug-problem.cpp) | State-space BFS exploring 6 fill, empty, and pour transitions between two jugs |
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) | State graph BFS transforming gene strings one mutation at a time |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix) | 🟡 `Medium` | [C++](Graphs/0542-01-matrix/0542-01-matrix.cpp) | Multi-source BFS initialized with all zero cells computing distance outward |
| 0733 | [Flood Fill](https://leetcode.com/problems/flood-fill) | 🟢 `Easy` | [C++](Graphs/0733-flood-fill/0733-flood-fill.cpp) | Grid flood fill updating connected pixels of identical original color |
| 0994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges) | 🟡 `Medium` | [C++](Graphs/0994-rotting-oranges/0994-rotting-oranges.cpp) | Multi-source BFS spreading rot layer-by-layer to adjacent fresh oranges |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix) | 🟡 `Medium` | [Approach 1](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix-approach-2-dijkstras-algorithm.cpp "Dijkstra's Algorithm") | 8-directional BFS in binary grid to find shortest path to bottom-right |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) | Queue BFS stepping through open cells to nearest perimeter boundary |

<a id="-graph-dfs"></a>
### 🗺️ Graph DFS, Connectivity & Bipartite Graphs

- **Core Intuition:** Deep recursive traversal across edges to discover connected components, cycle existence, and 2-colorability (bipartite graphs).
- **When to Apply:** Connected components counting, island problems, graph coloring, all-paths enumeration.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0133 | [Clone Graph](https://leetcode.com/problems/clone-graph) | 🟡 `Medium` | [C++](Graphs/0133-clone-graph/0133-clone-graph.cpp) | DFS/BFS with hash map mapping original nodes to cloned counterparts |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) | Grid DFS sinking visited land components ('1' to '0') |
| 0785 | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite) | 🟡 `Medium` | [C++](Graphs/0785-is-graph-bipartite/0785-is-graph-bipartite.cpp) | 2-coloring graph using alternating color DFS to detect odd-length cycles |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) | DAG DFS path tracking from source 0 to target $n-1$ |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [Approach 1](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/0841-keys-and-rooms/0841-keys-and-rooms-approach-2-dfs.cpp "DFS") | DFS/BFS room reachability check starting from room 0 |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) | Modeling dislikes as graph edges and checking 2-colorability |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) | BFS/DFS or DSU to verify path between source and destination |

<a id="-topological-sort"></a>
### 🧭 Topological Sort (DAG Dependency Resolution)

- **Core Intuition:** Linearly ordering vertices of a Directed Acyclic Graph such that every directed edge $u \to v$ has $u$ before $v$. Detects cycles when ordering is incomplete.
- **When to Apply:** Course prerequisites, task compilation schedules, and cycle detection in directed graphs.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) | Detecting directed cycles via Kahn's algorithm (in-degree queue) or 3-color DFS |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) | Returning valid dependency resolution sequence via topological sort |

<a id="-disjoint-set-union"></a>
### 🔗 Disjoint Set Union (DSU / Union-Find) & MST

- **Core Intuition:** Near $O(1)$ amortized operations (`find` with path compression, `union` by rank) to manage dynamic connectivity and find Minimum Spanning Trees (MST).
- **When to Apply:** Dynamic connected components, cycle detection in undirected graphs, Kruskal's MST algorithm.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces) | 🟡 `Medium` | [C++](Graphs/0547-number-of-provinces/0547-number-of-provinces.cpp) | Union-Find grouping directly connected cities into provinces |
| 0684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection) | 🟡 `Medium` | [C++](Graphs/0684-redundant-connection/0684-redundant-connection.cpp) | Finding edge whose endpoints already belong to same connected component |
| 0947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column) | 🟡 `Medium` | [C++](Graphs/0947-most-stones-removed-with-same-row-or-column/0947-most-stones-removed-with-same-row-or-column.cpp) | Unifying stone rows and columns to count connected components |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) | Unifying equal variables and validating inequalities against components |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) | DSU with root representing lexicographically smallest character |
| 1319 | [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | 🟡 `Medium` | [C++](Graphs/1319-number-of-operations-to-make-network-connected/1319-number-of-operations-to-make-network-connected.cpp) | Counting surplus edges vs number of disconnected components |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) | Kruskal's MST with DSU / Prim's greedy algorithm on complete graph |
| 2316 | [Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph) | 🟡 `Medium` | [C++](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp) | DSU component size calculation to compute non-connected node pairs |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) | Sorting nodes by value and merging components with DSU incrementally |

<a id="-shortest-paths"></a>
### 🚀 Shortest Paths in Weighted Graphs (Dijkstra & Relaxation)

- **Core Intuition:** Finding lowest-cost paths in non-negatively weighted graphs using priority queue relaxation (Dijkstra) or step-constrained relaxation (Bellman-Ford).
- **When to Apply:** Minimum latency, lowest flight fare with stopover limits, minimum effort paths in elevation grids.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time) | 🟡 `Medium` | [C++](Graphs/0743-network-delay-time/0743-network-delay-time.cpp) | Standard Dijkstra algorithm using min-heap for single-source shortest paths |
| 0787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops) | 🟡 `Medium` | [C++](Graphs/0787-cheapest-flights-within-k-stops/0787-cheapest-flights-within-k-stops.cpp) | Bellman-Ford / layer-by-layer BFS with at most $k$ edge relaxations |
| 1334 | [Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance) | 🟡 `Medium` | [C++](Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance.cpp) | Using Dijkstra's Algorithm (very lengthy) |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort) | 🟡 `Medium` | [App 1](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort.cpp "Dijkstra's Algorithm") · [App 2](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort-approach-2.cpp) · [App 3](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort-approach-3-dijkstras-algorithm.cpp "Dijkstra's Algorithm") | Dijkstra on grid minimizing maximum adjacent height difference |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) | 🟡 `Medium` | [C++](Graphs/1976-number-of-ways-to-arrive-at-destination/1976-number-of-ways-to-arrive-at-destination.cpp) | Dijkstra tracking shortest distances and DP path counts modulo $10^9+7$ |

<a id="-dynamic-programming"></a>
### 🧩 Dynamic Programming (1D, 2D Grid, String, Intervals & Partition)

- **Core Intuition:** Formulating recursive optimal substructure and caching overlapping subproblems. Transforms exponential brute-force searches into polynomial time.
- **When to Apply:** Knapsack problems, longest common subsequences, minimum edit operations, matrix paths, partition optimization.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0005 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) | 🟡 `Medium` | [C++](DynamicProgramming/0005-longest-palindromic-substring/0005-longest-palindromic-substring.cpp) | Top-Down Approach (Recursion + Memoization) |
| 0042 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water) | 🔴 `Hard` | [C++](DynamicProgramming/0042-trapping-rain-water/0042-trapping-rain-water.cpp) | Prefix max and suffix max arrays or two-pointer space optimization |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 `Medium` | [C++](DynamicProgramming/0053-maximum-subarray/0053-maximum-subarray.cpp) | Kadane's algorithm deciding whether to extend or start new subarray sum |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths) | 🟡 `Medium` | [C++](DynamicProgramming/0062-unique-paths/0062-unique-paths.cpp) | 2D grid combinations $dp[i][j] = dp[i-1][j] + dp[i][j-1]$ |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 `Medium` | [C++](DynamicProgramming/0063-unique-paths-ii/0063-unique-paths-ii.cpp) | Grid DP setting obstacle cells to 0 paths |
| 0072 | [Edit Distance](https://leetcode.com/problems/edit-distance) | 🟡 `Medium` | [C++](DynamicProgramming/0072-edit-distance/0072-edit-distance.cpp) | Levenshtein distance 2D DP for insert, delete, and replace operations |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) | Single pass tracking running minimum price and maximum profit |
| 0132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) | 🔴 `Hard` | [C++](DynamicProgramming/0132-palindrome-partitioning-ii/0132-palindrome-partitioning-ii.cpp) | 1D DP for minimum cuts utilizing 2D palindrome lookup table |
| 0198 | [House Robber](https://leetcode.com/problems/house-robber) | 🟡 `Medium` | [C++](DynamicProgramming/0198-house-robber/0198-house-robber.cpp) | State transition $dp[i] = \max(dp[i-1], dp[i-2] + nums[i])$ |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii) | 🟡 `Medium` | [C++](DynamicProgramming/0213-house-robber-ii/0213-house-robber-ii.cpp) | Running House Robber I twice (excluding first or last house) for circularity |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) | 🟡 `Medium` | [C++](DynamicProgramming/0264-ugly-number-ii/0264-ugly-number-ii.cpp) | Generating ugly numbers in order via three pointers $(2, 3, 5)$ |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares) | 🟡 `Medium` | [C++](DynamicProgramming/0279-perfect-squares/0279-perfect-squares.cpp) | Unbounded knapsack style 1D DP or Lagrange's four-square theorem |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 `Medium` | [C++](BinarySearch/0300-longest-increasing-subsequence/0300-longest-increasing-subsequence.cpp) | Classic $O(n^2)$ DP or $O(n \log n)$ patience sorting with binary search |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change) | 🟡 `Medium` | [C++](Graphs/0322-coin-change/0322-coin-change.cpp) | Unbounded knapsack DP computing minimum coins for amount |
| 0368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset) | 🟡 `Medium` | [C++](DynamicProgramming/0368-largest-divisible-subset/0368-largest-divisible-subset.cpp) | Bottom-Up Approach in $O(n * n)$ time |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 `Easy` | [C++](DynamicProgramming/0509-fibonacci-number/0509-fibonacci-number.cpp) | Base recurrence with rolling variables for $O(1)$ space |
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) | 2D interval DP comparing endpoints $s[i]$ and $s[j]$ |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) | Sorting by end coordinates + greedy interval selection or LIS DP |
| 0647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings) | 🟡 `Medium` | [C++](DynamicProgramming/0647-palindromic-substrings/0647-palindromic-substrings.cpp) | Recursion + Memoizatin (Top-Down Approach) |
| 1048 | [Longest String Chain](https://leetcode.com/problems/longest-string-chain) | 🟡 `Medium` | [C++](DynamicProgramming/1048-longest-string-chain/1048-longest-string-chain.cpp) | Top-Down Approach (Recursion + Memoization) in $O(n * n)$ time |
| 1092 | [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence) | 🔴 `Hard` | [C++](DynamicProgramming/1092-shortest-common-supersequence/1092-shortest-common-supersequence.cpp) | Bottom-UP Aproach in $O(m * n)$ time |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) | 2D grid state tracking matched characters between two strings |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome) | 🔴 `Hard` | [C++](DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/1312-minimum-insertion-steps-to-make-a-string-palindrome.cpp) | Recursion + Memoization in $O(n * n)$ time |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) | Partition DP splitting tasks into $d$ contiguous daily intervals |
| 1420 | [Build Array Where You Can Find The Maximum Exactly K Comparisons](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons) | 🔴 `Hard` | [C++](DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons.cpp) | Top-Down Approach (Recursion + Memoization) in $O(n * m * m * k)$ time |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) | Matrix Chain Multiplication / interval DP on sorted cut positions |
| 1911 | [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum) | 🟡 `Medium` | [C++](DynamicProgramming/1911-maximum-alternating-subsequence-sum/1911-maximum-alternating-subsequence-sum.cpp) | Two-state DP tracking maximum sum in even/odd position states |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) | Meet-in-the-middle subset generation + binary search lower bound |

<a id="-greedy-intervals"></a>
### 💡 Greedy Algorithms & Interval Scheduling

- **Core Intuition:** Making locally optimal decisions at every step that prove to yield a globally optimal solution.
- **When to Apply:** Interval merging, activity selection, stock trading with unlimited transactions, circular fuel balance.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 `Medium` | [C++](Greedy/0011-container-with-most-water/0011-container-with-most-water.cpp) | Optimal Greedy Algorithms approach with clean asymptotic complexity |
| 0056 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 `Medium` | [C++](Arrays/0056-merge-intervals/0056-merge-intervals.cpp) | Sorting intervals by start time and extending merged boundaries |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) | Greedily summing all positive consecutive price differentials |
| 0134 | [Gas Station](https://leetcode.com/problems/gas-station) | 🟡 `Medium` | [C++](Greedy/0134-gas-station/0134-gas-station.cpp) | Maintaining total balance and resetting start station on negative tank |

<a id="-heaps-priority-queues"></a>
### ⛰️ Heaps, Priority Queues & Top-K Elements

- **Core Intuition:** Dynamically maintaining sorted extremes (min or max) in $O(\log k)$ time, avoiding full array sorting.
- **When to Apply:** Finding $k$-th largest/smallest elements, streaming median, continuous ranking.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) | Min-heap of size $k$ or Quickselect for $O(n)$ average selection |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 `Medium` | [C++](Heaps/0347-top-k-frequent-elements/0347-top-k-frequent-elements.cpp) | Frequency map + min-heap or $O(n)$ bucket sort on counts |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 `Easy` | [C++](BinarySearch/0703-kth-largest-element-in-a-stream/0703-kth-largest-element-in-a-stream.cpp) | Min-heap storing top $k$ elements; root holds $k$-th largest |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 `Medium` | [C++](Heaps/0912-sort-an-array/0912-sort-an-array.cpp) | Max-heap sort / divide-and-conquer sorting algorithms |

<a id="-linked-list-manipulation"></a>
### 🪢 Linked List Pointer Surgery & In-Place Reversal

- **Core Intuition:** Carefully manipulating node pointers (`next`, `prev`), dummy heads, and local segment reversals with zero node copying in $O(1)$ memory.
- **When to Apply:** In-place list reversal, k-group reversal, cycle redirection, LRU cache memory structures.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists) | 🟢 `Easy` | [C++](Arrays/0021-merge-two-sorted-lists/0021-merge-two-sorted-lists.cpp) | Dummy head pointer splicing two sorted lists iteratively |
| 0024 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | 🟡 `Medium` | [C++](Arrays/0024-swap-nodes-in-pairs/0024-swap-nodes-in-pairs.cpp) | Pairwise next-pointer swap using pre-node tracker |
| 0025 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group) | 🔴 `Hard` | [C++](Arrays/0025-reverse-nodes-in-k-group/0025-reverse-nodes-in-k-group.cpp) | Reversing groups of $k$ nodes in-place while keeping remaining list intact |
| 0061 | [Rotate List](https://leetcode.com/problems/rotate-list) | 🟡 `Medium` | [C++](Arrays/0061-rotate-list/0061-rotate-list.cpp) | Forming circle by connecting tail to head, then cutting at $(len - k \% len)$ |
| 0092 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | 🟡 `Medium` | [C++](Arrays/0092-reverse-linked-list-ii/0092-reverse-linked-list-ii.cpp) | In-place pointer reversal for subsegment between positions left and right |
| 0138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) | 🟡 `Medium` | [C++](Arrays/0138-copy-list-with-random-pointer/0138-copy-list-with-random-pointer.cpp) | Interweaving cloned nodes between originals for $O(1)$ extra space copy |
| 0146 | [LRU Cache](https://leetcode.com/problems/lru-cache) | 🟡 `Medium` | [C++](Arrays/0146-lru-cache/0146-lru-cache.cpp) | Doubly linked list (for $O(1)$ eviction) coupled with hash map lookup |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 `Easy` | [C++](Arrays/0206-reverse-linked-list/0206-reverse-linked-list.cpp) | Canonical 3-pointer (`prev`, `curr`, `next`) list reversal |
| 0430 | [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list) | 🟡 `Medium` | [C++](Graphs/0430-flatten-a-multilevel-doubly-linked-list/0430-flatten-a-multilevel-doubly-linked-list.cpp) | DFS traversal splicing child doubly linked lists between current and next |

<a id="-matrix-manipulation"></a>
### 🔲 Matrix Traversal & In-Place State Manipulation

- **Core Intuition:** Simulating 2D boundary contractions and utilizing grid cells themselves as state markers for $O(1)$ auxiliary space.
- **When to Apply:** Layer-by-layer spiral peeling, in-place matrix zeroing without additional memory arrays.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix) | 🟡 `Medium` | [C++](Arrays/0054-spiral-matrix/0054-spiral-matrix.cpp) | 4-boundary pointer shrinkage (top, bottom, left, right) peeling matrix layers in clockwise order |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 `Medium` | [C++](Arrays/0073-set-matrix-zeroes/0073-set-matrix-zeroes.cpp) | Using first row and column as in-place $O(1)$ memory zero-marker flags |

<a id="-bit-manipulation-math"></a>
### ⚡ Bit Manipulation, Stacks & Mathematical Simulation

- **Core Intuition:** Bitwise masks, arithmetic simulation, LIFO stack matching, and number-theoretic properties.
- **When to Apply:** Binary bit checking, power-of-two tests, binary exponentiation, arithmetic without library tricks.

| # | Problem Name | Difficulty | Solution | Approach & Key Takeaway |
|:---:|:---|:---:|:---|:---|
| 0002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) | 🟡 `Medium` | [C++](Math/0002-add-two-numbers/0002-add-two-numbers.cpp) | Simulating elementary grade-school addition with carry across linked lists |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 `Easy` | [C++](Arrays/0020-valid-parentheses/0020-valid-parentheses.cpp) | Stack LIFO bracket matching for opening and closing symbols |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [C++](Math/0050-powx-n/0050-powx-n.cpp) | Binary exponentiation reducing power calculation to $O(\log n)$ |
| 0155 | [Min Stack](https://leetcode.com/problems/min-stack) | 🟡 `Medium` | [C++](Arrays/0155-min-stack/0155-min-stack.cpp) | Stack paired with secondary min-tracking stack for $O(1)$ getMin |
| 0225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | 🟢 `Easy` | [C++](Arrays/0225-implement-stack-using-queues/0225-implement-stack-using-queues.cpp) | Simulating LIFO behavior using queue rotations |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) | Bitwise check `n > 0 && (n & (n - 1)) == 0` |
| 0232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 `Easy` | [C++](Arrays/0232-implement-queue-using-stacks/0232-implement-queue-using-stacks.cpp) | FIFO queue simulation with input and output stacks amortized $O(1)$ |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) | Repeated trial division by prime factors 2, 3, and 5 |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) | Trial division or max integer power of three modulo check |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) | Power of two check combined with bit position mask `0x55555555` |
| 1392 | [Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix) | 🔴 `Hard` | [C++](Arrays/1392-longest-happy-prefix/1392-longest-happy-prefix.cpp) | KMP Longest Proper Prefix which is also Suffix (LPS array) computation |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring) | 🟡 `Medium` | [C++](Arrays/1910-remove-all-occurrences-of-a-substring/1910-remove-all-occurrences-of-a-substring.cpp) | Stack-based or string buffer matching and popping target substring |
| 2073 | [Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets) | 🟢 `Easy` | [C++](Arrays/2073-time-needed-to-buy-tickets/2073-time-needed-to-buy-tickets.cpp) | Direct single-pass calculation of tickets processed before position $k$ |


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
LeetCode-Questions/
│
├── BinarySearch/
│   ├── 0033-search-in-rotated-sorted-array/
│   ├── 0074-search-a-2d-matrix/
│   └── ... (25 problems)
├── Backtracking/
│   ├── 0037-sudoku-solver/
│   ├── 0039-combination-sum/
│   └── ... (12 problems)
├── Trees/
│   ├── 0014-longest-common-prefix/
│   ├── 0094-binary-tree-inorder-traversal/
│   └── ... (40 problems)
├── Graphs/
│   ├── 0133-clone-graph/
│   ├── 0200-number-of-islands/
│   └── ... (31 problems)
├── DynamicProgramming/
│   ├── 0005-longest-palindromic-substring/
│   ├── 0042-trapping-rain-water/
│   └── ... (27 problems)
├── Heaps/
│   ├── 0215-kth-largest-element-in-an-array/
│   ├── 0239-sliding-window-maximum/
│   └── ... (4 problems)
├── Greedy/
│   ├── 0011-container-with-most-water/
│   ├── 0122-best-time-to-buy-and-sell-stock-ii/
│   └── ... (3 problems)
├── BitManipulation/
│   ├── 0231-power-of-two/
│   ├── 0342-power-of-four/
├── Math/
│   ├── 0002-add-two-numbers/
│   ├── 0050-powx-n/
│   └── ... (5 problems)
├── Arrays/
│   ├── 0001-two-sum/
│   ├── 0003-longest-substring-without-repeating-characters/
│   └── ... (45 problems)
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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement))
                return {seen[complement], i};
            seen[nums[i]] = i;
        }
        return {};
    }
};
```

---

## 📋 Complete Problem Index

| # | Problem Name | Difficulty | Primary Topic | Problem Details | Solution |
|:---:|:---|:---:|:---|:---:|:---:|
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0001-two-sum/) | [C++](Arrays/0001-two-sum/0001-two-sum.cpp) |
| 0002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) | 🟡 `Medium` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0002-add-two-numbers/) | [C++](Math/0002-add-two-numbers/0002-add-two-numbers.cpp) |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0003-longest-substring-without-repeating-characters/) | [Java](Arrays/0003-longest-substring-without-repeating-characters/0003-longest-substring-without-repeating-characters.java) |
| 0005 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0005-longest-palindromic-substring/) | [C++](DynamicProgramming/0005-longest-palindromic-substring/0005-longest-palindromic-substring.cpp) |
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 `Medium` | [💡 Greedy Algorithms](Greedy/) | [Problem](Greedy/0011-container-with-most-water/) | [C++](Greedy/0011-container-with-most-water/0011-container-with-most-water.cpp) |
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0014-longest-common-prefix/) | [C++](Trees/0014-longest-common-prefix/0014-longest-common-prefix.cpp) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0015-3sum/) | [C++](Arrays/0015-3sum/0015-3sum.cpp) |
| 0018 | [4Sum](https://leetcode.com/problems/4sum) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0018-4sum/) | [C++](Arrays/0018-4sum/0018-4sum.cpp) |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0020-valid-parentheses/) | [C++](Arrays/0020-valid-parentheses/0020-valid-parentheses.cpp) |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0021-merge-two-sorted-lists/) | [C++](Arrays/0021-merge-two-sorted-lists/0021-merge-two-sorted-lists.cpp) |
| 0024 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0024-swap-nodes-in-pairs/) | [C++](Arrays/0024-swap-nodes-in-pairs/0024-swap-nodes-in-pairs.cpp) |
| 0025 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group) | 🔴 `Hard` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0025-reverse-nodes-in-k-group/) | [C++](Arrays/0025-reverse-nodes-in-k-group/0025-reverse-nodes-in-k-group.cpp) |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0031-next-permutation/) | [C++](Arrays/0031-next-permutation/0031-next-permutation.cpp) |
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |
| 0037 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver) | 🔴 `Hard` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0037-sudoku-solver/) | [C++](Backtracking/0037-sudoku-solver/0037-sudoku-solver.cpp) |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0039-combination-sum/) | [C++](Backtracking/0039-combination-sum/0039-combination-sum.cpp) |
| 0040 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0040-combination-sum-ii/) | [C++](Backtracking/0040-combination-sum-ii/0040-combination-sum-ii.cpp) |
| 0042 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0042-trapping-rain-water/) | [C++](DynamicProgramming/0042-trapping-rain-water/0042-trapping-rain-water.cpp) |
| 0046 | [Permutations](https://leetcode.com/problems/permutations) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0046-permutations/) | [C++](Backtracking/0046-permutations/0046-permutations.cpp) |
| 0049 | [Group Anagrams](https://leetcode.com/problems/group-anagrams) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0049-group-anagrams/) | [C++](Arrays/0049-group-anagrams/0049-group-anagrams.cpp) |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0050-powx-n/) | [C++](Math/0050-powx-n/0050-powx-n.cpp) |
| 0051 | [N-Queens](https://leetcode.com/problems/n-queens) | 🔴 `Hard` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0051-n-queens/) | [C++](Backtracking/0051-n-queens/0051-n-queens.cpp) |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0053-maximum-subarray/) | [C++](DynamicProgramming/0053-maximum-subarray/0053-maximum-subarray.cpp) |
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0054-spiral-matrix/) | [C++](Arrays/0054-spiral-matrix/0054-spiral-matrix.cpp) |
| 0056 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0056-merge-intervals/) | [C++](Arrays/0056-merge-intervals/0056-merge-intervals.cpp) |
| 0061 | [Rotate List](https://leetcode.com/problems/rotate-list) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0061-rotate-list/) | [C++](Arrays/0061-rotate-list/0061-rotate-list.cpp) |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0062-unique-paths/) | [C++](DynamicProgramming/0062-unique-paths/0062-unique-paths.cpp) |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0063-unique-paths-ii/) | [C++](DynamicProgramming/0063-unique-paths-ii/0063-unique-paths-ii.cpp) |
| 0072 | [Edit Distance](https://leetcode.com/problems/edit-distance) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0072-edit-distance/) | [C++](DynamicProgramming/0072-edit-distance/0072-edit-distance.cpp) |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0073-set-matrix-zeroes/) | [C++](Arrays/0073-set-matrix-zeroes/0073-set-matrix-zeroes.cpp) |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0074-search-a-2d-matrix/) | [C++](BinarySearch/0074-search-a-2d-matrix/0074-search-a-2d-matrix.cpp) |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0075-sort-colors/) | [C++](Arrays/0075-sort-colors/0075-sort-colors.cpp) |
| 0076 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) | 🔴 `Hard` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0076-minimum-window-substring/) | [C++](Arrays/0076-minimum-window-substring/0076-minimum-window-substring.cpp) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0078-subsets/) | [C++](Backtracking/0078-subsets/0078-subsets.cpp) |
| 0079 | [Word Search](https://leetcode.com/problems/word-search) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0079-word-search/) | [C++](Backtracking/0079-word-search/0079-word-search.cpp) |
| 0084 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram) | 🔴 `Hard` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0084-largest-rectangle-in-histogram/) | [C++](Arrays/0084-largest-rectangle-in-histogram/0084-largest-rectangle-in-histogram.cpp) |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0088-merge-sorted-array/) | [C++](Arrays/0088-merge-sorted-array/0088-merge-sorted-array.cpp) |
| 0090 | [Subsets II](https://leetcode.com/problems/subsets-ii) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0090-subsets-ii/) | [C++](Backtracking/0090-subsets-ii/0090-subsets-ii.cpp) |
| 0092 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0092-reverse-linked-list-ii/) | [C++](Arrays/0092-reverse-linked-list-ii/0092-reverse-linked-list-ii.cpp) |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0094-binary-tree-inorder-traversal/) | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0096-unique-binary-search-trees/) | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0098-validate-binary-search-tree/) | [C++](BinarySearch/0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp) |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0099-recover-binary-search-tree/) | [C++](BinarySearch/0099-recover-binary-search-tree/0099-recover-binary-search-tree.cpp) |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0100-same-tree/) | [C++](Trees/0100-same-tree/0100-same-tree.cpp) |
| 0101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0101-symmetric-tree/) | [C++](Trees/0101-symmetric-tree/0101-symmetric-tree.cpp) |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0102-binary-tree-level-order-traversal/) | [C++](Trees/0102-binary-tree-level-order-traversal/0102-binary-tree-level-order-traversal.cpp) |
| 0103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0103-binary-tree-zigzag-level-order-traversal/) | [C++](Trees/0103-binary-tree-zigzag-level-order-traversal/0103-binary-tree-zigzag-level-order-traversal.cpp) |
| 0105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/) | [C++](Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/0105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp) |
| 0106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/) | [C++](Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/0106-construct-binary-tree-from-inorder-and-postorder-traversal.cpp) |
| 0108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 `Easy` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/) | [C++](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/0108-convert-sorted-array-to-binary-search-tree.cpp) |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0110-balanced-binary-tree/) | [C++](Trees/0110-balanced-binary-tree/0110-balanced-binary-tree.cpp) |
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0111-minimum-depth-of-binary-tree/) | [C++](Trees/0111-minimum-depth-of-binary-tree/0111-minimum-depth-of-binary-tree.cpp) |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0112-path-sum/) | [C++](Trees/0112-path-sum/0112-path-sum.cpp) |
| 0113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0113-path-sum-ii/) | [C++](Backtracking/0113-path-sum-ii/0113-path-sum-ii.cpp) |
| 0114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0114-flatten-binary-tree-to-linked-list/) | [C++](Trees/0114-flatten-binary-tree-to-linked-list/0114-flatten-binary-tree-to-linked-list.cpp) |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0116-populating-next-right-pointers-in-each-node/) | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/) | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [💡 Greedy Algorithms](Greedy/) | [Problem](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 `Hard` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0124-binary-tree-maximum-path-sum/) | [C++](Trees/0124-binary-tree-maximum-path-sum/0124-binary-tree-maximum-path-sum.cpp) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0125-valid-palindrome/) | [C++](Arrays/0125-valid-palindrome/0125-valid-palindrome.cpp) |
| 0129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0129-sum-root-to-leaf-numbers/) | [C++](Trees/0129-sum-root-to-leaf-numbers/0129-sum-root-to-leaf-numbers.cpp) |
| 0131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0131-palindrome-partitioning/) | [C++](Backtracking/0131-palindrome-partitioning/0131-palindrome-partitioning.cpp) |
| 0132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0132-palindrome-partitioning-ii/) | [C++](DynamicProgramming/0132-palindrome-partitioning-ii/0132-palindrome-partitioning-ii.cpp) |
| 0133 | [Clone Graph](https://leetcode.com/problems/clone-graph) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0133-clone-graph/) | [C++](Graphs/0133-clone-graph/0133-clone-graph.cpp) |
| 0134 | [Gas Station](https://leetcode.com/problems/gas-station) | 🟡 `Medium` | [💡 Greedy Algorithms](Greedy/) | [Problem](Greedy/0134-gas-station/) | [C++](Greedy/0134-gas-station/0134-gas-station.cpp) |
| 0138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0138-copy-list-with-random-pointer/) | [C++](Arrays/0138-copy-list-with-random-pointer/0138-copy-list-with-random-pointer.cpp) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0141-linked-list-cycle/) | [C++](Arrays/0141-linked-list-cycle/0141-linked-list-cycle.cpp) |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0142-linked-list-cycle-ii/) | [C++](Arrays/0142-linked-list-cycle-ii/0142-linked-list-cycle-ii.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0146 | [LRU Cache](https://leetcode.com/problems/lru-cache) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0146-lru-cache/) | [C++](Arrays/0146-lru-cache/0146-lru-cache.cpp) |
| 0151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0151-reverse-words-in-a-string/) | [C++](Arrays/0151-reverse-words-in-a-string/0151-reverse-words-in-a-string.cpp) |
| 0155 | [Min Stack](https://leetcode.com/problems/min-stack) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0155-min-stack/) | [C++](Arrays/0155-min-stack/0155-min-stack.cpp) |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0169-majority-element/) | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0173-binary-search-tree-iterator/) | [C++](BinarySearch/0173-binary-search-tree-iterator/0173-binary-search-tree-iterator.cpp) |
| 0198 | [House Robber](https://leetcode.com/problems/house-robber) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0198-house-robber/) | [C++](DynamicProgramming/0198-house-robber/0198-house-robber.cpp) |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0199-binary-tree-right-side-view/) | [App 1](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view.cpp) · [App 2](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view-approach-2-bfs.cpp "BFS(Level Order Traversal)") · [App 3](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view-approach-3-dfs.cpp "DFS(Preorder Traversal)") |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0200-number-of-islands/) | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0206-reverse-linked-list/) | [C++](Arrays/0206-reverse-linked-list/0206-reverse-linked-list.cpp) |
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0207-course-schedule/) | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0210-course-schedule-ii/) | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0213-house-robber-ii/) | [C++](DynamicProgramming/0213-house-robber-ii/0213-house-robber-ii.cpp) |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |
| 0222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0222-count-complete-tree-nodes/) | [C++](BinarySearch/0222-count-complete-tree-nodes/0222-count-complete-tree-nodes.cpp) |
| 0225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0225-implement-stack-using-queues/) | [C++](Arrays/0225-implement-stack-using-queues/0225-implement-stack-using-queues.cpp) |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0230-kth-smallest-element-in-a-bst/) | [C++](BinarySearch/0230-kth-smallest-element-in-a-bst/0230-kth-smallest-element-in-a-bst.cpp) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0232-implement-queue-using-stacks/) | [C++](Arrays/0232-implement-queue-using-stacks/0232-implement-queue-using-stacks.cpp) |
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0234-palindrome-linked-list/) | [C++](Arrays/0234-palindrome-linked-list/0234-palindrome-linked-list.cpp) |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/) | [C++](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/0235-lowest-common-ancestor-of-a-binary-search-tree.cpp) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0236-lowest-common-ancestor-of-a-binary-tree/) | [C++](Trees/0236-lowest-common-ancestor-of-a-binary-tree/0236-lowest-common-ancestor-of-a-binary-tree.cpp) |
| 0238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0238-product-of-array-except-self/) | [C++](Arrays/0238-product-of-array-except-self/0238-product-of-array-except-self.cpp) |
| 0239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) | 🔴 `Hard` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0239-sliding-window-maximum/) | [C++](Heaps/0239-sliding-window-maximum/0239-sliding-window-maximum.cpp) |
| 0240 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0240-search-a-2d-matrix-ii/) | [C++](BinarySearch/0240-search-a-2d-matrix-ii/0240-search-a-2d-matrix-ii.cpp) |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0242-valid-anagram/) | [C++](Arrays/0242-valid-anagram/0242-valid-anagram.cpp) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0263-ugly-number/) | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0264-ugly-number-ii/) | [C++](DynamicProgramming/0264-ugly-number-ii/0264-ugly-number-ii.cpp) |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0279-perfect-squares/) | [C++](DynamicProgramming/0279-perfect-squares/0279-perfect-squares.cpp) |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0287-find-the-duplicate-number/) | [C++](BinarySearch/0287-find-the-duplicate-number/0287-find-the-duplicate-number.cpp) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0300-longest-increasing-subsequence/) | [C++](BinarySearch/0300-longest-increasing-subsequence/0300-longest-increasing-subsequence.cpp) |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0322-coin-change/) | [C++](Graphs/0322-coin-change/0322-coin-change.cpp) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0326-power-of-three/) | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0342-power-of-four/) | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0344-reverse-string/) | [C++](Arrays/0344-reverse-string/0344-reverse-string.cpp) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0347-top-k-frequent-elements/) | [C++](Heaps/0347-top-k-frequent-elements/0347-top-k-frequent-elements.cpp) |
| 0365 | [Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0365-water-and-jug-problem/) | [C++](Graphs/0365-water-and-jug-problem/0365-water-and-jug-problem.cpp) |
| 0368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0368-largest-divisible-subset/) | [C++](DynamicProgramming/0368-largest-divisible-subset/0368-largest-divisible-subset.cpp) |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/) | [C++](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/0378-kth-smallest-element-in-a-sorted-matrix.cpp) |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0387-first-unique-character-in-a-string/) | [C++](Arrays/0387-first-unique-character-in-a-string/0387-first-unique-character-in-a-string.cpp) |
| 0410 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum) | 🔴 `Hard` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0410-split-array-largest-sum/) | [C++](BinarySearch/0410-split-array-largest-sum/0410-split-array-largest-sum.cpp) |
| 0430 | [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0430-flatten-a-multilevel-doubly-linked-list/) | [C++](Graphs/0430-flatten-a-multilevel-doubly-linked-list/0430-flatten-a-multilevel-doubly-linked-list.cpp) |
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0433-minimum-genetic-mutation/) | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0443-string-compression/) | [C++](Arrays/0443-string-compression/0443-string-compression.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 0493 | [Reverse Pairs](https://leetcode.com/problems/reverse-pairs) | 🔴 `Hard` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0493-reverse-pairs/) | [C++](BinarySearch/0493-reverse-pairs/0493-reverse-pairs.cpp) |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0494-target-sum/) | [C++](Backtracking/0494-target-sum/0494-target-sum.cpp) |
| 0496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0496-next-greater-element-i/) | [C++](Arrays/0496-next-greater-element-i/0496-next-greater-element-i.cpp) |
| 0503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0503-next-greater-element-ii/) | [C++](Arrays/0503-next-greater-element-ii/0503-next-greater-element-ii.cpp) |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 `Easy` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0509-fibonacci-number/) | [C++](DynamicProgramming/0509-fibonacci-number/0509-fibonacci-number.cpp) |
| 0515 | [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0515-find-largest-value-in-each-tree-row/) | [C++](Trees/0515-find-largest-value-in-each-tree-row/0515-find-largest-value-in-each-tree-row.cpp) |
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0516-longest-palindromic-subsequence/) | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0540-single-element-in-a-sorted-array/) | [C++](BinarySearch/0540-single-element-in-a-sorted-array/0540-single-element-in-a-sorted-array.cpp) |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0542-01-matrix/) | [C++](Graphs/0542-01-matrix/0542-01-matrix.cpp) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0543-diameter-of-binary-tree/) | [C++](Trees/0543-diameter-of-binary-tree/0543-diameter-of-binary-tree.cpp) |
| 0547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0547-number-of-provinces/) | [C++](Graphs/0547-number-of-provinces/0547-number-of-provinces.cpp) |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0560-subarray-sum-equals-k/) | [C++](Arrays/0560-subarray-sum-equals-k/0560-subarray-sum-equals-k.cpp) |
| 0567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0567-permutation-in-string/) | [C++](Arrays/0567-permutation-in-string/0567-permutation-in-string.cpp) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0572-subtree-of-another-tree/) | [C++](Trees/0572-subtree-of-another-tree/0572-subtree-of-another-tree.cpp) |
| 0623 | [Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0623-add-one-row-to-tree/) | [C++](Trees/0623-add-one-row-to-tree/0623-add-one-row-to-tree.cpp) |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0646-maximum-length-of-pair-chain/) | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) |
| 0647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0647-palindromic-substrings/) | [C++](DynamicProgramming/0647-palindromic-substrings/0647-palindromic-substrings.cpp) |
| 0652 | [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0652-find-duplicate-subtrees/) | [C++](Trees/0652-find-duplicate-subtrees/0652-find-duplicate-subtrees.cpp) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0662-maximum-width-of-binary-tree/) | [C++](Trees/0662-maximum-width-of-binary-tree/0662-maximum-width-of-binary-tree.cpp) |
| 0684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0684-redundant-connection/) | [C++](Graphs/0684-redundant-connection/0684-redundant-connection.cpp) |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 `Easy` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0703-kth-largest-element-in-a-stream/) | [C++](BinarySearch/0703-kth-largest-element-in-a-stream/0703-kth-largest-element-in-a-stream.cpp) |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search) | 🟢 `Easy` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0704-binary-search/) | [C++](BinarySearch/0704-binary-search/0704-binary-search.cpp) |
| 0733 | [Flood Fill](https://leetcode.com/problems/flood-fill) | 🟢 `Easy` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0733-flood-fill/) | [C++](Graphs/0733-flood-fill/0733-flood-fill.cpp) |
| 0743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0743-network-delay-time/) | [C++](Graphs/0743-network-delay-time/0743-network-delay-time.cpp) |
| 0783 | [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) | 🟢 `Easy` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0783-minimum-distance-between-bst-nodes/) | [C++](BinarySearch/0783-minimum-distance-between-bst-nodes/0783-minimum-distance-between-bst-nodes.cpp) |
| 0785 | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0785-is-graph-bipartite/) | [C++](Graphs/0785-is-graph-bipartite/0785-is-graph-bipartite.cpp) |
| 0787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0787-cheapest-flights-within-k-stops/) | [C++](Graphs/0787-cheapest-flights-within-k-stops/0787-cheapest-flights-within-k-stops.cpp) |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0797-all-paths-from-source-to-target/) | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) |
| 0814 | [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0814-binary-tree-pruning/) | [C++](Trees/0814-binary-tree-pruning/0814-binary-tree-pruning.cpp) |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0841-keys-and-rooms/) | [Approach 1](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/0841-keys-and-rooms/0841-keys-and-rooms-approach-2-dfs.cpp "DFS") |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0852-peak-index-in-a-mountain-array/) | [C++](BinarySearch/0852-peak-index-in-a-mountain-array/0852-peak-index-in-a-mountain-array.cpp) |
| 0863 | [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0863-all-nodes-distance-k-in-binary-tree/) | [C++](Trees/0863-all-nodes-distance-k-in-binary-tree/0863-all-nodes-distance-k-in-binary-tree.cpp) |
| 0872 | [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0872-leaf-similar-trees/) | [C++](Trees/0872-leaf-similar-trees/0872-leaf-similar-trees.cpp) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0876-middle-of-the-linked-list/) | [C++](Arrays/0876-middle-of-the-linked-list/0876-middle-of-the-linked-list.cpp) |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0901-online-stock-span/) | [C++](Arrays/0901-online-stock-span/0901-online-stock-span.cpp) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0912-sort-an-array/) | [C++](Heaps/0912-sort-an-array/0912-sort-an-array.cpp) |
| 0947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0947-most-stones-removed-with-same-row-or-column/) | [C++](Graphs/0947-most-stones-removed-with-same-row-or-column/0947-most-stones-removed-with-same-row-or-column.cpp) |
| 0958 | [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0958-check-completeness-of-a-binary-tree/) | [C++](Trees/0958-check-completeness-of-a-binary-tree/0958-check-completeness-of-a-binary-tree.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 0994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0994-rotting-oranges/) | [C++](Graphs/0994-rotting-oranges/0994-rotting-oranges.cpp) |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/) | [C++](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/1008-construct-binary-search-tree-from-preorder-traversal.cpp) |
| 1026 | [Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1026-maximum-difference-between-node-and-ancestor/) | [Approach 1](Trees/1026-maximum-difference-between-node-and-ancestor/1026-maximum-difference-between-node-and-ancestor.cpp "Brute Force(Using two separate DFS)") · [Approach 2](Trees/1026-maximum-difference-between-node-and-ancestor/1026-maximum-difference-between-node-and-ancestor-approach-2-optimal.cpp "Optimal(DFS + Min/Max on Current Path)") |
| 1038 | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/) | [C++](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/1038-binary-search-tree-to-greater-sum-tree.cpp) |
| 1048 | [Longest String Chain](https://leetcode.com/problems/longest-string-chain) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1048-longest-string-chain/) | [C++](DynamicProgramming/1048-longest-string-chain/1048-longest-string-chain.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1091-shortest-path-in-binary-matrix/) | [Approach 1](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix-approach-2-dijkstras-algorithm.cpp "Dijkstra's Algorithm") |
| 1092 | [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1092-shortest-common-supersequence/) | [C++](DynamicProgramming/1092-shortest-common-supersequence/1092-shortest-common-supersequence.cpp) |
| 1110 | [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1110-delete-nodes-and-return-forest/) | [C++](Trees/1110-delete-nodes-and-return-forest/1110-delete-nodes-and-return-forest.cpp) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1143-longest-common-subsequence/) | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1161-maximum-level-sum-of-a-binary-tree/) | [C++](Trees/1161-maximum-level-sum-of-a-binary-tree/1161-maximum-level-sum-of-a-binary-tree.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/) | [C++](DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/1312-minimum-insertion-steps-to-make-a-string-palindrome.cpp) |
| 1319 | [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1319-number-of-operations-to-make-network-connected/) | [C++](Graphs/1319-number-of-operations-to-make-network-connected/1319-number-of-operations-to-make-network-connected.cpp) |
| 1334 | [Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) | [C++](Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1339 | [Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1339-maximum-product-of-splitted-binary-tree/) | [C++](Trees/1339-maximum-product-of-splitted-binary-tree/1339-maximum-product-of-splitted-binary-tree.cpp) |
| 1361 | [Validate Binary Tree Nodes](https://leetcode.com/problems/validate-binary-tree-nodes) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1361-validate-binary-tree-nodes/) | [C++](Trees/1361-validate-binary-tree-nodes/1361-validate-binary-tree-nodes.cpp) |
| 1392 | [Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix) | 🔴 `Hard` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/1392-longest-happy-prefix/) | [C++](Arrays/1392-longest-happy-prefix/1392-longest-happy-prefix.cpp) |
| 1420 | [Build Array Where You Can Find The Maximum Exactly K Comparisons](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/) | [C++](DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1584-min-cost-to-connect-all-points/) | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1631-path-with-minimum-effort/) | [App 1](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort.cpp "Dijkstra's Algorithm") · [App 2](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort-approach-2.cpp) · [App 3](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort-approach-3-dijkstras-algorithm.cpp "Dijkstra's Algorithm") |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/1910-remove-all-occurrences-of-a-substring/) | [C++](Arrays/1910-remove-all-occurrences-of-a-substring/1910-remove-all-occurrences-of-a-substring.cpp) |
| 1911 | [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1911-maximum-alternating-subsequence-sum/) | [C++](DynamicProgramming/1911-maximum-alternating-subsequence-sum/1911-maximum-alternating-subsequence-sum.cpp) |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1932 | [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst) | 🔴 `Hard` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1932-merge-bsts-to-create-single-bst/) | [C++](BinarySearch/1932-merge-bsts-to-create-single-bst/1932-merge-bsts-to-create-single-bst.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1976-number-of-ways-to-arrive-at-destination/) | [C++](Graphs/1976-number-of-ways-to-arrive-at-destination/1976-number-of-ways-to-arrive-at-destination.cpp) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/) | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/) | [C++](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/2064-minimized-maximum-of-products-distributed-to-any-store.cpp) |
| 2073 | [Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/2073-time-needed-to-buy-tickets/) | [C++](Arrays/2073-time-needed-to-buy-tickets/2073-time-needed-to-buy-tickets.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |
| 2316 | [Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/) | [C++](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |
| 2596 | [Check Knight Tour Configuration](https://leetcode.com/problems/check-knight-tour-configuration) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/2596-check-knight-tour-configuration/) | [C++](Graphs/2596-check-knight-tour-configuration/2596-check-knight-tour-configuration.cpp) |
| 2965 | [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/2965-find-missing-and-repeated-values/) | [C++](Math/2965-find-missing-and-repeated-values/2965-find-missing-and-repeated-values.cpp) |

---

## 📂 Topic-wise Problem Breakdown

### 🔍 [Binary Search](BinarySearch/) (25)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 `Medium` | [Problem Notes](BinarySearch/0074-search-a-2d-matrix/) | [C++](BinarySearch/0074-search-a-2d-matrix/0074-search-a-2d-matrix.cpp) |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0098-validate-binary-search-tree/) | [C++](BinarySearch/0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp) |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0099-recover-binary-search-tree/) | [C++](BinarySearch/0099-recover-binary-search-tree/0099-recover-binary-search-tree.cpp) |
| 0108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 `Easy` | [Problem Notes](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/) | [C++](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/0108-convert-sorted-array-to-binary-search-tree.cpp) |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | 🟡 `Medium` | [Problem Notes](BinarySearch/0173-binary-search-tree-iterator/) | [C++](BinarySearch/0173-binary-search-tree-iterator/0173-binary-search-tree-iterator.cpp) |
| 0222 | [Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes) | 🟡 `Medium` | [Problem Notes](BinarySearch/0222-count-complete-tree-nodes/) | [C++](BinarySearch/0222-count-complete-tree-nodes/0222-count-complete-tree-nodes.cpp) |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 `Medium` | [Problem Notes](BinarySearch/0230-kth-smallest-element-in-a-bst/) | [C++](BinarySearch/0230-kth-smallest-element-in-a-bst/0230-kth-smallest-element-in-a-bst.cpp) |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/) | [C++](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/0235-lowest-common-ancestor-of-a-binary-search-tree.cpp) |
| 0240 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii) | 🟡 `Medium` | [Problem Notes](BinarySearch/0240-search-a-2d-matrix-ii/) | [C++](BinarySearch/0240-search-a-2d-matrix-ii/0240-search-a-2d-matrix-ii.cpp) |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 `Medium` | [Problem Notes](BinarySearch/0287-find-the-duplicate-number/) | [C++](BinarySearch/0287-find-the-duplicate-number/0287-find-the-duplicate-number.cpp) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 `Medium` | [Problem Notes](BinarySearch/0300-longest-increasing-subsequence/) | [C++](BinarySearch/0300-longest-increasing-subsequence/0300-longest-increasing-subsequence.cpp) |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix) | 🟡 `Medium` | [Problem Notes](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/) | [C++](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/0378-kth-smallest-element-in-a-sorted-matrix.cpp) |
| 0410 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum) | 🔴 `Hard` | [Problem Notes](BinarySearch/0410-split-array-largest-sum/) | [C++](BinarySearch/0410-split-array-largest-sum/0410-split-array-largest-sum.cpp) |
| 0493 | [Reverse Pairs](https://leetcode.com/problems/reverse-pairs) | 🔴 `Hard` | [Problem Notes](BinarySearch/0493-reverse-pairs/) | [C++](BinarySearch/0493-reverse-pairs/0493-reverse-pairs.cpp) |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0540-single-element-in-a-sorted-array/) | [C++](BinarySearch/0540-single-element-in-a-sorted-array/0540-single-element-in-a-sorted-array.cpp) |
| 0703 | [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream) | 🟢 `Easy` | [Problem Notes](BinarySearch/0703-kth-largest-element-in-a-stream/) | [C++](BinarySearch/0703-kth-largest-element-in-a-stream/0703-kth-largest-element-in-a-stream.cpp) |
| 0704 | [Binary Search](https://leetcode.com/problems/binary-search) | 🟢 `Easy` | [Problem Notes](BinarySearch/0704-binary-search/) | [C++](BinarySearch/0704-binary-search/0704-binary-search.cpp) |
| 0783 | [Minimum Distance Between BST Nodes](https://leetcode.com/problems/minimum-distance-between-bst-nodes) | 🟢 `Easy` | [Problem Notes](BinarySearch/0783-minimum-distance-between-bst-nodes/) | [C++](BinarySearch/0783-minimum-distance-between-bst-nodes/0783-minimum-distance-between-bst-nodes.cpp) |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0852-peak-index-in-a-mountain-array/) | [C++](BinarySearch/0852-peak-index-in-a-mountain-array/0852-peak-index-in-a-mountain-array.cpp) |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal) | 🟡 `Medium` | [Problem Notes](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/) | [C++](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/1008-construct-binary-search-tree-from-preorder-traversal.cpp) |
| 1038 | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/) | [C++](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/1038-binary-search-tree-to-greater-sum-tree.cpp) |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort) | 🟡 `Medium` | [Problem Notes](BinarySearch/1631-path-with-minimum-effort/) | [App 1](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort.cpp "Dijkstra's Algorithm") · [App 2](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort-approach-2.cpp) · [App 3](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort-approach-3-dijkstras-algorithm.cpp "Dijkstra's Algorithm") |
| 1932 | [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst) | 🔴 `Hard` | [Problem Notes](BinarySearch/1932-merge-bsts-to-create-single-bst/) | [C++](BinarySearch/1932-merge-bsts-to-create-single-bst/1932-merge-bsts-to-create-single-bst.cpp) |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) | 🟡 `Medium` | [Problem Notes](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/) | [C++](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/2064-minimized-maximum-of-products-distributed-to-any-store.cpp) |

### 🔄 [Backtracking](Backtracking/) (12)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0037 | [Sudoku Solver](https://leetcode.com/problems/sudoku-solver) | 🔴 `Hard` | [Problem Notes](Backtracking/0037-sudoku-solver/) | [C++](Backtracking/0037-sudoku-solver/0037-sudoku-solver.cpp) |
| 0039 | [Combination Sum](https://leetcode.com/problems/combination-sum) | 🟡 `Medium` | [Problem Notes](Backtracking/0039-combination-sum/) | [C++](Backtracking/0039-combination-sum/0039-combination-sum.cpp) |
| 0040 | [Combination Sum II](https://leetcode.com/problems/combination-sum-ii) | 🟡 `Medium` | [Problem Notes](Backtracking/0040-combination-sum-ii/) | [C++](Backtracking/0040-combination-sum-ii/0040-combination-sum-ii.cpp) |
| 0046 | [Permutations](https://leetcode.com/problems/permutations) | 🟡 `Medium` | [Problem Notes](Backtracking/0046-permutations/) | [C++](Backtracking/0046-permutations/0046-permutations.cpp) |
| 0051 | [N-Queens](https://leetcode.com/problems/n-queens) | 🔴 `Hard` | [Problem Notes](Backtracking/0051-n-queens/) | [C++](Backtracking/0051-n-queens/0051-n-queens.cpp) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 `Medium` | [Problem Notes](Backtracking/0078-subsets/) | [C++](Backtracking/0078-subsets/0078-subsets.cpp) |
| 0079 | [Word Search](https://leetcode.com/problems/word-search) | 🟡 `Medium` | [Problem Notes](Backtracking/0079-word-search/) | [C++](Backtracking/0079-word-search/0079-word-search.cpp) |
| 0090 | [Subsets II](https://leetcode.com/problems/subsets-ii) | 🟡 `Medium` | [Problem Notes](Backtracking/0090-subsets-ii/) | [C++](Backtracking/0090-subsets-ii/0090-subsets-ii.cpp) |
| 0113 | [Path Sum II](https://leetcode.com/problems/path-sum-ii/) | 🟡 `Medium` | [Problem Notes](Backtracking/0113-path-sum-ii/) | [C++](Backtracking/0113-path-sum-ii/0113-path-sum-ii.cpp) |
| 0131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning) | 🟡 `Medium` | [Problem Notes](Backtracking/0131-palindrome-partitioning/) | [C++](Backtracking/0131-palindrome-partitioning/0131-palindrome-partitioning.cpp) |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum) | 🟡 `Medium` | [Problem Notes](Backtracking/0494-target-sum/) | [C++](Backtracking/0494-target-sum/0494-target-sum.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [Problem Notes](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |

### 🌳 [Trees & Binary Search Trees](Trees/) (40)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0014 | [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix) | 🟢 `Easy` | [Problem Notes](Trees/0014-longest-common-prefix/) | [C++](Trees/0014-longest-common-prefix/0014-longest-common-prefix.cpp) |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0094-binary-tree-inorder-traversal/) | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [Problem Notes](Trees/0096-unique-binary-search-trees/) | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) |
| 0100 | [Same Tree](https://leetcode.com/problems/same-tree) | 🟢 `Easy` | [Problem Notes](Trees/0100-same-tree/) | [C++](Trees/0100-same-tree/0100-same-tree.cpp) |
| 0101 | [Symmetric Tree](https://leetcode.com/problems/symmetric-tree) | 🟢 `Easy` | [Problem Notes](Trees/0101-symmetric-tree/) | [C++](Trees/0101-symmetric-tree/0101-symmetric-tree.cpp) |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) | 🟡 `Medium` | [Problem Notes](Trees/0102-binary-tree-level-order-traversal/) | [C++](Trees/0102-binary-tree-level-order-traversal/0102-binary-tree-level-order-traversal.cpp) |
| 0103 | [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal) | 🟡 `Medium` | [Problem Notes](Trees/0103-binary-tree-zigzag-level-order-traversal/) | [C++](Trees/0103-binary-tree-zigzag-level-order-traversal/0103-binary-tree-zigzag-level-order-traversal.cpp) |
| 0105 | [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal) | 🟡 `Medium` | [Problem Notes](Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/) | [C++](Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal/0105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp) |
| 0106 | [Construct Binary Tree from Inorder and Postorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal) | 🟡 `Medium` | [Problem Notes](Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/) | [C++](Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal/0106-construct-binary-tree-from-inorder-and-postorder-traversal.cpp) |
| 0110 | [Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree) | 🟢 `Easy` | [Problem Notes](Trees/0110-balanced-binary-tree/) | [C++](Trees/0110-balanced-binary-tree/0110-balanced-binary-tree.cpp) |
| 0111 | [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree) | 🟢 `Easy` | [Problem Notes](Trees/0111-minimum-depth-of-binary-tree/) | [C++](Trees/0111-minimum-depth-of-binary-tree/0111-minimum-depth-of-binary-tree.cpp) |
| 0112 | [Path Sum](https://leetcode.com/problems/path-sum) | 🟢 `Easy` | [Problem Notes](Trees/0112-path-sum/) | [C++](Trees/0112-path-sum/0112-path-sum.cpp) |
| 0114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list) | 🟡 `Medium` | [Problem Notes](Trees/0114-flatten-binary-tree-to-linked-list/) | [C++](Trees/0114-flatten-binary-tree-to-linked-list/0114-flatten-binary-tree-to-linked-list.cpp) |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [Problem Notes](Trees/0116-populating-next-right-pointers-in-each-node/) | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 `Hard` | [Problem Notes](Trees/0124-binary-tree-maximum-path-sum/) | [C++](Trees/0124-binary-tree-maximum-path-sum/0124-binary-tree-maximum-path-sum.cpp) |
| 0129 | [Sum Root to Leaf Numbers](https://leetcode.com/problems/sum-root-to-leaf-numbers) | 🟡 `Medium` | [Problem Notes](Trees/0129-sum-root-to-leaf-numbers/) | [C++](Trees/0129-sum-root-to-leaf-numbers/0129-sum-root-to-leaf-numbers.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0199 | [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view) | 🟡 `Medium` | [Problem Notes](Trees/0199-binary-tree-right-side-view/) | [App 1](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view.cpp) · [App 2](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view-approach-2-bfs.cpp "BFS(Level Order Traversal)") · [App 3](Trees/0199-binary-tree-right-side-view/0199-binary-tree-right-side-view-approach-3-dfs.cpp "DFS(Preorder Traversal)") |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/0236-lowest-common-ancestor-of-a-binary-tree/) | [C++](Trees/0236-lowest-common-ancestor-of-a-binary-tree/0236-lowest-common-ancestor-of-a-binary-tree.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [Problem Notes](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 0515 | [Find Largest Value in Each Tree Row](https://leetcode.com/problems/find-largest-value-in-each-tree-row) | 🟡 `Medium` | [Problem Notes](Trees/0515-find-largest-value-in-each-tree-row/) | [C++](Trees/0515-find-largest-value-in-each-tree-row/0515-find-largest-value-in-each-tree-row.cpp) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree) | 🟢 `Easy` | [Problem Notes](Trees/0543-diameter-of-binary-tree/) | [C++](Trees/0543-diameter-of-binary-tree/0543-diameter-of-binary-tree.cpp) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 `Easy` | [Problem Notes](Trees/0572-subtree-of-another-tree/) | [C++](Trees/0572-subtree-of-another-tree/0572-subtree-of-another-tree.cpp) |
| 0623 | [Add One Row to Tree](https://leetcode.com/problems/add-one-row-to-tree) | 🟡 `Medium` | [Problem Notes](Trees/0623-add-one-row-to-tree/) | [C++](Trees/0623-add-one-row-to-tree/0623-add-one-row-to-tree.cpp) |
| 0652 | [Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees) | 🟡 `Medium` | [Problem Notes](Trees/0652-find-duplicate-subtrees/) | [C++](Trees/0652-find-duplicate-subtrees/0652-find-duplicate-subtrees.cpp) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/0662-maximum-width-of-binary-tree/) | [C++](Trees/0662-maximum-width-of-binary-tree/0662-maximum-width-of-binary-tree.cpp) |
| 0814 | [Binary Tree Pruning](https://leetcode.com/problems/binary-tree-pruning) | 🟡 `Medium` | [Problem Notes](Trees/0814-binary-tree-pruning/) | [C++](Trees/0814-binary-tree-pruning/0814-binary-tree-pruning.cpp) |
| 0863 | [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/) | 🟡 `Medium` | [Problem Notes](Trees/0863-all-nodes-distance-k-in-binary-tree/) | [C++](Trees/0863-all-nodes-distance-k-in-binary-tree/0863-all-nodes-distance-k-in-binary-tree.cpp) |
| 0872 | [Leaf-Similar Trees](https://leetcode.com/problems/leaf-similar-trees) | 🟢 `Easy` | [Problem Notes](Trees/0872-leaf-similar-trees/) | [C++](Trees/0872-leaf-similar-trees/0872-leaf-similar-trees.cpp) |
| 0958 | [Check Completeness of a Binary Tree](https://leetcode.com/problems/check-completeness-of-a-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/0958-check-completeness-of-a-binary-tree/) | [C++](Trees/0958-check-completeness-of-a-binary-tree/0958-check-completeness-of-a-binary-tree.cpp) |
| 1026 | [Maximum Difference Between Node and Ancestor](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/) | 🟡 `Medium` | [Problem Notes](Trees/1026-maximum-difference-between-node-and-ancestor/) | [Approach 1](Trees/1026-maximum-difference-between-node-and-ancestor/1026-maximum-difference-between-node-and-ancestor.cpp "Brute Force(Using two separate DFS)") · [Approach 2](Trees/1026-maximum-difference-between-node-and-ancestor/1026-maximum-difference-between-node-and-ancestor-approach-2-optimal.cpp "Optimal(DFS + Min/Max on Current Path)") |
| 1110 | [Delete Nodes And Return Forest](https://leetcode.com/problems/delete-nodes-and-return-forest) | 🟡 `Medium` | [Problem Notes](Trees/1110-delete-nodes-and-return-forest/) | [C++](Trees/1110-delete-nodes-and-return-forest/1110-delete-nodes-and-return-forest.cpp) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/1161-maximum-level-sum-of-a-binary-tree/) | [C++](Trees/1161-maximum-level-sum-of-a-binary-tree/1161-maximum-level-sum-of-a-binary-tree.cpp) |
| 1339 | [Maximum Product of Splitted Binary Tree](https://leetcode.com/problems/maximum-product-of-splitted-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/1339-maximum-product-of-splitted-binary-tree/) | [C++](Trees/1339-maximum-product-of-splitted-binary-tree/1339-maximum-product-of-splitted-binary-tree.cpp) |
| 1361 | [Validate Binary Tree Nodes](https://leetcode.com/problems/validate-binary-tree-nodes) | 🟡 `Medium` | [Problem Notes](Trees/1361-validate-binary-tree-nodes/) | [C++](Trees/1361-validate-binary-tree-nodes/1361-validate-binary-tree-nodes.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [Problem Notes](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [Problem Notes](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [Problem Notes](Trees/1584-min-cost-to-connect-all-points/) | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [Problem Notes](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |

### 🕸️ [Graphs & BFS/DFS](Graphs/) (31)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0133 | [Clone Graph](https://leetcode.com/problems/clone-graph) | 🟡 `Medium` | [Problem Notes](Graphs/0133-clone-graph/) | [C++](Graphs/0133-clone-graph/0133-clone-graph.cpp) |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [Problem Notes](Graphs/0200-number-of-islands/) | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) |
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [Problem Notes](Graphs/0207-course-schedule/) | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [Problem Notes](Graphs/0210-course-schedule-ii/) | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change) | 🟡 `Medium` | [Problem Notes](Graphs/0322-coin-change/) | [C++](Graphs/0322-coin-change/0322-coin-change.cpp) |
| 0365 | [Water and Jug Problem](https://leetcode.com/problems/water-and-jug-problem/) | 🟡 `Medium` | [Problem Notes](Graphs/0365-water-and-jug-problem/) | [C++](Graphs/0365-water-and-jug-problem/0365-water-and-jug-problem.cpp) |
| 0430 | [Flatten a Multilevel Doubly Linked List](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list) | 🟡 `Medium` | [Problem Notes](Graphs/0430-flatten-a-multilevel-doubly-linked-list/) | [C++](Graphs/0430-flatten-a-multilevel-doubly-linked-list/0430-flatten-a-multilevel-doubly-linked-list.cpp) |
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [Problem Notes](Graphs/0433-minimum-genetic-mutation/) | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix) | 🟡 `Medium` | [Problem Notes](Graphs/0542-01-matrix/) | [C++](Graphs/0542-01-matrix/0542-01-matrix.cpp) |
| 0547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces) | 🟡 `Medium` | [Problem Notes](Graphs/0547-number-of-provinces/) | [C++](Graphs/0547-number-of-provinces/0547-number-of-provinces.cpp) |
| 0684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection) | 🟡 `Medium` | [Problem Notes](Graphs/0684-redundant-connection/) | [C++](Graphs/0684-redundant-connection/0684-redundant-connection.cpp) |
| 0733 | [Flood Fill](https://leetcode.com/problems/flood-fill) | 🟢 `Easy` | [Problem Notes](Graphs/0733-flood-fill/) | [C++](Graphs/0733-flood-fill/0733-flood-fill.cpp) |
| 0743 | [Network Delay Time](https://leetcode.com/problems/network-delay-time) | 🟡 `Medium` | [Problem Notes](Graphs/0743-network-delay-time/) | [C++](Graphs/0743-network-delay-time/0743-network-delay-time.cpp) |
| 0785 | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite) | 🟡 `Medium` | [Problem Notes](Graphs/0785-is-graph-bipartite/) | [C++](Graphs/0785-is-graph-bipartite/0785-is-graph-bipartite.cpp) |
| 0787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops) | 🟡 `Medium` | [Problem Notes](Graphs/0787-cheapest-flights-within-k-stops/) | [C++](Graphs/0787-cheapest-flights-within-k-stops/0787-cheapest-flights-within-k-stops.cpp) |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [Problem Notes](Graphs/0797-all-paths-from-source-to-target/) | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [Problem Notes](Graphs/0841-keys-and-rooms/) | [Approach 1](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/0841-keys-and-rooms/0841-keys-and-rooms-approach-2-dfs.cpp "DFS") |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [Problem Notes](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column) | 🟡 `Medium` | [Problem Notes](Graphs/0947-most-stones-removed-with-same-row-or-column/) | [C++](Graphs/0947-most-stones-removed-with-same-row-or-column/0947-most-stones-removed-with-same-row-or-column.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [Problem Notes](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 0994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges) | 🟡 `Medium` | [Problem Notes](Graphs/0994-rotting-oranges/) | [C++](Graphs/0994-rotting-oranges/0994-rotting-oranges.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [Problem Notes](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix) | 🟡 `Medium` | [Problem Notes](Graphs/1091-shortest-path-in-binary-matrix/) | [Approach 1](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix-approach-2-dijkstras-algorithm.cpp "Dijkstra's Algorithm") |
| 1319 | [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | 🟡 `Medium` | [Problem Notes](Graphs/1319-number-of-operations-to-make-network-connected/) | [C++](Graphs/1319-number-of-operations-to-make-network-connected/1319-number-of-operations-to-make-network-connected.cpp) |
| 1334 | [Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance) | 🟡 `Medium` | [Problem Notes](Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/) | [C++](Graphs/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1334-find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance.cpp) |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [Problem Notes](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [Problem Notes](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) | 🟡 `Medium` | [Problem Notes](Graphs/1976-number-of-ways-to-arrive-at-destination/) | [C++](Graphs/1976-number-of-ways-to-arrive-at-destination/1976-number-of-ways-to-arrive-at-destination.cpp) |
| 2316 | [Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph) | 🟡 `Medium` | [Problem Notes](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/) | [C++](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [Problem Notes](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |
| 2596 | [Check Knight Tour Configuration](https://leetcode.com/problems/check-knight-tour-configuration) | 🟡 `Medium` | [Problem Notes](Graphs/2596-check-knight-tour-configuration/) | [C++](Graphs/2596-check-knight-tour-configuration/2596-check-knight-tour-configuration.cpp) |

### 🧩 [Dynamic Programming](DynamicProgramming/) (27)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0005 | [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0005-longest-palindromic-substring/) | [C++](DynamicProgramming/0005-longest-palindromic-substring/0005-longest-palindromic-substring.cpp) |
| 0042 | [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/0042-trapping-rain-water/) | [C++](DynamicProgramming/0042-trapping-rain-water/0042-trapping-rain-water.cpp) |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0053-maximum-subarray/) | [C++](DynamicProgramming/0053-maximum-subarray/0053-maximum-subarray.cpp) |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0062-unique-paths/) | [C++](DynamicProgramming/0062-unique-paths/0062-unique-paths.cpp) |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0063-unique-paths-ii/) | [C++](DynamicProgramming/0063-unique-paths-ii/0063-unique-paths-ii.cpp) |
| 0072 | [Edit Distance](https://leetcode.com/problems/edit-distance) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0072-edit-distance/) | [C++](DynamicProgramming/0072-edit-distance/0072-edit-distance.cpp) |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [Problem Notes](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/) | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) |
| 0132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/0132-palindrome-partitioning-ii/) | [C++](DynamicProgramming/0132-palindrome-partitioning-ii/0132-palindrome-partitioning-ii.cpp) |
| 0198 | [House Robber](https://leetcode.com/problems/house-robber) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0198-house-robber/) | [C++](DynamicProgramming/0198-house-robber/0198-house-robber.cpp) |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0213-house-robber-ii/) | [C++](DynamicProgramming/0213-house-robber-ii/0213-house-robber-ii.cpp) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0264-ugly-number-ii/) | [C++](DynamicProgramming/0264-ugly-number-ii/0264-ugly-number-ii.cpp) |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0279-perfect-squares/) | [C++](DynamicProgramming/0279-perfect-squares/0279-perfect-squares.cpp) |
| 0368 | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0368-largest-divisible-subset/) | [C++](DynamicProgramming/0368-largest-divisible-subset/0368-largest-divisible-subset.cpp) |
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 `Easy` | [Problem Notes](DynamicProgramming/0509-fibonacci-number/) | [C++](DynamicProgramming/0509-fibonacci-number/0509-fibonacci-number.cpp) |
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0516-longest-palindromic-subsequence/) | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0646-maximum-length-of-pair-chain/) | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) |
| 0647 | [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0647-palindromic-substrings/) | [C++](DynamicProgramming/0647-palindromic-substrings/0647-palindromic-substrings.cpp) |
| 1048 | [Longest String Chain](https://leetcode.com/problems/longest-string-chain) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1048-longest-string-chain/) | [C++](DynamicProgramming/1048-longest-string-chain/1048-longest-string-chain.cpp) |
| 1092 | [Shortest Common Supersequence](https://leetcode.com/problems/shortest-common-supersequence) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1092-shortest-common-supersequence/) | [C++](DynamicProgramming/1092-shortest-common-supersequence/1092-shortest-common-supersequence.cpp) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1143-longest-common-subsequence/) | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) |
| 1312 | [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/) | [C++](DynamicProgramming/1312-minimum-insertion-steps-to-make-a-string-palindrome/1312-minimum-insertion-steps-to-make-a-string-palindrome.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1420 | [Build Array Where You Can Find The Maximum Exactly K Comparisons](https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/) | [C++](DynamicProgramming/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons/1420-build-array-where-you-can-find-the-maximum-exactly-k-comparisons.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 1911 | [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1911-maximum-alternating-subsequence-sum/) | [C++](DynamicProgramming/1911-maximum-alternating-subsequence-sum/1911-maximum-alternating-subsequence-sum.cpp) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/) | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) |

### ⛰️ [Heaps & Priority Queues](Heaps/) (4)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [Problem Notes](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |
| 0239 | [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum) | 🔴 `Hard` | [Problem Notes](Heaps/0239-sliding-window-maximum/) | [C++](Heaps/0239-sliding-window-maximum/0239-sliding-window-maximum.cpp) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 `Medium` | [Problem Notes](Heaps/0347-top-k-frequent-elements/) | [C++](Heaps/0347-top-k-frequent-elements/0347-top-k-frequent-elements.cpp) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 `Medium` | [Problem Notes](Heaps/0912-sort-an-array/) | [C++](Heaps/0912-sort-an-array/0912-sort-an-array.cpp) |

### 💡 [Greedy Algorithms](Greedy/) (3)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0011 | [Container With Most Water](https://leetcode.com/problems/container-with-most-water) | 🟡 `Medium` | [Problem Notes](Greedy/0011-container-with-most-water/) | [C++](Greedy/0011-container-with-most-water/0011-container-with-most-water.cpp) |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [Problem Notes](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |
| 0134 | [Gas Station](https://leetcode.com/problems/gas-station) | 🟡 `Medium` | [Problem Notes](Greedy/0134-gas-station/) | [C++](Greedy/0134-gas-station/0134-gas-station.cpp) |

### ⚡ [Bit Manipulation](BitManipulation/) (2)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [Problem Notes](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [Problem Notes](BitManipulation/0342-power-of-four/) | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) |

### 🔢 [Math & Number Theory](Math/) (5)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0002 | [Add Two Numbers](https://leetcode.com/problems/add-two-numbers) | 🟡 `Medium` | [Problem Notes](Math/0002-add-two-numbers/) | [C++](Math/0002-add-two-numbers/0002-add-two-numbers.cpp) |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [Problem Notes](Math/0050-powx-n/) | [C++](Math/0050-powx-n/0050-powx-n.cpp) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [Problem Notes](Math/0263-ugly-number/) | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [Problem Notes](Math/0326-power-of-three/) | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) |
| 2965 | [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values) | 🟢 `Easy` | [Problem Notes](Math/2965-find-missing-and-repeated-values/) | [C++](Math/2965-find-missing-and-repeated-values/2965-find-missing-and-repeated-values.cpp) |

### 📦 [Arrays & Hashing](Arrays/) (45)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum) | 🟢 `Easy` | [Problem Notes](Arrays/0001-two-sum/) | [C++](Arrays/0001-two-sum/0001-two-sum.cpp) |
| 0003 | [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters) | 🟡 `Medium` | [Problem Notes](Arrays/0003-longest-substring-without-repeating-characters/) | [Java](Arrays/0003-longest-substring-without-repeating-characters/0003-longest-substring-without-repeating-characters.java) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 `Medium` | [Problem Notes](Arrays/0015-3sum/) | [C++](Arrays/0015-3sum/0015-3sum.cpp) |
| 0018 | [4Sum](https://leetcode.com/problems/4sum) | 🟡 `Medium` | [Problem Notes](Arrays/0018-4sum/) | [C++](Arrays/0018-4sum/0018-4sum.cpp) |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 `Easy` | [Problem Notes](Arrays/0020-valid-parentheses/) | [C++](Arrays/0020-valid-parentheses/0020-valid-parentheses.cpp) |
| 0021 | [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists) | 🟢 `Easy` | [Problem Notes](Arrays/0021-merge-two-sorted-lists/) | [C++](Arrays/0021-merge-two-sorted-lists/0021-merge-two-sorted-lists.cpp) |
| 0024 | [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs) | 🟡 `Medium` | [Problem Notes](Arrays/0024-swap-nodes-in-pairs/) | [C++](Arrays/0024-swap-nodes-in-pairs/0024-swap-nodes-in-pairs.cpp) |
| 0025 | [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group) | 🔴 `Hard` | [Problem Notes](Arrays/0025-reverse-nodes-in-k-group/) | [C++](Arrays/0025-reverse-nodes-in-k-group/0025-reverse-nodes-in-k-group.cpp) |
| 0031 | [Next Permutation](https://leetcode.com/problems/next-permutation) | 🟡 `Medium` | [Problem Notes](Arrays/0031-next-permutation/) | [C++](Arrays/0031-next-permutation/0031-next-permutation.cpp) |
| 0049 | [Group Anagrams](https://leetcode.com/problems/group-anagrams) | 🟡 `Medium` | [Problem Notes](Arrays/0049-group-anagrams/) | [C++](Arrays/0049-group-anagrams/0049-group-anagrams.cpp) |
| 0054 | [Spiral Matrix](https://leetcode.com/problems/spiral-matrix) | 🟡 `Medium` | [Problem Notes](Arrays/0054-spiral-matrix/) | [C++](Arrays/0054-spiral-matrix/0054-spiral-matrix.cpp) |
| 0056 | [Merge Intervals](https://leetcode.com/problems/merge-intervals) | 🟡 `Medium` | [Problem Notes](Arrays/0056-merge-intervals/) | [C++](Arrays/0056-merge-intervals/0056-merge-intervals.cpp) |
| 0061 | [Rotate List](https://leetcode.com/problems/rotate-list) | 🟡 `Medium` | [Problem Notes](Arrays/0061-rotate-list/) | [C++](Arrays/0061-rotate-list/0061-rotate-list.cpp) |
| 0073 | [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes) | 🟡 `Medium` | [Problem Notes](Arrays/0073-set-matrix-zeroes/) | [C++](Arrays/0073-set-matrix-zeroes/0073-set-matrix-zeroes.cpp) |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 `Medium` | [Problem Notes](Arrays/0075-sort-colors/) | [C++](Arrays/0075-sort-colors/0075-sort-colors.cpp) |
| 0076 | [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring) | 🔴 `Hard` | [Problem Notes](Arrays/0076-minimum-window-substring/) | [C++](Arrays/0076-minimum-window-substring/0076-minimum-window-substring.cpp) |
| 0084 | [Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram) | 🔴 `Hard` | [Problem Notes](Arrays/0084-largest-rectangle-in-histogram/) | [C++](Arrays/0084-largest-rectangle-in-histogram/0084-largest-rectangle-in-histogram.cpp) |
| 0088 | [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array) | 🟢 `Easy` | [Problem Notes](Arrays/0088-merge-sorted-array/) | [C++](Arrays/0088-merge-sorted-array/0088-merge-sorted-array.cpp) |
| 0092 | [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii) | 🟡 `Medium` | [Problem Notes](Arrays/0092-reverse-linked-list-ii/) | [C++](Arrays/0092-reverse-linked-list-ii/0092-reverse-linked-list-ii.cpp) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 `Easy` | [Problem Notes](Arrays/0125-valid-palindrome/) | [C++](Arrays/0125-valid-palindrome/0125-valid-palindrome.cpp) |
| 0138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) | 🟡 `Medium` | [Problem Notes](Arrays/0138-copy-list-with-random-pointer/) | [C++](Arrays/0138-copy-list-with-random-pointer/0138-copy-list-with-random-pointer.cpp) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 `Easy` | [Problem Notes](Arrays/0141-linked-list-cycle/) | [C++](Arrays/0141-linked-list-cycle/0141-linked-list-cycle.cpp) |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 `Medium` | [Problem Notes](Arrays/0142-linked-list-cycle-ii/) | [C++](Arrays/0142-linked-list-cycle-ii/0142-linked-list-cycle-ii.cpp) |
| 0146 | [LRU Cache](https://leetcode.com/problems/lru-cache) | 🟡 `Medium` | [Problem Notes](Arrays/0146-lru-cache/) | [C++](Arrays/0146-lru-cache/0146-lru-cache.cpp) |
| 0151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string) | 🟡 `Medium` | [Problem Notes](Arrays/0151-reverse-words-in-a-string/) | [C++](Arrays/0151-reverse-words-in-a-string/0151-reverse-words-in-a-string.cpp) |
| 0155 | [Min Stack](https://leetcode.com/problems/min-stack) | 🟡 `Medium` | [Problem Notes](Arrays/0155-min-stack/) | [C++](Arrays/0155-min-stack/0155-min-stack.cpp) |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [Problem Notes](Arrays/0169-majority-element/) | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 `Easy` | [Problem Notes](Arrays/0206-reverse-linked-list/) | [C++](Arrays/0206-reverse-linked-list/0206-reverse-linked-list.cpp) |
| 0225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | 🟢 `Easy` | [Problem Notes](Arrays/0225-implement-stack-using-queues/) | [C++](Arrays/0225-implement-stack-using-queues/0225-implement-stack-using-queues.cpp) |
| 0232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 `Easy` | [Problem Notes](Arrays/0232-implement-queue-using-stacks/) | [C++](Arrays/0232-implement-queue-using-stacks/0232-implement-queue-using-stacks.cpp) |
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 `Easy` | [Problem Notes](Arrays/0234-palindrome-linked-list/) | [C++](Arrays/0234-palindrome-linked-list/0234-palindrome-linked-list.cpp) |
| 0238 | [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self) | 🟡 `Medium` | [Problem Notes](Arrays/0238-product-of-array-except-self/) | [C++](Arrays/0238-product-of-array-except-self/0238-product-of-array-except-self.cpp) |
| 0242 | [Valid Anagram](https://leetcode.com/problems/valid-anagram) | 🟢 `Easy` | [Problem Notes](Arrays/0242-valid-anagram/) | [C++](Arrays/0242-valid-anagram/0242-valid-anagram.cpp) |
| 0344 | [Reverse String](https://leetcode.com/problems/reverse-string) | 🟢 `Easy` | [Problem Notes](Arrays/0344-reverse-string/) | [C++](Arrays/0344-reverse-string/0344-reverse-string.cpp) |
| 0387 | [First Unique Character in a String](https://leetcode.com/problems/first-unique-character-in-a-string) | 🟢 `Easy` | [Problem Notes](Arrays/0387-first-unique-character-in-a-string/) | [C++](Arrays/0387-first-unique-character-in-a-string/0387-first-unique-character-in-a-string.cpp) |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression) | 🟡 `Medium` | [Problem Notes](Arrays/0443-string-compression/) | [C++](Arrays/0443-string-compression/0443-string-compression.cpp) |
| 0496 | [Next Greater Element I](https://leetcode.com/problems/next-greater-element-i) | 🟢 `Easy` | [Problem Notes](Arrays/0496-next-greater-element-i/) | [C++](Arrays/0496-next-greater-element-i/0496-next-greater-element-i.cpp) |
| 0503 | [Next Greater Element II](https://leetcode.com/problems/next-greater-element-ii) | 🟡 `Medium` | [Problem Notes](Arrays/0503-next-greater-element-ii/) | [C++](Arrays/0503-next-greater-element-ii/0503-next-greater-element-ii.cpp) |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 `Medium` | [Problem Notes](Arrays/0560-subarray-sum-equals-k/) | [C++](Arrays/0560-subarray-sum-equals-k/0560-subarray-sum-equals-k.cpp) |
| 0567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string) | 🟡 `Medium` | [Problem Notes](Arrays/0567-permutation-in-string/) | [C++](Arrays/0567-permutation-in-string/0567-permutation-in-string.cpp) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 `Easy` | [Problem Notes](Arrays/0876-middle-of-the-linked-list/) | [C++](Arrays/0876-middle-of-the-linked-list/0876-middle-of-the-linked-list.cpp) |
| 0901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span) | 🟡 `Medium` | [Problem Notes](Arrays/0901-online-stock-span/) | [C++](Arrays/0901-online-stock-span/0901-online-stock-span.cpp) |
| 1392 | [Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix) | 🔴 `Hard` | [Problem Notes](Arrays/1392-longest-happy-prefix/) | [C++](Arrays/1392-longest-happy-prefix/1392-longest-happy-prefix.cpp) |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring) | 🟡 `Medium` | [Problem Notes](Arrays/1910-remove-all-occurrences-of-a-substring/) | [C++](Arrays/1910-remove-all-occurrences-of-a-substring/1910-remove-all-occurrences-of-a-substring.cpp) |
| 2073 | [Time Needed to Buy Tickets](https://leetcode.com/problems/time-needed-to-buy-tickets) | 🟢 `Easy` | [Problem Notes](Arrays/2073-time-needed-to-buy-tickets/) | [C++](Arrays/2073-time-needed-to-buy-tickets/2073-time-needed-to-buy-tickets.cpp) |

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

<!---LeetCode Topics Start-->
# LeetCode Topics
## Tree
|  |
| ------- |
| [0515-find-largest-value-in-each-tree-row](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0515-find-largest-value-in-each-tree-row) |
## Depth-First Search
|  |
| ------- |
| [0515-find-largest-value-in-each-tree-row](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0515-find-largest-value-in-each-tree-row) |
## Breadth-First Search
|  |
| ------- |
| [0515-find-largest-value-in-each-tree-row](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0515-find-largest-value-in-each-tree-row) |
## Binary Tree
|  |
| ------- |
| [0515-find-largest-value-in-each-tree-row](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0515-find-largest-value-in-each-tree-row) |
<!---LeetCode Topics End-->