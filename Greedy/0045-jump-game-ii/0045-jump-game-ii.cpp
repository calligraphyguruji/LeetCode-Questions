class Solution {
public:
    //Approach : Greedy Range Expansion

    //Time Complexity = O(n) =>
    /* Traverses at most n - 1 elements in single loop.
    *  Constant O(1) operations per iteration.
    */

    //Space Complexity = O(1) =>
    /* Uses only primitive integer counters.
    * No extra arrays or recursion stack.
    */
    
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        // Step 1: Base case check.
        // Already at destination if array has 1 or fewer elements.
        if(n <= 1){
            return 0;
        }

        // Step 2: Initialize tracking variables.      
        int jumps = 0;// jumps: Count of jumps made so far.
        int currentEnd = 0;// currentEnd: Outer boundary reachable with current number of jumps.
        int farthest = 0;// farthest: Furthest index reachable with next jump.

        // Step 3: Traverse array up to n - 2.
        // Stop at n - 2 because reaching last index does not trigger another jump.
        for(int i = 0; i < n - 1;  i++){

            // Step 4: Expand search window.
            // Continuously track furthest index reachable from any visited point.
            farthest = max(farthest, i + nums[i]);

            // Step 5: Check current jump boundary.
            // If i reaches boundary of current jump, must take next jump.
            if(i == currentEnd){
                
                jumps++;
                
                currentEnd = farthest;

                if(currentEnd > n - 1){
                    break;
                }

            }
        }

        // Step 6: Return minimum jump count.
        return jumps;

    }
};