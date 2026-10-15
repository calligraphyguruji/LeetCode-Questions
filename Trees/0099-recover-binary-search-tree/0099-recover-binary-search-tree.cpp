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
    void recoverTree(TreeNode* root) {

        //three variables needed
        TreeNode* prev = NULL ;
        TreeNode* first = NULL ;
        TreeNode* second = NULL ;

        //Moris Inorder Traversal using Loop
    while(root != NULL){
        if(root->left == NULL){
            if(prev != NULL && root->val < prev->val){
                if(first == NULL){
                    first = prev ;
                }
                second = root ;
            }

            prev = root ;//update previous 
            root = root->right ;
        }

        else{
            //find the prev(IP) : Inorder predecessor
            TreeNode* IP = root->left ;
            while(IP->right != NULL && IP->right != root){
                IP = IP->right ;
            }

            if(IP->right == NULL){
                IP->right = root ;
                root = root->left ;
            }
            else{
                if(prev != NULL && root->val < prev->val){
                        if(first == NULL){
                            first = prev ;
                        }
                        second = root ;
                    }

                    //update previous
                    prev = root ;
                    IP->right = NULL ;
                    root = root->right ;
                }
            }
    }

        //swap the first & second
    if(first && second != NULL){
       int temp = first->val ;
       first->val = second->val ;
       second->val = temp ;

    }    
               
    }
};