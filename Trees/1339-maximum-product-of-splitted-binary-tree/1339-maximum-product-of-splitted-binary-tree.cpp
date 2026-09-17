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
    //Approach : Subtree Sum + Complement Sum

    //Time Complexity = O(N) =>
    /* O(n) — findTotalSum() visits every node once.
    * O(n) — dfs() visits every node once.
    * Overall: O(n)
    */

    //Space Complexity = O(h) =>
    /* O(h) — recursion stack.
    * h = height of the tree.
    * Worst case (skewed tree): O(n)
    * Balanced tree: O(log n)
    */

    
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