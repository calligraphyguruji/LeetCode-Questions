class Solution {
public:
    //Approach : Greedy + Harmonic Divisibility Count

    /*
    * Time Complexity: O(n log n)
    *   - Frequency & minPrice scan: O(n)
    *   - Harmonic sieve for divisibility counts:
    *     sum_{f=1..n} (n / f) = O(n log n)
    *   - Filtering candidates: O(n)
    *   - Sorting candidates by price: O(n log n)
    *   - Greedy purchase loop + remainder division: O(n)
    *   - Total: O(n log n)
    *
    * Space Complexity: O(n)
    *   - `freq` array of size n + 1: O(n)
    *   - `bonus` array of size n + 1: O(n)
    *   - `candidates` vector (at most n pairs): O(n)
    *   - Total: O(n)
    */

    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        
        int n = items.size();
        long long rem = budget;
        long long minPrice = LLONG_MAX; //infinity

        // Step 1: Count factor frequencies and find minPrice
        // Constraint: 1 <= factor_i <= n
        vector<int> freq(n+1, 0);

        for(int i = 0; i < n; i++){
            freq[items[i][0]]++;
            minPrice = min(minPrice, (long long)items[i][1]);
        }

        // Step 2: Precompute bonus[f] = count of j != i where f divides factor_j
        // Uses harmonic series: O(n log n) instead of O(n^2)
        vector<int> bonus(n+1, 0);

        for(int f = 0; f < n; f++){          
            if(freq[f] == 0) continue;

            int count = freq[f] - 1;// Other items with the same factor
            for(int mult = 2 * f; mult <= n; mult += f){
                count += freq[mult];
            }
            bonus[f] = count;
        }

        // Step 3: Collect items that can yield double-copies cheaper than 2 * minPrice
        // (If price >= 2 * minPrice, buying 2 single copies at minPrice is better/equal)
        vector<pair<long long, int>> candidates; // {price, max_double_copies}

        for(int i = 0; i < n; i++){
            int f = items[i][0];
            long long price = items[i][1];

            if(bonus[f] > 0 && price < 2 * minPrice){
                candidates.push_back({price, bonus[f]});
            }
        }

        // Step 4: Sort by price ascending to greedily buy cheapest double-copies first
        sort(candidates.begin(), candidates.end());

        long long ans = 0;

        for(auto& [p, maxCopies] : candidates){
            long long canBuy = min((long long)maxCopies, rem / p);
            if (canBuy == 0) break; // Remaining budget < p, cannot buy any further
            
            ans += canBuy * 2; // 1 purchased + 1 free copy each
            rem -= canBuy * p;
        }

        // Step 5: Spend any leftover budget on single copies of the cheapest item
        ans += rem / minPrice;

        return ans;
    }
};