class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        //1.) Initialize
        int inc = 1;
        int dec = 1;
        int ans = 1;

        //2.) Traverse from the second element
        for(int i = 1; i < nums.size(); i++){
            
            //Comparison:
            //Case-1: If the current number is larger, increase inc by 1 and reset dec to 1.
            if(nums[i] > nums[i-1]){

                inc += 1;
                dec = 1;
            }

            //Case-2: If the current number is smaller, increase dec by 1 and reset inc to 1.
            else if(nums[i] < nums[i-1]){

                dec += 1;
                inc = 1;
            }

            //Case-3: If curr and previous are equal
            else{

                inc = 1;
                dec = 1;
            }

            //Step-4: Record the best length
            ans = max({ans, inc, dec});
        }

        //5.) Finally return the answer
        return ans;
    }
};