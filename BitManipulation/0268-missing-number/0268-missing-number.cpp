class Solution {
public:
    //Approach : Mathematical Sum Approach

    //Time Complexity = O(n) =>
    /* We calculate the expectedSum in O(1) time using a math formula. 
    * Then, we iterate through the nums array exactly once to calculate 
    * the actualSum, which takes O(n) time. Overall time is O(n).
    */

    //Space Complexity = O(1) =>
    /* We only use a few integer variables (n, expectedSum, actualSum, ans) 
    * to store our values. We do not use any extra arrays or data structures, 
    * so the memory used remains constant regardless of the input size.
    */

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