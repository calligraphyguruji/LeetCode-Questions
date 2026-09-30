class Solution {
public:
    //Approach : Direct Indexing / Array mapping
    
    //Time Complexity = O(n) =>
    /* We traverse the nums array once using a single for loop.
    * For each element, we perform:
        nums[nums[i]]
    * Array indexing takes O(1) time.
    * Therefore: N iterations × O(1) work = O(N)
    */

    //Space Complexity = O(n) =>
    /* We create a separate ans vector to store the result.
    * If nums has N elements, ans will also contain N elements.
    * So the extra space used is:
        N elements → O(N)
    */

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