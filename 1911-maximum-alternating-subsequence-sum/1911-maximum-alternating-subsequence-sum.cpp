class Solution {
public:
    //Method-1 : Top-Down Approach (Recursion + Memoization)

    //Time Complexity = O(2 * n) = O(n)
    //Space Complexity = O(n) => recursion stack = O(n) + memoization table = O(2 * n) = O(n)
    typedef long long ll ; //long long ko ll kar diya hai
    ll dp[100001][2] ; //memoization table
    int n ; //global n so that we can use n in solve without passing in parameters

    ll solve(vector<int>& nums, int idx, bool flag){
        //1.) handle base case
        if(idx >= n) return 0 ; //index out of bound then zero

        //2.) check memoization table
        if(dp[idx][flag] != -1){
            return dp[idx][flag] ;
        }

        //3.) choice-1 : skip
        ll skip = solve(nums, idx+1, flag) ;

        //4.) choice-2 : take
        ll val = nums[idx] ;

        if(flag == false){ //change the sign if odd(flag == false)
            val = -val ;
        }

        ll take = val + solve(nums, idx+1, !flag) ; //also change the sign of flag, in take

        //5.) return the max of both
        return dp[idx][flag] = max(skip, take) ;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size() ;

        memset(dp, -1, sizeof(dp)) ;//fill memoization table with -1

        return solve(nums, 0, true) ; //function call to solve
    }
};