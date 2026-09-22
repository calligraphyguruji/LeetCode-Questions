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
    //Approach : DFS (Depth-First Search) + Backtracking + String Comparison

    //Time Complexity = O(N * N) => N nodes × O(N) path operations 
    /* N = number of nodes.
    * DFS visits every node → O(N).
    * At each leaf, reversing/comparing the path can take up to O(N).
    * In a highly skewed tree, there can be O(N) leaf/path processing in the worst-case analysis.
    */

    //Space Complexity = O(N) =>
    /* path can contain up to N characters for a skewed tree.
    * Recursive DFS call stack can also reach N.
    */

    
    void dfs(TreeNode* node, string& path, string& ans){
        //base-case
        if(node == NULL) return;

        //2.) convert current node into character
        char ch = 'a' + node->val;

        //3.) add this character to path
        path.push_back(ch);

        //4.) if current node is a leaf
        if(node->left == NULL && node->right == NULL){
            
            //4.a) reverse it get a leaf->root path
            reverse(path.begin(), path.end());

            //4.b) compare it with current ans and choose minimum
            if(path < ans){
                ans = path;
            }

            //4.c) reverse back to restore root->leaf path for further traversal
            reverse(path.begin(), path.end());
        }

        //5.) recursively explore left & right subtrees
        dfs(node->left, path, ans);
        dfs(node->right, path, ans);

        //6.) after both subtrees explored backtrack and pop_back()
        path.pop_back();

    }
    string smallestFromLeaf(TreeNode* root) {
        
        //Since we have to find smallest => intialize with greatest
        string ans = "{" ; //this comes after 'z' in ASCII values means greatest of all a-z

        string path;

        dfs(root, path, ans);

        //7.) finally return the smallest string found
        return ans;
    }
};