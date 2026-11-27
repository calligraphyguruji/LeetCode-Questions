class Solution {
public:
    //Approach : Top-Down(Recusion + Memoization)

    /*
    * Time Complexity: O(n^2 + n * budget)
    *   - Precomputation: Nested loops over `n` items check divisibility -> O(n^2)
    *   - Top-down DP: `n * budget` unique states (dp[n][budget]),
    *     each solved in O(1) work (take vs skip) -> O(n * budget)
    *   - Total: O(n^2 + n * budget) <= 10^6 + 1.5 * 10^6 operations
    *
    * Space Complexity: O(n * budget)
    *   - `copies` array: O(n)
    *   - Memoization table `dp[1001][1501]`: O(n * budget)
    *   - Recursion call stack depth: O(n)
    *   - Total: O(n * budget)
    */

    // Step 1: Memoization table dp[n][budget]
    // Stores max copies using first `n` items with `budget` remaining
    int dp[1001][1501];

    int solve(int n, int budget, int& minPrice, vector<vector<int>>& items, vector<int>& copies){

        // Step 2: Base case - no more distinct items to pick
        // Spend all remaining budget on the cheapest item (1 copy per minPrice)
        if(n == 0){
            return budget / minPrice;
        }
        
        //Step-3: Return the precomputed result
        if(dp[n][budget] != -1){ //means we have solved before
            return dp[n][budget]; //simply return that value
        }

        int price = items[n-1][1];
        
        // Step 4: Choice 1 - Buy 1st copy of item (n - 1) if affordable
        // Grants 1 purchased copy + copies[n - 1] free divisibility copies
        int take = 0;       
        if(price <= budget){
            take = 1 + copies[n-1] + solve(n-1, budget-price, minPrice, items, copies);
        }

        // Step 5: Choice 2 - Skip buying item (n - 1)
        int skip = solve(n-1, budget, minPrice, items, copies);

        // Step 6: Store and return the best of taking or skipping
        return dp[n][budget] = max(take, skip);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        int n = items.size(); 
        vector<int> copies(n, 0); //copies[i] = free items unlocked by buying item i
        int minPrice = INT_MAX;

        // Step 7: Precompute minPrice and free copy count for each item
        for(int i = 0; i < n; i++){
            minPrice = min(minPrice, items[i][1]); // Update outer minPrice
            int copy = 0;
            for(int j = 0; j < n; j++){
                // Item i gives 1 free copy of item j (j != i) if factor_i divides factor_j
                if(i != j){
                    if(items[j][0] % items[i][0] == 0){
                        copy++;
                    }
                }
            }
            copies[i] = copy;//store current free copies
        }

        // Step 8: Initialize DP table with -1 (unvisited)
        memset(dp, -1, sizeof(dp));

        // Step 9: Run top-down 0/1 Knapsack + greedy remainder
        return solve(n, budget, minPrice, items, copies);

    }
};