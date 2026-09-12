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
    vector<int> rightSideView(TreeNode* root) {

        //base-case
        if(root == NULL){
            return {};
        }

        vector<int> ans; //to store rightmost nodes value

        //create a queue
        queue<TreeNode*> q;

        //1.) push root in queue
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size(); //curr level size

            for(int i=0; i<levelSize; i++){//traverse in curr level
                TreeNode* node = q.front();
                q.pop();
                
                //add the last node in ans
                if(i == levelSize-1){
                    ans.push_back(node->val);
                }

                //push left, right child of node
                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }

        return ans;
    }
};