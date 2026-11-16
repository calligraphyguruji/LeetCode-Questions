class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // Step 1: Start at the last digit because addition begins
        // at the ones place
        int n = static_cast<int>(digits.size()); //handle 100 digit number to convert into int

        for(int i = n - 1; i >= 0; i--){

            // Step 2: If the current digit is less than 9,
            // adding 1 will not produce a carry.
            if(digits[i] < 9){

                digits[i] += 1;

                // Step 3: The addition is complete.
                // All digits to the left remain unchanged.
                return digits;
            }

            // Step 4: Otherwise, the current digit is 9.
            // Replace it with 0 because 9 + 1 = 10.
            digits[i] = 0;

            // Step 5: The loop moves left to add the carry of 1.
        }

        // Step 6: Reaching here means every original digit was 9.
        // All positions are now 0, but a carry of 1 remains.
        // Insert it at the beginning: [0, 0] becomes [1, 0, 0].
        digits.insert(digits.begin(), 1);

        // Step 7: Return the final digit array.
        return digits;
        
    }
};