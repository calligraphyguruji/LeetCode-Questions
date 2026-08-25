class Solution {
public:
    //Method : Kadane's Algorithm
    
    //Time Complexity = O(n)
    //Space complexity = O(1)
    int maxSubArray(vector<int>& nums) {
      int maxSum = INT_MIN ;
    int currSum = 0 ;
    for(int val: nums){
        currSum += val ;
        maxSum = max(maxSum,currSum);
        
        if(currSum < 0 ){
            currSum = 0 ;
        }
    }  
      return maxSum ;
   }
};