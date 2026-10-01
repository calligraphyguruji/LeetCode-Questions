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
    //Approach : BFS(level order) + Two-Pointer Reversal(left & right)
 
    //Time Complexity = O(n) => O(2n) = O(n) + O(n)
    /* Where n = number of nodes in the tree.
    1. We visit every node exactly once using BFS.
        Every node enters the queue and is removed once.
    2. Reversing odd levels:
        For odd levels, we use two pointers:
            If a level contains K nodes, this takes approximately K/2 operations → O(K)
            Across all odd levels, the total number of nodes is at most n.
    */

    //Space Complexity = O(n) => O(2n) = O(n) + O(n)
    /* We use two extra data structures: 
    1. Queue : The queue stores nodes of the current/next level.
    * In a perfect binary tree, the last level can contain roughly n/2 nodes.
    * So the queue can require: O(n)
    2. Vector : vector<TreeNode*> nodes;
    * This stores all nodes of the current level.
    * The largest level can contain roughly n/2 nodes.
    * So: O(n)
    */


    TreeNode* reverseOddLevels(TreeNode* root) {
        
        //1.) queue for BFS
        queue<TreeNode*> q;

        q.push(root);

        //2.) current level
        int level = 0;

        while(!q.empty()){

            int N = q.size(); //size of current level
            
            //3.a) store all nodes of that level in a vector
            vector<TreeNode*> nodes;

            //3.)for every level
            while(N--){                
                
                TreeNode* curr = q.front();
                q.pop();
                
                nodes.push_back(curr);

                //Add children for next level
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
            //3.b) if curr level is odd => reverse using two pointers
            if(level % 2 != 0){
                
                int left = 0;
                int right = nodes.size() - 1;

                while(left < right){
                    swap(nodes[left]->val, nodes[right]->val);

                    left++;
                    right--;
                }
            }                
            //4.) current level completed
            level++;
        }
        
        //5.)
        return root;
    }
};