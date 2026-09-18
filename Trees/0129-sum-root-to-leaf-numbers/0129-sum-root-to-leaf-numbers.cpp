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
    //Approach : Top-Down DFS (Root-to-Leaf DFS) + Running Number

    //Time Complexity = O(N) =>
    /* Our DFS visits every node exactly once.
    * For each node, we do only constant-time work: 
        current = current * 10 + node->val;
        and check whether it is a leaf.
    * Overall : N nodes × O(1) work = O(N)
    */

    //Space Complexity = O(H) =>
    /* The extra space comes from the recursive call stack.
    * So the stack uses O(H) space.
    * Worst case: O(N) — completely skewed tree.
    * Balanced tree: O(log N) approximately.
    */

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