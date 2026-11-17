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
    int gain(TreeNode* root, int& best){

        if(root == NULL) return 0;

        //Step 2: Process both children
        // Step 3: Skip negative contributions.
        int L = max(0, gain(root->left, best)); // max(0, ....)
        int R = max(0, gain(root->right, best)); // max(0, ....) 0 is used for skip negative contributions

        //Step 4: Check a complete path using both sides.
        best = max(best, root->val + L + R);

        //Step 5: Return only one chain to the parent.
        return root->val + max(L, R);

    }
    int maxPathSum(TreeNode* root) {
        
        //Step 1: Initialize the overall answer.
        int best = INT_MIN; // (-ve)infinity

        gain(root, best);

        return best;
    }
};