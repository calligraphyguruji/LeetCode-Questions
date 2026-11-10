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
    void helper(TreeNode* root){

        //base-case
        if(root == NULL) return;
        
        // Swap the two child branches of current node
        TreeNode* originalLeft = root->left;
        root->left = root->right;
        root->right = originalLeft;

        //Now recursively invert the left subtree & right subtree
        helper(root->left);
        helper(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        
        //call helper func.
        helper(root);

        return root;//finally return the swapped binary tree

    }
};