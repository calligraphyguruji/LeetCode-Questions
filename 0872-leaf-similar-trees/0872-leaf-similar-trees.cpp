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
    void dfs(TreeNode* root, vector<int>& leaf){
        //base-case
        if(root == NULL){
            return;
        }

        //check if it a leaf node
        if(root->left == NULL && root->right == NULL){
            leaf.push_back(root->val);
            return;
        }

        //recursively traverse the left subTree
        dfs(root->left, leaf);
        dfs(root->right, leaf);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leaf1; //stores the leaf sequence of root1
        vector<int> leaf2;
        
        dfs(root1, leaf1);
        dfs(root2, leaf2);

        if(leaf1 == leaf2){
            return true;
        }

        else{
            return false;
        }

    }
};