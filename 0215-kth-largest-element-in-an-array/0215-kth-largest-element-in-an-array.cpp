class Solution {
public:
    //Method-1 : Sorting(Not recommended)
    int findKthLargest(vector<int>& nums, int k) {
        //sort the nums into descending order
        sort(nums.begin(), nums.end(), greater<int>()) ; //here greater<int>() is comparator which is used for decreasing order

        return nums[k-1] ; //now for 0 based indexing => kth largest will be at k-1 index.
    }
};