/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //Time Complexity = O(n)  => cause traversing n nodes of the tree
    //Space Complexity = O(H) => where H is height of the tree(recursion stack height)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //edge case
        if(root == NULL) 
            return NULL ; //for empty tree

        //edge case 
        if(root == p || root == q) 
            return root ;
       
       //finding leftN that is (p)
       TreeNode* leftN = lowestCommonAncestor(root->left, p, q) ;

       //finding rightN that is q
       TreeNode* rightN = lowestCommonAncestor(root->right, p, q) ;

      //Case-1: when both leftN & rightN are not NULL(p,q both return to root)
      if(leftN != NULL && rightN != NULL){
         return root ; //then ans is root
      }
      
      //Case-2 : when one val(leftN) is not NULL ,rightN is NULL
      if(leftN != NULL)
         return leftN ; //then ans is leftN

      //Case-3 : when rightN is not NULL, leftN is NULL
       else{
        return rightN ;
       }

    
    }
};