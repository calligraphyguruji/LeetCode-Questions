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
    int helper(TreeNode* root){

        //base-case
        if(root == NULL) return 0;

        //Postorder DFS : left -> right -> root
        int leftDepth = helper(root->left);
        int rightDepth = helper(root->right);

        //depth(root) = 1 + max(leftDepth, rightDepth)
        return 1 + max(leftDepth, rightDepth);
    }
    int maxDepth(TreeNode* root) {
        
        //func. call to helper
        return helper(root);
    }
};