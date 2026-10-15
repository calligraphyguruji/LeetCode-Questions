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
    //Time Complexity = O(n) => very much obvious traverse the whole LL of n elements
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head ;
        int count = 0 ;
        //Step 1 : check if k nodes exist
        while(count < k){
            if(temp == NULL) return head ;//if doesn't exist

            temp = temp->next ;
            count++ ;//important to update to end the loop after k
        }
        //Step 2 : recursively call of the LL
        ListNode *prevNode = reverseKGroup(temp,k) ;

        //Step 3 : reverse the current group
        temp = head ; count = 0 ;

        while(count < k){
            ListNode *next = temp->next ;
            temp->next = prevNode ;

            prevNode = temp ;
            temp = next ;

            count++ ;//important to update to end the loop after k
        }

        return prevNode ; //return newHead 

        
    }
};