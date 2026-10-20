class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans(2); //size 2 is fixed for two integer indices = [index1, index2]
        
        //Initialize two pointers
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while(start < end){

            //calc. currSum
            int currSum = nums[start] + nums[end];

            //Case-1: when target is greater
            if(currSum < target){
                start++;//move to right
            }

            //Case-2: when target is lesser
            else if(currSum > target){
                end--; //move to left
            }

            //Case-3 : if currSum == target
            else{
                ans[0] = start+1; //store index1 in ans
                ans[1] = end+1; //store index2 in ans
                break;
            }
        }


        //finally return the output
        return ans;

    }
};