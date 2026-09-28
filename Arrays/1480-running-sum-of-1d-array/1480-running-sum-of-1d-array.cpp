class Solution {
public:
    //Approach : Prefix Sum (Running Sum)

    //Time Complexity = O(N) =>
    /* We traverse the nums array once, where N is the number of elements.
    */

    //Space Complexity = O(N) =>
    /* We use an ans vector to store N output elements.
    */

    
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans; //to store the output array
        
        int runSum = 0;

        for(int n : nums){
            runSum += n;//adds the current value to runningSum
            ans.push_back(runSum); //insert the current runningSum into ans
        }

        //finally return the output
        return ans;
    }
};