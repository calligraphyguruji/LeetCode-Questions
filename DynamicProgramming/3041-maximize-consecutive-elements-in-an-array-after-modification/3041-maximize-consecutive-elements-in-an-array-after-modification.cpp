class Solution {
public:
    //Approach : DP + Sorting

    //Time Complexity = O(n * logn) =>
    /* Sorting : O(n * logn)
    * For Loop : O(n)
    */

    //Space Complexity = O(n) =>
    /* Sorting Stack : O(logn)
    * Unordered_Map dp : O(n)
    */

    int maxSelectedElements(vector<int>& nums) {
        
        // Step 1: Sort nums so values are processed in increasing order.
        sort(nums.begin(), nums.end());

        // Step 2: dp[v] stores the longest consecutive sequence
        // ending at value v. Unset values are treated as 0.
        unordered_map<int, int> dp;

        // Step 5: Track the largest sequence length found.
        int ans = 0;

        // Step 3: Process each value x in sorted order.
        for(int x : nums){
            // Use this element as x + 1.
            // Extend the best sequence that currently ends at x.
            dp[x+1] = dp[x] + 1;

            // Step 4: Use this element as x without increasing it.
            // Extend the best sequence that currently ends at x - 1.
            dp[x] = dp[x-1] + 1;

            // Update the largest sequence length.
            ans = max({ans, dp[x], dp[x+1]});
        }

        // Return the maximum number of elements in a consecutive sequence.
        return ans;
    }
};