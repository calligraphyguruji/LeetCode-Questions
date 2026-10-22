<h2><a href="https://leetcode.com/problems/diameter-of-binary-tree">543. Diameter of Binary Tree</a></h2><h3>Easy</h3><hr><p>Given the <code>root</code> of a binary tree, return <em>the length of the <strong>diameter</strong> of the tree</em>.</p>

<p>The <strong>diameter</strong> of a binary tree is the <strong>length</strong> of the longest path between any two nodes in a tree. This path may or may not pass through the <code>root</code>.</p>

<p>The <strong>length</strong> of a path between two nodes is represented by the number of edges between them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is the length of the path [4,2,1,3] or [5,2,1,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


<!-- AUTO-GENERATED-SOLUTION-START -->
---

## 🧠 Visual Solution & Intuition

### Part 1

![Diameter of Binary Tree — Part 1](./images/solution-part-1.jpg)

### Part 2

![Diameter of Binary Tree — Part 2](./images/solution-part-2.jpg)

### Part 3

![Diameter of Binary Tree — Part 3](./images/solution-part-3.jpg)

---

## ⏱️ Complexity Analysis

```text
Time Complexity = O(n*n) => cause in diameter func. for currDiam height func. is calling
Space Complexity = O(1)
```

---

## 💻 C++ Solution

[View Original C++ File](./0543-diameter-of-binary-tree.cpp)

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Time Complexity = O(n*n) => cause in diameter func. for currDiam height func. is calling
    //Space Complexity = O(1)
    int height(TreeNode* root){
        //base case
        if(root == NULL) return 0 ;

        //for left
        int leftHt = height(root->left) ;
        //for right
        int rightHt = height(root->right) ;

        return max(leftHt, rightHt) + 1 ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //base case
        if(root == NULL) return 0 ;

        int leftDiam = diameterOfBinaryTree(root->left) ;
        int rightDiam = diameterOfBinaryTree(root->right) ;
        int currDiam = height(root->left) + height(root->right) ;

        return max(currDiam, max(leftDiam, rightDiam)) ;
    }
};
```

<!-- AUTO-GENERATED-SOLUTION-END -->
