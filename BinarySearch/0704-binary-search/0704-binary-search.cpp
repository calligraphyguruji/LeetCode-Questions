class Solution {
public:
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