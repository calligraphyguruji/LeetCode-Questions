class Solution {
public:
    //Approach : Brute Force / Nested Loop Comparison

    //Time Complexity = O(n * n) =>
    /* We use two nested loops:
    *   for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
    */

    //Space Complexity = O(n) =>
    /* We create: vector<int> ans;
    * The answer array stores n elements.
    */

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans; //to store output

        
        for(int i = 0; i < n; i++){
            
            //reset count after every next ith element
            int count = 0; //to count how many numbers are smaller

            for(int j = 0; j < n; j++){

                if(j != i && nums[j] < nums[i]){
                    count++;
                }
            }
            ans.push_back(count);
        }
        
        //finally return the output
        return ans;
    }
};