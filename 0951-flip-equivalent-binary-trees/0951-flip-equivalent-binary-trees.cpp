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
  
    bool dfs(TreeNode* root1, TreeNode* root2){
        //2.) base-cases
        if(!root1 && !root2){
            return true;
        }
        
        if(!root1 || !root2){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        //3.) For current pair of nodes(children) : check two possibilites a.)no flip b.)flip
        //a.) no flip : compare same children
        bool noFlip = dfs(root1->left, root2->left) && dfs(root1->right, root2->right);
        
        //b.) flip : compare diff children
        bool flip = dfs(root1->left, root2->right) && dfs(root1->right, root2->left);

        //4.) return true if either possibility true
        return noFlip || flip;
        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
        //func. call to dfs
        return dfs(root1, root2);
    }
};