class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
        // Minimum costs to reach n from i + 1, i + 2, and i + 3.
        int next1 = 0, next2 = 0, next3 = 0;

        for(int i = n - 1; i >= 0; i--){
            // A one-step jump is always valid here.
            int best = costs[i] + 1 + next1;

            if(i + 2 <= n){
                best = min(best, costs[i + 1] + 4 + next2);
            }

            if(i + 3 <= n){
                best = min(best, costs[i + 2] + 9 + next3);
            }

            // Shift the saved costs before moving one step left.
            next3 = next2;
            next2 = next1;
            next1 = best;
        }

        // After processing step 0, next1 holds the minimum cost from step 0 to step n.
        return next1;
    }
};