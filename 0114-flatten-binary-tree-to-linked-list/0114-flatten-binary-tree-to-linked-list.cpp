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
    //Time Complexity = O(n^2) 
    //Space Complexity = O(H) => recursion stack height = height of the tree. // H = logn for balanced tree. // H = n for skewed tree.
    void flatten(TreeNode* root) {
        //for empty tree
        if(root == NULL) return ;

        //trust and call for root->left to flatten
        flatten(root->left) ;
        
        //lly for right child trust and func. call
        flatten(root->right) ;

        TreeNode* leftTree = root->left ;
        TreeNode* rightTree = root->right ;
        //given condition
        root->left = NULL ; 
        root->right = leftTree ;

        TreeNode* temp = root ;             
        //traverse till last node of flattened
        while(temp->right != NULL){
                temp = temp->right ;
        }
        //make connection of last node to root
        temp->right = rightTree ;

    }
};