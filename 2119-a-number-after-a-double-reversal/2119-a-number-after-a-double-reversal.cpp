class Solution {
public:

    //Approach : Two-Pass Digit Reversal Approach

    //Time Complexity = O(logn) =>
    /* The first while loop reverses the original number.
    * The second while loop reverses the number again.
    * A number with n digits takes O(log n) time relative to its numeric value because the number of digits is proportional to log(n).
    */

    //Space Complexity = O(1) =>
    /* We use a fixed number of integer variables: original, reversed1, reversed2, and digit.
    * No additional data structures are used to store.
    * The number of variables remains constant regardless of the input size.
    */


    bool isSameAfterReversals(int num) {
        
        int original = num; //store num to compare in last
        int reversed1 = 0;
        int reversed2 = 0;

        while(num > 0){
            int digit = num % 10;// Get last digit
            reversed1 = reversed1 * 10 + digit;// Build reversed number
            
            num /= 10;  // Remove last digit           
        }

        while(reversed1 > 0){
            int digit = reversed1 % 10;// Get last digit
            reversed2 = reversed2 * 10 + digit;// Build reversed number
            
            reversed1 /= 10;// Remove last digit
        }
        
        //check condition
        if(reversed2 == original){
            return true;
        }

        return false;
    }
};