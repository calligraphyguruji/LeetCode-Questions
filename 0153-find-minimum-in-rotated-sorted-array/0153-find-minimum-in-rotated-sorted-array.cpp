class Solution {
public:
    //Approach : Binary Search

    //Time Complexity = O(logn) =>
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

        //1.) Initialize two pointers
        int left = 0;
        int right = n-1;

        //2.) Traverse nums using two pointers
        while(left <= right){

            int mid = left + (right - left)/2;
            
            //Compare nums[mid] with nums[right]

            //Case-1: if nums[mid] is greater than nums[right]
            if(nums[mid] > nums[right]){
                left = mid+1; //minimum lies to the right of mid.
            }

            //Case-2: if nums[mid] is smaller than nums[right]
            else if(nums[mid] < nums[right]){
                right = mid; //minimum lies at mid or to its left.
            }

            //Case-3: if nums[mid] == nums[right]
            else{//Cannot determine which side contains the minimum lies
                right--; //safely remove one duplicate
            }

        }

        //finally return the minimum element
        //after while loop stops => left == right => you can either return nums[right] or nums[left]
        return nums[left];

    }
};