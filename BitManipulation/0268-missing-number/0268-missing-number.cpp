class Solution {
public:
    int missingNumber(vector<int>& nums) {
         
        //1.) Initialization  
        int n = nums.size();

        //2.) Calculate Expected Sum : n * (n + 1) / 2
        int expectedSum = n *(n + 1)/2;

        //3.) Calculate Actual Sum 
        //Create a variable actualSum = 0. 
        //Loop through every element in the given nums array 
        int actualSum = 0;
        for(int num : nums){

            actualSum += num;
        }

        //4.) Find the Difference
        //Subtract actualSum from expectedSum.
        int ans = expectedSum - actualSum;

        //5.) Return the final answer
        return ans;
    }
};