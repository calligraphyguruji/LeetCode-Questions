class Solution {
public:
    //Approach : Bottom-Up DP

    //Time Complexity = O(n) =>
    /* Base case check (n <= 2) takes O(1) time.
    * Single for loop runs from i = 3 to n, executing n - 2 iterations.
    * Each iteration performs constant-time O(1) addition and variable assignments.
    * Total operations grow linearly with n, giving O(n).
    */

    //Space Complexity = O(1) =>
    /* Uses only fixed scalar integer variables (prev2, prev1, current, i).
    * No DP array, hash map, or recursion call stack allocated.
    * Memory usage stays constant regardless of n, giving O(1) auxiliary space.
    */

    int climbStairs(int n) {
        
        // Step 1: Initialization
        // Handle small base cases directly: 1 step -> 1 way, 2 steps -> 2 ways
        if(n <= 2){
            return n;
        }

        // Set starting values required to compute step 3 onward
        int prev2 = 1; // ways for step 1
        int prev1 = 2; // ways for step 2

        // Step 2: Main Traversal
        // Build answers sequentially from smallest subproblems up to n
        for(int i = 3; i <= n; i++){

            // Step 3: Important Conditions and Decisions
            // Apply core recurrence: ways(i) = ways(i - 1) + ways(i - 2)
            int curr = prev1 + prev2;

            // Step 4: Update Variables
            // Shift window forward: discard older state and prepare for i + 1
            prev2 = prev1;
            prev1 = curr;
        }

        // Step 5: Return Final Answer
        // prev1 holds current value computed for step n
        return prev1;
    }
};