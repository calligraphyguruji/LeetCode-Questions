class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        //1.) Intialize deque and ans array
        deque<int> dq; //to store indices of max. in decreasing order

        vector<int> ans;

        //2.) Traverse the array from left to right
        int left = 0;
        

        for(int right = 0; right < nums.size(); right++){
            
            //3.) Remove the smaller indices from back
            while(!dq.empty() && nums[dq.back()] < nums[right]){
                dq.pop_back();
            }
            
            //4.)Add current index into deque at back
            dq.push_back(right);

            //5.) Remove indices from front if
            while(!dq.empty() && dq.front() < left){
                dq.pop_front();
            }

            //6.) When window size becomes k
            if(right - left + 1 == k){

                //push front index into ans
                ans.push_back(nums[dq.front()]);

                //Slide the window one position to right
                left++; //move left pointer
            }

        }
        
        //finally return the answer
        return ans;

    }
};