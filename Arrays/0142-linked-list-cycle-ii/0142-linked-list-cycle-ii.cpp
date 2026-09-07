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
    //Method to detect cycle : Floyd's Detection / Hair - Tortoise Method
    //Time Complexity = O(n) => cause traversing n nodes of the Linked List.
    //Space Complexity = O(1) => no extra data structure used for storing nodes.
    ListNode *detectCycle(ListNode *head) {
        //initialize slow , fast with head
        ListNode *slow = head ;
        ListNode *fast = head ;
        //bool variable to detect cycle
        bool isCycle = false ;

        //Step 1 : detect cycle
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ; //update by +1
            fast = fast->next->next ; //update by +2

            //check for cycle
            if(slow == fast){
                isCycle = true ;//cycle detected
                break ; //to preserve the fast value
            }
        }
        
        if(!isCycle){ //no cycle detected
            return NULL ;
        }
        //Step 2 : find the cycle start element
        //re-initialize slow
        slow = head ;
        
        while(slow != fast){
            slow = slow->next ; //update by +1
            fast = fast->next ; //update by +1
        }
        return slow ; //points towards the cycle start element
        //we can either return slow or fast 
        //both points towards the same element
    }
};