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
    //Time Complexity = O(n) => cause traversing n nodes of the tree.
    //Space Complexity = O(1) => cause no extra data structures used for storing nodes.
    
    //Very-very easy problem if you have already solved many problems of BST

    long long prev = LLONG_MIN ; //var to track prev values
    bool inorder(TreeNode* root){
        //for empty tree
        if(root == NULL) return true ;
        
        //Sequeunce :
        //1.) left
        //if the left subTree is invalid not follow BST rules then
        if(!inorder(root->left)) return false ;

        //2.) check current root node
        if(root->val <= prev) return false ; 

        //update prev
        prev = root->val ;

        //3.)func. call for right subTree
        return inorder(root->right) ;
    }
    bool isValidBST(TreeNode* root) {
        
        //func. call to inorder traversal
        return inorder(root) ;
        
    }
};