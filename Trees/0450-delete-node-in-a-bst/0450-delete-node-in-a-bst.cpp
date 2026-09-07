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
    //BST Deletion : Recursive

    //Time Complexity = O(h)
    //Space Complexity = O(h)
    // h = height of the tree
    // h = logn, if balanced tree
    // h = n, if skewed tree


    TreeNode* deleteNode(TreeNode* root, int key) {
        //edge-case/ base-case
        if(root == NULL) return NULL;

        //if key is smaller than root => go to left Subtree
        if(key < root->val){
           root->left = deleteNode(root->left, key);
        }

        //if key is greater than root => go to right Subtree
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }

        else{

            TreeNode* temp;
            //Case-1 : no children => leaf node or single node tree
            if(root->left == NULL && root->right == NULL){
                //delete root
                delete root;
                return NULL;
            }

            //Case-2 : single child
            if(root->left == NULL){
                temp = root->right;
                //delete root
                delete root;
                return temp;
            }
            
            if(root->right == NULL){
                temp = root->left;
                //delete root
                delete root;
                return temp;
            }


            //Case-3 : if both children exist
            /*. 1. Find inorder successor => min(right subtree)
                2. Copy successor’s value
                3. Delete successor 
            */

            temp = root->right; 
           
            //find the min in right subtree
            while(temp->left != NULL){
                temp = temp->left;
            }
            //copy successor's value
            root->val = temp->val;

            //delete inorder successor
            root->right = deleteNode(root->right, temp->val);
            
        }

        //finally return the root
        return root;
    }
};