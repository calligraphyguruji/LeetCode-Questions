class Solution {
public:
    //Time Complexity = O(n * n)
    //Space Complexity = O(n * n)
    int n ;
    int dp[2501][2501] ;
    int solve(vector<int>& nums, int i, int prev){
        //1.) Handle edge case
        if(i >= n) return 0 ;

        //2.) check memoization table
        if(prev != -1 && dp[i][prev] != -1){

            return dp[i][prev] ;
        }
        
        //3.) choice-1 : take the curr elem
        int take = 0 ;
        
        if(prev == -1 || nums[i] > nums[prev]){

            take = 1 + solve(nums, i+1, i) ;
        }

        //4.) choice-2 : skip the curr elem
        int skip = solve(nums, i+1, prev) ;

        //5.) store the answer
        if(prev != -1){
            dp[i][prev] = max(take, skip) ;
        }
                
        return max(take, skip) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size() ;

        memset(dp, -1, sizeof(dp)) ;

        return solve(nums, 0, -1) ;
    }
};