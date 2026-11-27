class Solution {
public:
    //Approach : Bottom-UP(0/1 Knapsack + Greedy Remainder)
    
    /*
    * Time Complexity: O(n^2 + n * budget)
    *   - Precomputation: Nested loops over `n` items check divisibility -> O(n^2)
    *   - Base case loop: Filling `dp[0][0..budget]` -> O(budget)
    *   - Bottom-Up DP loops: `n` items * `(budget + 1)` capacities,
    *     each state computed in O(1) -> O(n * budget)
    *   - Total: O(n^2 + n * budget)
    *
    * Space Complexity: O(n * budget)
    *   - `copies` array: O(n)
    *   - 2D `dp` table of size `(n + 1) x (budget + 1)`: O(n * budget)
    *   - No recursion stack (iterative)
    *   - Total: O(n * budget)  [Can be space-optimized to O(budget) using 1D DP]
    */
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        int n = items.size(); 
        vector<int> copies(n, 0); //copies[i] = free items unlocked by buying item i
        int minPrice = INT_MAX; //Track cheapest item price
        
        // Step 1: Precompute minPrice and free copy count for each item
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

        // Step 2: Initialize 2D DP table
        // dp[i][b] = max copies obtainable using first `i` items with budget `b`
        vector<vector<int>> dp(n+1, vector<int>(budget+1, 0));//filled with 0

        // Step 3: Base case (i == 0, no distinct items left)
        // Spend any remaining budget `b` on the cheapest item (1 copy per minPrice)
        for(int b = 0; b <= budget; b++){
            dp[0][b] = b / minPrice;
        }

        // Step 4: Fill DP table iteratively
        for(int i = 1; i <= n; i++){
            int price = items[i-1][1];

            for(int b = 0; b <= budget; b++){
                // Choice 1: Buy 1st copy of item (i - 1) if affordable
                // Gives 1 purchased copy + copies[i - 1] free copies
                int take = 0;
                if(price <= b){
                    take = 1 + copies[i-1] + dp[i-1][b - price];
                }
                // Choice 2: Skip item (i - 1)
                int skip = dp[i-1][b];

                dp[i][b] = max(take, skip);// Store best of taking or skipping
            }
        }

        // Step 5: Return max copies using all `n` items within `budget`
        return dp[n][budget];
    }
};