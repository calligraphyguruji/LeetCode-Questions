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
    //Approach : Hash Map + (Two Passes)
    
    //Time Complexity = O(n) =>
    /* First pass creates n copied nodes. = O(n)
    * Second pass connects their pointers. = O(n)
    * Each hash map operation takes O(1) average time.
    */

    //Space Complexity = O(n) =>
    /* The hash map stores n original-to-copy pointer mappings. = O(n)
    * The copied list also requires O(n) output space.
    */

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
            
            map[curr]->next = map[curr->next];// Point to the copy of the next node.
            map[curr]->random = map[curr->random];// Point to the copy of the random node.
        }


        //4.) Return the new head
        return map[head];
       
    }
};