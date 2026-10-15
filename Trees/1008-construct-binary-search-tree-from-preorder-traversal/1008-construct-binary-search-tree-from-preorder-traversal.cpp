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
    TreeNode* buildBST(vector<int>& preorder, int &i, int upBound){

        if( i >= preorder.size() || preorder[i] > upBound){
            return NULL;
        }


        //start building with preorder
        //first root node
        TreeNode* root = new TreeNode(preorder[i++]) ;
        
        root->left = buildBST(preorder,i,root->val) ;

        root->right = buildBST(preorder,i,upBound) ;

        return root ;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ; //start traversing from idx = 0

        return buildBST(preorder,i,INT_MAX) ;
    }
};