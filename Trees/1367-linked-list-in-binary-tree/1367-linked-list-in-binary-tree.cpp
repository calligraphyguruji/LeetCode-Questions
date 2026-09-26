/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(TreeNode* root, ListNode* head){

        if(!head){ //head == NULL => means all node matched
            return true;
        }

        if(!root){ //root == NULL
            return false;
        }        

        //2.) if current node matches then recursively match left or right
        if(root->val == head->val){

            return dfs(root->left, head->next) ||
                   dfs(root->right, head->next);
        }

        //3.) if no current node matched
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        
        if(!root){
            return false;
        }
        

        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);

    }
};