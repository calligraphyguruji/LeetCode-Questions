class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        
        //1.) Initialize :
        long long MOD1 = 1e9 + 7; //10^9 + 7
        long long MOD2 = 1e9 + 9; //10^9 + 9
        long long BASE = 911382323; 
        
        int n = nums.size();

        //2.) Check whether any subarray of length len appears once.
        auto hasUniqueSubarray = [&](int len){

            // Step 2a: Find the power for the outgoing (leftmost) value.
            long long power1 = 1;
            long long power2 = 1;

            for(int i = 1; i < len; i++){

                power1 = (power1 * BASE) % MOD1;
                power2 = (power2 * BASE) % MOD2;
            }

            // Step 2b: Hash the first window.
            long long hash1 = 0;
            long long hash2 = 0;

            for(int i = 0; i < len; i++){

                hash1 = (hash1 * BASE + nums[i]) % MOD1;
                hash2 = (hash2 * BASE + nums[i]) % MOD2;
            }

            // Step 2c: Combine both hashes into one map key.
            auto makeKey = [](long long h1, long long h2){

                return (static_cast<uint64_t>(h1) << 32) |
                       static_cast<uint32_t>(h2);
            };

            unordered_map<uint64_t, int> freq; //hash table
            freq.reserve(n * 2); //size

            // Step 2d: Count the first window.
            freq[makeKey(hash1, hash2)]++;

            // Step 3: Slide across the remaining windows and count their hashes.
            for(int start = 1; start + len <= n; start++){

                int outgoing = nums[start - 1];
                int incoming = nums[start + len - 1];

                // Remove outgoing value, shift the hash, then add incoming value.
                hash1 = (hash1 - outgoing * power1 % MOD1 + MOD1) % MOD1;
                hash1 = (hash1 * BASE + incoming) % MOD1;

                hash2 = (hash2 - outgoing * power2 % MOD2 + MOD2) % MOD2;
                hash2 = (hash2 * BASE + incoming) % MOD2;

                freq[makeKey(hash1, hash2)]++;
            }

            // Step 4: Check whether any subarray hash occurred once.
            for(auto [key, count] : freq){

                if(count == 1){
                    return true;
                }
            }

            return false;

        };

        // Step 5: Binary-search the minimum valid length.
        int low = 1;
        int high = n;
        int ans = n;// The entire array occurs once.

        while(low <= high){

            int mid = low + (high - low)/2;

            if(hasUniqueSubarray(mid)){

                ans = mid;
                high = mid - 1 ;// Try a shorter length.
            }
            else{
                low = mid + 1; // Try a longer length.
            }
        }

        //5b.) Return the minimum length found
        return ans;

    }
};