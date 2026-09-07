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
| 🟢 **Easy** | 15 | 17.4% |
| 🟡 **Medium** | 64 | 74.4% |
| 🔴 **Hard** | 7 | 8.1% |
| 🎯 **Total Solved** | **86** | **100%** |

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
│   ├── 0098-validate-binary-search-tree/
│   └── ... (10 problems)
├── Backtracking/
│   ├── 0078-subsets/
│   ├── 0494-target-sum/
│   └── ... (3 problems)
├── Trees/
│   ├── 0094-binary-tree-inorder-traversal/
│   ├── 0096-unique-binary-search-trees/
│   └── ... (11 problems)
├── Graphs/
│   ├── 0133-clone-graph/
│   ├── 0200-number-of-islands/
│   └── ... (22 problems)
├── DynamicProgramming/
│   ├── 0053-maximum-subarray/
│   ├── 0062-unique-paths/
│   └── ... (18 problems)
├── Heaps/
│   ├── 0215-kth-largest-element-in-an-array/
│   ├── 0347-top-k-frequent-elements/
│   └── ... (3 problems)
├── Greedy/
│   ├── 0122-best-time-to-buy-and-sell-stock-ii/
├── BitManipulation/
│   ├── 0231-power-of-two/
│   ├── 0342-power-of-four/
├── Math/
│   ├── 0050-powx-n/
│   ├── 0263-ugly-number/
│   └── ... (4 problems)
├── Arrays/
│   ├── 0001-two-sum/
│   ├── 0015-3sum/
│   └── ... (12 problems)
```

Each problem folder contains:
- `README.md` — Problem description, examples, and constraints.
- `<problem-name>.cpp` — Clean C++ solution with complexity notes.

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
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0015-3sum/) | [C++](Arrays/0015-3sum/0015-3sum.cpp) |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0020-valid-parentheses/) | [C++](Arrays/0020-valid-parentheses/0020-valid-parentheses.cpp) |
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0050-powx-n/) | [C++](Math/0050-powx-n/0050-powx-n.cpp) |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0053-maximum-subarray/) | [C++](DynamicProgramming/0053-maximum-subarray/0053-maximum-subarray.cpp) |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0062-unique-paths/) | [C++](DynamicProgramming/0062-unique-paths/0062-unique-paths.cpp) |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0063-unique-paths-ii/) | [C++](DynamicProgramming/0063-unique-paths-ii/0063-unique-paths-ii.cpp) |
| 0072 | [Edit Distance](https://leetcode.com/problems/edit-distance) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0072-edit-distance/) | [C++](DynamicProgramming/0072-edit-distance/0072-edit-distance.cpp) |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0075-sort-colors/) | [C++](Arrays/0075-sort-colors/0075-sort-colors.cpp) |
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0078-subsets/) | [C++](Backtracking/0078-subsets/0078-subsets.cpp) |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0094-binary-tree-inorder-traversal/) | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0096-unique-binary-search-trees/) | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0098-validate-binary-search-tree/) | [C++](BinarySearch/0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp) |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0099-recover-binary-search-tree/) | [C++](BinarySearch/0099-recover-binary-search-tree/0099-recover-binary-search-tree.cpp) |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0102-binary-tree-level-order-traversal/) | [C++](Trees/0102-binary-tree-level-order-traversal/0102-binary-tree-level-order-traversal.cpp) |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0116-populating-next-right-pointers-in-each-node/) | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/) | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [💡 Greedy Algorithms](Greedy/) | [Problem](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |
| 0132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0132-palindrome-partitioning-ii/) | [C++](DynamicProgramming/0132-palindrome-partitioning-ii/0132-palindrome-partitioning-ii.cpp) |
| 0133 | [Clone Graph](https://leetcode.com/problems/clone-graph) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0133-clone-graph/) | [C++](Graphs/0133-clone-graph/0133-clone-graph.cpp) |
| 0138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0138-copy-list-with-random-pointer/) | [C++](Arrays/0138-copy-list-with-random-pointer/0138-copy-list-with-random-pointer.cpp) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0141-linked-list-cycle/) | [C++](Arrays/0141-linked-list-cycle/0141-linked-list-cycle.cpp) |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0142-linked-list-cycle-ii/) | [C++](Arrays/0142-linked-list-cycle-ii/0142-linked-list-cycle-ii.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0151-reverse-words-in-a-string/) | [C++](Arrays/0151-reverse-words-in-a-string/0151-reverse-words-in-a-string.cpp) |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0169-majority-element/) | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0173-binary-search-tree-iterator/) | [C++](BinarySearch/0173-binary-search-tree-iterator/0173-binary-search-tree-iterator.cpp) |
| 0198 | [House Robber](https://leetcode.com/problems/house-robber) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0198-house-robber/) | [C++](DynamicProgramming/0198-house-robber/0198-house-robber.cpp) |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0200-number-of-islands/) | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) |
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0207-course-schedule/) | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0210-course-schedule-ii/) | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) |
| 0213 | [House Robber II](https://leetcode.com/problems/house-robber-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0213-house-robber-ii/) | [C++](DynamicProgramming/0213-house-robber-ii/0213-house-robber-ii.cpp) |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0263-ugly-number/) | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0264-ugly-number-ii/) | [C++](DynamicProgramming/0264-ugly-number-ii/0264-ugly-number-ii.cpp) |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0279-perfect-squares/) | [C++](DynamicProgramming/0279-perfect-squares/0279-perfect-squares.cpp) |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0287-find-the-duplicate-number/) | [C++](BinarySearch/0287-find-the-duplicate-number/0287-find-the-duplicate-number.cpp) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0300-longest-increasing-subsequence/) | [C++](BinarySearch/0300-longest-increasing-subsequence/0300-longest-increasing-subsequence.cpp) |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0322-coin-change/) | [C++](Graphs/0322-coin-change/0322-coin-change.cpp) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0326-power-of-three/) | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0342-power-of-four/) | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0347-top-k-frequent-elements/) | [C++](Heaps/0347-top-k-frequent-elements/0347-top-k-frequent-elements.cpp) |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/) | [C++](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/0378-kth-smallest-element-in-a-sorted-matrix.cpp) |
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0433-minimum-genetic-mutation/) | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0443-string-compression/) | [C++](Arrays/0443-string-compression/0443-string-compression.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/0494-target-sum/) | [C++](Backtracking/0494-target-sum/0494-target-sum.cpp) |
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0516-longest-palindromic-subsequence/) | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0542-01-matrix/) | [C++](Graphs/0542-01-matrix/0542-01-matrix.cpp) |
| 0547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0547-number-of-provinces/) | [C++](Graphs/0547-number-of-provinces/0547-number-of-provinces.cpp) |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0646-maximum-length-of-pair-chain/) | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) |
| 0684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0684-redundant-connection/) | [C++](Graphs/0684-redundant-connection/0684-redundant-connection.cpp) |
| 0733 | [Flood Fill](https://leetcode.com/problems/flood-fill) | 🟢 `Easy` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0733-flood-fill/) | [C++](Graphs/0733-flood-fill/0733-flood-fill.cpp) |
| 0785 | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0785-is-graph-bipartite/) | [C++](Graphs/0785-is-graph-bipartite/0785-is-graph-bipartite.cpp) |
| 0787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0787-cheapest-flights-within-k-stops/) | [C++](Graphs/0787-cheapest-flights-within-k-stops/0787-cheapest-flights-within-k-stops.cpp) |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0797-all-paths-from-source-to-target/) | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0841-keys-and-rooms/) | [C++](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp) |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0852-peak-index-in-a-mountain-array/) | [C++](BinarySearch/0852-peak-index-in-a-mountain-array/0852-peak-index-in-a-mountain-array.cpp) |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0901-online-stock-span/) | [C++](Arrays/0901-online-stock-span/0901-online-stock-span.cpp) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0912-sort-an-array/) | [C++](Heaps/0912-sort-an-array/0912-sort-an-array.cpp) |
| 0947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0947-most-stones-removed-with-same-row-or-column/) | [C++](Graphs/0947-most-stones-removed-with-same-row-or-column/0947-most-stones-removed-with-same-row-or-column.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/) | [C++](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/1008-construct-binary-search-tree-from-preorder-traversal.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1143-longest-common-subsequence/) | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1584-min-cost-to-connect-all-points/) | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring) | 🟡 `Medium` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/1910-remove-all-occurrences-of-a-substring/) | [C++](Arrays/1910-remove-all-occurrences-of-a-substring/1910-remove-all-occurrences-of-a-substring.cpp) |
| 1911 | [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1911-maximum-alternating-subsequence-sum/) | [C++](DynamicProgramming/1911-maximum-alternating-subsequence-sum/1911-maximum-alternating-subsequence-sum.cpp) |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1932 | [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst) | 🔴 `Hard` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/1932-merge-bsts-to-create-single-bst/) | [C++](BinarySearch/1932-merge-bsts-to-create-single-bst/1932-merge-bsts-to-create-single-bst.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1976-number-of-ways-to-arrive-at-destination/) | [C++](Graphs/1976-number-of-ways-to-arrive-at-destination/1976-number-of-ways-to-arrive-at-destination.cpp) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/) | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |
| 2965 | [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/2965-find-missing-and-repeated-values/) | [C++](Math/2965-find-missing-and-repeated-values/2965-find-missing-and-repeated-values.cpp) |

---

## 📂 Topic-wise Problem Breakdown

### 🔍 [Binary Search](BinarySearch/) (10)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |
| 0098 | [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0098-validate-binary-search-tree/) | [C++](BinarySearch/0098-validate-binary-search-tree/0098-validate-binary-search-tree.cpp) |
| 0099 | [Recover Binary Search Tree](https://leetcode.com/problems/recover-binary-search-tree) | 🟡 `Medium` | [Problem Notes](BinarySearch/0099-recover-binary-search-tree/) | [C++](BinarySearch/0099-recover-binary-search-tree/0099-recover-binary-search-tree.cpp) |
| 0173 | [Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator) | 🟡 `Medium` | [Problem Notes](BinarySearch/0173-binary-search-tree-iterator/) | [C++](BinarySearch/0173-binary-search-tree-iterator/0173-binary-search-tree-iterator.cpp) |
| 0287 | [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number) | 🟡 `Medium` | [Problem Notes](BinarySearch/0287-find-the-duplicate-number/) | [C++](BinarySearch/0287-find-the-duplicate-number/0287-find-the-duplicate-number.cpp) |
| 0300 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence) | 🟡 `Medium` | [Problem Notes](BinarySearch/0300-longest-increasing-subsequence/) | [C++](BinarySearch/0300-longest-increasing-subsequence/0300-longest-increasing-subsequence.cpp) |
| 0378 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix) | 🟡 `Medium` | [Problem Notes](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/) | [C++](BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix/0378-kth-smallest-element-in-a-sorted-matrix.cpp) |
| 0852 | [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0852-peak-index-in-a-mountain-array/) | [C++](BinarySearch/0852-peak-index-in-a-mountain-array/0852-peak-index-in-a-mountain-array.cpp) |
| 1008 | [Construct Binary Search Tree from Preorder Traversal](https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal) | 🟡 `Medium` | [Problem Notes](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/) | [C++](BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal/1008-construct-binary-search-tree-from-preorder-traversal.cpp) |
| 1932 | [Merge BSTs to Create Single BST](https://leetcode.com/problems/merge-bsts-to-create-single-bst) | 🔴 `Hard` | [Problem Notes](BinarySearch/1932-merge-bsts-to-create-single-bst/) | [C++](BinarySearch/1932-merge-bsts-to-create-single-bst/1932-merge-bsts-to-create-single-bst.cpp) |

### 🔄 [Backtracking](Backtracking/) (3)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0078 | [Subsets](https://leetcode.com/problems/subsets) | 🟡 `Medium` | [Problem Notes](Backtracking/0078-subsets/) | [C++](Backtracking/0078-subsets/0078-subsets.cpp) |
| 0494 | [Target Sum](https://leetcode.com/problems/target-sum) | 🟡 `Medium` | [Problem Notes](Backtracking/0494-target-sum/) | [C++](Backtracking/0494-target-sum/0494-target-sum.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [Problem Notes](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |

### 🌳 [Trees & Binary Search Trees](Trees/) (11)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0094-binary-tree-inorder-traversal/) | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [Problem Notes](Trees/0096-unique-binary-search-trees/) | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) |
| 0102 | [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal) | 🟡 `Medium` | [Problem Notes](Trees/0102-binary-tree-level-order-traversal/) | [C++](Trees/0102-binary-tree-level-order-traversal/0102-binary-tree-level-order-traversal.cpp) |
| 0116 | [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node) | 🟡 `Medium` | [Problem Notes](Trees/0116-populating-next-right-pointers-in-each-node/) | [C++](Trees/0116-populating-next-right-pointers-in-each-node/0116-populating-next-right-pointers-in-each-node.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [Problem Notes](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [Problem Notes](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [Problem Notes](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1584 | [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points) | 🟡 `Medium` | [Problem Notes](Trees/1584-min-cost-to-connect-all-points/) | [C++](Trees/1584-min-cost-to-connect-all-points/1584-min-cost-to-connect-all-points.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [Problem Notes](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |

### 🕸️ [Graphs & BFS/DFS](Graphs/) (22)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0133 | [Clone Graph](https://leetcode.com/problems/clone-graph) | 🟡 `Medium` | [Problem Notes](Graphs/0133-clone-graph/) | [C++](Graphs/0133-clone-graph/0133-clone-graph.cpp) |
| 0200 | [Number of Islands](https://leetcode.com/problems/number-of-islands) | 🟡 `Medium` | [Problem Notes](Graphs/0200-number-of-islands/) | [C++](Graphs/0200-number-of-islands/0200-number-of-islands.cpp) |
| 0207 | [Course Schedule](https://leetcode.com/problems/course-schedule) | 🟡 `Medium` | [Problem Notes](Graphs/0207-course-schedule/) | [C++](Graphs/0207-course-schedule/0207-course-schedule.cpp) |
| 0210 | [Course Schedule II](https://leetcode.com/problems/course-schedule-ii) | 🟡 `Medium` | [Problem Notes](Graphs/0210-course-schedule-ii/) | [C++](Graphs/0210-course-schedule-ii/0210-course-schedule-ii.cpp) |
| 0322 | [Coin Change](https://leetcode.com/problems/coin-change) | 🟡 `Medium` | [Problem Notes](Graphs/0322-coin-change/) | [C++](Graphs/0322-coin-change/0322-coin-change.cpp) |
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [Problem Notes](Graphs/0433-minimum-genetic-mutation/) | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) |
| 0542 | [01 Matrix](https://leetcode.com/problems/01-matrix) | 🟡 `Medium` | [Problem Notes](Graphs/0542-01-matrix/) | [C++](Graphs/0542-01-matrix/0542-01-matrix.cpp) |
| 0547 | [Number of Provinces](https://leetcode.com/problems/number-of-provinces) | 🟡 `Medium` | [Problem Notes](Graphs/0547-number-of-provinces/) | [C++](Graphs/0547-number-of-provinces/0547-number-of-provinces.cpp) |
| 0684 | [Redundant Connection](https://leetcode.com/problems/redundant-connection) | 🟡 `Medium` | [Problem Notes](Graphs/0684-redundant-connection/) | [C++](Graphs/0684-redundant-connection/0684-redundant-connection.cpp) |
| 0733 | [Flood Fill](https://leetcode.com/problems/flood-fill) | 🟢 `Easy` | [Problem Notes](Graphs/0733-flood-fill/) | [C++](Graphs/0733-flood-fill/0733-flood-fill.cpp) |
| 0785 | [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite) | 🟡 `Medium` | [Problem Notes](Graphs/0785-is-graph-bipartite/) | [C++](Graphs/0785-is-graph-bipartite/0785-is-graph-bipartite.cpp) |
| 0787 | [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops) | 🟡 `Medium` | [Problem Notes](Graphs/0787-cheapest-flights-within-k-stops/) | [C++](Graphs/0787-cheapest-flights-within-k-stops/0787-cheapest-flights-within-k-stops.cpp) |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [Problem Notes](Graphs/0797-all-paths-from-source-to-target/) | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [Problem Notes](Graphs/0841-keys-and-rooms/) | [C++](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp) |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [Problem Notes](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0947 | [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column) | 🟡 `Medium` | [Problem Notes](Graphs/0947-most-stones-removed-with-same-row-or-column/) | [C++](Graphs/0947-most-stones-removed-with-same-row-or-column/0947-most-stones-removed-with-same-row-or-column.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [Problem Notes](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [Problem Notes](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [Problem Notes](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [Problem Notes](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 1976 | [Number of Ways to Arrive at Destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination) | 🟡 `Medium` | [Problem Notes](Graphs/1976-number-of-ways-to-arrive-at-destination/) | [C++](Graphs/1976-number-of-ways-to-arrive-at-destination/1976-number-of-ways-to-arrive-at-destination.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [Problem Notes](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |

### 🧩 [Dynamic Programming](DynamicProgramming/) (18)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
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
| 0516 | [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0516-longest-palindromic-subsequence/) | [C++](DynamicProgramming/0516-longest-palindromic-subsequence/0516-longest-palindromic-subsequence.cpp) |
| 0646 | [Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0646-maximum-length-of-pair-chain/) | [C++](DynamicProgramming/0646-maximum-length-of-pair-chain/0646-maximum-length-of-pair-chain.cpp) |
| 1143 | [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1143-longest-common-subsequence/) | [C++](DynamicProgramming/1143-longest-common-subsequence/1143-longest-common-subsequence.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 1911 | [Maximum Alternating Subsequence Sum](https://leetcode.com/problems/maximum-alternating-subsequence-sum) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1911-maximum-alternating-subsequence-sum/) | [C++](DynamicProgramming/1911-maximum-alternating-subsequence-sum/1911-maximum-alternating-subsequence-sum.cpp) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/) | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) |

### ⛰️ [Heaps & Priority Queues](Heaps/) (3)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [Problem Notes](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |
| 0347 | [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements) | 🟡 `Medium` | [Problem Notes](Heaps/0347-top-k-frequent-elements/) | [C++](Heaps/0347-top-k-frequent-elements/0347-top-k-frequent-elements.cpp) |
| 0912 | [Sort an Array](https://leetcode.com/problems/sort-an-array) | 🟡 `Medium` | [Problem Notes](Heaps/0912-sort-an-array/) | [C++](Heaps/0912-sort-an-array/0912-sort-an-array.cpp) |

### 💡 [Greedy Algorithms](Greedy/) (1)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [Problem Notes](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |

### ⚡ [Bit Manipulation](BitManipulation/) (2)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [Problem Notes](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [Problem Notes](BitManipulation/0342-power-of-four/) | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) |

### 🔢 [Math & Number Theory](Math/) (4)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [Problem Notes](Math/0050-powx-n/) | [C++](Math/0050-powx-n/0050-powx-n.cpp) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [Problem Notes](Math/0263-ugly-number/) | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [Problem Notes](Math/0326-power-of-three/) | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) |
| 2965 | [Find Missing and Repeated Values](https://leetcode.com/problems/find-missing-and-repeated-values) | 🟢 `Easy` | [Problem Notes](Math/2965-find-missing-and-repeated-values/) | [C++](Math/2965-find-missing-and-repeated-values/2965-find-missing-and-repeated-values.cpp) |

### 📦 [Arrays & Hashing](Arrays/) (12)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0001 | [Two Sum](https://leetcode.com/problems/two-sum) | 🟢 `Easy` | [Problem Notes](Arrays/0001-two-sum/) | [C++](Arrays/0001-two-sum/0001-two-sum.cpp) |
| 0015 | [3Sum](https://leetcode.com/problems/3sum) | 🟡 `Medium` | [Problem Notes](Arrays/0015-3sum/) | [C++](Arrays/0015-3sum/0015-3sum.cpp) |
| 0020 | [Valid Parentheses](https://leetcode.com/problems/valid-parentheses) | 🟢 `Easy` | [Problem Notes](Arrays/0020-valid-parentheses/) | [C++](Arrays/0020-valid-parentheses/0020-valid-parentheses.cpp) |
| 0075 | [Sort Colors](https://leetcode.com/problems/sort-colors) | 🟡 `Medium` | [Problem Notes](Arrays/0075-sort-colors/) | [C++](Arrays/0075-sort-colors/0075-sort-colors.cpp) |
| 0138 | [Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer) | 🟡 `Medium` | [Problem Notes](Arrays/0138-copy-list-with-random-pointer/) | [C++](Arrays/0138-copy-list-with-random-pointer/0138-copy-list-with-random-pointer.cpp) |
| 0141 | [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle) | 🟢 `Easy` | [Problem Notes](Arrays/0141-linked-list-cycle/) | [C++](Arrays/0141-linked-list-cycle/0141-linked-list-cycle.cpp) |
| 0142 | [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii) | 🟡 `Medium` | [Problem Notes](Arrays/0142-linked-list-cycle-ii/) | [C++](Arrays/0142-linked-list-cycle-ii/0142-linked-list-cycle-ii.cpp) |
| 0151 | [Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string) | 🟡 `Medium` | [Problem Notes](Arrays/0151-reverse-words-in-a-string/) | [C++](Arrays/0151-reverse-words-in-a-string/0151-reverse-words-in-a-string.cpp) |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [Problem Notes](Arrays/0169-majority-element/) | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) |
| 0443 | [String Compression](https://leetcode.com/problems/string-compression) | 🟡 `Medium` | [Problem Notes](Arrays/0443-string-compression/) | [C++](Arrays/0443-string-compression/0443-string-compression.cpp) |
| 0901 | [Online Stock Span](https://leetcode.com/problems/online-stock-span) | 🟡 `Medium` | [Problem Notes](Arrays/0901-online-stock-span/) | [C++](Arrays/0901-online-stock-span/0901-online-stock-span.cpp) |
| 1910 | [Remove All Occurrences of a Substring](https://leetcode.com/problems/remove-all-occurrences-of-a-substring) | 🟡 `Medium` | [Problem Notes](Arrays/1910-remove-all-occurrences-of-a-substring/) | [C++](Arrays/1910-remove-all-occurrences-of-a-substring/1910-remove-all-occurrences-of-a-substring.cpp) |

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
| [0050-powx-n](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0050-powx-n) |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0231-power-of-two](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0231-power-of-two) |
| [0263-ugly-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0263-ugly-number) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0326-power-of-three](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0326-power-of-three) |
| [0342-power-of-four](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0342-power-of-four) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Dynamic Programming
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0072-edit-distance](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0072-edit-distance) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0121-best-time-to-buy-and-sell-stock](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0121-best-time-to-buy-and-sell-stock) |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0132-palindrome-partitioning-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0132-palindrome-partitioning-ii) |
| [0198-house-robber](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0198-house-robber) |
| [0213-house-robber-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0213-house-robber-ii) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
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
| [0102-binary-tree-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0102-binary-tree-level-order-traversal) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0108-convert-sorted-array-to-binary-search-tree) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0703-kth-largest-element-in-a-stream) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Binary Search Tree
|  |
| ------- |
| [0033-search-in-rotated-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0033-search-in-rotated-sorted-array) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0108-convert-sorted-array-to-binary-search-tree) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0703-kth-largest-element-in-a-stream) |
| [0852-peak-index-in-a-mountain-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0852-peak-index-in-a-mountain-array) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Binary Tree
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0102-binary-tree-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0102-binary-tree-level-order-traversal) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0108-convert-sorted-array-to-binary-search-tree) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0703-kth-largest-element-in-a-stream) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
## Array
|  |
| ------- |
| [0001-two-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0001-two-sum) |
| [0015-3sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0015-3sum) |
| [0033-search-in-rotated-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0033-search-in-rotated-sorted-array) |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
| [0078-subsets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0078-subsets) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0108-convert-sorted-array-to-binary-search-tree) |
| [0121-best-time-to-buy-and-sell-stock](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0121-best-time-to-buy-and-sell-stock) |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0198-house-robber](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0198-house-robber) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0213-house-robber-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0213-house-robber-ii) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0300-longest-increasing-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0300-longest-increasing-subsequence) |
| [0322-coin-change](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0322-coin-change) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
| [0542-01-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0542-01-matrix) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0852-peak-index-in-a-mountain-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0852-peak-index-in-a-mountain-array) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1911-maximum-alternating-subsequence-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1911-maximum-alternating-subsequence-sum) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Sorting
|  |
| ------- |
| [0015-3sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0015-3sum) |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
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
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
| [0151-reverse-words-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0151-reverse-words-in-a-string) |
| [0287-find-the-duplicate-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0287-find-the-duplicate-number) |
| [0443-string-compression](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0443-string-compression) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bit Manipulation
|  |
| ------- |
| [0078-subsets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0078-subsets) |
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
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bitmask
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## String
|  |
| ------- |
| [0020-valid-parentheses](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0020-valid-parentheses) |
| [0072-edit-distance](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0072-edit-distance) |
| [0132-palindrome-partitioning-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0132-palindrome-partitioning-ii) |
| [0151-reverse-words-in-a-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0151-reverse-words-in-a-string) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
| [0443-string-compression](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0443-string-compression) |
| [0516-longest-palindromic-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0516-longest-palindromic-subsequence) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1061-lexicographically-smallest-equivalent-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1061-lexicographically-smallest-equivalent-string) |
| [1143-longest-common-subsequence](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1143-longest-common-subsequence) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [1910-remove-all-occurrences-of-a-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1910-remove-all-occurrences-of-a-substring) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
## Backtracking
|  |
| ------- |
| [0078-subsets](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0078-subsets) |
| [0494-target-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/0494-target-sum) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
## Recursion
|  |
| ------- |
| [0050-powx-n](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0050-powx-n) |
| [0231-power-of-two](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0231-power-of-two) |
| [0326-power-of-three](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/0326-power-of-three) |
| [0342-power-of-four](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0342-power-of-four) |
## Hash Table
|  |
| ------- |
| [0001-two-sum](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0001-two-sum) |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0138-copy-list-with-random-pointer](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0138-copy-list-with-random-pointer) |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
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
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0703-kth-largest-element-in-a-stream) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Breadth-First Search
|  |
| ------- |
| [0102-binary-tree-level-order-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0102-binary-tree-level-order-traversal) |
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
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
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
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0378-kth-smallest-element-in-a-sorted-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0378-kth-smallest-element-in-a-sorted-matrix) |
| [0542-01-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0542-01-matrix) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [2965-find-missing-and-repeated-values](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Math/2965-find-missing-and-repeated-values) |
## Depth-First Search
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0098-validate-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0098-validate-binary-search-tree) |
| [0099-recover-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0099-recover-binary-search-tree) |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0200-number-of-islands](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0200-number-of-islands) |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0210-course-schedule-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0210-course-schedule-ii) |
| [0230-kth-smallest-element-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0230-kth-smallest-element-in-a-bst) |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0235-lowest-common-ancestor-of-a-binary-search-tree) |
| [0547-number-of-provinces](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0547-number-of-provinces) |
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0733-flood-fill](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0733-flood-fill) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1932-merge-bsts-to-create-single-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1932-merge-bsts-to-create-single-bst) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
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
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Graph Theory
|  |
| ------- |
| [0133-clone-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0133-clone-graph) |
| [0207-course-schedule](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0207-course-schedule) |
| [0210-course-schedule-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0210-course-schedule-ii) |
| [0547-number-of-provinces](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0547-number-of-provinces) |
| [0684-redundant-connection](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0684-redundant-connection) |
| [0785-is-graph-bipartite](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0785-is-graph-bipartite) |
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0947-most-stones-removed-with-same-row-or-column](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0947-most-stones-removed-with-same-row-or-column) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1584-min-cost-to-connect-all-points](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1584-min-cost-to-connect-all-points) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Divide and Conquer
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0108-convert-sorted-array-to-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0108-convert-sorted-array-to-binary-search-tree) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [0912-sort-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0912-sort-an-array) |
## Counting
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0347-top-k-frequent-elements](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0347-top-k-frequent-elements) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
## Boyer–Moore Majority Vote Algorithm
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
## Greedy
|  |
| ------- |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0646-maximum-length-of-pair-chain](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0646-maximum-length-of-pair-chain) |
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
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
| [1008-construct-binary-search-tree-from-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/1008-construct-binary-search-tree-from-preorder-traversal) |
| [1910-remove-all-occurrences-of-a-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1910-remove-all-occurrences-of-a-substring) |
## DP on Trees
|  |
| ------- |
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
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
## Bubble Sort
|  |
| ------- |
| [0075-sort-colors](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0075-sort-colors) |
## Simulation
|  |
| ------- |
| [1910-remove-all-occurrences-of-a-substring](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/1910-remove-all-occurrences-of-a-substring) |
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
| [0787-cheapest-flights-within-k-stops](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0787-cheapest-flights-within-k-stops) |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
## Dijkstra's Algorithm
|  |
| ------- |
| [1976-number-of-ways-to-arrive-at-destination](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1976-number-of-ways-to-arrive-at-destination) |
## Merge Sort
|  |
| ------- |
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
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0703-kth-largest-element-in-a-stream) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
## Iterator
|  |
| ------- |
| [0173-binary-search-tree-iterator](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0173-binary-search-tree-iterator) |
## Linked List
|  |
| ------- |
| [0116-populating-next-right-pointers-in-each-node](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0116-populating-next-right-pointers-in-each-node) |
| [0138-copy-list-with-random-pointer](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0138-copy-list-with-random-pointer) |
| [0141-linked-list-cycle](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0141-linked-list-cycle) |
| [0142-linked-list-cycle-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0142-linked-list-cycle-ii) |
## Monotonic Stack
|  |
| ------- |
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
| [0703-kth-largest-element-in-a-stream](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0703-kth-largest-element-in-a-stream) |
| [0901-online-stock-span](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0901-online-stock-span) |
## Binary Lifting
|  |
| ------- |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0235-lowest-common-ancestor-of-a-binary-search-tree) |
## Lowest Common Ancestor
|  |
| ------- |
| [0235-lowest-common-ancestor-of-a-binary-search-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0235-lowest-common-ancestor-of-a-binary-search-tree) |
<!---LeetCode Topics End-->
