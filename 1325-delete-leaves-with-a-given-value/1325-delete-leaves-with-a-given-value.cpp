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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        //base-case
        if(root == NULL) return NULL;

        //1.) Traverse in Postorder : left -> right -> root

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        //2.) After processing both the children, check if current is a leaf & equals target

        if(root->left == NULL && root->right == NULL && root->val == target){
            return NULL;
        }

        //3.)otherwise return current node
        return root;

    }
};