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
    //Approach : Iterative Two-Pointer Merge using a Dummy Node 

    //Time Complexity = O(m + n) =>
    /* n and m are the lengths of list1 and list2.
    * Each iteration compares the current nodes, attaches the smaller one, and advances one list pointer.
    * Each node is processed at most once.
    * Attaching the remaining list takes O(1), since only one pointer is updated.
    * Therefore, the worst-case time complexity is O(n + m).
    */

    //Space Complexity = O(1) =>
    /* Only one dummy node and a fixed number of pointers are used.
    * Existing nodes are reused by changing their links; no new list nodes are created for the result.
    * There is no recursion or extra data structure.
    * Therefore, auxiliary space remains O(1) regardless of the list lengths.
    */

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Temporary helper node placed before the merged list.
        // Its next pointer starts as nullptr.
        ListNode dummy;
        
        // tail points to the last node added to the merged list.
        ListNode* tail = &dummy;

        // Compare nodes while Both lists still have nodes.
        while(list1 && list2){
            
            //compare values
            if(list1->val <= list2->val){
                tail->next = list1;// Attach the smaller node from list1.

                list1 = list1->next;//move to next node
            }

            else{
                tail->next = list2; //Attach the smaller node from list2.

                list2 = list2->next;//move to next node
            }

            tail = tail->next;//Move tail to the node we just attached.
        }

        // One list has ended. Attach the remaining list.
        // If both ended, this sets tail->next to nullptr.
        tail->next = list1 ? list1 : list2;

        // Skip the helper node and return the first real node.
        return dummy.next;//new head

    }
};