class Solution {
public:
    //Approach : Bottom-Up Dp(Space-Optimised)
    
    // Time Complexity = O(n) =>
    /* Single for loop runs from i = 2 to n, executing n - 1 iterations.
     * Each iteration performs constant-time O(1) additions, min, and assignments.
     * Total operations grow linearly with n, giving O(n).
     */
    // Space Complexity = O(1) =>
    /* Uses only fixed scalar integer variables (n, prev2, prev1, curr, i).
     * No DP array, hash map, or recursion call stack allocated.
     * Memory usage stays constant regardless of n, giving O(1) auxiliary space.
     */


    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();

        // Step 1: Initialization
        // Starting at index 0 or index 1 costs 0 before jumping
        int prev2 = 0; // min cost to reach step 0 (prev2 = i - 2)
        int prev1 = 0; // min cost to reach step 1 (prev1 = i - 1)

        // Step 2: Main Traversal
        // Compute minimum cost to reach every step from 2 up to top (index n)
        for(int i = 2; i <= n; i++){
            // Step 3: Important Conditions and Decisions
            // Either jump 1 step from (i - 1) or 2 steps from (i - 2); pick cheaper path
            int jumpOne = prev1 + cost[i-1];
            int jumpTwo = prev2 + cost[i-2];

            int curr = min(jumpOne, jumpTwo);

            // Step 4: Update Variables
            // Shift window forward: discard older state and prepare for i + 1
            prev2 = prev1;
            prev1 = curr;
        }

        // Step 5: Return Final Answer
        // prev1 holds minimum cost to reach top (index n)
        return prev1;

    }
};