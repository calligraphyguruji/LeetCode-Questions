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
    //Method-2 : Iterative

    //Time Complexity = O(n) => visiting n nodes 

    //Space Complexity = O(h) => h = height of the tree
    // h = logn for balanced tree
    // h = n for skewed tree


    vector<int> preorderTraversal(TreeNode* root) {
        //ans. vector to store result 
        vector<int> ans;
        
        //edge-case : if empty tree
        if(root == NULL) return ans;

        //Make a stack st
        stack<TreeNode*> st ;

        st.push(root); //start traversal with root first

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            
            ans.push_back(node->val); //push root node value

            if(node->right != NULL){
                st.push(node->right);
            }

            if(node->left != NULL){
                st.push(node->left);
            }
        }
        
        //finally return the traversal vector
        return ans;
    }
};