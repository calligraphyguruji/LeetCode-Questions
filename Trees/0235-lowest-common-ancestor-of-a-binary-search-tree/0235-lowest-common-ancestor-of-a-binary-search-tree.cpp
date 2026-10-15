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
    //Time Complexity = O(H) => H = height of the tree.
    // H = logn for balanced tree.
    //Space Complexity= O(H) => H = recursion stack height= height of the tree.
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //for empty tree
        if(root == NULL) return NULL ;

        //stores value of current node for comparing
        int curr = root->val ;

        //Case-2 : if both p,q lies on the left side
        // if p,q are smaller than curr, the move to left
        if(curr > p->val && curr > q->val){
            return lowestCommonAncestor(root->left,p,q) ;
        }

        //Case-3 : if both p,q lies on the right side
        //if p,q are greater than curr, then move to right.
        if(curr < p->val && curr < q->val){
            return lowestCommonAncestor(root->right,p,q) ;
        }

        //Case-1 : if in above ans not found then ans is root
        return root ;
    }
};