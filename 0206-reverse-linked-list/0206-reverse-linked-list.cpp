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
    //Time Complexity = O(n) => traverse the whole Linked List single time
    //Space Complexity = O(1) => no extra data structure used
    ListNode* reverseList(ListNode* head) {
        //initialization of 3 pointers
        ListNode *prev = NULL ;
        ListNode *curr = head ;
        ListNode *next = NULL ;

        //loop to reverse the LL
        while(curr != NULL){
            next = curr->next ;
            curr->next = prev ;//make backward connection
           //update prev, curr
            prev = curr ;
            curr = next ;
        }
        return prev ; //prev is the new head of the LL
    }
};