class Solution {
public:
    //Approach : Sorting + Greedy Interval Scheduling 

    //Time Complexity = O(n * logn) =>
    /* Sorting intervals by end time takes O(n log n).
    * Single linear pass to count removals takes O(n).
    * Total: O(n log n) + O(n) = O(n log n).
    */

    //Space Complexity = O(logn) =>
    /* O(log n) to O(n) auxiliary stack space used internally by std::sort.
    * O(1) extra space because we only use two scalar variables (removals, prevEnd).
    */

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // 1. Sort by END time (earliest finishing interval leaves max room)
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){

            return a[1] < b[1]; //index[0] = start, index[1] = end, a[1],b[1] = end time 
        });

        // Tracks count of removed intervals needed to resolve all overlaps.
        int removals = 0;

        // Stores end time of the most recent kept interval to detect future collisions.
        int prevEnd = intervals[0][1];

        // Step 2: Compare each subsequent interval with the last kept interval's end.
        for(int i = 1; i < intervals.size(); i++){

            // Step 3: If start time is strictly less than previous end, overlap exists -> remove.
            if(intervals[i][0] < prevEnd){ //intervals[i][0] is start index time
                removals++;
            }
            // Step 4: If no overlap, keep current interval and update previous end.
            else{
                prevEnd = intervals[i][1]; //intervals[i][1] is end index time
            }
        }

        // Step 5: Return total count of removed intervals.
        return removals;

    }
};