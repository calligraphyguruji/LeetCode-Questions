class Solution {
public:
    //Method : Top-Down Approach(Recursion + Memoization)

    //Time Complexity = O(n√n) =>
    // 1.)There are n possible states: helper(0) ... helper(n) → O(n).
    // 2.)For each state n, the loop checks all perfect squares:
    // =>.  1², 2², 3², ..., √n² → O(√n).

    //Space Complexity = O(n)
    // 1.) dp[10001] → O(n) space.
    // 2.) Recursion stack height = n => O(n)

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