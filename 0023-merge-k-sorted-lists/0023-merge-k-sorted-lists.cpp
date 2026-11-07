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
    //Approach : Min-Heap (Priority Queue) for K-Way Merge

    //Time Complexity = O(k + N log(h + 1)) =>
    /* Checking all k list heads takes O(k) time.
    * Each of the N nodes is pushed into the heap once and popped once.
    * The heap holds at most h nodes, one from each non-empty list. Each push or pop takes up to O(log(h + 1)) time.
    */

    //Space Complexity = O(h + 1) =>
    /* The heap stores at most h node pointers.
    * The dummy node and local pointers use O(1) space. The merged list reuses the original nodes.
    */


    ListNode* mergeKLists(vector<ListNode*>& lists) {

        auto compare = [&](const ListNode* a, const ListNode* b){
            
            return a->val > b->val;
        };

        //Declare minHeap to store heads of non-empty LL
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare) > pq(compare);

        //1.) Push the heads of non-empty LL in pq
        for(auto head : lists){
            
            if(head != NULL){
                pq.push(head);
            }
        }

        //2.) Create a dummy node
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        //3.) Take the smallest first
        while(!pq.empty()){

            auto node = pq.top();
            pq.pop();

            //save its next
            ListNode* next = node->next;

            //4.) Attach the node and move the tail
            tail->next = node;
            tail = node;//move tail to node

            //5.) Push the successor if it exists
            if(next != NULL){
                pq.push(next);
            }
     
        }

        //6.) Return the new head
        return dummy->next;
    }
};