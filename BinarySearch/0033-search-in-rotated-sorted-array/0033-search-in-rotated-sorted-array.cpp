class Solution {
public:
    //Method : Modified Binary Search

    //Time Complexity = O(logn) =>
    /* In each step, we remove half of the remaining search area.
    * So, we find the target or finish searching in about log₂(n) steps.
    */

    //Space Complexity = O(1) =>
    /* We use only a few variables, such as left, right, and mid.
    * No extra array is needed, so memory usage stays constant.
    */

    
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();

        //1.) Initialize two pointers
        int left = 0;
        int right = n-1;

        //2.) Traverse in nums using two pointers & Apply Binary Search
        while(left <= right){

            int mid = left + (right - left)/2;//mid index
           
            //Check the target first
            if(nums[mid] == target){
                return mid;//mid index
            }
             
            //Case-1: If left half of nums is sorted
            else if(nums[left] <= nums[mid]){
                
                // Target lies within the sorted left half.
                if(nums[left] <= target && target < nums[mid]){ 
                    right = mid-1; //move right pointer towards lef
                }

                // Target can only be in the right half.
                else{
                    left = mid+1; //move left pointer towards right
                }
            }

            //Case-2: If right half of nums is sorted
            else{
                
                // Target lies within the sorted right half.
                if(target <= nums[right] && target > nums[mid]){
                    left = mid+1; //move left pointer towards right
                }

                // Target can only be in the left half.
                else{
                    right = mid-1; //move right pointer towards the left
                }

            }
        }

        //Finally if target not found
        return -1;
    }
};