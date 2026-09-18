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
    //Approach : BFS(Level Order Traversal)


    //Time Complexity = O(N) =>
    /* N = number of nodes in the binary tree.
    * Each node is:
        * pushed into the queue once
        * popped from the queue once
        * checked once for whether it is a leaf.
    * Therefore, total work is proportional to N.
    */

    //Space Complexity = O(N) =>
    /* The extra space comes from the queue.
    * In the worst case, the queue can contain many nodes from the same level.
    * For example, in a nearly complete binary tree, the last level can contain about N/2 nodes.
    * So the queue can hold O(N) nodes.
    */


    int bfs(TreeNode* root, int depth){
        //base-case
        if(root == NULL) return 0; //depth = 0
        
        queue<TreeNode*> q;
        q.push(root);
         
        while(!q.empty()){
            int N = q.size(); //size of level

            while(N--){ //process the current level

                TreeNode* node = q.front();
                q.pop();

                //check if reached to leaf node
                if(node->left == NULL && node->right == NULL){
                    return depth;
                }

                //push left child
                if(node->left != NULL){
                    q.push(node->left);
                }
                //push right child
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            depth++;//current level completed increase depth
        }

        return depth;

    }
    int minDepth(TreeNode* root) {
        
        int depth = 1;//root depth = 1
        
        //finally return the depth usiing dfs
        return bfs(root, depth);
    }
};