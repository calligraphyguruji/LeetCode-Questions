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
    //Approach : Iterative Depth-First Search (DFS) using a stack

    //Time Complexity = O(n) =>
    /* Each of the n nodes is pushed onto and popped from the stack once.
    * At each node, comparison, maximum update, and child checks take O(1) time.
    * Total: n × O(1) = O(n).
    */

    //Space Complexity = O(h) =>
    /* The stack stores nodes waiting to be visited, along with their path maximum.
    * In DFS, at most O(h) such entries are needed, where h is the tree’s height.
    * Balanced tree: O(log n).
    * Worst case: O(n).
    * A completely skewed tree actually uses O(1) stack space in this iterative implementation, because only one child waits at a time. Other tree shapes can make the stack grow to O(n).
    * The remaining variables use O(1) space.
    */

    int goodNodes(TreeNode* root) {
        
        //1.) Initialize: Set count = 0.
        int count = 0;
        int maxSoFar = INT_MIN; // (-)infinity

        if(root == NULL) return count;
        
        // Each stack entry stores: {node, maximum on its ancestor path}.
        stack<pair<TreeNode*, int>> st;
        st.push({root, maxSoFar});


        //2.)  Visit every node using iterative DFS
        while(!st.empty()){
            TreeNode* node = st.top().first;
            maxSoFar = st.top().second;//update maxSoFar
            st.pop();

            // 3.) Count the node if no ancestor has a greater value.
            // Equal values are allowed.
            if(node->val >= maxSoFar){
                count++;
            }

            // 4.) Include this node in the maximum passed to its children.
            int updatedMax = max(maxSoFar, node->val);

            // 5.) Give each child its own path maximum.
            // Push right first so the left child is visited first.
            if(node->right != NULL){
                st.push({node->right, updatedMax});
            }

            if(node->left != NULL){
                st.push({node->left, updatedMax});
            }
        }

        // 6.) Return the total number of good nodes.
        return count;
    }
};