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

    vector<int> dfs(TreeNode* root, int distance, int& ans){
       
        //1.) Handle leaf nodes
        if(root->left == NULL && root->right == NULL){
            return {1};
        }
        
        //2.) Use Postorder DFS
        vector<int> left;
        vector<int> right;

        if(root->left != NULL){
            left = dfs(root->left, distance, ans);
        }
        
        if(root->right != NULL){
            right = dfs(root->right, distance, ans);
        }

        //3.) Get distances from both subtrees & Count good pairs
        for(int l : left){
            for(int r : right){
                if(l + r <= distance){
                    ans++;
                }
            }
        }

        //4.) Update distances by +1 for both left & right
        vector<int> curr;

        for(int d : left){
            if(d + 1 <= distance){
                curr.push_back(d+1);
            }
        }

        for(int d : right){
            if(d + 1 <= distance){
                curr.push_back(d+1);
            }
        }

        //5.) return updated value to parent
        return curr;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;

        dfs(root, distance, ans);
        
        //6.)finally return the output
        return ans;
    }
};