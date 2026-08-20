# 📚 LeetCode Solutions

Welcome to my personal collection of **LeetCode problem solutions**, written primarily in **C++**. This repository serves as a structured log of my journey to strengthen my **Data Structures and Algorithms (DSA)** skills through consistent, hands-on practice.

**To find my handwritten solutions : https://leetcode.com/u/calligraphyguruji/**
---

## 📌 About This Repository

This repository contains my solutions to various LeetCode problems, organized by topic and difficulty. It's not just a solution dump — each solution (where possible) includes the reasoning, complexity analysis, and alternative approaches I explored while solving the problem.

The goal is simple: **practice daily, think deeply, and get better at solving problems one step at a time.**

---

## 🎯 What I'm Learning

Through this repository, I'm actively working on:

- Understanding core **Data Structures** (Arrays, Linked Lists, Trees, Graphs, Stacks, Queues, Hash Maps)
- Applying **Algorithmic techniques** (Recursion, Backtracking, DP, Greedy, Binary Search)
- Improving my ability to **analyze time and space complexity**
- Learning to identify patterns and choose the right approach for a problem
- Building the problem-solving mindset needed for **technical interviews**

---

## 🧩 Topics Covered

| Category | Category | Category |
|---|---|---|
| Arrays | Two Pointers | Sliding Window |
| Strings | Binary Search | Recursion |
| Backtracking | Linked Lists | Stacks & Queues |
| Trees | Graphs | Dynamic Programming |
| Greedy Algorithms | Bit Manipulation | Hashing |
| Sorting & Searching | Heaps | Math & Number Theory |

> This list will keep growing as I explore more topics.

---

## 🗂️ Repository Structure

Solutions are organized topic-wise for easy navigation:

```
LeetCode-Solutions/
│
├── Arrays/
│   └── two-sum.cpp
├── LinkedList/
│   └── reverse-linked-list.cpp
├── Trees/
│   └── binary-tree-inorder-traversal.cpp
├── DynamicProgramming/
│   └── climbing-stairs.cpp
├── Graphs/
│   └── number-of-islands.cpp
├── Backtracking/
│   └── subsets.cpp
└── ...
```

Each folder represents a topic, and each file corresponds to a single problem, named as closely as possible to the original LeetCode problem title.

---

## 🧠 Solution Format

Wherever possible, each solution file follows a consistent structure:

- ✅ **Approach Name** (e.g., Brute Force, Optimal, Two Pointers, DP)
- 💡 **Explanation / Comments** describing the logic
- ⏱️ **Time Complexity**
- 💾 **Space Complexity**
- 💻 **C++ Implementation**

**Example:**

```cpp
// Problem: Two Sum
// Approach: Hash Map (Optimal)
// Explanation: Store each number's index in a map while iterating.
// For every element, check if its complement already exists in the map.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <vector>
#include <unordered_map>
using namespace std;

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

## 📈 Progress

> This section is updated regularly as I solve more problems.

- 🟢 Actively solving problems and adding new solutions
- 🟢 Focusing on strengthening core topics before moving to advanced ones
- 🔄 Revisiting older solutions to optimize and refactor them

---

## 🎯 Goals

- 🏗️ Build strong DSA fundamentals from the ground up
- 🧩 Improve problem-solving speed and accuracy
- 💼 Prepare for coding interviews and campus placements
- 📅 Maintain consistent, long-term LeetCode practice

---

## 🔗 LeetCode Profile

🔗 [My LeetCode Profile] : (https://leetcode.com/u/calligraphyguruji/)

---

## ⚠️ Disclaimer

This repository is created **purely for learning and educational purposes**. The solutions reflect my personal understanding and problem-solving approach at the time of writing, and may be updated or optimized as I continue to learn.

---

⭐ If you find this repository helpful for your own DSA practice, feel free to star it!A collection of LeetCode questions to ace the coding interview! - Created using [LeetHub v2](https://github.com/arunbhardwaj/LeetHub-2.0)

<!---LeetCode Topics Start-->
# LeetCode Topics
## Math
|  |
| ------- |
| [0050-powx-n](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0050-powx-n) |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0096-unique-binary-search-trees) |
| [0263-ugly-number](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0263-ugly-number) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0264-ugly-number-ii) |
## Dynamic Programming
|  |
| ------- |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0096-unique-binary-search-trees) |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0264-ugly-number-ii) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1547-minimum-cost-to-cut-a-stick) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Tree
|  |
| ------- |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0096-unique-binary-search-trees) |
## Binary Search Tree
|  |
| ------- |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0096-unique-binary-search-trees) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Binary Tree
|  |
| ------- |
| [0096-unique-binary-search-trees](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0096-unique-binary-search-trees) |
## Array
|  |
| ------- |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1547-minimum-cost-to-cut-a-stick) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Sorting
|  |
| ------- |
| [1547-minimum-cost-to-cut-a-stick](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1547-minimum-cost-to-cut-a-stick) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Two Pointers
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bit Manipulation
|  |
| ------- |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Meet in the Middle
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Ordered Set
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## Bitmask
|  |
| ------- |
| [2035-partition-array-into-two-arrays-to-minimize-sum-difference](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/2035-partition-array-into-two-arrays-to-minimize-sum-difference) |
## String
|  |
| ------- |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
## Backtracking
|  |
| ------- |
| [1239-maximum-length-of-a-concatenated-string-with-unique-characters](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/1239-maximum-length-of-a-concatenated-string-with-unique-characters) |
## Recursion
|  |
| ------- |
| [0050-powx-n](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0050-powx-n) |
## Hash Table
|  |
| ------- |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0264-ugly-number-ii) |
## Heap (Priority Queue)
|  |
| ------- |
| [0264-ugly-number-ii](https://github.com/calligraphyguruji/LeetCode-Questions/tree/master/0264-ugly-number-ii) |
<!---LeetCode Topics End-->
