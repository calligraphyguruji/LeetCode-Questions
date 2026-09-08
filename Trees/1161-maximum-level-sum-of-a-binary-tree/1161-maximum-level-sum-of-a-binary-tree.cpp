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
    //Space Complexity = O(W) => W is max. width of the tree.
    //DFS : Inorder Traversal and using Map
    map<int,int> m ;

    void inOrder(TreeNode* root, int level){
        //base case
        if(root == NULL){
            return ;
        }
        //push values in map
        m[level] += root->val ;

        //inOrder traversal sequence
        //1.) left
        inOrder(root->left,level+1) ;
        
        //2.) right
        inOrder(root->right,level+1) ;

    }

    int maxLevelSum(TreeNode* root) {
        m.clear() ;
        
        inOrder(root,1) ; //1 is currLevel

        int maxSum = INT_MIN ;
        int resultLevel = 0 ;

        //traverse in map and check maxSum
        for(auto &mp : m){
            int level = mp.first ;
            int sum = mp.second ;

            //check if sum > maxSum
            if(sum > maxSum){
                maxSum = sum ;
                resultLevel = level ;
            }
        }
        //very important to return the ans.
        return resultLevel ;
       
    }
};