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
    //Time Complexity = O(n+m) => where n = no. of elements in list1
    // m = no. of elements in list2
    //Space Complexity = O(n+m)
    ListNode*mergeTwoLists(ListNode* head1, ListNode* head2) {
        //base-case
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1 ;
           //if head1 == NULL then return head2 
           //if head2 == NULL then return head1
        }
        //Case 1 :
        if(head1->val <= head2->val){
            head1->next = mergeTwoLists(head1->next, head2) ;
            return head1 ;
        }
        //Case 2 :
        else{
            head2->next = mergeTwoLists(head2->next, head1) ;
            return head2 ;
        }
    }
};