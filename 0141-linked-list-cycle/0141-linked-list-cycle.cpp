/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Time Complexity = O(n) => at most taversing n nodes
    //Space Complexity = O(1) => no extra data structures used for storing nodes.

    bool hasCycle(ListNode *head) {
        //initialize slow , fast with head
        ListNode *slow = head ;
        ListNode *fast = head ;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next ; //update by +1
            fast = fast->next->next ; //update by +2
            //check condition
            if(slow == fast){
                return true ;//cycle detected
            }
        }
        //when in loop no cycle detected
        return false ;
    }
};