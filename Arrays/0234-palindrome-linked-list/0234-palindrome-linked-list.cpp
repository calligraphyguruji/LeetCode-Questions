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
    //Time Complexity = O(n) => for traversing on LL
    //Space Complexity = O(n) => using stack data structure to store
    bool isPalindrome(ListNode* head) {
        stack<int> st ;
        //to find mid of the LL we will use Slow-fast pointer approach
        //move slow with 1 step, fast with 2 step
        //until fast = NULL or fast->next = NULL
        //at that time slow will point the mid
        ListNode *slow = head, *fast = head ;
        
        //step 1 : push first half element in the stack
        while(fast != NULL && fast->next != NULL){
            st.push(slow->val) ;
            slow = slow->next ; //1 step
            fast = fast->next->next ; //2 step
        }
        //if odd length LL : skip the middle node
        if(fast != NULL){
            slow = slow->next ;
        }

        //step 2 : compare second half LL with stack elements
        while(slow != NULL){
            if(slow->val != st.top()){
                return false ; //if not matched
            }
            else{
                st.pop(); //pop the top value 
                slow = slow->next ; //and move for next value
            }
        }
        
        //if in above loop all value matched
        return true ;

    }
};