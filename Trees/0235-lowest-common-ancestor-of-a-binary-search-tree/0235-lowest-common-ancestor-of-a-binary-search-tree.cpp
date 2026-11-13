/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Step 1: Start at the root.
        TreeNode* curr = root;

        // Step 2: Follow the subtree containing both target nodes.
        while(curr != NULL){

            if(p->val < curr->val && q->val < curr->val){
                // Step 3: Both targets are smaller, so move left.
                curr = curr->left;
            }

            else if(p->val > curr->val && q->val > curr->val){
                // Step 4: Both targets are larger, so move right.
                curr = curr->right;
            }
            else{
                // Step 5: Targets split here, or current equals p or q.
                // No deeper node can be an ancestor of both.
                return curr;
            }
        }

        // Both targets exist, so valid inputs always return inside the loop.
        return NULL;
    }
};