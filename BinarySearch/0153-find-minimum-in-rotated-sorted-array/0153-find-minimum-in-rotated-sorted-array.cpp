class Solution {
public:
    //Approach : Binary Search
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