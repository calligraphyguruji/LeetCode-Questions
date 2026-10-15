class Solution {
public:
    //Time Complexity = O(n) => cause pushing and popping n elements in deque
   //Space Complexity = O(k) => cause store k elements at a time in deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq ; //to store viable ans to find res
        vector<int> res ; //to store answers

        //Step 1 : analyze first window
        for(int i=0 ; i<k ; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back() ; //pop smaller values than current element
            }
            //push idx of current element in the dequeue
            dq.push_back(i) ;

        }

        //Step 2 : SWM for other windows
        for(int i=k ; i<nums.size() ; i++){
            //first push idx of front element in the res
            res.push_back(nums[dq.front()]) ;

            //remove elements from dq which are not part of curr window
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front() ;
            }

            //remove the smaller values than current
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back() ;
            }

            //push current idx in dq
            dq.push_back(i) ;

        }

        //push last ans in result
        res.push_back(nums[dq.front()]) ;

        return res ; //very important to return result 

    }
};