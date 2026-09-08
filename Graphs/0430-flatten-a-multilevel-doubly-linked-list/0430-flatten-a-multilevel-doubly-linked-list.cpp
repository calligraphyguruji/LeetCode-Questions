/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    //Time Complexity = O(n) => cause of traversing each element in LL
    
    Node* flatten(Node* head) {
        //check if head->NULL
        if(head == NULL){
            return head ;
        }

        //make a curr node pointing to head
        Node*curr = head ;

        while(curr != NULL){
            //check if valid child
            if(curr->child != NULL){
                //Step 1 : flatten the child nodes
                Node*next = curr->next ;//next pointer to store 
                //flatten the child nodes
                curr->next = flatten(curr->child) ;
                //make reverse connection
                curr->next->prev = curr ;
                //break connection of child
                curr->child = NULL ;

                //Step 2 :find tail
                while(curr->next != NULL){
                    curr = curr->next ;
                }

                //Step 3 : attach tail with next pointer
                if(next != NULL){
                    curr->next = next ;//forward connection
                    next->prev = curr ;//reverse connection
                }

            }

            //else
            curr = curr->next ; //update curr to next
        }
        //return the head to backtrack to next
        return head ;
    }
};