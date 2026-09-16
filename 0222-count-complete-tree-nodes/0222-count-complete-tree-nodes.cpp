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
    //Approach : Binary Tree Height + Divide and Conquer

    //Time Complexity = O(logn * logn) =>
    /* 1. leftHeight() → follows only the left path
    → O(log n)
    2. rightHeight() → follows only the right path
    → O(log n)
    * countNodes() recursively goes down at most O(log n) levels because the tree is complete.
    */


    //Space Complexity = O(logn) =>
    /* leftHeight() and rightHeight() use only while → O(1) extra space.
    * countNodes() uses recursion.
    * Complete binary tree height = O(log n).
    * Therefore recursion stack = O(log n).
    */


    int leftHeight(TreeNode* root){

        int h = 0;

        while(root != NULL){
            h++;
            root = root->left; //checking only one(left) side height
        }

        return h;
    }
    int rightHeight(TreeNode* root){

        int h = 0;

        while(root != NULL){
            h++;
            root = root->right; //checking only one(left) side height
        }

        return h;
    }
    int countNodes(TreeNode* root) {
        
        //base-case
        if(root == NULL){
            return 0;
        }
        
        int lh = leftHeight(root->left);
        int rh = rightHeight(root->right);

        if(lh == rh){ //nodes = 2^(h+1) - 1
            return (1 << (lh + 1)) - 1; // 1 << n = 2^n in Bit Manipulation //left shift 
        }
        else{
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};