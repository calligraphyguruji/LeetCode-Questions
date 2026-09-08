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
    //Time Complexity = O(n) => traversing the LL
    //Space Complexity = O(1) => no extra data structure used
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //base-case
        if( !head || left == right) return head ;

        //make a dummy node that will point towards head
        ListNode dummy(0) ;
        dummy.next = head ;

        ListNode *leftPrev = &dummy ;//leftPrev is dummy node 

        //step 1 : move the leftPrev till left-1
        for(int i=1 ; i<left ; i++){
            leftPrev = leftPrev->next ;
        }

        //step 2 : reverse the sublist
        ListNode *currNode = leftPrev->next ; //currNode = left
        ListNode *prevNode = nullptr ; //prevNode = NULL
        
        for(int i=0 ; i<= right-left ; i++){
            ListNode *nextNode = currNode->next ;
            currNode->next = prevNode ;
            prevNode = currNode ;
            currNode = nextNode ;
        }
        //step 3 : reconnect LL to fix (prevNode = nullptr)
        ListNode *sublistHead = leftPrev->next ; //points towards left
        leftPrev->next = prevNode ;
        sublistHead->next = currNode ;

       return dummy.next ; //this will point towards head
    }
};