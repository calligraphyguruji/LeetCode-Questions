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
class FindElements {
public:
    unordered_set<int> values;

    void recover(TreeNode* root, int val){

        //base-case
        if(root == NULL) return;

        root->val = val;

        values.insert(val);
        
        //if tree has left => val = 2*val + 1
        recover(root->left, 2*val + 1);

        //if tree has right => val = 2*val + 2
        recover(root->right, 2*val + 2);

    }
    FindElements(TreeNode* root) {
        
        //intial val = 0

        recover(root, 0);
    }
    
    bool find(int target) {
        
        //check whether target exists in the set
        return values.count(target) > 0; 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */