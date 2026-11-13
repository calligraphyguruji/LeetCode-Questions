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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;//to store the output
        
        if(root == NULL){
            return result;
        }

        //1.) Intialize a queue for BFS
        queue<TreeNode*> q;

        q.push(root); //start with root

        //2.) Process until q is empty
        while(!q.empty()){
         
            int N = q.size();//level size
            
            vector<int> level;
            
            //3.) Process exactly levelSize nodes
            while(N--){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                //4.) Prepare the next level: push children in queue
                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

            // 5.) Store the completed level.
            result.push_back(level);
        }

        return result;
    }
};