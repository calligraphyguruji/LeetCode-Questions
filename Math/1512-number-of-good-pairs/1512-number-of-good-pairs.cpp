class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();

        int countPairs = 0;//to store the output

        //traverse in nums
        for(int i = 0; i < n; i++){

            for(int j = i+1; j < n; j++){ //i < j because j = i+1
                
                if(nums[i] == nums[j]){ //check condition
                    countPairs++;
                }
            }
        }


        //return output
        return countPairs;


    }
};