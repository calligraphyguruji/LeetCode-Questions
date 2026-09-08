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
    //Time Complexity = O(n^2) 
    //Space Complexity = O(H) 
    TreeNode* solution(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
        //edge case
        if(inStart > inEnd){
            return NULL ;
        }
        //Step 1: Find root that is last element of postorder
        TreeNode* root = new TreeNode(postorder[postEnd]) ;

        //Step 2 : Search for that root in inorder
        int i = inStart ;

        for( ; i<= inEnd ; i++){

            if(root->val == inorder[i]) //i is the index of the root
                break ;
        }
        
        //Step 3 : root ke left me => left subTree
        //         root ke right me => right subTree
        int leftsize = i-inStart ;
        int rightsize = inEnd-i ;
        
        //func. call for left
        root->left = solution(inorder, postorder, inStart, i-1, postStart, postStart+leftsize-1) ;
        //func. call for right
        root->right = solution(inorder, postorder, i+1, inEnd, postEnd-rightsize, postEnd-1) ;

        return root ; //very important to return the root
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size() ;
        
        //two variables for inorder
        int inStart = 0 ;
        int inEnd = n-1 ;
        
        //two variables for postorder
        int postStart = 0 ;
        int postEnd = n-1 ;

        return solution(inorder, postorder, inStart, inEnd, postStart, postEnd) ;
    }
};