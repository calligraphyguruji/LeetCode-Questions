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
    //Space Complexity = O(H) = O(logn) => H is height of the tree(generally logn)
    bool checkMirrorImage(TreeNode *l, TreeNode *r){
        //base case
        if(l == NULL && r == NULL){
            return true ;
        }
        //edge cases
        if(l == NULL && r != NULL){
            return false ;
        }
        if(l != NULL && r == NULL){
            return false ;
        }

        //checks
        if((l->val == r->val) && checkMirrorImage(l->left,r->right) && checkMirrorImage(l->right,r->left)){
            return true ;
        }
        
        //if no true found in above then false
        return false ;
        
    }
    bool isSymmetric(TreeNode* root) {

        if(root == NULL) return true ;

        return checkMirrorImage(root->left,root->right) ;
    }
};