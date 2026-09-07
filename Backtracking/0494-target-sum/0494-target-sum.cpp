class Solution {
public:
    //Time Complexity = O(2^n)
    //Space Complexity = O(n)
    int solve(vector<int>& nums, int target, int i, int currSum){
        //Base-case
        if(i == nums.size() ){
            if(currSum == target)
                return 1 ;

            else {
                return 0 ;
            }
        }

        //choose '+' sign : no. of ways choosing '+' sign
        int plus = solve(nums, target, i+1, currSum + nums[i]) ;

        //choose '-' sign : no. of ways choosing '-' sign
        int minus = solve(nums, target, i+1, currSum - nums[i]) ;


        //return the total no. of ways
        return plus + minus ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0) ;
    }
};