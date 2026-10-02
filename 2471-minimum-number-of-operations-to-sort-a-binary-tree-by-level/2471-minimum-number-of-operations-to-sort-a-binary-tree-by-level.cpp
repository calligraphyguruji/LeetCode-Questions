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
    //Approach : BFS + Cycle detection

    //Time Complexity = O(n * logn) =>
    /* BFS visits every node → O(n)
    * Sorting each level → overall worst case O(n log n)
    * Cycle detection → O(n)
    */

    //Space Complexity = O(n) =>
    /* BFS queue → O(n)
    * nodes array → O(n)
    * sortedLevel → O(n)
    * indexMap → O(n)
    * visited → O(n)
    */

    
    int minimumOperations(TreeNode* root) {
        
        int ans = 0;

        //1.) queue for BFS
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            
            int  N = q.size();
            //2.) store all node values of curr level
            vector<int> nodes;

            while(N--){//process current level

                TreeNode* curr = q.front();
                q.pop();

                //push current node in nodes
                nodes.push_back(curr->val);
                
                //store children for next level
                if(curr->left){
                    q.push(curr->left);
                }

                if(curr->right){
                    q.push(curr->right);
                }
            }
            //3.) Create a sorted version
            vector<int> sortedLevel = nodes;

            sort(sortedLevel.begin(), sortedLevel.end());

            //4.) Map each value to its current index
            // map
            unordered_map<int, int> indexMap;
            
            int n = nodes.size();

            for(int i = 0; i < n; i++){
                indexMap[nodes[i]] = i;
            }

            //Find Cycles
            vector<bool> visited(n, false);

            for(int i = 0; i < n; i++){

                // Already in correct position
                if(visited[i] || nodes[i] == sortedLevel[i]){
                    continue;
                }

                int cycleSize = 0;
                int j = i;

                while(!visited[j]){
                    visited[j] = true;

                    //find correct position for current value
                    j = indexMap[sortedLevel[j]];
                    cycleSize++;
                }
                //6.) A cycle of size k requires k - 1 swaps
                ans += cycleSize - 1;
            }
        }

        //finally return the output
        return ans;
    }
};