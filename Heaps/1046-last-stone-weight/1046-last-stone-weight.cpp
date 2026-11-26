class Solution {
public:
    //Approach : Max Heap(Priority Queue)

    //Time Complexity = O(n * logn) =>
    /* Adding n stones to the priority queue takes O(n log n) total.
    * Each smash removes up to two stones and may add one back. Each heap operation takes O(log n).
    * There are at most n - 1 smashes, so the total remains O(n log n)
    */

    //Space Complexity = O(n) =>
    /* The priority queue stores the stones.
    * At most n stones are in it at any time.
    */


    int lastStoneWeight(vector<int>& stones) {
        
        //Use a max heap so the two largest weights are quick to retrieve.
        //1.) Initialization: Put every stone into a max heap.
        priority_queue<int> pq;

        for(auto stone : stones){
            pq.push(stone);
        }
 
        //2.)Choose the two heaviest: Remove the heap’s largest weight twice.
        while(pq.size() > 1){
            
            int y = pq.top(); //First heaviest
            pq.pop();

            int x = pq.top(); //Second heaviest
            pq.pop();

            //3.) Apply the smash rule: If the weights differ, calculate their difference.
            if(x != y){
                pq.push(y - x); //4.) update the heap
            }
        }
        
        //5.) Return the result
        return pq.empty() ? 0 : pq.top();
    }
};