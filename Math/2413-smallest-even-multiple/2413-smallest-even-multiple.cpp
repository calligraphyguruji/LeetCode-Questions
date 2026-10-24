class Solution {
public:
    //Approach : Mathematical Approach (Parity Check / Odd-Even Check)

    //Time Complexity = O(1) =>
    /* No loops used for traversal.
    * Parity Check: n % 2 takes O(1) time.
    * Multiplication: n * 2 takes O(1) time.
    * Total: O(1) — Constant time complexity.
    */

    //Space Complexity = O(1) =>
    /* Extra Variables: No additional variables are created.
    * In-place Modification: We directly modify n.
    * Total: O(1) — Constant auxiliary space.
    */

    int smallestEvenMultiple(int n) {
        
        if(n % 2 != 0){//if n is odd
            n *= 2;//then smallest even will be found after muliplying two
        }
        else{ //if n is even 
            n *= 1;//then number itself is smallest even multiple.
        }

        return n;
    }
};