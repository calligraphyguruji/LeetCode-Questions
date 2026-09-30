class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        //Just go through the question
        //read 2-3 times and then
        //you will get to know that why this an easy problem.
        //just copy the description

        int n = nums.size();

        vector<int> ans; //to store the output

        for(int i=0; i<n; i++){
            ans.push_back(nums[nums[i]]);
        }

        return ans;
    }
};