class Solution {
public:
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