class Solution {
public:
   //Time Complexity = O(nlogn) for sorting + O(n) for traversing intervals = O(nlogn) 
   //Space Complexity = O(n) => cause using ans vector to store
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //Step 1 : sort in ascending order
        sort(intervals.begin(), intervals.end()) ;

        vector<vector<int>> ans ; //to store all the ans vectors

        //iterate on the intervals
        for(int i=0 ; i<intervals.size() ; i++){

            //if ans vector is empty push current
            if(ans.empty()){
                ans.push_back(intervals[i]) ;
            }
            else{
                vector<int> &v = ans.back() ; //this is prev interval
                //e.g. v = [1,5] so v[0] = 1, v[1] = ending of prev
                int y = v[1] ; //stores the ending of prev
                
                //check if current interval overlaps with prev
                if(intervals[i][0] <= v[1]){
                    v[1] = max(intervals[i][1] , y) ;
                    //ending of prev interval will change to max of current, prev
                }
                else{ //if no overlap then simply add in ans 
                    ans.push_back(intervals[i]) ; //push current
                }
            }
        }

        return ans ; //very important to return the ans vector
    }
};