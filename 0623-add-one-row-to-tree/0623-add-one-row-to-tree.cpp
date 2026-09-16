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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
       
        //Special case
        if(depth == 1){
            //make a new root with value = val
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;//make original root to its left child
            return newRoot;
        }
        
        queue<TreeNode*> q; 

        q.push(root);

        int currDepth = 1; //given root depth = 1

        while(!q.empty()){

            int N = q.size();//size of curr level
            
            while(N--){//Process every node at this level
                
                TreeNode* curr = q.front();
                q.pop();

                if(currDepth == depth-1){ //if we have reached depth-1

                //store original left & right children
                TreeNode* leftOrg = curr->left;
                TreeNode* rightOrg = curr->right;
                
                //make new nodes
                TreeNode* newLeft = new TreeNode(val);
                TreeNode* newRight = new TreeNode(val);
                
                //attach new left, new right
                curr->left = newLeft;
                curr->right = newRight;
                
                //preserve original subTrees
                newLeft->left = leftOrg;
                newRight->right = rightOrg;                
                }

                else{
                    if(curr->left != NULL){
                        q.push(curr->left);
                    }
                    if(curr->right != NULL){
                        q.push(curr->right);
                    }
                }
            }

            //if row was inserted, then stop
            if(currDepth == depth-1){
                break;
            }

            currDepth++;//update level or depth            
            
        }

        //finally return root of the new tree
        return root;

    }
};