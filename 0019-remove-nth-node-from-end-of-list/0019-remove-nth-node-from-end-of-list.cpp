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
class Solution {
public:
    //Approach : Two pointers with a fixed gap, using a dummy node.

    //Time Complexity = O(size) =>
    /* size is the total number of nodes.
    * fast first moves n + 1 steps, then both pointers move together.
    * Each pointer travels through the list at most once.
    * Removing the target takes O(1) time.
    */

    //Space Complexity = O(1) =>
    /* We use one dummy node and a fixed number of pointers.
    * Extra memory stays constant regardless of the list’s size.
    */


    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        //1.) 1. Create a dummy node connected to head
        ListNode* dummy = new ListNode(0, head);

        //2.) Initialize Slow-Fast pointers
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        //move fast to (n + 1) steps
        for(int i = 0; i < n + 1; i++){
           
            fast = fast->next;
        }

        //3.) Start moving slow-fast pointers until fast == NULL
        while(fast != NULL){
            
            //both moves 1 step at a time 
            slow = slow->next;
            fast = fast->next;//because fast is already n + 1 steps ahead
        }
        
        //4.) Remove the target
        //when loop stops the target node is slow.next
        //so remove that node
        ListNode* target = slow->next;
        slow->next = target->next; //connect slow with target->next node
        delete target;//remove target node
        
        //5.) Return the new head of LL
        return dummy->next;
    }
};