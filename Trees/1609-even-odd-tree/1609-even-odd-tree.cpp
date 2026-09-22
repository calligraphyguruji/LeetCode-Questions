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
    bool isEvenOddTree(TreeNode* root) {
        //Step-1.
        queue<TreeNode*> q;

        q.push(root);
        
        //Step-2.
        int level = 0;//current level of root is zero

        //start traversing
        while(!q.empty()){
            
            int N = q.size();
            int prev;
            
            //Step-3.
            if(level % 2 == 0){//even level
                prev = INT_MIN;
            }
            else{ //odd level
                prev = INT_MAX;
            }

            while(N--){
                TreeNode* curr = q.front();
                q.pop();

                //Step-4.
                //check if even level => values must be odd and curr > prev
                if(level % 2 == 0){
                    
                    if(curr->val % 2 == 0 || curr->val <= prev){ //even values or curr <= prev
                        return false; //Step-5
                    }
                }
                //check if odd level => values must be even and curr < prev
                else{
                    
                    if(curr->val % 2 != 0 || curr->val >= prev){ //odd values or curr >= prev
                        return false; //Step-5
                    }
                }

                //Update the prev after checks
                prev = curr->val;

                //6.) push left, right children
                if(curr->left != NULL){
                    q.push(curr->left);
                }
                
                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }
            //move to the next level
            level++;
        }

        //7.) if all levels pass above checks then
        return true;
    }
};