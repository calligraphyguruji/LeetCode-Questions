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
    //Time Complexity = O(n) => traversing n nodes in the tree
    //Space Complexity = O(n) => level order traversal using queue
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        queue<TreeNode*> q ;
        //first push the root1, root2 in the queue 
        q.push(root1) ; 
        q.push(root2) ;

        //traverse on trees and make the modification

        while(!q.empty()){
            //make two pointers to point left child, right child null
            //if there is no child
            TreeNode* first = q.front() ; q.pop() ;
            TreeNode* second = q.front() ; q.pop() ;

            //if both null then continue
            if(first == NULL && second == NULL){
                continue ;
            }

            //if one val is NULL or values not same then false
            if(first == NULL || second == NULL || first->val != second->val){
                return false ;
            }

            //push children in same order left,left && right,right
            q.push(first->left) ;
            q.push(second->left) ;

            q.push(first->right) ;
            q.push(second->right) ;
        }

        //if no false found in above loop then
        return true ;
    }
};