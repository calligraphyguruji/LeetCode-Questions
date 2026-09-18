/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* targetNode = NULL;
    unordered_map<TreeNode*, TreeNode* > par;
    
    //Step-1:
    void dfs(TreeNode* node, TreeNode* parent, int target){
        //base-case
        if(node == NULL) return;
        
        par[node] = parent;//store parents in map

        //Step-2: 
        if(node->val == target){
            targetNode = node;
        }

        dfs(node->left, node, target);
        dfs(node->right, node, target);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Build parent map and find targetNode
        dfs(root, NULL, target->val);
        
        vector<int > ans;//to store the output

        queue<TreeNode* > q;
        unordered_set<TreeNode* > visited;

        //Step-3: start with BFS with targetNode
        q.push(targetNode);
        visited.insert(targetNode);

        int distance = 0;

        while(!q.empty()){
            int N = q.size();//size of current level

            while(N--){//process all nodes of current level

                TreeNode* node = q.front();
                q.pop();

                //check if reached (distance == k) then add to ans
                if(distance == k){
                    ans.push_back(node->val);
                    continue;
                }
                
                //explore neighbors in 3 directions
                //left
                if(node->left && visited.count(node->left) == false){
                    q.push(node->left);
                    visited.insert(node->left);
                }

                //right
                if(node->right && visited.count(node->right) == false){
                    q.push(node->right);
                    visited.insert(node->right);
                }

                //parent
                if(par[node] && visited.count(par[node]) == false){
                    q.push(par[node]);
                    visited.insert(par[node]);
                }
            }
            //after current level
            if(distance == k){
                break;
            }
            distance++;
        }

        //finally return the output array
        return ans;
       
    }
};