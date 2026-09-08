class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: sort
        sort(nums.begin(), nums.end());

        // Step 2: choose i, j
        for(int i = 0; i < n; i++){
            // skip duplicate i
            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i + 1; j < n; j++){
                // skip duplicate j
                if(j > i + 1 && nums[j] == nums[j-1]) continue;

                int p = j + 1, q = n - 1;

                while(p < q){
                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if(sum < tar){
                        p++;
                    }
                    else if(sum > tar){
                        q--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                        p++;
                        q--;

                        // skip duplicate p
                        while(p < q && nums[p] == nums[p-1]) p++;

                        // skip duplicate q
                        while(p < q && nums[q] == nums[q+1]) q--;
                    }
                }
            }
        }
        return ans;
    }
};