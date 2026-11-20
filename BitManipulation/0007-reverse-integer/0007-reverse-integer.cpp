class Solution {
public:
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