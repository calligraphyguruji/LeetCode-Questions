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
| 🟢 **Easy** | 10 | 26.3% |
| 🟡 **Medium** | 22 | 57.9% |
| 🔴 **Hard** | 6 | 15.8% |
| 🎯 **Total Solved** | **38** | **100%** |

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
├── Backtracking/
│   ├── 1239-maximum-length-of-a-concatenated-string-with-unique-characters/
├── Trees/
│   ├── 0094-binary-tree-inorder-traversal/
│   ├── 0096-unique-binary-search-trees/
│   └── ... (8 problems)
├── Graphs/
│   ├── 0433-minimum-genetic-mutation/
│   ├── 0797-all-paths-from-source-to-target/
│   └── ... (9 problems)
├── DynamicProgramming/
│   ├── 0053-maximum-subarray/
│   ├── 0062-unique-paths/
│   └── ... (11 problems)
├── Heaps/
│   ├── 0215-kth-largest-element-in-an-array/
├── Greedy/
│   ├── 0122-best-time-to-buy-and-sell-stock-ii/
├── BitManipulation/
│   ├── 0231-power-of-two/
│   ├── 0342-power-of-four/
├── Math/
│   ├── 0050-powx-n/
│   ├── 0263-ugly-number/
│   └── ... (3 problems)
├── Arrays/
│   ├── 0169-majority-element/
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
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [🔍 Binary Search](BinarySearch/) | [Problem](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0050-powx-n/) | [C++](Math/0050-powx-n/0050-powx-n.cpp) |
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0053-maximum-subarray/) | [C++](DynamicProgramming/0053-maximum-subarray/0053-maximum-subarray.cpp) |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0062-unique-paths/) | [C++](DynamicProgramming/0062-unique-paths/0062-unique-paths.cpp) |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0063-unique-paths-ii/) | [C++](DynamicProgramming/0063-unique-paths-ii/0063-unique-paths-ii.cpp) |
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0094-binary-tree-inorder-traversal/) | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0096-unique-binary-search-trees/) | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/) | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) |
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [💡 Greedy Algorithms](Greedy/) | [Problem](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |
| 0132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0132-palindrome-partitioning-ii/) | [C++](DynamicProgramming/0132-palindrome-partitioning-ii/0132-palindrome-partitioning-ii.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [📦 Arrays & Hashing](Arrays/) | [Problem](Arrays/0169-majority-element/) | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) |
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [⛰️ Heaps & Priority Queues](Heaps/) | [Problem](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0263-ugly-number/) | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0264-ugly-number-ii/) | [C++](DynamicProgramming/0264-ugly-number-ii/0264-ugly-number-ii.cpp) |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/0279-perfect-squares/) | [C++](DynamicProgramming/0279-perfect-squares/0279-perfect-squares.cpp) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [🔢 Math & Number Theory](Math/) | [Problem](Math/0326-power-of-three/) | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [⚡ Bit Manipulation](BitManipulation/) | [Problem](BitManipulation/0342-power-of-four/) | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) |
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0433-minimum-genetic-mutation/) | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0797-all-paths-from-source-to-target/) | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0841-keys-and-rooms/) | [C++](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp) |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [🔄 Backtracking](Backtracking/) | [Problem](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [🧩 Dynamic Programming](DynamicProgramming/) | [Problem](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/) | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [🌳 Trees & Binary Search Trees](Trees/) | [Problem](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [🕸️ Graphs & BFS/DFS](Graphs/) | [Problem](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |

---

## 📂 Topic-wise Problem Breakdown

### 🔍 [Binary Search](BinarySearch/) (1)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0033 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array) | 🟡 `Medium` | [Problem Notes](BinarySearch/0033-search-in-rotated-sorted-array/) | [C++](BinarySearch/0033-search-in-rotated-sorted-array/0033-search-in-rotated-sorted-array.cpp) |

### 🔄 [Backtracking](Backtracking/) (1)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 1239 | [Maximum Length of a Concatenated String with Unique Characters](https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters) | 🟡 `Medium` | [Problem Notes](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/) | [C++](Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters/1239-maximum-length-of-a-concatenated-string-with-unique-characters.cpp) |

### 🌳 [Trees & Binary Search Trees](Trees/) (8)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0094 | [Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0094-binary-tree-inorder-traversal/) | [C++](Trees/0094-binary-tree-inorder-traversal/0094-binary-tree-inorder-traversal.cpp) |
| 0096 | [Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees) | 🟡 `Medium` | [Problem Notes](Trees/0096-unique-binary-search-trees/) | [C++](Trees/0096-unique-binary-search-trees/0096-unique-binary-search-trees.cpp) |
| 0144 | [Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0144-binary-tree-preorder-traversal/) | [C++](Trees/0144-binary-tree-preorder-traversal/0144-binary-tree-preorder-traversal.cpp) |
| 0145 | [Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal) | 🟢 `Easy` | [Problem Notes](Trees/0145-binary-tree-postorder-traversal/) | [C++](Trees/0145-binary-tree-postorder-traversal/0145-binary-tree-postorder-traversal.cpp) |
| 0450 | [Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst) | 🟡 `Medium` | [Problem Notes](Trees/0450-delete-node-in-a-bst/) | [C++](Trees/0450-delete-node-in-a-bst/0450-delete-node-in-a-bst.cpp) |
| 1443 | [Minimum Time to Collect All Apples in a Tree](https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/) | 🟡 `Medium` | [Problem Notes](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/) | [C++](Trees/1443-minimum-time-to-collect-all-apples-in-a-tree/1443-minimum-time-to-collect-all-apples-in-a-tree.cpp) |
| 1519 | [Number of Nodes in the Sub-Tree With the Same Label](https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label) | 🟡 `Medium` | [Problem Notes](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/) | [C++](Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label/1519-number-of-nodes-in-the-sub-tree-with-the-same-label.cpp) |
| 2246 | [Longest Path With Different Adjacent Characters](https://leetcode.com/problems/longest-path-with-different-adjacent-characters) | 🔴 `Hard` | [Problem Notes](Trees/2246-longest-path-with-different-adjacent-characters/) | [C++](Trees/2246-longest-path-with-different-adjacent-characters/2246-longest-path-with-different-adjacent-characters.cpp) |

### 🕸️ [Graphs & BFS/DFS](Graphs/) (9)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0433 | [Minimum Genetic Mutation](https://leetcode.com/problems/minimum-genetic-mutation) | 🟡 `Medium` | [Problem Notes](Graphs/0433-minimum-genetic-mutation/) | [C++](Graphs/0433-minimum-genetic-mutation/0433-minimum-genetic-mutation.cpp) |
| 0797 | [All Paths From Source to Target](https://leetcode.com/problems/all-paths-from-source-to-target) | 🟡 `Medium` | [Problem Notes](Graphs/0797-all-paths-from-source-to-target/) | [C++](Graphs/0797-all-paths-from-source-to-target/0797-all-paths-from-source-to-target.cpp) |
| 0841 | [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms) | 🟡 `Medium` | [Problem Notes](Graphs/0841-keys-and-rooms/) | [C++](Graphs/0841-keys-and-rooms/0841-keys-and-rooms.cpp) |
| 0886 | [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) | 🟡 `Medium` | [Problem Notes](Graphs/0886-possible-bipartition/) | [C++](Graphs/0886-possible-bipartition/0886-possible-bipartition.cpp) |
| 0990 | [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations) | 🟡 `Medium` | [Problem Notes](Graphs/0990-satisfiability-of-equality-equations/) | [C++](Graphs/0990-satisfiability-of-equality-equations/0990-satisfiability-of-equality-equations.cpp) |
| 1061 | [Lexicographically Smallest Equivalent String](https://leetcode.com/problems/lexicographically-smallest-equivalent-string) | 🟡 `Medium` | [Problem Notes](Graphs/1061-lexicographically-smallest-equivalent-string/) | [C++](Graphs/1061-lexicographically-smallest-equivalent-string/1061-lexicographically-smallest-equivalent-string.cpp) |
| 1926 | [Nearest Exit from Entrance in Maze](https://leetcode.com/problems/nearest-exit-from-entrance-in-maze) | 🟡 `Medium` | [Problem Notes](Graphs/1926-nearest-exit-from-entrance-in-maze/) | [C++](Graphs/1926-nearest-exit-from-entrance-in-maze/1926-nearest-exit-from-entrance-in-maze.cpp) |
| 1971 | [Find if Path Exists in Graph](https://leetcode.com/problems/find-if-path-exists-in-graph) | 🟢 `Easy` | [Problem Notes](Graphs/1971-find-if-path-exists-in-graph/) | [C++](Graphs/1971-find-if-path-exists-in-graph/1971-find-if-path-exists-in-graph.cpp) |
| 2421 | [Number of Good Paths](https://leetcode.com/problems/number-of-good-paths) | 🔴 `Hard` | [Problem Notes](Graphs/2421-number-of-good-paths/) | [C++](Graphs/2421-number-of-good-paths/2421-number-of-good-paths.cpp) |

### 🧩 [Dynamic Programming](DynamicProgramming/) (11)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0053 | [Maximum Subarray](https://leetcode.com/problems/maximum-subarray) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0053-maximum-subarray/) | [C++](DynamicProgramming/0053-maximum-subarray/0053-maximum-subarray.cpp) |
| 0062 | [Unique Paths](https://leetcode.com/problems/unique-paths) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0062-unique-paths/) | [C++](DynamicProgramming/0062-unique-paths/0062-unique-paths.cpp) |
| 0063 | [Unique Paths II](https://leetcode.com/problems/unique-paths-ii) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0063-unique-paths-ii/) | [C++](DynamicProgramming/0063-unique-paths-ii/0063-unique-paths-ii.cpp) |
| 0121 | [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock) | 🟢 `Easy` | [Problem Notes](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/) | [C++](DynamicProgramming/0121-best-time-to-buy-and-sell-stock/0121-best-time-to-buy-and-sell-stock.cpp) |
| 0132 | [Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/0132-palindrome-partitioning-ii/) | [C++](DynamicProgramming/0132-palindrome-partitioning-ii/0132-palindrome-partitioning-ii.cpp) |
| 0264 | [Ugly Number II](https://leetcode.com/problems/ugly-number-ii) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0264-ugly-number-ii/) | [C++](DynamicProgramming/0264-ugly-number-ii/0264-ugly-number-ii.cpp) |
| 0279 | [Perfect Squares](https://leetcode.com/problems/perfect-squares) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/0279-perfect-squares/) | [C++](DynamicProgramming/0279-perfect-squares/0279-perfect-squares.cpp) |
| 1335 | [Minimum Difficulty of a Job Schedule](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/) | [C++](DynamicProgramming/1335-minimum-difficulty-of-a-job-schedule/1335-minimum-difficulty-of-a-job-schedule.cpp) |
| 1547 | [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/) | [C++](DynamicProgramming/1547-minimum-cost-to-cut-a-stick/1547-minimum-cost-to-cut-a-stick.cpp) |
| 1594 | [Maximum Non Negative Product in a Matrix](https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix) | 🟡 `Medium` | [Problem Notes](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/) | [C++](DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix/1594-maximum-non-negative-product-in-a-matrix.cpp) |
| 2035 | [Partition Array Into Two Arrays to Minimize Sum Difference](https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference) | 🔴 `Hard` | [Problem Notes](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/) | [C++](DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference/2035-partition-array-into-two-arrays-to-minimize-sum-difference.cpp) |

### ⛰️ [Heaps & Priority Queues](Heaps/) (1)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0215 | [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array) | 🟡 `Medium` | [Problem Notes](Heaps/0215-kth-largest-element-in-an-array/) | [C++](Heaps/0215-kth-largest-element-in-an-array/0215-kth-largest-element-in-an-array.cpp) |

### 💡 [Greedy Algorithms](Greedy/) (1)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0122 | [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii) | 🟡 `Medium` | [Problem Notes](Greedy/0122-best-time-to-buy-and-sell-stock-ii/) | [C++](Greedy/0122-best-time-to-buy-and-sell-stock-ii/0122-best-time-to-buy-and-sell-stock-ii.cpp) |

### ⚡ [Bit Manipulation](BitManipulation/) (2)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0231 | [Power of Two](https://leetcode.com/problems/power-of-two) | 🟢 `Easy` | [Problem Notes](BitManipulation/0231-power-of-two/) | [C++](BitManipulation/0231-power-of-two/0231-power-of-two.cpp) |
| 0342 | [Power of Four](https://leetcode.com/problems/power-of-four) | 🟢 `Easy` | [Problem Notes](BitManipulation/0342-power-of-four/) | [C++](BitManipulation/0342-power-of-four/0342-power-of-four.cpp) |

### 🔢 [Math & Number Theory](Math/) (3)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0050 | [Pow(x, n)](https://leetcode.com/problems/powx-n) | 🟡 `Medium` | [Problem Notes](Math/0050-powx-n/) | [C++](Math/0050-powx-n/0050-powx-n.cpp) |
| 0263 | [Ugly Number](https://leetcode.com/problems/ugly-number) | 🟢 `Easy` | [Problem Notes](Math/0263-ugly-number/) | [C++](Math/0263-ugly-number/0263-ugly-number.cpp) |
| 0326 | [Power of Three](https://leetcode.com/problems/power-of-three) | 🟢 `Easy` | [Problem Notes](Math/0326-power-of-three/) | [C++](Math/0326-power-of-three/0326-power-of-three.cpp) |

### 📦 [Arrays & Hashing](Arrays/) (1)

| # | Problem Name | Difficulty | Problem Details | Solution |
|:---:|:---|:---:|:---:|:---:|
| 0169 | [Majority Element](https://leetcode.com/problems/majority-element) | 🟢 `Easy` | [Problem Notes](Arrays/0169-majority-element/) | [C++](Arrays/0169-majority-element/0169-majority-element.cpp) |

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
## Dynamic Programming
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0121-best-time-to-buy-and-sell-stock](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0121-best-time-to-buy-and-sell-stock) |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0132-palindrome-partitioning-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0132-palindrome-partitioning-ii) |
| [0198-house-robber](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0198-house-robber) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Tree
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Binary Search Tree
|  |
| ------- |
| [0033-search-in-rotated-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0033-search-in-rotated-sorted-array) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Binary Tree
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0096-unique-binary-search-trees) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0450-delete-node-in-a-bst](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0450-delete-node-in-a-bst) |
## Array
|  |
| ------- |
| [0033-search-in-rotated-sorted-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BinarySearch/0033-search-in-rotated-sorted-array) |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [0121-best-time-to-buy-and-sell-stock](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0121-best-time-to-buy-and-sell-stock) |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0198-house-robber](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0198-house-robber) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Sorting
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1547-minimum-cost-to-cut-a-stick) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Two Pointers
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bit Manipulation
|  |
| ------- |
| [0231-power-of-two](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/BitManipulation/0231-power-of-two) |
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
| [0132-palindrome-partitioning-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0132-palindrome-partitioning-ii) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1061-lexicographically-smallest-equivalent-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1061-lexicographically-smallest-equivalent-string) |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Backtracking/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
## Backtracking
|  |
| ------- |
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
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Heap (Priority Queue)
|  |
| ------- |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0264-ugly-number-ii) |
## Breadth-First Search
|  |
| ------- |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
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
## Complete Knapsack
|  |
| ------- |
| [0279-perfect-squares](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0279-perfect-squares) |
## Bidirectional Search
|  |
| ------- |
| [0433-minimum-genetic-mutation](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0433-minimum-genetic-mutation) |
## Matrix
|  |
| ------- |
| [0063-unique-paths-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0063-unique-paths-ii) |
| [1594-maximum-non-negative-product-in-a-matrix](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/1594-maximum-non-negative-product-in-a-matrix) |
| [1926-nearest-exit-from-entrance-in-maze](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1926-nearest-exit-from-entrance-in-maze) |
## Depth-First Search
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
## Union-Find
|  |
| ------- |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1061-lexicographically-smallest-equivalent-string](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1061-lexicographically-smallest-equivalent-string) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Graph Theory
|  |
| ------- |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
| [0841-keys-and-rooms](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0841-keys-and-rooms) |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
| [0990-satisfiability-of-equality-equations](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0990-satisfiability-of-equality-equations) |
| [1971-find-if-path-exists-in-graph](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/1971-find-if-path-exists-in-graph) |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
| [2421-number-of-good-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/2421-number-of-good-paths) |
## Divide and Conquer
|  |
| ------- |
| [0053-maximum-subarray](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0053-maximum-subarray) |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
## Counting
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
## Boyer–Moore Majority Vote Algorithm
|  |
| ------- |
| [0169-majority-element](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Arrays/0169-majority-element) |
## Greedy
|  |
| ------- |
| [0122-best-time-to-buy-and-sell-stock-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Greedy/0122-best-time-to-buy-and-sell-stock-ii) |
## Combinatorics
|  |
| ------- |
| [0062-unique-paths](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/DynamicProgramming/0062-unique-paths) |
## Graph Coloring
|  |
| ------- |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
## Bipartite Graph
|  |
| ------- |
| [0886-possible-bipartition](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0886-possible-bipartition) |
## Directed Acyclic Graph
|  |
| ------- |
| [0797-all-paths-from-source-to-target](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Graphs/0797-all-paths-from-source-to-target) |
## Stack
|  |
| ------- |
| [0094-binary-tree-inorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0094-binary-tree-inorder-traversal) |
| [0144-binary-tree-preorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0144-binary-tree-preorder-traversal) |
| [0145-binary-tree-postorder-traversal](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/0145-binary-tree-postorder-traversal) |
## DP on Trees
|  |
| ------- |
| [1443-minimum-time-to-collect-all-apples-in-a-tree](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1443-minimum-time-to-collect-all-apples-in-a-tree) |
| [1519-number-of-nodes-in-the-sub-tree-with-the-same-label](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/1519-number-of-nodes-in-the-sub-tree-with-the-same-label) |
## Quickselect
|  |
| ------- |
| [0215-kth-largest-element-in-an-array](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Heaps/0215-kth-largest-element-in-an-array) |
## Topological Sort
|  |
| ------- |
| [2246-longest-path-with-different-adjacent-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/main/Trees/2246-longest-path-with-different-adjacent-characters) |
<!---LeetCode Topics End-->
