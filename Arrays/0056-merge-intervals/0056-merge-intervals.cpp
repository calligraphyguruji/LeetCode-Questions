class Solution {
public:
    //Approach : Sorting + Linear Scan (Greedy Interval Merging)

    //Time Complexity = O(n * logn) =>
    /* Sorting : O(n * logn)
    * Linear Scan : O(n)
    * Total : O(n * logn) + O(n) = O(n * logn)
    */

    //Space Complexity = O(n) =>
    /* O(log n) to O(n) auxiliary space for std::sort recursion stack.
    * O(n) output space to store the merged ans vector.
    * 
    */


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by start time.
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans; //to store the output

        //Traverse the intervals
        for(auto& interval : intervals){

            // Step 2: If empty or no overlap, add as a new interval.
            if(ans.empty() || ans.back()[1] < interval[0]){ // index[0] = start, index[1] = end, ans.back()[1] means end of ans, interval[0] means start of interval
                ans.push_back(interval);
            }

            // Step 3: If overlapping, expand end to larger boundary.
            else{
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }

        //Finally return the output
        return ans;
    }
};