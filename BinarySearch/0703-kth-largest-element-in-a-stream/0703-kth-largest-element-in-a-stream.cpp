class KthLargest {
public:
    //Time Complexity = O(nlogk) => for n values push function = O(logk)
    //Space Complexity = O(k)
    int K ; //global K to access in add func.
    //min-heap => priority queue
    priority_queue<int, vector<int>, greater<int>> pq ;
    KthLargest(int k, vector<int>& nums) {
        K = k ;

        //push the values in pq
        for(int &val : nums){
            pq.push(val) ;

            //check size
            if(pq.size() > k)
               pq.pop() ; 
        }
    }
    
    int add(int val) {
        //push new val in pq
        pq.push(val) ;

        //check size and pop
        if(pq.size() > K){
            pq.pop() ; //minimum top element will be popped.
        }

        //return the ans that is top
        return pq.top() ;
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */