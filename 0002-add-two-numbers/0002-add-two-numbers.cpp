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
    //Time Complexity = O(n)=> for traversing the l1, l2
    //Space Complexity = O(n) => taking space new result LL
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0) ; //result dummy node
        ListNode *ptr = result ; //updates to result
        //two variables carry, sum
        int carry = 0 ; //initialize carry with 0

        while(l1 != nullptr || l2 != nullptr){
            int sum = 0 + carry ;

            if(l1 != nullptr){ //until l1 = nullptr , just add in sum
                sum += l1->val ; //add the val
                l1 = l1->next ; //update for next val
            }
            
            if(l2 != nullptr){
                sum += l2->val ; //add the val
                l2 = l2->next ; //update for next val
            }

            //update carry , sum
            carry = sum/10 ; //removes the last digit 
            sum = sum % 10 ; //removes the first digit

            ptr->next = new ListNode(sum) ; //insert sum val in the node
            ptr = ptr->next ; //update ptr for next nodes

        }

        //edge case when no digits left only carry then
        if(carry == 1){
            ptr->next = new ListNode(carry) ;
        }

        return result->next ; //because result is dummy node (result->next = head) = return head
    }
};