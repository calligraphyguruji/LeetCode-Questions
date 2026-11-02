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
    //Approach : Iterative Reversing links

    //Time Complexity = O(n) =>
    /* Visiting each node once , so for n nodes = O(n)
    */


    //Space Complexity = O(1) =>
    /* used only three pointers, regardless of list size.
    */

    ListNode* reverseList(ListNode* head) {
        
        // No nodes have been reversed yet.
        ListNode* prev = NULL;

        // Start at the first node.
        ListNode* curr = head;

        while(curr != NULL){
            // Save the next node before changing the link.
            ListNode* next = curr->next;

            // Reverse the link: current node points backward.
            curr->next = prev;
            
            // Current node becomes the head of the reversed part.
            prev = curr;

            // Move to the saved next node.
            curr = next;
        }

        // (Return head)prev points to the new head of the reversed list.
        return prev;

    } 
};