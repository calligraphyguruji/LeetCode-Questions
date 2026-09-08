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
    //Space Complexity = O(H) => H = recursion stack height = Height of the tree.
    // H = logn for balanced tree, H = n for skewed tree.
    int maxSum ; //global var to store the ans

    int solution(TreeNode* root){
        //for empty tree
        if(root == NULL) return 0 ;

        //calculate left sum
        int left = solution(root->left) ;
        //calculate right sum
        int right = solution(root->right) ;

        //Case 1 : if both right and left provide good sum
        int both_good_sum = left + right + (root->val) ;

        //Case 2 : if only one left or right is good sum
        int only_one_good = max(left,right) + (root->val) ;

        //Case 3 : if both right & left are -ve sum
        int only_root = root->val ;

        maxSum = max(maxSum,  max({both_good_sum, only_one_good, only_root}) ); //very important how to write max of this.

        return max(only_one_good, only_root) ; //return case 2 or case 3 to explore more.
    }
    int maxPathSum(TreeNode* root) {

       maxSum = INT_MIN ; // -♾️ infinity

       solution(root) ;

       return maxSum ; //very important to return the ans.
        
    }
};