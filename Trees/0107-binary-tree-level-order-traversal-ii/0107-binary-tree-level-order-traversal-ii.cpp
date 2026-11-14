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
    //Approach : BFS (Level-Order Traversal)

    //Time Complexity = O(n) =>
    /* Each of the n nodes is added to and removed from the queue once: O(n).
    * Collecting all node values takes O(n).
    * Reversing h levels takes O(h). Since h ≤ n, total time is O(n).
    */

    //Space Complexity = O(n) =>
    /* Queue: O(w), where w is the maximum number of nodes at any level.
    * Temporary level vector: O(w).
    * Reversing ans: O(1) extra space.
    * Auxiliary space excluding output: O(w), worst case O(n).
    * Output ans: O(n), so total space including output is O(n).
    */


    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;//to store the output array

        //1.) Base-case
        if(root == NULL){
            return ans;
        }

        //2.) Initialize a queue with root
        queue<TreeNode*> q;
        q.push(root);

        //3.) Process until queue is empty
        while(!q.empty()){

            int N = q.size(); //level size

            vector<int> level;//to store nodes of one level at a time

            while(N--){//4.) Process exactly one level at a time

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                //add its existing children—left first, then right.
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

            }
            
            //5.) Save the completed level.
            ans.push_back(level);
        }
        
        //6.) Reverse the collected levels and return them.
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};