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
    //Method-2 : Iterative postorder

    //Time Complexity = O(n) => visiting n nodes
    //Space Complexity = O(n) 

    vector<int> postorderTraversal(TreeNode* root) {

        //Sequence : Left -> Right -> Root

        //ans vector to store traversal node->val
        vector<int> ans;

        //edge-case : if empty tree
        if(root == NULL) return ans;

        //Two stacks for traversal
        stack<TreeNode*> s1;
        stack<TreeNode*> s2; 


        //push root into s1
        s1.push(root);

        while(!s1.empty()){
            //1.)
            TreeNode* node = s1.top();
            s1.pop();
            
            //2.)
            s2.push(node);
            
            //3.)
            if(node->left != NULL){
                s1.push(node->left);
            }
            
            //4.)
            if(node->right != NULL){
                s1.push(node->right);
            }            

        }


        while(!s2.empty()){

            //1.)
            TreeNode* node = s2.top();
            s2.pop();

            //2.) insert node->val
            ans.push_back(node->val);
        }

       //finally return the traversal vector 
       return ans;
    }
};