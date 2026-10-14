class Solution {
public:
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