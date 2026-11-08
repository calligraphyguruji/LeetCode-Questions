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
    //Approach : Digit-by-digit addition with carry

    //Time Complexity = O(max(m,n)) =>
    /* m and n are the lengths of the two input lists.
    * We traverse both lists together, processing each node once.
    * Each iteration does constant work: addition, carry calculation, and node creation.
    * The loop runs max(m, n) times, with at most one extra iteration for a final carry.
    */

    //Space Complexity =  O(1) =>
    /* Auxiliary space: O(1) — pointers, digit variables, carry, and the dummy node use constant space.
    * Including the output: O(max(m, n)) — the result contains at most max(m, n) + 1 nodes.
    * No recursion or additional data structures are used.
    */

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //1.) Create a dummy node & curr pointer & carry = 0
        ListNode* dummy = new ListNode();

        ListNode* curr = dummy; //to build the answer linked list

        int carry = 0;

        //2.) continue while either list has nodes or carry is non-zero
        while(l1 || l2 || carry != 0){
            
            //2.a) Read each digit; use 0 if the list has ended.
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;

            //2.b) Calculate total and update carry
            int total = digit1 + digit2 + carry;
            carry = total / 10;

            //2.c) Append the result digit in answer linked list
            curr->next = new ListNode(total % 10);
            curr = curr->next;

            //2.d) Move the input pointers to next
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

        }

        //3.) Return the result head and delety dummy node
        ListNode* result = dummy->next;
        delete dummy;

        return result;//new head of result Linked list

    }
};