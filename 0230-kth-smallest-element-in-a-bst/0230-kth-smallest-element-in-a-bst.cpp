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
    int kthSmallest(TreeNode* root, int k) {
        
        //1.) Initialization : Create an empty stack, set current = root, and initialize count = 0.

        stack<TreeNode*> st;
        TreeNode* curr = root;

        int count = 0;

        // Step 5: Repeat while a current node or waiting ancestor exists.
        while(curr != NULL || !st.empty()){
            
            // Step 2: Move as far left as possible.
            // This reaches the smallest remaining value.
            while(curr != NULL){
                
                st.push(curr);
                curr = curr->left;
            }

            // Step 3: Process the next node in ascending order.
            curr = st.top();
            st.pop();

            // Count when popping: all smaller nodes in this
            // node's left subtree have now been processed.
            count++;

            // Step 4: Return the kth smallest value.
            if(count == k){
                return curr->val;
            }

            // Otherwise, explore the right subtree.
            // The next iteration follows its leftmost path.
            curr = curr->right;

        }

        //If not possible 
        return -1;

    }
};