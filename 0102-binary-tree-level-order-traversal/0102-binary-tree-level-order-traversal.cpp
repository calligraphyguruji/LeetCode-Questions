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
    //Time Complexity = O(n) => cause visiting n nodes of the tree.
    //Space Complexity = O(n) => cause at most queue stores n/2 nodes of the tree.
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans ; //to store the the output

        //base case
        if(root == NULL){
            return ans ;
        }

        //make a queue
        queue<TreeNode*> q ;
        //start with root node (level-1)
        q.push(root) ;

        //loop till queue is not empty
        while(!q.empty()){
            int size = q.size() ;
            vector<int> level ; //stores each level

            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front() ;
                //Step 1 : pop and print(insert in level)
                q.pop() ;

                level.push_back(node->val) ;

                //Step 2 : add the left child to queue
                if(node->left) q.push(node->left) ;
                //Step 3 : add the right child to queue
                if(node->right) q.push(node->right) ;
                
            }
            //Now push level values in ans
            ans.push_back(level) ;

        }

        //Finally very important to return the output
        return ans ;

    }
};