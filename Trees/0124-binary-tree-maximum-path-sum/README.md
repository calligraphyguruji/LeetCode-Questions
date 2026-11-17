<h2><a href="https://leetcode.com/problems/binary-tree-maximum-path-sum">124. Binary Tree Maximum Path Sum</a></h2><h3>Hard</h3><hr><p>A <strong>path</strong> in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence <strong>at most once</strong>. Note that the path does not need to pass through the root.</p>

<p>The <strong>path sum</strong> of a path is the sum of the node&#39;s values in the path.</p>

<p>Given the <code>root</code> of a binary tree, return <em>the maximum <strong>path sum</strong> of any <strong>non-empty</strong> path</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx1.jpg" style="width: 322px; height: 182px;" />
<pre>
<strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The optimal path is 2 -&gt; 1 -&gt; 3 with a path sum of 2 + 1 + 3 = 6.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg" />
<pre>
<strong>Input:</strong> root = [-10,9,20,null,null,15,7]
<strong>Output:</strong> 42
<strong>Explanation:</strong> The optimal path is 15 -&gt; 20 -&gt; 7 with a path sum of 15 + 20 + 7 = 42.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 3 * 10<sup>4</sup>]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>


<!-- AUTO-GENERATED-SOLUTION-START -->
---

## 🧠 Visual Solution & Intuition

### Part 1

![Binary Tree Maximum Path Sum — Part 1](./images/solution-part-1.jpg)

### Part 2

![Binary Tree Maximum Path Sum — Part 2](./images/solution-part-2.jpg)

---

## 💻 C++ Solution

[View Original C++ File](./0124-binary-tree-maximum-path-sum.cpp)

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
    int gain(TreeNode* root, int& best){

        if(root == NULL) return 0;

        //Step 2: Process both children
        // Step 3: Skip negative contributions.
        int L = max(0, gain(root->left, best)); // max(0, ....)
        int R = max(0, gain(root->right, best)); // max(0, ....) 0 is used for skip negative contributions

        //Step 4: Check a complete path using both sides.
        best = max(best, root->val + L + R);

        //Step 5: Return only one chain to the parent.
        return root->val + max(L, R);

    }
    int maxPathSum(TreeNode* root) {
        
        //Step 1: Initialize the overall answer.
        int best = INT_MIN; // (-ve)infinity

        gain(root, best);

        return best;
    }
};
```

<!-- AUTO-GENERATED-SOLUTION-END -->
