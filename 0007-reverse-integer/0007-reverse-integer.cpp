class Solution {
public:
    //Approach : Modulo-Division Digit Reversal (% 10 and / 10)

    // Time Complexity = O(log10(|x|)) [or O(d) where d = number of digits, which is O(1) <= 10 steps] =>
    /* 
     * 1. In each iteration of the while(x != 0) loop, we divide x by 10 (x /= 10).
     * 2. Dividing a number by 10 repeatedly until it reaches 0 takes floor(log10(|x|)) + 1 iterations,
     *    which equals the number of base-10 digits (d) in x.
     * 3. Inside the loop, every operation (%, /=, comparisons, *, +) is a constant O(1) CPU arithmetic operation.
     * 4. Because x is a 32-bit signed integer [-2,147,483,648 to 2,147,483,647], it has at most 10 digits.
     *    Therefore, the loop runs at most 10 times, making it O(log10(|x|)) in terms of input value x,
     *    or O(1) worst-case bounded constant time.
     */

    // Space Complexity = O(1) =>
    /* 
     * 1. We only allocate two 32-bit integer variables (`rev` and `last_digit`), taking 4 bytes each.
     * 2. No extra arrays, strings, or recursion call stacks are used.
     * 3. The memory used stays strictly constant regardless of the value of x, so auxiliary space is O(1).
     */

    int reverse(int x) {
        
        //1.) Initialization
        int rev = 0;

        //2.) Process digits one by one until none remain.
        // Using (x != 0) instead of (x > 0) handles both positive and negative numbers.
        while(x != 0){

            //3.)Pop the last digit from x
            int last_digit = x % 10;

            // Remove the last digit from x (e.g., 123 -> 12, or -123 -> -12).
            x /= 10;

            //4.) Check for 32-bit positive overflow BEFORE multiplying rev by 10.
            // INT_MAX is 2,147,483,647, so INT_MAX / 10 is 214,748,364.
            // - If rev > 214,748,364, then rev * 10 will definitely exceed INT_MAX.
            // - If rev == 214,748,364, then rev * 10 + digit exceeds INT_MAX if digit > 7.
            if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && last_digit > 7 )){
                return 0;
            } 

            // Step 5: Check for 32-bit negative underflow BEFORE multiplying rev by 10.
            // INT_MIN is -2,147,483,648, so INT_MIN / 10 is -214,748,364.
            // - If rev < -214,748,364, then rev * 10 will definitely drop below INT_MIN.
            // - If rev == -214,748,364, then rev * 10 + digit drops below INT_MIN if digit < -8.
            if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && last_digit < -8)){
                return 0;
            }

            //6.) Safely push the extracted digit onto the right of rev.
            rev = rev * 10 + last_digit;


        }

        //7.) Return the reversed 32-bit integer.
        return rev;

    }
};