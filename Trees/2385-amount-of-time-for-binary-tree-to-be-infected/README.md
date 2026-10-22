<h2><a href="https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected">2461. Amount of Time for Binary Tree to Be Infected</a></h2><h3>Medium</h3><hr><p>You are given the <code>root</code> of a binary tree with <strong>unique</strong> values, and an integer <code>start</code>. At minute <code>0</code>, an <strong>infection</strong> starts from the node with value <code>start</code>.</p>

<p>Each minute, a node becomes infected if:</p>

<ul>
	<li>The node is currently uninfected.</li>
	<li>The node is adjacent to an infected node.</li>
</ul>

<p>Return <em>the number of minutes needed for the entire tree to be infected.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231744-1.png" style="width: 400px; height: 306px;" />
<pre>
<strong>Input:</strong> root = [1,5,3,null,4,10,6,9,2], start = 3
<strong>Output:</strong> 4
<strong>Explanation:</strong> The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/06/25/image-20220625231812-2.png" style="width: 75px; height: 66px;" />
<pre>
<strong>Input:</strong> root = [1], start = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> At minute 0, the only node in the tree is infected so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>Each node has a <strong>unique</strong> value.</li>
	<li>A node with a value of <code>start</code> exists in the tree.</li>
</ul>


<!-- AUTO-GENERATED-SOLUTION-START -->
---

## 🧠 Visual Solution & Intuition

### Part 1

![Amount of Time for Binary Tree to Be Infected — Part 1](./images/solution-part-1.jpg)

### Part 2

![Amount of Time for Binary Tree to Be Infected — Part 2](./images/solution-part-2.jpg)

---

## 💡 Approach

```text
Approach : Parent map(DFS) + BFS
```

---

## ⏱️ Complexity Analysis

```text
Time Complexity = O(N) =>
Space Complexity = O(N) =>
```

---

## 💻 C++ Solution

[View Original C++ File](./2385-amount-of-time-for-binary-tree-to-be-infected.cpp)

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
    //Approach : Parent map(DFS) + BFS

    //Time Complexity = O(N) =>
    /* DFS visits every node exactly once to:
        * Store its parent in the parent map.
        * Find the startNode. 
        * So : N nodes -> O(N)

    * BFS also visits every node once.
    * For each node, we check at most 3 neighbors:
        left
        right
        parent

    * So : N nodes × 3 → O(N)
    */

    //Space Complexity = O(N) =>
    /* We use extra space for:
    * parent map → stores one parent for each node → O(N)
    * visited set → stores each visited node → O(N)
    * queue → can contain nodes from the current/next BFS levels → O(N) in the worst case
    */


    unordered_map<TreeNode* , TreeNode*> parent;
    TreeNode* startNode = NULL;

    void dfs(TreeNode* node, TreeNode* par, int start){
        //base-case
        if(node == NULL) return;

        parent[node] = par;//store current node parent

        if(node->val == start){
            startNode = node;
        }

        //left
        dfs(node->left, node, start);

        //right
        dfs(node->right, node, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        
        //1.) Build parent map
        dfs(root, NULL, start);
         
        //2.) Start BFS
        //queue for BFS
        queue<TreeNode* > q;
        
        unordered_set<TreeNode* > visited;

        q.push(startNode);
        visited.insert(startNode);

        int time = 0;//initially no nodes infected

        while(!q.empty()){
            int N = q.size(); //current level size

            while(N--){//process current level
                
                TreeNode* node = q.front();
                q.pop();

                
                //check if not visited left, right, parent
                //left
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                //right
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                //parent
                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }                                
            }
            // One minute has passed if another level exists
            if(!q.empty())
                time++;
        }

        //finally return total time
        return time;
    }
};
```

<!-- AUTO-GENERATED-SOLUTION-END -->
