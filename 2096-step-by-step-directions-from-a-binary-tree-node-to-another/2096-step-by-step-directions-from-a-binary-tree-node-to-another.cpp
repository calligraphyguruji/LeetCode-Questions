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
    //Approach : Root-to-Node Path(DFS) + LCA(Lowest Common Ancestor)
    
    bool dfs(TreeNode* root, int target, string& path){//finds Root-to-Node path
        //base-case
        if(root == NULL) return false;

        if(root->val == target){
            return true;
        }

        //Go to left
        path.push_back('L');
        if( dfs(root->left, target, path) ){
            return true;
        }
        //in backtracking remove curr char. from path
        path.pop_back();

        //Go to right
        path.push_back('R');
        if( dfs(root->right, target, path) ){
            return true;
        }
        //in backtracking remove curr char. from path
        path.pop_back();


        return false; //if no path exists

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string ans;//to store the output

        string startPath, destPath;
         
        //Step-1 : Find path from root to startValue
        dfs(root, startValue, startPath);

        //Step-2 : Find path from root to destValue
        dfs(root, destValue, destPath);

        //Step-3 : Find common path 
        int i = 0; //i = length of common path
        while(i < startPath.size() && i < destPath.size() && startPath[i] == destPath[i]){
            i++;
        }

        //Step-4 : Move from start to LCA(all nodes will give 'U')
        for(int j=i; j<startPath.size(); j++){
            ans += 'U';
        }

        //Step-5 : Move from LCA to dest(all nodes will either 'L' or 'R')
        for(int j=i; j<destPath.size(); j++){
            ans += destPath[j];
        }

        //Step-6 : return the combined string
        return ans;
    }
};