class Solution {
public:
    //Approach: Subarray Enumeration with a Running Sum

    //Time Complexity = O(n²) =>
    /* The outer loop tries all n starting indices.
    * For each start, the inner loop processes at most r elements.
    * Each iteration performs constant-time work: addition, comparison, and updating the minimum.
    * Total: O(n × r). Since r can equal n, the worst case is O(n²).
    */

    //Space Complexity = O(1) =>
    /* We use only a fixed number of variables: n, best, start, end, sum, and length.
    * No extra arrays or other data structures are created.
    * Subarrays are processed using indices; they are never copied.
    * Therefore, extra memory stays constant as the input grows.
    */


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