class Solution {
public:
    //Approach : Sorting + Greedy (Three-Case Analysis)

    //Time Complexity = O(n * logn) =>
    /* Sorting the array takes O(n log n).
    * Calculating the three possible scores takes O(1).
    * Finding the minimum of those three scores takes O(1).
    * Overall: O(n log n) + O(1) = O(n log n).
    */

    
    //Space Complexit = O(logn) =>
    /* The variables use O(1) extra space.
    * C++ std::sort typically uses O(log n) stack space.
    * We modify the original array without creating another array.
    * Overall auxiliary space: O(log n).
    */

    int minimizeSum(vector<int>& nums) {
        
        int n = nums.size();

        //Step 1: Sort the array.
        sort(nums.begin(), nums.end());

        //Step 2: Calculate the range after changing the two smallest.
        // The unchanged elements range from nums[2] to nums[n - 1].
        int changeTwoSmallest = nums[n-1] - nums[2];

        // Step 3: Change the smallest and the largest elements.
        // The unchanged elements range from nums[1] to nums[n - 2].
        int changeBothEnds = nums[n-2] - nums[1];

        // Step 4: Change the two largest elements.
        // The unchanged elements range from nums[0] to nums[n - 3].
        int changeTwoLargest = nums[n-3] - nums[0];

        // Step 5: Both changed elements can match an unchanged value.
        // This makes the low score 0 without increasing the range.
        // Return the smallest achievable high score.
        return min({changeTwoSmallest, changeBothEnds, changeTwoLargest});

    }
};