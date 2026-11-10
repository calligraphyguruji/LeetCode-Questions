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
    //Approach : Postorder DFS

    //Time Complexity = O(n) =>
    /* DFS visits all n nodes once. 
    * Each node does constant work to combine its two child depths.
    */

    //Space Complexity = O(h) =>
    /* The recursion stack holds one path at a time, where h is the tree’s height. 
    * That’s O(logn) for a balanced tree and O(n) for a tree shaped like a chain.
    */

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