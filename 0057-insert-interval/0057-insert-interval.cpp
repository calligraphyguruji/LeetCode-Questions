class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        //1.) Initialize an empty list ans
        vector<vector<int>> ans; //to store the output

        //2.) Copy intervals before the new range.
        // While an interval ends before the new range starts, add it unchanged.
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            
            ans.push_back(intervals[i]);

            i++;
        }

        //3.) Merge every overlap
        //While an interval starts at or before the current new range’s end:
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            //Move the new range’s start to the smaller start.
            newInterval[0] = min(newInterval[0], intervals[i][0]);

            //Move its end to the larger end.
            newInterval[1] = max(newInterval[1], intervals[i][1]);

            i++;
        }

        //4.) Add the merged range
        ans.push_back(newInterval);

        //5.) Copy the remaining intervals
        //They begin after the merged range ends and can be added unchanged.
        while(i < intervals.size()){

            ans.push_back(intervals[i]);

            i++;
        }

        //Finally return the output
        return ans;
    }
};