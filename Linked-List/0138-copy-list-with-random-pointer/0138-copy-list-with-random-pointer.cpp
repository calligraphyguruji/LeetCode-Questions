/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //Time Complexity = O(n) => cause visiting n elements of the Linked List
    //Space Complexity= O(n) => cause storing n elements in the unordered map
    Node* copyRandomList(Node* head) {
        //check
        if(head == NULL){
            return NULL ;
        }
        //unordered to map to store oldNode, newNode
        unordered_map<Node* ,Node*> m ;

        //make a newHead points to head->val
        Node *newHead = new Node(head->val) ;
        //make an oldTemp
        Node *oldTemp = head->next ;
        //make a newTemp =
        Node *newTemp = newHead ;
        //store head in map
        m[head] = newHead ;

        //Step 1 : Make a simple copy
        while(oldTemp != NULL){
            Node *copyNode = new Node(oldTemp->val) ;
            //store in map
            m[oldTemp] = copyNode ;
            //copy the node
            newTemp->next = copyNode ;
            
            //update both oldTemp, newTemp
            oldTemp = oldTemp->next ;
            newTemp = newTemp->next ;
        }

        //Step 2 : Random connection copy to the new LL
        //re-initialize
        oldTemp = head ;
        newTemp = newHead ;

        while(oldTemp != NULL){
            //make random connection
            newTemp->random = m[oldTemp->random] ;
            //upate oldTemp, newTemp
            oldTemp = oldTemp->next ;
            newTemp = newTemp->next ;            
        }
        return newHead ; //head of the new LL

    }
};