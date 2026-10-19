class Solution {
public:
    //Approach : Bit Manipulation (XOR + AND + Left Shift)

    //Time Complexity = O(1) =>
    /* Each iteration performs constant-time bitwise operations.
    * The carry can propagate through at most 32 bit positions.
    * Therefore, the maximum number of iterations is bounded by 32.
    */

    //Space Complexity = O(1) =>
    /* Only one additional variable, carry, is used.
    * No extra arrays or data structures are required.
    * Total SC = O(1).
    */

    int getSum(int a, int b) {
        
        //if b == 0 stop
        while(b != 0){

            //calc. carry
            unsigned int carry = (unsigned int)(a & b) << 1; 

            //calc. sum and assign to a
            a = a ^ b;

            //update b with carry
            b = static_cast<int>(carry);//type-cast : convert carry into integer
        }

        //finally return the sum
        return a;
    }
};