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
    //Approach : BFS (Level Order Traversal) + Maximum Value Tracking

    //Time Complexity = O(N) =>
    /* Every node is visited exactly once.
    */

    
    //Space Complexity = O(N) =>
    /* The queue can hold up to N/2 nodes in the worst case (for a complete/balanced binary tree).
    * The ans array stores one value per level, which takes O(H).
    * Therefore, overall SC = O(N).
    */ 

    void bfs(TreeNode* root, vector<int>& ans){
        //1.) base-case
        if(root == NULL){
           return; 
        }
        
        //2.)
        queue<TreeNode* > q;
        q.push(root);

        //3.) 
        while(!q.empty()){
            int N = q.size(); //current levelsize

            int maxVal = INT_MIN; // (-)infinity

            while(N--){//3.c) process all nodes of curr level
                TreeNode* node = q.front();
                q.pop();

                if(maxVal < node->val){ //3.d) update maxValue
                    maxVal = node->val;
                }

                //3.e) push left, right into queue
                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            //level completed
            ans.push_back(maxVal);
        }

    }
    vector<int> largestValues(TreeNode* root) {
        
        vector<int> ans;//to store the output
        
        //func. call to bfs
        bfs(root, ans);
        
        //finally return the output
        return ans;
    }
};