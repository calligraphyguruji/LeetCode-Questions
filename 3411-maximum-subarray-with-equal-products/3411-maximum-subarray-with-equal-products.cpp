class Solution {
public:
    //Approach : Brute Force with Incremental GCD and LCM Updates

    // Time Complexity: O(n^2 * log M)
    /* There are O(n^2) subarrays.
    * Each subarray extension updates the GCD/LCM in O(log M),
    * where M is the maximum value in nums.
    */

    // Space Complexity: O(1)
    /* Uses only a few variables, regardless of input size.
    */


    int maxLength(vector<int>& nums) {
        
        int n = nums.size();

        int maxLen = 0;

        //1.)Choose a start index i. Initialize product, GCD, and LCM from that element.
        for(int i = 0; i < n; i++){

            long long prod = 1;
            long long g = 0;
            long long l = 1;
            //2.)Extend the end index j. Add the next number to the current subarray.
            for(int j = i; j < n; j++){
                
                prod *= nums[j]; //Update the product
                g = gcd(g, nums[j]); //Update the GCD
                l = lcm(l, nums[j]); //Update the LCM

                //3.) Check the condition. If product == GCD × LCM, update the longest length found.
                if(prod == 1LL * g * l){
                    maxLen = max(maxLen, j - i + 1);
                }

                //Bounded LCM Guard :
                //Elements are <= 10
                //max(lcm) = lcm(1....10) = 2520
                //max possible lcm * gcd <= 2520 * 10 <= 25200
                //if running product > 25200 break the loop to avoid overflow
                if(prod > 25200){ //To avoid overflow
                    break;
                }

            }
        }

        //4.) Finally return the output
        return maxLen;
    }
};