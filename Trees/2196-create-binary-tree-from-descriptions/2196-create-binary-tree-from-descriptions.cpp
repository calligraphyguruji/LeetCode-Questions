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
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        //1.)
        unordered_map<int, TreeNode*> map;

        //2.)
        unordered_set<int> childSet;

        //3.) traverse every description
        for(auto& d : descriptions){ //description[i] = [parent, child, isLeft]
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            //4.)get/create the parent & child nodes using hashMap
            if(!map.count(parent)){
                map[parent] = new TreeNode(parent);
            }

            if(!map.count(child)){ 
                map[child] = new TreeNode(child);
            }

            //5.) connect the child
            if(isLeft == 1){
                map[parent]->left = map[child];
            }

            if(isLeft == 0){
                map[parent]->right = map[child];
            }

            //6.) Insert the child value in childSet
            childSet.insert(child);
            
        }

        //7.) After processing all the descriptions , root is not present in childSet => return root
        for(auto& it : map){
            if(!childSet.count(it.first)){//first is node->val
                return it.second; //second value is root node
            }
        }
        
        //8.) if no root found
        return NULL;
    }
};