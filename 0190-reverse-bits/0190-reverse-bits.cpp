class Solution {
public:
    //Approach : Bit Manipulation — Bit-by-Bit Reversal

    //Time Complexity = O(32) = O(1) =>
    /* The loop runs exactly 32 times, regardless of the value of n.
    * Each iteration uses constant-time operations: AND, OR, shifts, and assignment.
    * Total work is O(32), which simplifies to O(1) because 32 is fixed.
    * For a variable input width of b bits, it would be O(b).
    */

    //Space Complexity = O(1) =>
    /* We use only a fixed number of variables: answer, bit, and i.
    * No extra arrays, strings, or recursion are used.
    * Extra memory stays constant, so auxiliary space is O(1).
    */

    int reverseBits(int n) {
        
        int ans = 0;

        // Process all 32 bits, including leading zeros.
        for(int i = 0; i < 32; i++){

            int bit = n & 1; // Extract the last bit.

            ans = (ans << 1) | bit; // Make room and append it.

            n >>= 1; // Remove the processed bit.

        }

        return ans;
    }
};