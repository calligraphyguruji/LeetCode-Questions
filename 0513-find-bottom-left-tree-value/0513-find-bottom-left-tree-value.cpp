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
    int findBottomLeftValue(TreeNode* root) {
        //base-case
        if(root == NULL) return -1;

        //1.)queue for BFS
        queue<TreeNode*> q;
        
        //2.)
        q.push(root);
        
        int ans = root->val;
        
        //3.)
        while(!q.empty()){
            int N = q.size(); //curr level size
            ans = q.front()->val; //leftmost is the first node

            while(N--){
                
                TreeNode* node = q.front();
                q.pop();

                //if left exists
                if(node->left != NULL){
                    q.push(node->left);
                }

                //if right exists
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }

        //4.) finally return the leftmose node value
        return ans;
    }
};