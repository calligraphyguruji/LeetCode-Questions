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
    //Approach : Postorder DFS
 
    //Time Complexity = O(n) =>
    /* n is the number of nodes.
    * Each node is visited at most once.
    * At each node, comparisons, subtraction, abs(), and max() take O(1) time.
    * Total work: n × O(1) = O(n) in the worst case.
    * Early stopping can reduce work, but the worst-case complexity remains O(n).
    */

    //Space Complexity = O(h) =>
    /* h is the tree’s height.
    * Recursive calls use the call stack.
    * At most O(h) calls are active together—the nodes along one root-to-leaf path.
    * Each call stores only a constant amount of information.
    * Balanced tree: h = O(log n) → O(log n) space.
    * Skewed tree: h = O(n) → O(n) space.
    * Left and right subtrees are processed sequentially, so their stack space does not add together.
    */


    int height(TreeNode* root){

        //1.) Base-case
        if(root == NULL) return 0;

        //2.) Process the left , right subtree
        int leftHeight = height(root->left);
        
        if(leftHeight == -1){// If it is unbalanced, propagate the failure upward.
            return -1;
        }

        int rightHeight = height(root->right);
        if (rightHeight == -1){// If it is unbalanced, propagate the failure upward.
            return -1;
        }
 
        // 4. This node is unbalanced if the heights differ by more than 1.
        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }

        // 5. Both subtrees are balanced, so return this subtree's height.
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        
        // A valid height means balanced; -1 means unbalanced.
        return height(root) != -1;
    }
};