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
    typedef long long ll;
    ll totalSum = 0;
    ll ans = 0;
    const ll MOD = 1e9 + 7;
    
    //Step-1:
    ll findTotalSum(TreeNode* root){
        if(root == NULL) return 0;

        return root->val + findTotalSum(root->left) + findTotalSum(root->right);
    }
    
    ll dfs(TreeNode* root){
        //base-case
        if(root == NULL) return 0;
        
        //Step-2 :
        ll subSum = root->val + dfs(root->left) + dfs(root->right);

        
        ll sum1 = subSum;
        //Step-3:
        ll sum2 = totalSum - subSum;
        //Step-4:
        ll product = sum1 * sum2;

        ans = max(ans, product);

        return subSum;
    }
    int maxProduct(TreeNode* root) {
        
        totalSum = findTotalSum(root);
        
        dfs(root);

        //finally return maxProduct with modulo
        return ans % MOD;
    }
};