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
    //Approach : Recursive Depth-First Search (DFS)

    //Time Complexity = O(n) =>
    /* N is the number of nodes in the larger tree.
    * Each pair of corresponding nodes is compared at most once.
    * Each comparison takes O(1) time.
    * In the worst case, the trees are identical, so we check every node.
    * Best case: O(1) if the roots immediately reveal a mismatch or both trees are empty.
    */

    //Space Complexity = O(h) =>
    /* H is the height of the tree.
    * Recursion uses the call stack to store active function calls.
    * At most one root-to-leaf path is active at a time.
    * Balanced tree: O(log N) stack space.
    * Skewed tree: O(N) stack space.
    * No additional arrays or queues are used.
    */

    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //1.) Start with root nodes
        if(p == NULL && q == NULL){
            
            return true;
        }

        //2.) Only one empty subtree means different structures.
        if(p == NULL || q == NULL){

            return false;
        }

        //3.) Corresponding nodes must have equal values.
        if(p->val != q->val){
            return false;
        }

        //4.) Both left and right subtree pairs must match.
        return isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right);
    }
};