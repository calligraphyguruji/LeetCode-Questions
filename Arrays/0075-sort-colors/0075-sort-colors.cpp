class Solution {
public:
    //Time Complexity = O(n)
    //Space Complexity = O(1)
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;
        int low = 0, mid = 0 , high = n-1 ;
        //DNF(Dutch National Flag Algorithm)
        //Time Complexity = O(n)
        while(mid <= high){

            if(nums[mid] == 0){
                swap(nums[low],nums[mid]) ;
                mid++ ; low++ ;
            }
            else if(nums[mid] == 1){
                mid++ ;
            }
            else { //if nums[mid] == 2 
                swap(nums[high],nums[mid]) ;
                high-- ;
            }
        }

    }
};