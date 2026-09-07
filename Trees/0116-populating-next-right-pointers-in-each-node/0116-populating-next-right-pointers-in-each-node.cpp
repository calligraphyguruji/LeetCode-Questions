/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //Time Complexity = O(n) => cause visiting n nodes of the tree.
    //Space Complexity = O(W) => W = width of the tree.
    Node* connect(Node* root) {
        //base case
        if(root == NULL || root->left == NULL){
            return root ;
        }

        queue<Node*> q ; //to store each level nodes

        //first start push with root 
        q.push(root) ;

        q.push(NULL) ;//to mark the ending of each level

        Node* prev = NULL ; //to track previous values

        while(!q.empty()){
            Node* curr = q.front() ;
            q.pop() ;

            if(curr == NULL){
                //end of current level
                prev = NULL ; //reset previous for next level

                if(q.empty() ){
                    break ;
                }

                else{
                    q.push(NULL) ;
                }

            }
            else{
                if(curr->left != NULL){
                    q.push(curr->left) ;
                }

                if(curr->right != NULL){
                    q.push(curr->right) ;
                }

                if(prev != NULL){
                    prev->next = curr ;
                }

                //update prev for next checks
                prev = curr ;

            }
 
        }
        //very important to return the root
        return root ;
    }
};