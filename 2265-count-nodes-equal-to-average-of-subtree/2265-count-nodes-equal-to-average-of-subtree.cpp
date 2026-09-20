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
    //Approach : DFS(Postorder)

    //Time Complexity = O(n) =>
    /* Each node is visited exactly once.
    */

    //Space Complexity = O(h) =>
    /* Recursion stack can hold up to H nodes, where H is the height of the tree.
    * Worst case (skewed tree): O(N)
    * Balanced tree: O(log N)
    */


    pair<int, int> dfs(TreeNode* node, int& ans){ //dfs is paired {sum, count}
        //base-case
        if(node == NULL){
            return {0, 0}; //{sum , count}
        }
        

        //Postorder : left -> right -> root
        //2.)
        auto left = dfs(node->left, ans);
        
        //3.)
        auto right = dfs(node->right, ans);

        //4.)
        int sum = left.first + right.first + node->val;

        //5.)
        int count = left.second + right.second + 1;

        //6.)
        if(node->val == sum / count){
            ans++;
        }

        //7.)
        return {sum, count};

    }

    int averageOfSubtree(TreeNode* root) {
        
        int ans = 0;//initially no nodes have been checked

        
        dfs(root, ans);

        //finally return the output
        return ans;
    }
};