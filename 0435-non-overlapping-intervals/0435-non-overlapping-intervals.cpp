class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // 1. Sort by END time (earliest finishing interval leaves max room)
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){

            return a[1] < b[1];
        });

        // Tracks count of removed intervals needed to resolve all overlaps.
        int removals = 0;

        // Stores end time of the most recent kept interval to detect future collisions.
        int prevEnd = intervals[0][1];

        // Step 2: Compare each subsequent interval with the last kept interval's end.
        for(int i = 1; i < intervals.size(); i++){

            // Step 3: If start time is strictly less than previous end, overlap exists -> remove.
            if(intervals[i][0] < prevEnd){
                removals++;
            }
            // Step 4: If no overlap, keep current interval and update previous end.
            else{
                prevEnd = intervals[i][1];
            }
        }

        // Step 5: Return total count of removed intervals.
        return removals;

    }
};