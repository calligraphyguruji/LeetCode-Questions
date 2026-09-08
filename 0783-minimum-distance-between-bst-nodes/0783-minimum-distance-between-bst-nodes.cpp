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
    //Space Complexity = O(H) where H = height of the tree
    //global prev pointer 
    TreeNode *prev = NULL ;

    int minDiffInBST(TreeNode* root) {
        
        //base case
        if(root == NULL){
            return INT_MAX ; 
        }

        int ans = INT_MAX ;
        //Step 1 : for left subTree
        if(root->left){
            int leftMin = minDiffInBST(root->left) ;
            ans = min(ans, leftMin) ;
        }

        //Step 2 : for root node
        if(prev != NULL){
            ans = min(ans, root->val - prev->val) ; //currDiff = root-prev
        }
        prev = root ; //update prev pointer
        

        //Step 3 : for right subTree
        if(root->right){
            int rightMin = minDiffInBST(root->right) ;
            ans = min(ans, rightMin) ;
        }

        return ans ; //very important to return the ans
    }
};