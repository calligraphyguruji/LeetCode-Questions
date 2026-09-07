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
    //Time Complexity = O(n) => cause visting n nodes of the tree.
    //Space Complexity = O(H) => H = recursion stack height = height of the tree.
    int prevIdx = 0 ;

    int kthSmallest(TreeNode* root, int k) {
        //for empty tree
        if(root == NULL) return -1 ;
        
        //Inorder Traversal sequence : 1.)left 2.)root 3.)right
        //1.) call for left SubTree
        if(root->left != NULL){
            int leftAns = kthSmallest(root->left,k) ;

            if(leftAns != -1)
                return leftAns ; //as final ans.
        }

        //2.) for root val
        if(prevIdx + 1 == k){
            return root->val ;           
        }
        prevIdx ++; //update prevIdx in backtracking

        //3.) call for right subTree
        if(root->right != NULL){
            int rightAns = kthSmallest(root->right,k) ;

            if(rightAns != -1){
                return rightAns ; //as final ans.
            }
        }


        //if in above calls no ans found then
        return -1 ;

    }
};