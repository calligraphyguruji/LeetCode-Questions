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
    typedef unsigned long long ll ; //this will help to avoid writing long long everywhere.
    //int datatype will give overflow size
    int widthOfBinaryTree(TreeNode* root) {
        //make pair queue to store (val,idx) 
        queue<pair<TreeNode*, ll>> q ;
        //push (root,0)
        q.push({root,0}) ;

        ll maxWidth = 0 ;
        //Level order traversal
        while(!q.empty()){
            //find leftmost & rightmost idx
            ll L = q.front().second ;
            ll R = q.back().second ;
            ll width = R-L+1 ;

            maxWidth = max(maxWidth, width) ;

            int n = q.size() ; //current level size

            while(n--){
                TreeNode* curr = q.front().first ; //curr node of tree
                ll idx = q.front().second ;
                q.pop() ; 

                if(curr->left)
                    q.push({curr->left, 2*idx+1}) ;
                
                if(curr->right)
                    q.push({curr->right, 2*idx+2}) ;
            }
        }

        return maxWidth ; //very important to return the ans.
    }
};