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
    //Time Complexity = O(n) => cause of traversing whole linked list n elements only once.
    //Space Complexity = O(1) => no extra space used
    ListNode* swapPairs(ListNode* head) {
        //base case
        if(head == NULL || head->next == NULL){
            return head ;
        }
        //Make 3 pointers
        ListNode *first = head ;
        ListNode *second = head->next ;
        ListNode *prev = NULL ;

        while(first != NULL && second != NULL){
            //swap for 1 pair
            ListNode *third = second->next ;
            second->next = first ;
            first->next = third ;
            //optimization
            if(prev != NULL){
                prev->next = second ;
            }
            else{
                head = second ;
            }
            //updation for next iterations
            prev = first ;
            first = third ;
            //check
            if(third != NULL){
                second = third->next ;
            }
            else{
                second = NULL ;
            }
            
        }

        return head ; //very important condition to return head
    
    }
};