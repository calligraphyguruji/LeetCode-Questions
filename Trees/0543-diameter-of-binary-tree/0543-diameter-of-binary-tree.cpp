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