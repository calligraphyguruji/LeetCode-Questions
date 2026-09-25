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
    //Approach : Postorder DFS + Tree Dynamic Programming (Distance Tracking)

    //Time Complexity = O(N × D²) = O(N × 10²) = O(100N) ≈ O(N) => D ≤ 10
    /* At each node, we compare leaf distances from the left and right subtrees.
    * DFS visits every node → O(N)
    * At a node, comparing distances can take up to O(D²) because we only store distances up to distance.
    * Updating the distance lists also takes O(D).
    * Therefore:
    * Time Complexity: O(N × D²)
    * Since distance ≤ 10, this is effectively very efficient:
    * O(N × 10²) = O(100N) ≈ O(N)
    */


    //Space Complexity = O(n + d ) = O(n + 10) = O(n) => d ≤ 10
    /* We store the distances of leaf nodes at each level of the recursion.
    * Since we only keep distances up to distance, and distance ≤ 10, the list can contain at most O(10) distances.
    * The recursion stack can go up to N in the worst case (skewed tree).
    * Therefore : SC = O(N + D) = O(N + 10)
    */
    
    vector<int> dfs(TreeNode* root, int distance, int& ans){
       
        //1.) Handle leaf nodes
        if(root->left == NULL && root->right == NULL){
            return {1};
        }
        
        //2.) Use Postorder DFS
        vector<int> left;
        vector<int> right;

        if(root->left != NULL){
            left = dfs(root->left, distance, ans);
        }
        
        if(root->right != NULL){
            right = dfs(root->right, distance, ans);
        }

        //3.) Get distances from both subtrees & Count good pairs
        for(int l : left){
            for(int r : right){
                if(l + r <= distance){
                    ans++;
                }
            }
        }

        //4.) Update distances by +1 for both left & right
        vector<int> curr;

        for(int d : left){
            if(d + 1 <= distance){
                curr.push_back(d+1);
            }
        }

        for(int d : right){
            if(d + 1 <= distance){
                curr.push_back(d+1);
            }
        }

        //5.) return updated value to parent
        return curr;
    }

    int countPairs(TreeNode* root, int distance) {
        int ans = 0;

        dfs(root, distance, ans);
        
        //6.)finally return the output
        return ans;
    }
};