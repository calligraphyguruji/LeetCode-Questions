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
    //Approach : Parent map(DFS) + BFS

    //Time Complexity = O(N) =>
    /* DFS visits every node exactly once to:
        * Store its parent in the parent map.
        * Find the startNode. 
        * So : N nodes -> O(N)

    * BFS also visits every node once.
    * For each node, we check at most 3 neighbors:
        left
        right
        parent

    * So : N nodes × 3 → O(N)
    */

    //Space Complexity = O(N) =>
    /* We use extra space for:
    * parent map → stores one parent for each node → O(N)
    * visited set → stores each visited node → O(N)
    * queue → can contain nodes from the current/next BFS levels → O(N) in the worst case
    */


    unordered_map<TreeNode* , TreeNode*> parent;
    TreeNode* startNode = NULL;

    void dfs(TreeNode* node, TreeNode* par, int start){
        //base-case
        if(node == NULL) return;

        parent[node] = par;//store current node parent

        if(node->val == start){
            startNode = node;
        }

        //left
        dfs(node->left, node, start);

        //right
        dfs(node->right, node, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        
        //1.) Build parent map
        dfs(root, NULL, start);
         
        //2.) Start BFS
        //queue for BFS
        queue<TreeNode* > q;
        
        unordered_set<TreeNode* > visited;

        q.push(startNode);
        visited.insert(startNode);

        int time = 0;//initially no nodes infected

        while(!q.empty()){
            int N = q.size(); //current level size

            while(N--){//process current level
                
                TreeNode* node = q.front();
                q.pop();

                
                //check if not visited left, right, parent
                //left
                if(node->left && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                //right
                if(node->right && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                //parent
                if(parent[node] && !visited.count(parent[node])){
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }                                
            }
            // One minute has passed if another level exists
            if(!q.empty())
                time++;
        }

        //finally return total time
        return time;
    }
};