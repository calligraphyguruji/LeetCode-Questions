class Solution {
public:
    //Approach : Sorting + Median

    //Time Complexity = O(n * logn) =>
    /* Copying the array: O(n)
    * Sorting: O(n log n)
    * Selecting the median: O(1)
    * Summing distances: O(n)
    * Total: O(n log n)
    */

    //Space Complexity = O(n) =>
    /* Copied array sorted: O(n)
    * Variables: O(1)
    * Sorting stack: O(log n)
    * Total: O(n)
    */


    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();

        //1.) Sort the array
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        //2.) Choose a median or target element
        int median = sorted[n/2]; 
        
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