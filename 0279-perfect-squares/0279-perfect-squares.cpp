class Solution {
public:
    //Method : Top-Down Approach(Recursion + Memoization)

    //Time Complexity = O(n√n)
    //Space Complexity = O(n)
    int dp[10001] ; //10^4 is max size given.
    int helper(int n){
        //base-case
        if(n == 0) return 0 ; //when number is zero no need to add any sqaure.

        //check memoization array : if we have solved before or not
        if(dp[n] != -1){ //means solved before
            return dp[n] ; //just return that value
        }

        int minCount = INT_MAX ; 

        //1, 4, 9, .... <= n
        for(int i=1 ; i*i <= n ; i++){
            int result = 1 + helper(n-i*i) ;
            minCount = min(minCount, result) ;
        }

        return dp[n] = minCount ;
    }
    int numSquares(int n) {
        
        memset(dp, -1, sizeof(dp)) ;//initialize with -1

        return helper(n) ;//func. call to helper 

    }
};