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
    int dfs(TreeNode* node, int& moves){
        //1.)base-case
        if(node == NULL) return 0;

        //2.) recursively calculate for left, right
        int leftBalance = dfs(node->left, moves);

        int rightBalance = dfs(node->right, moves);

        //3.) Count moves required across child-parent edges
        moves += abs(leftBalance);
        moves += abs(rightBalance);

        //4.) Calculate the current subtree
        int balance = leftBalance + rightBalance + node->val - 1;

        //5.)
        return balance; //to parent
    }
    int distributeCoins(TreeNode* root) {
        
        int moves = 0;

        dfs(root, moves);


        //finally return the min. no. of steps/moves required.
        return moves;
    }
};