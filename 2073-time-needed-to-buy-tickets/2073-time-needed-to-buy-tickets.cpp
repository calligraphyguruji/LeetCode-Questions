class Solution {
public:
    //Time Complexity = O(n) => traversing the tickets array(vector)
    //Space Complexity = O(n) => cause using stack
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        //Queue Based Approach
        int n = tickets.size() ;
        queue<int> q ;

        //push all elements in queue
        for(int i=0 ; i<n ; i++){
            q.push(i) ;
        }

        int time = 0 ;
        //traverse in queue & pop front & dec val by -1 each time
        while(!q.empty()){
            time++ ; //for next iteration

            int front = q.front() ; //store front value
            q.pop() ; //then pop

            tickets[front]-- ; //then dec by -1

            //base case
            if(k == front && tickets[front] == 0){
                return time ;
            }
            //if front val is not 0 then
            if(tickets[front] != 0){
                q.push(front) ; //push the front at end
            }
        }

        return time ; //very important to return the ans
    }
};