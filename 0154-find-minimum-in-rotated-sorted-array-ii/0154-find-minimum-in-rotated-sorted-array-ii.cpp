class Solution {
public:
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