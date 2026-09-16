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
    //Approach : DFS (Preorder)

    //Time Complexity = O(n + m) =>
    /* n = number of nodes in root1
    * m = number of nodes in root2
    * dfs(root1) visits every node → O(n)
    * dfs(root2) visits every node → O(m)
    * Comparing leaf1 == leaf2 takes O(L), where L is the number of leaves.
    * Since L ≤ n,m, total remains: O(n + m)
    */

    //Space Complexity = O(n) =>
    /* leaf1 stores up to n leaf values → O(n)
    * leaf2 stores up to m leaf values → O(m)
    * DFS recursion stack:
        * Worst case skewed tree → O(n + m) 
    */

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

        //recursively traverse the left, right subTree
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