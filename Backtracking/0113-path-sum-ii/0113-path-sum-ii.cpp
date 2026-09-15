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
    //Topic : Binary Trees
    
    //Approach : DFS + Backtracking

    //Time Complexity = O(N) =>
    /* O(N) — Each node is visited once.
    * Plus path-copying cost for every valid path. 
    */

    //Space Complexity = O(H) =>
    /* Recursion stack + current temp path.
    * Output: O(K × H) for K valid paths.
    */
    void pathDFS(TreeNode* root, int sum, int targetSum, vector<int>& temp, vector<vector<int>>& ans){

        //base-case or edge-case
        if(root == NULL){
            return;
        }
        
        //1.)
        temp.push_back(root->val);
        //2.)
        sum += root->val;

        //3.)if reached to leaf node
        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(temp);
            }
        }

        //4.)recursively call left & right 
        pathDFS(root->left, sum, targetSum, temp, ans);
        pathDFS(root->right, sum, targetSum, temp, ans);

        //5.)Backtrack : remove current node from path
        temp.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        //ans to store the output of all paths
        vector<vector<int>> ans;

        vector<int> temp; //to store current path

        int sum = 0;

       //func. call
       pathDFS(root, sum, targetSum, temp, ans);


        //finally return the output
        return ans;

    }
};