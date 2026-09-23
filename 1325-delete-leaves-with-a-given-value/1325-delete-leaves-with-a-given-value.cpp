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

    //Approach : DFS (Postorder)

    //Time Complexity = O(n) =>
    /* Suppose the tree has N nodes.
    * In the DFS, each node is visited exactly once.
    * At every node, we do only constant-time operations:
        * Check left subtree
        * Check right subtree
        * Check whether it is a leaf
        * Compare node->val with target
    * So : N nodes × O(1) work per node = O(N)
    */

    //Space Complexity = O(h) =>
    /* The algorithm uses recursion, so the extra space comes from the recursion call stack.
    * h = height of the binary tree.
    * At any moment, the recursion stack contains at most h nodes.
    */

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