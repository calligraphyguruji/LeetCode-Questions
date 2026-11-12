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
    //Approach : Postorder DFS with height calculation

    //Time Complexity = O(n) =>
    /* Each node is visited exactly once.
    * At each node, adding heights, comparing values, and returning height take O(1) time.
    * For n nodes, total time is O(n).
    */

    //Space Complexity = O(h) =>
    /* Recursive calls use stack space proportional to the tree’s height h.
    * Balanced tree: height is O(log n), so space is O(log n).
    * Skewed tree: height is O(n), so space is O(n).
    * Each call uses only a constant amount of local storage.
    */


    int height(TreeNode* root, int& diameter){

        //base-case
        if(root == NULL) return 0;

        // Step 5: Calculate the left & right subtree's height in nodes.
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);

        //Step 6: Update diameter
        diameter = max(diameter, leftHeight + rightHeight);

        // Step 8: Return this subtree's height to its parent.
        // A parent can extend only one branch, so choose the taller one
        // and add 1 to include the current node.
        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        // Step 1: Initialize the longest path length to 0 edges.
        int diameter = 0;
        
        // Step 2: Traverse the tree and update the diameter.
        height(root, diameter);
        
        //Finally 
        return diameter;
    }
};