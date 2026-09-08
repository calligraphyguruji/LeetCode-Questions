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
    //Time Complexity = O(N) => traversing n elements of the tree
    //Space Complexity =  O(N + M) => N = no. of nodes in root , M = no. of nodes in subRoot
    //also recursion stack height = N, => O(N) for recursion preorder

    string preorder(TreeNode* node){
        //base case
        if(node == NULL) return "null" ;
        
        //now do preorder traversal
        //1.) add root node val in string
        string s = "," + to_string(node->val) ;
        //2.) left child
        s += preorder(node->left) ;
        //3.) right child
        s += preorder(node->right) ;
        

        return s ; //after the traversal
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //converting both trees to string to do pre-order traversal and check subtree(substring)
        string fullTree = preorder(root) ;
        string subTree = preorder(subRoot) ;

        //return true if subTree exists inside fullTree
        return fullTree.find(subTree) != string::npos ;
        //npos → means “not found”
    
    }
};