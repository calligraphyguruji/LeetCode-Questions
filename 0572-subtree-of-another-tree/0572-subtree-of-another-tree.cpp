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
    //Approach : Brute Force using DFS + Recursive Tree Comparison

    //Time Complexity = O(n × m) =>
    /* n = number of nodes in root.
    * m = number of nodes in subRoot.
    * isSubtree() can visit all n nodes as possible starting points.
    * At each starting point, isSameTree() can compare up to m nodes.
    * Therefore, the worst-case time is n × O(m) = O(n × m).
    */

    //Space Complexity = O(hRoot + hSub) =>
    /* hRoot and hSub are the heights of the two trees.
    * Searching through root uses a recursion stack of up to O(hRoot).
    * Comparing trees adds up to O(hSub) recursive calls while search calls remain active.
    No additional arrays or other data structures are created.
    Balanced trees: O(log n + log m).
    Worst-case skewed trees: O(n + m).
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

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        //1.) An empty target is a subtree of any tree.
        if(subRoot == NULL) return true;

        //2.) An empty tree cannot contain a non-empty target.
        if(root == NULL) return false;

        //3.) Check whether the entire tree starting at
        // the current node matches subRoot exactly.
        if(isSameTree(root, subRoot)) return true;

        //4.) If the current node does not start a match,
        // try every possible starting point in its left subtree.
        if(isSubtree(root->left, subRoot)) return true;

        //5.) Search the right subtree.
        // Return false if no match exists there either.
        return isSubtree(root->right, subRoot);
        
    }
};