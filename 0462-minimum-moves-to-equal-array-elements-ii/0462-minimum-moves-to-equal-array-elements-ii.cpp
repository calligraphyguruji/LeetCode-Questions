class Solution {
public:
    //Approach : Sorting + Median

    //Time Complexity = O(n * logn) =>
    /* Sorting: O(n log n)
    * Selecting the median: O(1)
    * Loop through all elements: O(n)
    * Total: O(n log n)
    */

    //Space Complexity = O(log n) =>
    /* No copied array; sorting modifies nums.
    std::sort typically uses O(log n) stack space.
    Other variables use O(1).
    Total: O(log n)
    */


    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();

        //1.) Sort the array   
        sort(nums.begin(), nums.end());

        //2.) Choose a median or target element
        int median = nums[n/2]; 
        
        //3.) Start the move counter
        long long moves = 0;//used long long to avoid integer overflow
        
        //4.) Visit every element
        for(int elem : nums){

            moves += abs(elem - median);
        }


        //finally return the answer
        return static_cast<int>(moves); //type cast moves into int
    }
};