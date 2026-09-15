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
    //Approach : PostOrder DFS (left -> right -> root)

    //Time Complexity = O(N) =>
    /* Each node is visited once.
    * For every node, we perform constant-time work.
    * Therefore, total time = O(N).
    */

    //Space Complexity = O(H) =>
    /* Due to the recursion stack.
    * H = height of the tree.
    * Worst case (skewed tree): O(N).
    * Best case (balanced tree): O(log N).
    */

    
    TreeNode* pruneTree(TreeNode* root) {
        //base-case or edge-case
        //if empty tree
        if(root == NULL){
            return NULL;
        }

        //1.) recursively call for root->left
        root->left = pruneTree(root->left);

        //2.) recursively call for root->right
        root->right = pruneTree(root->right);


        //3.) check if root == 0 ? or 1 ? for single node
        if(root->left == NULL && root->right == NULL && root->val == 0){
            return NULL;
        }
        
        else{
            return root;
        }
    }
};