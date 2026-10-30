class Solution {
public:
    //Approach : Binary Search + Two Pointers

    //Time Complexity = O(n) =>
    /* Best Case: O(log n) — Binary search reduces the search space by approximately half in each iteration.
    * Average Case: Typically O(log n) — When duplicates do not significantly interfere with binary search.
    * Worst Case: O(n) — When nums[mid] == nums[right] repeatedly, we use right--, eliminating only one element per iteration.
    */

    //Space Complexity = O(1) =>
    /* Only three variables (left, right, mid) are used.
    * No additional data structures are required.
    */
    int findMin(vector<int>& nums) {
        
        int n = nums.size();

        //Step-1: Initialize pointers
        int left = 0;
        int right = n-1;

        //Step-2: Perform binary Search : because array is sorted
        while(left <= right){
            
            //3.) calc. mid
            int mid = left + (right - left)/2;

            //4.) compare conditions
            if(nums[mid] > nums[right]){
                left = mid+1; //move to right minimum lies to right of mid
            }

            else if(nums[mid] < nums[right]){
                right = mid; //move to left min. lies at mid or left of mid
            }

            else{// nums[mid] == nums[right]
                // Cannot determine which side contains the minimum.
                right--; //safely remove duplicate
            }
        }
        
        //Finally return the answer
        return nums[left]; //because when the binary search ends, left and right point to the same index

        //OR return nums[right] => both are correct
    }
};