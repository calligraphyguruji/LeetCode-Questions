class Solution {
public:
    //Approach : Brute Force + Set

    //Time Complexity = O(n * n) =>
    /* Outer loop: Runs n times.
    * Inner loop: Runs up to n times for each iteration of the outer loop.
    * Set insertion: set.insert(nums[j]) takes O(1) time on average.
    * Set size: set.size() takes O(1) time.
    */

    //Space Complexity = O(n) =>
    /* The set stores the distinct elements of the current subarray.
    * In the worst case, all n elements are different, so the set can contain up to n elements.
    */

    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();

        int ans = 0; //to store the output

        
        for(int i = 0; i < n; i++){
           
           unordered_set<int> set; //to check distinct values

           for(int j = i; j < n; j++){

                set.insert(nums[j]); //insert the current element
                int distinct = set.size(); //count distinct values
                ans += distinct * distinct; //add the square
           } 
        }


        return ans;
    }
};