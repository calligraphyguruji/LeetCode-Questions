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
    unordered_map<int, int> inorderIdx;//Hash map {value, idx}
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int left, int right){

        //3.) An empty range represents an empty subtree.
        if(left > right){
            return NULL;
        }

        //4.) Take the next preorder value as the root.
        int rootValue = preorder[preIdx++];

        TreeNode* root = new TreeNode(rootValue);

        //5.) Find where the root divides the inorder range.
        int mid = inorderIdx.at(rootValue);

        //6.) Build the left subtree first, following preorder order.
        root->left = build(preorder, left, mid - 1);

        //7.) Build the right subtree.
        root->right = build(preorder, mid + 1, right);

        //8.) Return the completed subtree
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        //1.) Reset shared state and store each value's inorder index.
        preIdx = 0;
        inorderIdx.clear();

        int n = static_cast<int>(inorder.size());

        for(int i = 0; i < n; i++){
            inorderIdx[inorder[i]] = i; //idx fill in hash map
        }
       
        //2.) Build the tree using the entire inorder range.
        return build(preorder, 0, n-1);
   
    }
};