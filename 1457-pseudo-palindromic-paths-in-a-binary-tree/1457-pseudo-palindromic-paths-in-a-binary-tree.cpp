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
    //Approach : DFS(Preorder) + Bitmasking

    //Time Complexity = O(N) =>
    /* We visit every node exactly once.
    * At each node, toggling a bit and checking the mask take O(1).
    * Therefore, for N nodes: O(N)
    */
 
    //Space Compleixty = O(H) =>
    /* H = height of the binary tree.
    * The DFS recursion stack can go as deep as the tree height.
    * The mask is passed by value, but it is only an integer, so each recursive call uses O(1) extra space. 
    */


    int ans = 0; //initially no nodes are pseudo-palindromic because we haven't started traversing

    void dfs(TreeNode* node, int mask){ //Preorder DFS : root, left, right
        //base-case
        if(node == NULL) return;

        // toggle the current node
        mask ^= (1 << node->val);

        // check if it's a leaf
        if(node->left == NULL && node->right == NULL){
            //check its bitmask
            //if set bit 0 or 1 => ans ++
            if( (mask & (mask-1)) == 0 ){
                ans++;
            }
            //else
            return;
        }


        //continue dfs to left, right
        dfs(node->left, mask);
        dfs(node->right, mask);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int mask = 0; // 0 in binary has all bits set to 0
        
        //func. call to dfs
        dfs(root, mask);
        
        //finally return the output : no. of pseudo-palidromic paths
        return ans;
    }
};