class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        //1.) Initialization
        int n = nums.size();
        int minSum = INT_MAX;// +infinity

        //2.) Try every possible starting index.
        for(int start = 0; start < n; start++){

            int sum = 0;

            //3.) Extend the subarray up to length r,
            // without going beyond the array.
            for(int end = start; end < n && end - start + 1 <= r; end++){

                //4.) Add the new element to the running sum.
                sum += nums[end];
                int length = end - start + 1;

                // Step 5: Consider only allowed lengths and positive sums.
                if(length >= l && sum > 0){

                    minSum = min(minSum, sum);
                }
            }
        }

        //6.) Finally return the answer if found else -1
        return minSum == INT_MAX ? -1 : minSum;
    }
};