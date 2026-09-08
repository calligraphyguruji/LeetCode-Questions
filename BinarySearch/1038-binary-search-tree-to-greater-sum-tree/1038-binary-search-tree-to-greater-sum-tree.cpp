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
    //Time Complexity = O(n)
    //Space Complexity = O(H) => recursion stack height(height of the tree)
    //O(logn) => for balanced tree
    //O(n) => for skewed tree
    void optSolution(TreeNode* root, int &sum){
        //for empty tree
        if(root == NULL) return ;

        //reversed inorder traversal 
        //1.) traverse in right 
        optSolution(root->right,sum) ;
        
        //update sum
        sum += root->val ;

        //update new root->val to sum
        root->val = sum ;

        //2.) traverse in left 
        optSolution(root->left,sum) ;

    }
    TreeNode* bstToGst(TreeNode* root) {
        //sum var to store sum
        int sum = 0 ;

        //func. call to optSolution
        optSolution(root,sum) ;

        return root ;
    }
};