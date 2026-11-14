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