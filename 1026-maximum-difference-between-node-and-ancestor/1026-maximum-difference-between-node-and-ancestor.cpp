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
    int maxDiff = 0; //initialize with 0

    void findDescendants(TreeNode* node, int ancestor){
        //base-case
        if(node == NULL) return;

        maxDiff = max(maxDiff, abs(ancestor - node->val));

        //recursively find diff of all descendants
        findDescendants(node->left, ancestor);
        findDescendants(node->right, ancestor);
    }

    void chooseAncestor(TreeNode* root){
        //base-case
        if(root == NULL) return;

        //first choose root as ancestor
        findDescendants(root->left, root->val);
        findDescendants(root->right, root->val);

        //call for choosing next ancestors
        chooseAncestor(root->left);
        chooseAncestor(root->right);
    }

    int maxAncestorDiff(TreeNode* root) {
        
        chooseAncestor(root);
        
        //finally return the output
        return maxDiff;
    }
};