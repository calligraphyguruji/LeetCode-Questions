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
    Node* copyRandomList(Node* head) {
        
        //base-case or edge-case
        if(head == NULL) return NULL;

        //1.) Unordered_map to store {original -> copy}
        unordered_map<Node*, Node*> map;
        map[NULL] = NULL;

        //2.) Pass-1: Create a copy of every node.
        for(Node* curr = head; curr != NULL; curr = curr->next){

            map[curr] = new Node(curr->val);
        }


        //3.) Pass-2: Connect the copied nodes.
        for(Node* curr = head; curr != NULL; curr = curr->next){
            
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
        }


        //4.) Return the new head
        return map[head];
       
    }
};