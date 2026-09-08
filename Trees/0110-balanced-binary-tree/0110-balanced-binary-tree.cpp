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
    //Time Complexity = O(n) => cause traversing single time n nodes of the tree.
    //Space Complexity = O(H) => H = height of the tree(recursion stack height).
    int check(TreeNode* node){
        //base case
        if(node == NULL) return 0 ;

        //check for left
        int leftHt = check(node->left) ;
        if(leftHt == -1) return -1 ;
        //check for right
        int rightHt = check(node->right) ;
        if(rightHt == -1) return -1 ;

        //check absolute val
        if(abs(leftHt-rightHt) > 1) return -1 ;

        return max(leftHt,rightHt)+1 ;
    }
    bool isBalanced(TreeNode* root) {
        //check
        return check(root) != -1 ; //this gives boolean true or false
        //here if balanced true, not balanced -1 or false.
    }
};