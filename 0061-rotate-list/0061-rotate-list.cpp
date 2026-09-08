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
    //Space Complexity = O(1) => no extra data structure
    ListNode* findNode(ListNode* temp,int k){
        int count = 1 ;
        //traverse till k = length-k value
        while(temp != NULL){
            if(count == k) return temp ;
            count++ ; 
            temp = temp->next ;
        }
        return temp ; //return the node

    }
    ListNode* rotateRight(ListNode* head, int k) {
        //edge case
        if(head == nullptr || k == 0) return head ;
        int length = 1 ;
        ListNode *tail = head ; 
       //Step 1 :find length and last node
       //traverse till last node
        while(tail->next != NULL){
            length++ ; //update by +1 everytime until tail->next = NULL
            tail = tail->next ; //also update tail till last
        }
        //edge case : if k is a multiple of length
        if(k % length == 0){
            return head ; //if k = n*length
        }
        //otherwise for larger k values
        k = k % length ; //gives smaller k values after removing the multiple of length of LL
        tail->next = head ; //connect last node with head

        //Step 2 : make the lastNode(newtail) points to NULL
        ListNode *newTail = findNode(head,length-k) ;
        head = newTail->next ;
        newTail->next = NULL ; //points to NULL


        return head ;

    }
};