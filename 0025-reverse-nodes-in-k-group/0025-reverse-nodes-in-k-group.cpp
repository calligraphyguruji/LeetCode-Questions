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
    ListNode* getKthNode(ListNode* curr, int k){

        while(curr != NULL && k > 0){
            curr = curr->next;
            k--;
        }

        return curr;      
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Initialization
        // Create a dummy node before 'head' to uniformly handle the first group
        // and easily return the new head of the modified list.
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;
        

        while(true){
            // Step 2: Find the k-th node of the current group
            ListNode* kth = getKthNode(groupPrev, k);

            // Step 3: Important Condition & Decision
            // If fewer than k nodes remain, leave the remaining nodes as they are and stop.
            if(kth == NULL){
                break;
            }

            // Save the start of the NEXT group before breaking links
            ListNode* groupNext = kth->next;

            // Step 4: Reverse the current group of k nodes in-place
            // Key Trick: Initialize 'prev' to 'groupNext' instead of nullptr so that
            // the first node of our current group automatically connects to 'groupNext'!
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while(curr != groupNext){
                ListNode* temp = curr->next;// Save next node
                curr->next = prev;// Reverse current node's pointer
                prev = curr;//Move prev
                curr = temp;//Move curr
            }

            // Stitch the reversed group back to the previous part of the list:
            // 1. 'groupPrev->next' is still pointing to the original 1st node of this group,
            //    which is now the TAIL of the reversed group. Save it in 'oldGroupStart'.
            ListNode* oldGroupStart = groupPrev->next;

            // 2. Connect 'groupPrev' to 'kth' (which is now the new HEAD of this group).
            groupPrev->next = kth;

            // 3. Advance 'groupPrev' to the tail of this reversed group for the next iteration
            groupPrev = oldGroupStart;
        }

        // Step 5: Return the new head of the modified list
        return dummy.next;
    }
};