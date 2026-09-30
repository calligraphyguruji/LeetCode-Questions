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
    //Approach : DFS + Tree DP(Rerooting DP using DFS)

    //Time Complexity = O(n + m) => n = number of nodes in the tree,     m = number of queries
    /* We perform 3 main operations:
    1. First DFS — calcHeight() :
        Every node is visited exactly once. => TC : O(n)
    2. Second DFS — calcAns() :
        Again, every node is visited exactly once. => TC : O(n)
    3. Process queries using loop :
        We directly access ans[q], so each query takes O(1).
        For m queries: TC = O(m)
    */

    //Space Complexity = O(n) => O(3n) = O(n + n + n)
    /* We use three arrays:
    * vector<int> depth;
    * vector<int> subtreeHeight;
    * vector<int> ans;
    * Each has size n + 1.
    depth          → O(n)
    subtreeHeight  → O(n)
    ans            → O(n)

    */

    //global depth, subtreeHeight, ans
    vector<int> depth;
    vector<int> subtreeHeight;
    vector<int> ans;

    int calcHeight(TreeNode* node, int d){
        //base-case
        if(node == NULL){
            return -1;
        }

        depth[node->val] = d;

        int leftHeight = calcHeight(node->left, d+1);
        int rightHeight = calcHeight(node->right, d+1);

        subtreeHeight[node->val] = 1 + max(leftHeight, rightHeight);

        return subtreeHeight[node->val];
    }

    void calcAns(TreeNode* node, int heightAfterRemoval){
        //base-case
        if(node == NULL){
            return;
        }

        ans[node->val] = heightAfterRemoval;

        //for left child
        if(node->left){
            int siblingHeight = -1;

            if(node->right){
                siblingHeight = subtreeHeight[node->right->val];
            }
            int heightFromRight = depth[node->val] + 1 + siblingHeight;

            int newHeightLeft = max(heightFromRight, heightAfterRemoval);

            calcAns(node->left, newHeightLeft);
        }

        //for right child
        if(node->right){
            int siblingHeight = -1;

            if(node->left){
                siblingHeight = subtreeHeight[node->left->val];
            }
            
            int heightFromLeft = depth[node->val] + 1 + siblingHeight;

            int newHeightRight = max(heightFromLeft, heightAfterRemoval);

            calcAns(node->right, newHeightRight);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        //given n = 10^5
        int n = 100000;

        depth.resize(n+1);
        subtreeHeight.resize(n+1);
        ans.resize(n+1);

        //calling First DFS
        calcHeight(root, 0);

        //calling Second DFS
        calcAns(root, 0);


        //Answer queries
        vector<int> result;

        for(int q : queries){
            result.push_back(ans[q]);
        }
        
        //finally return the output
        return result;
    }
};