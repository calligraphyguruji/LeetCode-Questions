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

| Metric | Count | Percentage |
|:---|:---:|:---:|
| 🟢 **Easy** | 39 | 23.5% |
| 🟡 **Medium** | 109 | 65.7% |
| 🔴 **Hard** | 18 | 10.8% |
| 🎯 **Total Solved** | **166** | **100%** |

</div>

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
│   └── ... (24 problems)
├── Backtracking/
│   ├── 0037-sudoku-solver/
│   ├── 0039-combination-sum/
│   └── ... (11 problems)
├── Trees/
│   ├── 0014-longest-common-prefix/
│   ├── 0094-binary-tree-inorder-traversal/
│   └── ... (25 problems)
├── Graphs/
│   ├── 0133-clone-graph/
│   ├── 0200-number-of-islands/
│   └── ... (29 problems)
├── DynamicProgramming/
│   ├── 0042-trapping-rain-water/
│   ├── 0053-maximum-subarray/
│   └── ... (20 problems)
├── Heaps/
│   ├── 0215-kth-largest-element-in-an-array/
│   ├── 0239-sliding-window-maximum/
│   └── ... (4 problems)
├── Greedy/
│   ├── 0122-best-time-to-buy-and-sell-stock-ii/
│   ├── 0134-gas-station/
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
│   └── ... (44 problems)
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
| 0114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0114-flatten-binary-tree-to-linked-list/) | [C++](Trees/0114-flatten-binary-tree-to-linked-list/0114-flatten-binary-tree-to-linked-list.cpp) |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0116-populating-next-right-pointers-in-each-node/) | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/) | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [💡 Greedy Algorithms](Greedy/) | [Problem](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 `Hard` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0124-binary-tree-maximum-path-sum/) | [C++](Trees/0124-binary-tree-maximum-path-sum/0124-binary-tree-maximum-path-sum.cpp) |
| 0125 | [Valid Palindrome](https://leetcode.com/problems/valid-palindrome) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0125-valid-palindrome/) | [C++](Arrays/0125-valid-palindrome/0125-valid-palindrome.cpp) |
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
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0200-number-of-islands/) | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) |
| 0206 | [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0206-reverse-linked-list/) | [C++](Arrays/0206-reverse-linked-list/0206-reverse-linked-list.cpp) |
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0207-course-schedule/) | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0210-course-schedule-ii/) | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0213-house-robber-ii/) | [C++](DynamicProgramming/0213-house-robber-ii/0213-house-robber-ii.cpp) |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |
| 0225 | [Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0225-implement-stack-using-queues/) | [C++](Arrays/0225-implement-stack-using-queues/0225-implement-stack-using-queues.cpp) |
| 0230 | [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0230-kth-smallest-element-in-a-bst/) | [C++](BinarySearch/0230-kth-smallest-element-in-a-bst/0230-kth-smallest-element-in-a-bst.cpp) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0232 | [Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0232-implement-queue-using-stacks/) | [C++](Arrays/0232-implement-queue-using-stacks/0232-implement-queue-using-stacks.cpp) |
| 0234 | [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0234-palindrome-linked-list/) | [C++](Arrays/0234-palindrome-linked-list/0234-palindrome-linked-list.cpp) |
| 0235 | [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/) | [C++](BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree/0235-lowest-common-ancestor-of-a-binary-search-tree.cpp) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0236-lowest-common-ancestor-of-a-binary-tree/) | [C++](Trees/0236-lowest-common-ancestor-of-a-binary-tree/0236-lowest-common-ancestor-of-a-binary-tree.cpp) |
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
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0516-longest-palindromic-subsequence/) | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) |
| 0540 | [Single Element in a Sorted Array](https://leetcode.com/problems/single-element-in-a-sorted-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0540-single-element-in-a-sorted-array/) | [C++](BinarySearch/0540-single-element-in-a-sorted-array/0540-single-element-in-a-sorted-array.cpp) |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0542-01-matrix/) | [C++](Graphs/0542-01-matrix/0542-01-matrix.cpp) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0543-diameter-of-binary-tree/) | [C++](Trees/0543-diameter-of-binary-tree/0543-diameter-of-binary-tree.cpp) |
| 0547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0547-number-of-provinces/) | [C++](Graphs/0547-number-of-provinces/0547-number-of-provinces.cpp) |
| 0560 | [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0560-subarray-sum-equals-k/) | [C++](Arrays/0560-subarray-sum-equals-k/0560-subarray-sum-equals-k.cpp) |
| 0567 | [Permutation in String](https://leetcode.com/problems/permutation-in-string) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0567-permutation-in-string/) | [C++](Arrays/0567-permutation-in-string/0567-permutation-in-string.cpp) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0572-subtree-of-another-tree/) | [C++](Trees/0572-subtree-of-another-tree/0572-subtree-of-another-tree.cpp) |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0646-maximum-length-of-pair-chain/) | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) |
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
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0841-keys-and-rooms/) | [Approach 1](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/0841-keys-and-rooms/0841-keys-and-rooms-approach-2-dfs.cpp "DFS") |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0852-peak-index-in-a-mountain-array/) | [C++](BinarySearch/0852-peak-index-in-a-mountain-array/0852-peak-index-in-a-mountain-array.cpp) |
| 0876 | [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0876-middle-of-the-linked-list/) | [C++](Arrays/0876-middle-of-the-linked-list/0876-middle-of-the-linked-list.cpp) |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0901-online-stock-span/) | [C++](Arrays/0901-online-stock-span/0901-online-stock-span.cpp) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0912-sort-an-array/) | [C++](Heaps/0912-sort-an-array/0912-sort-an-array.cpp) |
| 0947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0947-most-stones-removed-with-same-row-or-column/) | [C++](Graphs/0947-most-stones-removed-with-same-row-or-column/0947-most-stones-removed-with-same-row-or-column.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 0994 | [Rotting Oranges](https://leetcode.com/problems/rotting-oranges) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0994-rotting-oranges/) | [C++](Graphs/0994-rotting-oranges/0994-rotting-oranges.cpp) |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/) | [C++](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/1008-construct-binary-search-tree-from-preorder-traversal.cpp) |
| 1038 | [Binary Search Tree to Greater Sum Tree](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/) | [C++](BinarySearch/1038-binary-search-tree-to-greater-sum-tree/1038-binary-search-tree-to-greater-sum-tree.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1091 | [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1091-shortest-path-in-binary-matrix/) | [Approach 1](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix.cpp "BFS(Breadth First Search)") · [Approach 2](Graphs/1091-shortest-path-in-binary-matrix/1091-shortest-path-in-binary-matrix-approach-2-dijkstras-algorithm.cpp "Dijkstra's Algorithm") |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1143-longest-common-subsequence/) | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1161-maximum-level-sum-of-a-binary-tree/) | [C++](Trees/1161-maximum-level-sum-of-a-binary-tree/1161-maximum-level-sum-of-a-binary-tree.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |
| 1319 | [Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1319-number-of-operations-to-make-network-connected/) | [C++](Graphs/1319-number-of-operations-to-make-network-connected/1319-number-of-operations-to-make-network-connected.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1392 | [Longest Happy Prefix](https://leetcode.com/problems/longest-happy-prefix) | 🔴 `Hard` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/1392-longest-happy-prefix/) | [C++](Arrays/1392-longest-happy-prefix/1392-longest-happy-prefix.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1584-min-cost-to-connect-all-points/) | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1631-path-with-minimum-effort/) | [C++](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort.cpp) |
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

### 🔍 [Binary Search](BinarySearch/) (24)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |
| 0074 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix) | 🟡 `Medium` | [Problem Notes](BinarySearch/0074-search-a-2d-matrix/) | [C++](BinarySearch/0074-search-a-2d-matrix/0074-search-a-2d-matrix.cpp) |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0098-validate-binary-search-tree/) | [C++](BinarySearch/0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp) |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0099-recover-binary-search-tree/) | [C++](BinarySearch/0099-recover-binary-search-tree/0099-recover-binary-search-tree.cpp) |
| 0108 | [Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree) | 🟢 `Easy` | [Problem Notes](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/) | [C++](BinarySearch/0108-convert-sorted-array-to-binary-search-tree/0108-convert-sorted-array-to-binary-search-tree.cpp) |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | 🟡 `Medium` | [Problem Notes](BinarySearch/0173-binary-search-tree-iterator/) | [C++](BinarySearch/0173-binary-search-tree-iterator/0173-binary-search-tree-iterator.cpp) |
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
| 1631 | [Path With Minimum Effort](https://leetcode.com/problems/path-with-minimum-effort) | 🟡 `Medium` | [Problem Notes](BinarySearch/1631-path-with-minimum-effort/) | [C++](BinarySearch/1631-path-with-minimum-effort/1631-path-with-minimum-effort.cpp) |
| 1932 | [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst) | 🔴 `Hard` | [Problem Notes](BinarySearch/1932-merge-bsts-to-create-single-bst/) | [C++](BinarySearch/1932-merge-bsts-to-create-single-bst/1932-merge-bsts-to-create-single-bst.cpp) |
| 2064 | [Minimized Maximum of Products Distributed to Any Store](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store) | 🟡 `Medium` | [Problem Notes](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/) | [C++](BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store/2064-minimized-maximum-of-products-distributed-to-any-store.cpp) |

### 🔄 [Backtracking](Backtracking/) (11)

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
| 0131 | [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning) | 🟡 `Medium` | [Problem Notes](Backtracking/0131-palindrome-partitioning/) | [C++](Backtracking/0131-palindrome-partitioning/0131-palindrome-partitioning.cpp) |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum) | 🟡 `Medium` | [Problem Notes](Backtracking/0494-target-sum/) | [C++](Backtracking/0494-target-sum/0494-target-sum.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [Problem Notes](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |

### 🌳 [Trees & Binary Search Trees](Trees/) (25)

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
| 0114 | [Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list) | 🟡 `Medium` | [Problem Notes](Trees/0114-flatten-binary-tree-to-linked-list/) | [C++](Trees/0114-flatten-binary-tree-to-linked-list/0114-flatten-binary-tree-to-linked-list.cpp) |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [Problem Notes](Trees/0116-populating-next-right-pointers-in-each-node/) | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) |
| 0124 | [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum) | 🔴 `Hard` | [Problem Notes](Trees/0124-binary-tree-maximum-path-sum/) | [C++](Trees/0124-binary-tree-maximum-path-sum/0124-binary-tree-maximum-path-sum.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0236 | [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/0236-lowest-common-ancestor-of-a-binary-tree/) | [C++](Trees/0236-lowest-common-ancestor-of-a-binary-tree/0236-lowest-common-ancestor-of-a-binary-tree.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [Problem Notes](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 0543 | [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree) | 🟢 `Easy` | [Problem Notes](Trees/0543-diameter-of-binary-tree/) | [C++](Trees/0543-diameter-of-binary-tree/0543-diameter-of-binary-tree.cpp) |
| 0572 | [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree) | 🟢 `Easy` | [Problem Notes](Trees/0572-subtree-of-another-tree/) | [C++](Trees/0572-subtree-of-another-tree/0572-subtree-of-another-tree.cpp) |
| 0662 | [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/0662-maximum-width-of-binary-tree/) | [C++](Trees/0662-maximum-width-of-binary-tree/0662-maximum-width-of-binary-tree.cpp) |
| 1161 | [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree) | 🟡 `Medium` | [Problem Notes](Trees/1161-maximum-level-sum-of-a-binary-tree/) | [C++](Trees/1161-maximum-level-sum-of-a-binary-tree/1161-maximum-level-sum-of-a-binary-tree.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [Problem Notes](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [Problem Notes](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [Problem Notes](Trees/1584-min-cost-to-connect-all-points/) | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [Problem Notes](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |

### 🕸️ [Graphs & BFS/DFS](Graphs/) (29)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0133 | [Clone Graph](https://leetcode.com/problems/clone-graph) | 🟡 `Medium` | [Problem Notes](Graphs/0133-clone-graph/) | [C++](Graphs/0133-clone-graph/0133-clone-graph.cpp) |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [Problem Notes](Graphs/0200-number-of-islands/) | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) |
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [Problem Notes](Graphs/0207-course-schedule/) | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [Problem Notes](Graphs/0210-course-schedule-ii/) | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change) | 🟡 `Medium` | [Problem Notes](Graphs/0322-coin-change/) | [C++](Graphs/0322-coin-change/0322-coin-change.cpp) |
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
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [Problem Notes](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [Problem Notes](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) | 🟡 `Medium` | [Problem Notes](Graphs/1976-number-of-ways-to-arrive-at-destination/) | [C++](Graphs/1976-number-of-ways-to-arrive-at-destination/1976-number-of-ways-to-arrive-at-destination.cpp) |
| 2316 | [Count Unreachable Pairs of Nodes in an Undirected Graph](https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph) | 🟡 `Medium` | [Problem Notes](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/) | [C++](Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [Problem Notes](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |
| 2596 | [Check Knight Tour Configuration](https://leetcode.com/problems/check-knight-tour-configuration) | 🟡 `Medium` | [Problem Notes](Graphs/2596-check-knight-tour-configuration/) | [C++](Graphs/2596-check-knight-tour-configuration/2596-check-knight-tour-configuration.cpp) |

### 🧩 [Dynamic Programming](DynamicProgramming/) (20)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
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
| 0509 | [Fibonacci Number](https://leetcode.com/problems/fibonacci-number) | 🟢 `Easy` | [Problem Notes](DynamicProgramming/0509-fibonacci-number/) | [C++](DynamicProgramming/0509-fibonacci-number/0509-fibonacci-number.cpp) |
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0516-longest-palindromic-subsequence/) | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0646-maximum-length-of-pair-chain/) | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1143-longest-common-subsequence/) | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
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

### 💡 [Greedy Algorithms](Greedy/) (2)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
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

### 📦 [Arrays & Hashing](Arrays/) (44)

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

⭐ If you find this repository helpful for your own DSA practice, feel free to star it! A collection of LeetCode questions to ace the coding interview! - Created using [LeetHub v2](https://github.com/arunbhardwaj/LeetHub-2.0)

<!---LeetCode Topics Start-->
# LeetCode Topics
## Math
|  |
| ------- |
| [0002-add-two-numbers](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0002-add-two-numbers) |
| [0050-powx-n](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0050-powx-n) |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0231-power-of-two](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0231-power-of-two) |
| [0263-ugly-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0263-ugly-number) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0326-power-of-three](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0326-power-of-three) |
| [0342-power-of-four](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0342-power-of-four) |
| [0509-fibonacci-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0509-fibonacci-number) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Dynamic Programming
|  |
| ------- |
| [0042-trapping-rain-water](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0042-trapping-rain-water) |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0072-edit-distance](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0072-edit-distance) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0121-best-time-to-buy-and-sell-stock](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0121-best-time-to-buy-and-sell-stock) |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0124-binary-tree-maximum-path-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0124-binary-tree-maximum-path-sum) |
| [0131-palindrome-partitioning](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0131-palindrome-partitioning) |
| [0132-palindrome-partitioning-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0132-palindrome-partitioning-ii) |
| [0198-house-robber](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0198-house-robber) |
| [0213-house-robber-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0213-house-robber-ii) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
| [0410-split-array-largest-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0410-split-array-largest-sum) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
| [0509-fibonacci-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0509-fibonacci-number) |
| [0516-longest-palindromic-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0516-longest-palindromic-subsequence) |
| [0542-01-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0542-01-matrix) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [1143-longest-common-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1143-longest-common-subsequence) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1911-maximum-alternating-subsequence-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1911-maximum-alternating-subsequence-sum) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Tree
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0100-same-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0100-same-tree) |
| [0101-symmetric-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0101-symmetric-tree) |
| [0102-binary-tree-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0102-binary-tree-level-order-traversal) |
| [0103-binary-tree-zigzag-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0103-binary-tree-zigzag-level-order-traversal) |
| [0105-construct-binary-tree-from-preorder-and-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal) |
| [0106-construct-binary-tree-from-inorder-and-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0108-convert-sorted-array-to-binary-search-tree) |
| [0110-balanced-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0110-balanced-binary-tree) |
| [0114-flatten-binary-tree-to-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0114-flatten-binary-tree-to-linked-list) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0124-binary-tree-maximum-path-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0124-binary-tree-maximum-path-sum) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0236-lowest-common-ancestor-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0236-lowest-common-ancestor-of-a-binary-tree) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [0543-diameter-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0543-diameter-of-binary-tree) |
| [0662-maximum-width-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0662-maximum-width-of-binary-tree) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0703-kth-largest-element-in-a-stream) |
| [0783-minimum-distance-between-bst-nodes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0783-minimum-distance-between-bst-nodes) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1038-binary-search-tree-to-greater-sum-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1038-binary-search-tree-to-greater-sum-tree) |
| [1161-maximum-level-sum-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1161-maximum-level-sum-of-a-binary-tree) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Binary Search Tree
|  |
| ------- |
| [0033-search-in-rotated-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0033-search-in-rotated-sorted-array) |
| [0074-search-a-2d-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0074-search-a-2d-matrix) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0108-convert-sorted-array-to-binary-search-tree) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0240-search-a-2d-matrix-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0240-search-a-2d-matrix-ii) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0410-split-array-largest-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0410-split-array-largest-sum) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
| [0540-single-element-in-a-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0540-single-element-in-a-sorted-array) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0703-kth-largest-element-in-a-stream) |
| [0704-binary-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0704-binary-search) |
| [0783-minimum-distance-between-bst-nodes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0783-minimum-distance-between-bst-nodes) |
| [0852-peak-index-in-a-mountain-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0852-peak-index-in-a-mountain-array) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1038-binary-search-tree-to-greater-sum-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1038-binary-search-tree-to-greater-sum-tree) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
| [2064-minimized-maximum-of-products-distributed-to-any-store](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store) |
## Binary Tree
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0100-same-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0100-same-tree) |
| [0101-symmetric-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0101-symmetric-tree) |
| [0102-binary-tree-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0102-binary-tree-level-order-traversal) |
| [0103-binary-tree-zigzag-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0103-binary-tree-zigzag-level-order-traversal) |
| [0105-construct-binary-tree-from-preorder-and-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal) |
| [0106-construct-binary-tree-from-inorder-and-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0108-convert-sorted-array-to-binary-search-tree) |
| [0110-balanced-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0110-balanced-binary-tree) |
| [0114-flatten-binary-tree-to-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0114-flatten-binary-tree-to-linked-list) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0124-binary-tree-maximum-path-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0124-binary-tree-maximum-path-sum) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0236-lowest-common-ancestor-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0236-lowest-common-ancestor-of-a-binary-tree) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [0543-diameter-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0543-diameter-of-binary-tree) |
| [0662-maximum-width-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0662-maximum-width-of-binary-tree) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0703-kth-largest-element-in-a-stream) |
| [0783-minimum-distance-between-bst-nodes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0783-minimum-distance-between-bst-nodes) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1038-binary-search-tree-to-greater-sum-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1038-binary-search-tree-to-greater-sum-tree) |
| [1161-maximum-level-sum-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1161-maximum-level-sum-of-a-binary-tree) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
## Array
|  |
| ------- |
| [0001-two-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0001-two-sum) |
| [0014-longest-common-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0014-longest-common-prefix) |
| [0015-3sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0015-3sum) |
| [0018-4sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0018-4sum) |
| [0031-next-permutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0031-next-permutation) |
| [0033-search-in-rotated-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0033-search-in-rotated-sorted-array) |
| [0037-sudoku-solver](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0037-sudoku-solver) |
| [0039-combination-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0039-combination-sum) |
| [0040-combination-sum-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0040-combination-sum-ii) |
| [0042-trapping-rain-water](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0042-trapping-rain-water) |
| [0046-permutations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0046-permutations) |
| [0049-group-anagrams](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0049-group-anagrams) |
| [0051-n-queens](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0051-n-queens) |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0054-spiral-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0054-spiral-matrix) |
| [0056-merge-intervals](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0056-merge-intervals) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0073-set-matrix-zeroes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0073-set-matrix-zeroes) |
| [0074-search-a-2d-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0074-search-a-2d-matrix) |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
| [0078-subsets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0078-subsets) |
| [0079-word-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0079-word-search) |
| [0084-largest-rectangle-in-histogram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0084-largest-rectangle-in-histogram) |
| [0088-merge-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0088-merge-sorted-array) |
| [0090-subsets-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0090-subsets-ii) |
| [0105-construct-binary-tree-from-preorder-and-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal) |
| [0106-construct-binary-tree-from-inorder-and-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0108-convert-sorted-array-to-binary-search-tree) |
| [0121-best-time-to-buy-and-sell-stock](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0121-best-time-to-buy-and-sell-stock) |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0134-gas-station](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0134-gas-station) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0198-house-robber](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0198-house-robber) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0213-house-robber-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0213-house-robber-ii) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0239-sliding-window-maximum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0239-sliding-window-maximum) |
| [0240-search-a-2d-matrix-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0240-search-a-2d-matrix-ii) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0410-split-array-largest-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0410-split-array-largest-sum) |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
| [0496-next-greater-element-i](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0496-next-greater-element-i) |
| [0503-next-greater-element-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0503-next-greater-element-ii) |
| [0540-single-element-in-a-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0540-single-element-in-a-sorted-array) |
| [0542-01-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0542-01-matrix) |
| [0560-subarray-sum-equals-k](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0560-subarray-sum-equals-k) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
| [0704-binary-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0704-binary-search) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0852-peak-index-in-a-mountain-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0852-peak-index-in-a-mountain-array) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [0994-rotting-oranges](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0994-rotting-oranges) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1091-shortest-path-in-binary-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1091-shortest-path-in-binary-matrix) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1911-maximum-alternating-subsequence-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1911-maximum-alternating-subsequence-sum) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
| [2064-minimized-maximum-of-products-distributed-to-any-store](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store) |
| [2073-time-needed-to-buy-tickets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/2073-time-needed-to-buy-tickets) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
| [2596-check-knight-tour-configuration](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2596-check-knight-tour-configuration) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Sorting
|  |
| ------- |
| [0015-3sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0015-3sum) |
| [0018-4sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0018-4sum) |
| [0049-group-anagrams](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0049-group-anagrams) |
| [0056-merge-intervals](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0056-merge-intervals) |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
| [0088-merge-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0088-merge-sorted-array) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0242-valid-anagram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0242-valid-anagram) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Two Pointers
|  |
| ------- |
| [0015-3sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0015-3sum) |
| [0018-4sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0018-4sum) |
| [0031-next-permutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0031-next-permutation) |
| [0042-trapping-rain-water](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0042-trapping-rain-water) |
| [0061-rotate-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0061-rotate-list) |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
| [0088-merge-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0088-merge-sorted-array) |
| [0125-valid-palindrome](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0125-valid-palindrome) |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
| [0151-reverse-words-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0151-reverse-words-in-a-string) |
| [0234-palindrome-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0234-palindrome-linked-list) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0344-reverse-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0344-reverse-string) |
| [0443-string-compression](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0443-string-compression) |
| [0567-permutation-in-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0567-permutation-in-string) |
| [0876-middle-of-the-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0876-middle-of-the-linked-list) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bit Manipulation
|  |
| ------- |
| [0078-subsets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0078-subsets) |
| [0090-subsets-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0090-subsets-ii) |
| [0231-power-of-two](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0231-power-of-two) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0342-power-of-four](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0342-power-of-four) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Meet in the Middle
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Ordered Set
|  |
| ------- |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bitmask
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## String
|  |
| ------- |
| [0003-longest-substring-without-repeating-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0003-longest-substring-without-repeating-characters) |
| [0014-longest-common-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0014-longest-common-prefix) |
| [0020-valid-parentheses](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0020-valid-parentheses) |
| [0049-group-anagrams](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0049-group-anagrams) |
| [0072-edit-distance](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0072-edit-distance) |
| [0076-minimum-window-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0076-minimum-window-substring) |
| [0079-word-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0079-word-search) |
| [0125-valid-palindrome](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0125-valid-palindrome) |
| [0131-palindrome-partitioning](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0131-palindrome-partitioning) |
| [0132-palindrome-partitioning-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0132-palindrome-partitioning-ii) |
| [0151-reverse-words-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0151-reverse-words-in-a-string) |
| [0242-valid-anagram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0242-valid-anagram) |
| [0344-reverse-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0344-reverse-string) |
| [0387-first-unique-character-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0387-first-unique-character-in-a-string) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
| [0443-string-compression](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0443-string-compression) |
| [0516-longest-palindromic-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0516-longest-palindromic-subsequence) |
| [0567-permutation-in-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0567-permutation-in-string) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1061-lexicographically-smallest-equivalent-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1061-lexicographically-smallest-equivalent-string) |
| [1143-longest-common-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1143-longest-common-subsequence) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [1392-longest-happy-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1392-longest-happy-prefix) |
| [1910-remove-all-occurrences-of-a-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1910-remove-all-occurrences-of-a-substring) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
## Backtracking
|  |
| ------- |
| [0037-sudoku-solver](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0037-sudoku-solver) |
| [0039-combination-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0039-combination-sum) |
| [0040-combination-sum-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0040-combination-sum-ii) |
| [0046-permutations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0046-permutations) |
| [0051-n-queens](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0051-n-queens) |
| [0078-subsets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0078-subsets) |
| [0079-word-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0079-word-search) |
| [0090-subsets-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0090-subsets-ii) |
| [0131-palindrome-partitioning](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0131-palindrome-partitioning) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
## Recursion
|  |
| ------- |
| [0002-add-two-numbers](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0002-add-two-numbers) |
| [0021-merge-two-sorted-lists](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0021-merge-two-sorted-lists) |
| [0024-swap-nodes-in-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0024-swap-nodes-in-pairs) |
| [0025-reverse-nodes-in-k-group](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0025-reverse-nodes-in-k-group) |
| [0050-powx-n](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0050-powx-n) |
| [0206-reverse-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0206-reverse-linked-list) |
| [0231-power-of-two](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0231-power-of-two) |
| [0234-palindrome-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0234-palindrome-linked-list) |
| [0326-power-of-three](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0326-power-of-three) |
| [0342-power-of-four](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0342-power-of-four) |
| [0509-fibonacci-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0509-fibonacci-number) |
## Hash Table
|  |
| ------- |
| [0001-two-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0001-two-sum) |
| [0003-longest-substring-without-repeating-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0003-longest-substring-without-repeating-characters) |
| [0037-sudoku-solver](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0037-sudoku-solver) |
| [0049-group-anagrams](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0049-group-anagrams) |
| [0073-set-matrix-zeroes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0073-set-matrix-zeroes) |
| [0076-minimum-window-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0076-minimum-window-substring) |
| [0105-construct-binary-tree-from-preorder-and-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal) |
| [0106-construct-binary-tree-from-inorder-and-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal) |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0138-copy-list-with-random-pointer](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0138-copy-list-with-random-pointer) |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
| [0146-lru-cache](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0146-lru-cache) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0242-valid-anagram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0242-valid-anagram) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0387-first-unique-character-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0387-first-unique-character-in-a-string) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
| [0496-next-greater-element-i](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0496-next-greater-element-i) |
| [0560-subarray-sum-equals-k](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0560-subarray-sum-equals-k) |
| [0567-permutation-in-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0567-permutation-in-string) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Heap (Priority Queue)
|  |
| ------- |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0239-sliding-window-maximum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0239-sliding-window-maximum) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0703-kth-largest-element-in-a-stream) |
| [0743-network-delay-time](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0743-network-delay-time) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
## Breadth-First Search
|  |
| ------- |
| [0100-same-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0100-same-tree) |
| [0101-symmetric-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0101-symmetric-tree) |
| [0102-binary-tree-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0102-binary-tree-level-order-traversal) |
| [0103-binary-tree-zigzag-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0103-binary-tree-zigzag-level-order-traversal) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0210-course-schedule-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0210-course-schedule-ii) |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
| [0542-01-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0542-01-matrix) |
| [0547-number-of-provinces](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0547-number-of-provinces) |
| [0662-maximum-width-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0662-maximum-width-of-binary-tree) |
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0743-network-delay-time](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0743-network-delay-time) |
| [0783-minimum-distance-between-bst-nodes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0783-minimum-distance-between-bst-nodes) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0994-rotting-oranges](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0994-rotting-oranges) |
| [1091-shortest-path-in-binary-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1091-shortest-path-in-binary-matrix) |
| [1161-maximum-level-sum-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1161-maximum-level-sum-of-a-binary-tree) |
| [1319-number-of-operations-to-make-network-connected](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1319-number-of-operations-to-make-network-connected) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph) |
| [2596-check-knight-tour-configuration](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2596-check-knight-tour-configuration) |
## Knapsack Problem
|  |
| ------- |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
## Complete Knapsack
|  |
| ------- |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
## Bidirectional Search
|  |
| ------- |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
## Matrix
|  |
| ------- |
| [0037-sudoku-solver](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0037-sudoku-solver) |
| [0054-spiral-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0054-spiral-matrix) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0073-set-matrix-zeroes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0073-set-matrix-zeroes) |
| [0074-search-a-2d-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0074-search-a-2d-matrix) |
| [0079-word-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0079-word-search) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0240-search-a-2d-matrix-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0240-search-a-2d-matrix-ii) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0542-01-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0542-01-matrix) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0994-rotting-oranges](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0994-rotting-oranges) |
| [1091-shortest-path-in-binary-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1091-shortest-path-in-binary-matrix) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [2596-check-knight-tour-configuration](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2596-check-knight-tour-configuration) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Depth-First Search
|  |
| ------- |
| [0079-word-search](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0079-word-search) |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0100-same-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0100-same-tree) |
| [0101-symmetric-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0101-symmetric-tree) |
| [0110-balanced-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0110-balanced-binary-tree) |
| [0114-flatten-binary-tree-to-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0114-flatten-binary-tree-to-linked-list) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0124-binary-tree-maximum-path-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0124-binary-tree-maximum-path-sum) |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0210-course-schedule-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0210-course-schedule-ii) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0236-lowest-common-ancestor-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0236-lowest-common-ancestor-of-a-binary-tree) |
| [0430-flatten-a-multilevel-doubly-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0430-flatten-a-multilevel-doubly-linked-list) |
| [0543-diameter-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0543-diameter-of-binary-tree) |
| [0547-number-of-provinces](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0547-number-of-provinces) |
| [0662-maximum-width-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0662-maximum-width-of-binary-tree) |
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0743-network-delay-time](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0743-network-delay-time) |
| [0783-minimum-distance-between-bst-nodes](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0783-minimum-distance-between-bst-nodes) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
| [1038-binary-search-tree-to-greater-sum-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1038-binary-search-tree-to-greater-sum-tree) |
| [1161-maximum-level-sum-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1161-maximum-level-sum-of-a-binary-tree) |
| [1319-number-of-operations-to-make-network-connected](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1319-number-of-operations-to-make-network-connected) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph) |
| [2596-check-knight-tour-configuration](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2596-check-knight-tour-configuration) |
## Union-Find
|  |
| ------- |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0547-number-of-provinces](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0547-number-of-provinces) |
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1061-lexicographically-smallest-equivalent-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1061-lexicographically-smallest-equivalent-string) |
| [1319-number-of-operations-to-make-network-connected](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1319-number-of-operations-to-make-network-connected) |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Graph Theory
|  |
| ------- |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0210-course-schedule-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0210-course-schedule-ii) |
| [0547-number-of-provinces](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0547-number-of-provinces) |
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0743-network-delay-time](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0743-network-delay-time) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1319-number-of-operations-to-make-network-connected](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1319-number-of-operations-to-make-network-connected) |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2316-count-unreachable-pairs-of-nodes-in-an-undirected-graph) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Divide and Conquer
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0105-construct-binary-tree-from-preorder-and-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0105-construct-binary-tree-from-preorder-and-inorder-traversal) |
| [0106-construct-binary-tree-from-inorder-and-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0106-construct-binary-tree-from-inorder-and-postorder-traversal) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0108-convert-sorted-array-to-binary-search-tree) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0240-search-a-2d-matrix-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0240-search-a-2d-matrix-ii) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Counting
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0387-first-unique-character-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0387-first-unique-character-in-a-string) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
## Boyer–Moore Majority Vote Algorithm
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
## Greedy
|  |
| ------- |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0134-gas-station](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0134-gas-station) |
| [0410-split-array-largest-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0410-split-array-largest-sum) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
| [2064-minimized-maximum-of-products-distributed-to-any-store](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/2064-minimized-maximum-of-products-distributed-to-any-store) |
## Combinatorics
|  |
| ------- |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
## Graph Coloring
|  |
| ------- |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
## Bipartite Graph
|  |
| ------- |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
## Directed Acyclic Graph
|  |
| ------- |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
## Stack
|  |
| ------- |
| [0020-valid-parentheses](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0020-valid-parentheses) |
| [0042-trapping-rain-water](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0042-trapping-rain-water) |
| [0084-largest-rectangle-in-histogram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0084-largest-rectangle-in-histogram) |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0114-flatten-binary-tree-to-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0114-flatten-binary-tree-to-linked-list) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0155-min-stack](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0155-min-stack) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0225-implement-stack-using-queues](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0225-implement-stack-using-queues) |
| [0232-implement-queue-using-stacks](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0232-implement-queue-using-stacks) |
| [0234-palindrome-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0234-palindrome-linked-list) |
| [0496-next-greater-element-i](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0496-next-greater-element-i) |
| [0503-next-greater-element-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0503-next-greater-element-ii) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1910-remove-all-occurrences-of-a-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1910-remove-all-occurrences-of-a-substring) |
## DP on Trees
|  |
| ------- |
| [0124-binary-tree-maximum-path-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0124-binary-tree-maximum-path-sum) |
| [0543-diameter-of-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0543-diameter-of-binary-tree) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
## Quickselect
|  |
| ------- |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
## Topological Sort
|  |
| ------- |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0210-course-schedule-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0210-course-schedule-ii) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
## Longest Increasing Subsequence
|  |
| ------- |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
## Ternary Search
|  |
| ------- |
| [0852-peak-index-in-a-mountain-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0852-peak-index-in-a-mountain-array) |
## Quicksort
|  |
| ------- |
| [0056-merge-intervals](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0056-merge-intervals) |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
## Bubble Sort
|  |
| ------- |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
## Simulation
|  |
| ------- |
| [0054-spiral-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0054-spiral-matrix) |
| [1910-remove-all-occurrences-of-a-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1910-remove-all-occurrences-of-a-substring) |
| [2073-time-needed-to-buy-tickets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/2073-time-needed-to-buy-tickets) |
| [2596-check-knight-tour-configuration](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2596-check-knight-tour-configuration) |
## Longest Common Subsequence
|  |
| ------- |
| [1143-longest-common-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1143-longest-common-subsequence) |
## Minimum Spanning Tree
|  |
| ------- |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
## Prim's Algorithm
|  |
| ------- |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
## Kruskal's Algorithm
|  |
| ------- |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
## Borůvka's Algorithm
|  |
| ------- |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
## 0-1 Knapsack
|  |
| ------- |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
## Shortest Path
|  |
| ------- |
| [0743-network-delay-time](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0743-network-delay-time) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
## Dijkstra's Algorithm
|  |
| ------- |
| [0743-network-delay-time](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0743-network-delay-time) |
| [1631-path-with-minimum-effort](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1631-path-with-minimum-effort) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
## Merge Sort
|  |
| ------- |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Bucket Sort
|  |
| ------- |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Radix Sort
|  |
| ------- |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Counting Sort
|  |
| ------- |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Design
|  |
| ------- |
| [0146-lru-cache](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0146-lru-cache) |
| [0155-min-stack](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0155-min-stack) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0225-implement-stack-using-queues](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0225-implement-stack-using-queues) |
| [0232-implement-queue-using-stacks](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0232-implement-queue-using-stacks) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0703-kth-largest-element-in-a-stream) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
## Iterator
|  |
| ------- |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
## Linked List
|  |
| ------- |
| [0002-add-two-numbers](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0002-add-two-numbers) |
| [0021-merge-two-sorted-lists](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0021-merge-two-sorted-lists) |
| [0024-swap-nodes-in-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0024-swap-nodes-in-pairs) |
| [0025-reverse-nodes-in-k-group](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0025-reverse-nodes-in-k-group) |
| [0061-rotate-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0061-rotate-list) |
| [0092-reverse-linked-list-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0092-reverse-linked-list-ii) |
| [0114-flatten-binary-tree-to-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0114-flatten-binary-tree-to-linked-list) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0138-copy-list-with-random-pointer](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0138-copy-list-with-random-pointer) |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
| [0146-lru-cache](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0146-lru-cache) |
| [0206-reverse-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0206-reverse-linked-list) |
| [0234-palindrome-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0234-palindrome-linked-list) |
| [0430-flatten-a-multilevel-doubly-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0430-flatten-a-multilevel-doubly-linked-list) |
| [0876-middle-of-the-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0876-middle-of-the-linked-list) |
## Monotonic Stack
|  |
| ------- |
| [0042-trapping-rain-water](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0042-trapping-rain-water) |
| [0084-largest-rectangle-in-histogram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0084-largest-rectangle-in-histogram) |
| [0496-next-greater-element-i](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0496-next-greater-element-i) |
| [0503-next-greater-element-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0503-next-greater-element-ii) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
## Pigeonhole Principle
|  |
| ------- |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
## Floyd's Cycle Finding Algorithm
|  |
| ------- |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
## Bracket Sequences
|  |
| ------- |
| [0020-valid-parentheses](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0020-valid-parentheses) |
## Data Stream
|  |
| ------- |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0703-kth-largest-element-in-a-stream) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
## Binary Lifting
|  |
| ------- |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0236-lowest-common-ancestor-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0236-lowest-common-ancestor-of-a-binary-tree) |
## Lowest Common Ancestor
|  |
| ------- |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0236-lowest-common-ancestor-of-a-binary-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0236-lowest-common-ancestor-of-a-binary-tree) |
## Rolling Hash
|  |
| ------- |
| [1392-longest-happy-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1392-longest-happy-prefix) |
## String Matching
|  |
| ------- |
| [1392-longest-happy-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1392-longest-happy-prefix) |
## Hash Function
|  |
| ------- |
| [1392-longest-happy-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1392-longest-happy-prefix) |
## Z Algorithm
|  |
| ------- |
| [1392-longest-happy-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1392-longest-happy-prefix) |
## Knuth–Morris–Pratt Algorithm
|  |
| ------- |
| [1392-longest-happy-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1392-longest-happy-prefix) |
## Sliding Window
|  |
| ------- |
| [0003-longest-substring-without-repeating-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0003-longest-substring-without-repeating-characters) |
| [0076-minimum-window-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0076-minimum-window-substring) |
| [0239-sliding-window-maximum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0239-sliding-window-maximum) |
| [0567-permutation-in-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0567-permutation-in-string) |
## Queue
|  |
| ------- |
| [0225-implement-stack-using-queues](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0225-implement-stack-using-queues) |
| [0232-implement-queue-using-stacks](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0232-implement-queue-using-stacks) |
| [0239-sliding-window-maximum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0239-sliding-window-maximum) |
| [0387-first-unique-character-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0387-first-unique-character-in-a-string) |
| [2073-time-needed-to-buy-tickets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/2073-time-needed-to-buy-tickets) |
## Binary Indexed Tree
|  |
| ------- |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
## Segment Tree
|  |
| ------- |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
## Treap
|  |
| ------- |
| [0493-reverse-pairs](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0493-reverse-pairs) |
## Trie
|  |
| ------- |
| [0014-longest-common-prefix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0014-longest-common-prefix) |
## Monotonic Queue
|  |
| ------- |
| [0239-sliding-window-maximum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0239-sliding-window-maximum) |
## Range Minimum/Maximum Query
|  |
| ------- |
| [0084-largest-rectangle-in-histogram](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0084-largest-rectangle-in-histogram) |
| [0239-sliding-window-maximum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0239-sliding-window-maximum) |
## Doubly-Linked List
|  |
| ------- |
| [0146-lru-cache](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0146-lru-cache) |
| [0430-flatten-a-multilevel-doubly-linked-list](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0430-flatten-a-multilevel-doubly-linked-list) |
## Algorithm X
|  |
| ------- |
| [0037-sudoku-solver](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0037-sudoku-solver) |
| [0051-n-queens](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0051-n-queens) |
## Dancing Links
|  |
| ------- |
| [0037-sudoku-solver](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0037-sudoku-solver) |
## Memoization
|  |
| ------- |
| [0509-fibonacci-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0509-fibonacci-number) |
## Prefix Sum
|  |
| ------- |
| [0410-split-array-largest-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0410-split-array-largest-sum) |
| [0560-subarray-sum-equals-k](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0560-subarray-sum-equals-k) |
<!---LeetCode Topics End-->
