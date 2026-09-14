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
    //Approach : DFS + Hash Set

    //Time Complexity = O(N + D) => N = number of tree nodes, D = number of nodes in to_delete
    /* Hash Set creation → O(D)
    * DFS visits every node once → O(N)
    * set.find() → O(1) average
    * Overall → O(N + D) = O(N)
    */

    //Space Complexity = O(N + D) => 
    /* Hash Set → O(D)
    * Recursion stack → O(H), worst case O(N)
    * Answer vector → O(N)
    * Overall → O(N)
    */


    TreeNode* helperDFS(TreeNode* root, unordered_set<int>& set, vector<TreeNode*>& ans){

        if(root == NULL){
            return NULL;
        }

        root->left = helperDFS(root->left, set, ans);
        root->right = helperDFS(root->right, set, ans);

        //if curr root is in to_delete then
        if(set.find(root->val) != set.end()){

            if(root->left != NULL){
                ans.push_back(root->left);
            }

            if(root->right != NULL){
                ans.push_back(root->right);
            }

            return NULL;
        }
        else{ //if curr root is not in to_delete
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        //ans vector to store the output
        vector<TreeNode*> ans;

        //Hash set to store to_delete
        unordered_set<int> set;

        //push all elements of to_delete into set
        for(int num : to_delete){
            set.insert(num);
        }

        //func. call to DFS helper
        helperDFS(root, set, ans);


        //check condition if actual tree root is in to_delete
        //if not then add this root also in ans
        if(set.find(root->val) == set.end()){
            ans.push_back(root);
        }

        //finally return the output
        return ans;
    }
};