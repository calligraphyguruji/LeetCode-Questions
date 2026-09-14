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
    //Approach : BFS + Queue

    //Time Complexity = O(n) => for n nodes
    /* Every node is pushed into the queue once.
    * Every node is popped from the queue once.
    * Each node does constant work:
    * check NULL
    * push left child
    * push right child
    */

    //Space Complexity = O(n) =>
    /* Because of the queue:
    * In the worst case, the queue can contain n nodes.
    */

    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        
        //1.)
        q.push(root);
        
        bool foundNull = false;

        while(!q.empty()){
            //2.)
            TreeNode* node = q.front();
            q.pop();
            //3.)
            if(node != NULL){
                //3.a)
                if(foundNull == true){
                    return false;
                }
                
                //3.b)
                q.push(node->left);
                q.push(node->right);
            }
            else{//means node is null
                foundNull = true;
            }
        }
        
        //4.) If no non-NULL node is found after NULL, tree is complete.
        return true;
    }
};