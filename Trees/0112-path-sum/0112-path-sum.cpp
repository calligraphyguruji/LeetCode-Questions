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
    //Approach : DFS Inorder 

    //Time Complexity = O(N) =>
    /* O(N) — Each node is visited once.
    */

    //Space Complexity = O(H) =>
    /* O(H) — Recursion stack, where H is the height of the tree.
    * Worst case: O(N) for a skewed tree.
    * Best case: O(log N) for a balanced tree.
    */

    
    bool checkPathDFS(TreeNode* root, int sum, int targetSum){
        
        //base-case or edge-case
        if(root == NULL){
            return false;
        }


        sum += root->val;

        //if reached to leaf node
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                return true;
            }
            else{
                return false;
            }
        }

        //check for left subtree
        bool leftSubTree = checkPathDFS(root->left, sum, targetSum);

        //check for right subtree
        bool rightSubTree = checkPathDFS(root->right, sum, targetSum);
         

        //return any one of the paths
        return leftSubTree || rightSubTree;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
                       
        int sum = 0;

        return checkPathDFS(root, sum, targetSum);
    }
};