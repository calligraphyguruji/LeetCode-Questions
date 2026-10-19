class Solution {
public:
    //Approach : Prefix & Suffix Product (Two Passes)

    //Time Complexity = O(n) =>
    /* First loop (Prefix Product): O(n) — Traverses the array from left to right.
    * Second loop (Suffix Product): O(n) — Traverses the array from right to left.
    * Total: O(n) + O(n) = O(2n) = O(n).
    */

    //Space Complexity = O(1) [excluding output array]
    

    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans(n, -1); //to store the output
        
        //Step-1: Calculate prefix products (Left to Right)
        int prefix = 1;

        for(int i = 0; i < n; i++){

            ans[i] = prefix;
            prefix *= nums[i];
        }

        //Step-2: Calculate suffix products (Right to Left)
        int suffix = 1;

        for(int i = n-1; i >= 0; i--){
            
            ans[i] *= suffix;
            suffix *= nums[i];

        }
        
        //finally return the output
        return ans;
    }
};