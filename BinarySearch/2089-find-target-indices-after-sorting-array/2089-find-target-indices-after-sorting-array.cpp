class Solution {
public:
    //Approach :  Sorting + Binary Search (Lower Bound) + Linear Traversal

    //Time Complexity = O(n * logn) =>
    /* Sorting: O(n log n) to sort the array.
    * Binary Search: O(log n) to find the first occurrence of the target.
    * Linear Traversal: O(k) to collect all target indices, where k ≤ n.
    * Overall: O(n log n).
    */

    //Space Complexity = O(logn) =>
    /* Sorting: O(log n) auxiliary space for the recursion stack of typical C++ std::sort implementations.
    * Binary Search: O(1) extra space.
    * Output Vector: O(k) to store target indices.
    * Overall: O(log n) auxiliary space, excluding the output vector.
    */


    vector<int> targetIndices(vector<int>& nums, int target) {
        
        int n = nums.size();

        vector<int> indices;//to store the output

        //First sort the array
        sort(nums.begin(), nums.end());

        //Use Binary Search to find the target indices
        int st = 0;
        int end = n-1;
        int first = -1;

        while(st <= end){
            int mid = st + (end-st)/2;

            //curr value if less than target
            if(nums[mid] < target){
                st = mid+1;
            }

            else if(nums[mid] > target){
                end = mid-1;
            }

            else{//if nums[i] == target
                first = mid; //one target index found

                end = mid-1;// Continue searching towards the left
            }
        }

        // Collect all target indices
        if(first != -1){
            
            for(int i = first; i < n && nums[i] == target; i++){
                indices.push_back(i);
            }
        }
        
        
        //finally return the output
        return indices;
        
    }
};