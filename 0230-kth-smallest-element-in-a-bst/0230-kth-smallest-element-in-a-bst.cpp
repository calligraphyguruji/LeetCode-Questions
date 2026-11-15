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
    //Approach : Iterative Inorder Traversal using a Stack

    //Time Complexity = O(h + k) =>
    /* h is the tree’s height, and k is the requested rank.
    * Reaching the leftmost node initially takes up to O(h) work.
    * We pop and count exactly k nodes. Total stack operations take O(h + k) time.
    * Balanced BST: O(log n + k).
    * Worst case: O(n).
    */

    //Space Complexity = O(h) =>
    /* The stack stores waiting nodes along a root-to-node path.
    * It can hold at most h nodes.
    * Balanced BST: O(log n).
    * Skewed BST, worst case: O(n).
    * current and count use only O(1) extra space.
    */


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