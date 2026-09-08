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
    //Time Complexity = O(n) => cause traversing n nodes of the tree.
    //Space Complexity = O(n) => cause queue stores elements of each level // in worst case queue stores n/2 elements at a time.
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzag ; //to store the output or ans.

        //for empty tree
        if(root == NULL) return zigzag ;

        queue<TreeNode*> q ; 

        //Push root in the queue as level-1
        q.push(root) ;

       //now traverse in the tree and push values in the queue level wise   
       bool flag = false ; //for root

       while(!q.empty()){
        int n = q.size() ;

        vector<int> level ; //to store values on each level

        stack<int> rev ; //to reverse the altenate level values

        while(n--){
            TreeNode* node = q.front() ;
            q.pop() ;

            if(flag){ //flag == true
                rev.push(node->val) ;
            }
            else{ //flag == false then 
                level.push_back(node->val) ;//simply add that value in the level
            }

            //push left, right child in the queue.
            if(node->left != NULL)
                  q.push(node->left) ;

            if(node->right != NULL){
                  q.push(node->right) ;
            }
        }
        //after each iteration update the flag
        flag = !flag ;

        //push in the queue & pop all elements from the stack
        while(!rev.empty()){
            level.push_back(rev.top()) ;
            rev.pop() ;
        }

        //after each level
        zigzag.push_back(level) ;

       }

       //very important to return the output
       return zigzag ;
    }
};