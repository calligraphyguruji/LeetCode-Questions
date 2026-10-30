class Solution {
public:
    //Approach : Iterative Binary Search

    //Time Complexity = O(logn) =>
    /* Binary Search reduces the search space by half in every iteration.
    * Example: n = 16 => 16 → 8 → 4 → 2 → 1
    * After 1 iteration → n/2 elements
    * After 2 iterations → n/4 elements
    * After k iterations → n/2ᵏ elements
    * when only 1 element remains : n / 2^k = 1 => n = 2^k => k = logn base-2
    */

    //Space Complexity = O(1) =>
    /* Only a few variables (left, right, mid) are used.
    * No extra data strucutres required to store.
    */

    int search(vector<int>& nums, int target) {
    
        int n = nums.size();

        //Step-1: Initialize two pointers
        int start = 0;
        int end = n-1;

        //Step-2: Traverse nums using two pointers
        while(start <= end){
            //In this we have to return only the index not value at nums[index]
            int mid = start + (end - start)/2; //mid is index

            //Case-1: when target is greater than curr nums[mid]
            if(nums[mid] < target){
                start = mid+1;//move to right for greater elements
            }

            //Case-2: when target is smaller than curr nums[mid]
            else if(nums[mid] > target){
                end = mid-1;//move to left for smaller elements
            }

            //Case-3: if target is equals to nums[mid]
            else{
                return mid;//return the mid index
            }
        }
        
        //if target is not found in the nums
        return -1;
    }
};