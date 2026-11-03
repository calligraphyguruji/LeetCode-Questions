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