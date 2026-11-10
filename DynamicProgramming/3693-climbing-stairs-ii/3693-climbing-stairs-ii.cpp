class Solution {
public:
    //Approach : Bottom-Up DP

    //Time Complexity = O(n) =>
    /* The loop visits each of the n steps once and checks at most three jumps per step.
    */

    //Space Compelexity = O(n) =>
    /* The dp array stores (n+1) values, one for each step from 0 to n.
    */

    int climbStairs(int n, vector<int>& costs) {
        
        // dp[j] is the minimum cost to reach step j from step 0.
        vector<int> dp(n+1);
        
        // Step 1. Set dp[0] = 0 because we start at step 0 for free.
        dp[0] = 0;

        // Step 2. Visit steps j = 1 to n.
        for(int j = 1; j <= n; j++){
            // Step 3. Try jump lengths d = 1, 2, 3 if j - d >= 0.
            // Each candidate includes the previous cost and the penalty d * d.
            int best = dp[j-1] + 1;

            if(j >= 2){
                
                best = min(best, dp[j-2] + 4);
            }

            if(j >= 3){
                best = min(best, dp[j-3] + 9);
            }

            // Step 4. Add the landing cost of step j to the best candidate.
            dp[j] = best + costs[j-1];
            
        }
        
        // Step 5. Return dp[n], the cheapest cost to reach the final step.
        return dp[n];
    }
};