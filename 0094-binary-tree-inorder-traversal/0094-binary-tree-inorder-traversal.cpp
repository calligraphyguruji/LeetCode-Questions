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
    //Method-3 : Iterative Inorder

    //Time Complexity = O(n)
    //Space Complexity = O(h) => h = height of the tree
    //h = logn , if balanced tree
    // h = n , if skewed tree


    vector<int> inorderTraversal(TreeNode* root) {

        //Sequence : Left->Root->Right

        //ans. vector to store nodes->val
        vector<int> ans;

        //edge-case: if empty tree
        if(root == NULL) return ans;

        //stack to traverse
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){
            
            //1.)
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            
            //2.)
            curr = st.top();
            st.pop();
            
            //3.)
            ans.push_back(curr->val); //insert val
    
            //4.)
            curr = curr->right;
            
        }
        

        //finally return traversal vector
        return ans;
    }
};