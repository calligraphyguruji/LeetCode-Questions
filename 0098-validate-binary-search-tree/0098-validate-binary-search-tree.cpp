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
    bool validate(TreeNode* node, long long lower, long long upper){
        // Step 1: An empty subtree is a valid BST.
        if(node == NULL){
            
            return true;
        }

        // Step 2: Check the restrictions imposed by ALL ancestors.
        // Strict bounds also reject duplicate values.
        if(node->val <= lower || node->val >= upper){
            
            return false;
        }

        // Step 3: Every value in the left subtree must be smaller
        // than this node, while respecting the inherited lower bound.
        if(!validate(node->left, lower, node->val)){
            
            return false;
        }
        
        // Step 4: Every value in the right subtree must be greater
        // than this node, while respecting the inherited upper bound.
        return validate(node->right, node->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        // Step 5: Start with bounds beyond all possible int values.
        // long long allows INT_MIN and INT_MAX to be valid node values.
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};