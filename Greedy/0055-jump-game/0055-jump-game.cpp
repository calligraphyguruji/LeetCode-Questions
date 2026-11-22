class Solution {
public:
    //Approach : Greedy Approach (Max Reachable Index)

    //Time Complexity = O(n) =>
    /* Single loop traverses at most n elements from index 0 to n - 1.
    *  Each iteration performs O(1) constant-time comparisons and arithmetic operations.
    *  Early exit (maxReach >= n - 1) can terminate loop even earlier in O(1) best case.
    *  Overall worst-case time complexity is strictly linear: O(n).
    */

    //Space Complexity = O(1) =>
    /* Uses only two integer variables: 'n' and 'maxReach'.
    *  Operates entirely in-place without recursion stack or auxiliary data structures.
    *  Overall auxiliary space complexity is constant: O(1).
    */


    bool canJump(vector<int>& nums) {
        
        int n = nums.size();

        //Step 1: Initialization: Initialize integer maxReach = 0.
        int maxReach = 0;

        //Step 2: Main traversal: Iterate index i from 0 to n - 1.
        for(int i = 0; i < n; i++){

            //Step 3: Check reachability: If i > maxReach, return false
            if(i > maxReach){
                return false;
            }

            //Step 4: Update boundary: Update maxReach = max(maxReach, i + nums[i]).
            maxReach = max(maxReach, i + nums[i]);

            //Step 5: Early exit check: If maxReach >= n - 1, return true.
            if(maxReach >= n - 1){
                return true;
            }

        }

        //Step 6: Final return: If traversal finishes without trap, return true.
        return true;
    }
};