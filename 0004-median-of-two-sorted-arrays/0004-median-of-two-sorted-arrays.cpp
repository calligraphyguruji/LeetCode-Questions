class Solution {
public:
    //Approach : Binary Search on Partition

    //Time Complexity =  O(log(min(m, n) + 1)) =>
    /* Binary search is performed on the smaller array.
    * Each iteration reduces the search space by half → O(log(min(m, n) + 1)).
    * Finding partition elements and checking conditions → O(1) per iteration.
    */

    //Space Complexity = O(1) =>
    /* Only a few variables (m, n, low, high, i, j, L1, R1, L2, R2) are used.
    * No extra arrays or data structures are created.
    * At most one recursive call is made to swap array arguments.
    */

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //Step-1: Ensure smaller for array for binary search
        int m = nums1.size();
        int n = nums2.size();

        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }

        //2.) Binary Search on partition 
        int low = 0;
        int high = m;
        
        while(low <= high){

            int i = (low + high)/2;//(elements from nums 1 in left part)
            int j = (m + n + 1)/2 - i;// (elements from nums 2 in left part)

            //3.) Find left and right elements of both partitions
            int L1 = (i > 0) ? nums1[i-1] : INT_MIN;
            int R1 = (i < m) ? nums1[i] : INT_MAX;
            
            int L2 = (j > 0) ? nums2[j-1] : INT_MIN;
            int R2 = (j < n) ? nums2[j] : INT_MAX;

            //4.) Check for Valid Partition
            if(L1 <= R2 && L2 <= R1){

                //Case 1 : total elements are odd
                if( (m + n) % 2 != 0){
                    return max(L1, L2);
                }

                //Case 2 : total elements are even
                else{
                    return ((double)max(L1, L2) + min(R1, R2)) / 2.0;
                }
            }

            //5.) Adjust Binary Search Space
            //Case-1: Too many elements from nums1 in left part
            else if(L1 > R2){
                high = i-1;//move left
            }

            //Case-2: Too few elements from nums1 in left part
            else{
                low = i+1;//move right
            }
       
        }


        return 0.0;//It is a fallback return statement because the function’s return type is double.

    }
};