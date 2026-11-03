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

    //Approach : Floyd’s Cycle Detection Algorithm || Slow-Fast Pointer || Hare and Tortoise
    
    //Time Complexity = O(n)  =>
    /* Without a cycle: fast moves two nodes at a time and reaches the end in about n/2 iterations. We ignore constant factors, so this is O(n).
    With a cycle: once both pointers enter the cycle, fast gains one node on slow each iteration. They meet within at most one cycle’s length, making the total time O(n).
    */

    //Space Complexity = O(1) =>
    /* We only use two pointers, slow and fast.
    * No extra data structures are used for storage.(like array, stack, queue, map)
    */

    bool hasCycle(ListNode *head) {
        
        // Start both pointers at the first node.
        ListNode* slow = head;
        ListNode* fast = head;

        // Keep moving while fast can safely take two steps.
        // Check fast first so we don't access next on a null pointer.
        while(fast != NULL && fast->next != NULL){

            slow = slow->next;// Slow moves forward by one node.
            fast = fast->next->next;// Fast moves forward by two nodes.

            if(slow == fast){// Compare their positions AFTER moving.
                return true;// If they meet at the same node, the list has a cycle.
            }
        }

        // Fast reached the end, so the list has no cycle.
        // This also handles an empty list.
        return false;

    }
};