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
    int sum = 0;
    void dfs(TreeNode* node, int current){
        //base-case
        if(node == NULL) return;
        
        //1.) root
        current = current * 10 + node->val;
        
        //check if reached leaf node
        if(node->left == NULL && node->right == NULL){
            sum += current;
            return;
        }

        //2.) left
        dfs(node->left, current);
        
        //3.) right
        dfs(node->right, current);       

    }
    int sumNumbers(TreeNode* root) {
        
        int current = 0;

        dfs(root, current);

        return sum;
    }
};