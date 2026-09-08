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
     
    //Time Complexity = O(n) => cause traversing n nodes of the tree.
    //Space Complexity = O(n) + O(H) = O(n) => where O(n) : for Hashmap, O(H) for recursion stack height(height of the tree)
    TreeNode* splitTree(vector<int>& preorder,unordered_map<int, int>& inorderIndexMap, int rootIndex, int left, int right){
        //edge case invalid condition
        if(left > right){
            return NULL ;
        }
        //Start Constructing the tree with root that is found in preorder rootIndex.
        TreeNode* root = new TreeNode(preorder[rootIndex]);

        //Find root position in inorder traversal
        int mid = inorderIndexMap[preorder[rootIndex]] ;

        //Create left SubTree( for all the nodes left of the root present in inorder)
        if(mid > left){
            root->left = splitTree(preorder, inorderIndexMap, rootIndex+1, left, mid-1) ;
        }

        //Create right SubTree(for all the nodes right of the root present in inorder)
        if(mid < right){
            root->right = splitTree(preorder, inorderIndexMap, rootIndex + (mid-left) + 1, mid+1, right) ;
        }

        return root ;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap ;

        //Store value->index in Map from inorder traversal
        for(int i = 0 ; i<inorder.size() ; i++){
            inorderIndexMap[inorder[i]] = i ; //inserted i->val in map
        }

        //func. call to splitTree for constructing using preorder
        return splitTree(preorder, inorderIndexMap, 0, 0, inorder.size()-1) ;
    }
};