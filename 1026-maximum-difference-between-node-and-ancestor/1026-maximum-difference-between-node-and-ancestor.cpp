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
    //Approach-2 : Optimal(DFS + Min/Max on Current Path)

    //Time Complexity = O(n) =>
    /* Each node is visited exactly once.
    * At every node, we perform only constant-time operations:
        * abs() → O(1)
        * max() → O(1)
        * min() → O(1)
    * Then we recursively visit the left and right children.
    */

    //Space Complexity = O(h) =>
    /* Recursion depth = tree height
    * O(h) → worst case O(n). => height of skewed tree = n.
    */

    int ans = 0; //initialize with 0

    void dfs(TreeNode* node, int minVal, int maxVal){
        //base-case
        if(node == NULL){
            return;
        }

        ans = max({ans, abs(node->val - minVal), abs(node->val - maxVal)});

        //update minVal, maxVal
        minVal = min(minVal, node->val);
        maxVal = max(maxVal, node->val);

        //DFS left
        dfs(node->left, minVal, maxVal);

        //DFS right
        dfs(node->right, minVal, maxVal);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int minVal = root->val;
        int maxVal = root->val;

        dfs(root, minVal, maxVal);

        //finally return the output
        return ans;
    }
};