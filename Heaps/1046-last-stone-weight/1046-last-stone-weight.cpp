class Solution {
public:
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
                pq.push(y - x);
            }

            //4.) Update the heap: Add that difference back;
            //pq.push(y);
        }
        
        //5.) Return the result
        return pq.empty() ? 0 : pq.top();
    }
};