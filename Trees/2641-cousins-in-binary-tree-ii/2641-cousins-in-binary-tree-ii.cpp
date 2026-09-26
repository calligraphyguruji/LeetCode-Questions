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
    void bfs(TreeNode* root){
        //base-case
        if(!root) return;

        queue<TreeNode*> q;

        q.push(root);
        root->val = 0; //because root has no cousins

        while(!q.empty()){
            int N = q.size();
             
            //First : Calculate level Sum
            int levelSum = 0;
            queue<TreeNode*> temp = q;

            while(!temp.empty()){
                TreeNode* curr = temp.front();
                temp.pop();

                if(curr->left){
                    levelSum += curr->left->val;
                }

                if(curr->right){
                    levelSum += curr->right->val;
                }
            }

            //Second : Calculate siblingSum           

            while(N--){
                TreeNode* curr = q.front();
                q.pop();
                
                int siblingSum = 0;
                if(curr->left){
                    siblingSum += curr->left->val;
                }

                if(curr->right){
                    siblingSum += curr->right->val;
                }

                //Update/Replace new values
                if(curr->left){
                    curr->left->val = levelSum - siblingSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = levelSum - siblingSum;
                    q.push(curr->right);
                }
            }
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        
        bfs(root);

        return root;
    }
};