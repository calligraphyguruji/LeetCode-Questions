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
    //Time Complexity = O(n) => traverse the linked list single time
    //Space Complexity = O(1) => no extra data structure used
    ListNode* middleNode(ListNode* head) {
        //initialize slow , fast with head
        ListNode *slow = head ;
        ListNode *fast = head ;

        //loop to check
        while(fast != NULL && fast->next != NULL){
            slow = slow->next ;//update slow by +1
            fast = fast->next->next ;//update fast by +2
        }
        return slow ; //because slow will point towards middle
    }
};