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
    //Approach : Slow–Fast Pointers + Reverse Second Half + Alternate Merge.

    //Time Complexity = O(n) =>
    /* Finding the middle takes O(n).
    * Reversing the second half takes O(n).
    * Merging the halves takes O(n).
    * Total: O(n) + O(n) + O(n) = O(n).
    */

    //Space Complexity = O(1) =>
    /* Uses a fixed number of pointers.
    * Rearranges existing nodes in place without creating extra nodes or using recursion.
    */

    void reorderList(ListNode* head) {
        
        //base-case or edge-case
        if(head == NULL || head->next == NULL) return;

        //1.) Initialize slow-fast pointers
        ListNode* slow = head;
        ListNode* fast = head;

        //2.) Find the middle of LL using slow-fast pointers
        while(fast->next != NULL && fast->next->next != NULL){

            slow = slow->next; //slow moves by 1 step
            fast = fast->next->next; //fast moves by 2 steps
        }

        //3.) Split at the middle => cut the connection at middle
        ListNode* second = slow->next;//first store 
        slow->next = NULL;//then cut

        //4.) Reverse the second half
        ListNode* prev = NULL;

        while(second != NULL){
            ListNode* next = second->next;//save the next before changing link
            second->next = prev; // Point the current node backward.
            prev = second;  // Move prev to the node we just reversed.
            second = next; // Move to the next node saved earlier.
        }

        //5.) Merge the halves alternatively
        ListNode* first = head;
        second = prev;

        while(second != NULL){
            // Save both next nodes before changing any links.
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second; // Insert the current second-half node after first.
            second->next = nextFirst; // Connect it to the next first-half node.

            // Move to the next unprocessed node in each half.
            first = nextFirst;
            second = nextSecond;
        }
    }
};