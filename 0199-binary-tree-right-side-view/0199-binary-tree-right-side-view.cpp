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
    //Approach-2 : DFS(Preorder Traversal)

    //Time Complexity = O(h) => visiting n nodes
    //Space Complexity = O(h) => extra ans vector used to store nodes value
    
    void solve(TreeNode* root, int depth, vector<int>& ans){
        //base case: empty tree
        if(root == NULL){
            return;
        }
        
        if(depth == ans.size()){ //right node of this depth
            ans.push_back(root->val);
        }

        //recursively traverse :
        //1.) right subTree
        solve(root->right, depth+1, ans);

        //2.) left subTree
        solve(root->left, depth+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans; //to store rightmost nodes value

        int depth = 0;

        solve(root, depth, ans);

        return ans;
    }
};