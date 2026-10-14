class Solution {
public:
    //Approach : Digit Extraction using Modulo and Division

    //Time Complexity = O(logn) =>
    /* n each iteration, we extract one digit using n % 10.
    * We remove the last digit using n /= 10.
    * If n has d digits, the loop runs d times.
    * The number of digits in n is approximately logn.
    */

    //Space Complexity = O(1) =>
    /* We use only a fixed number of variables: product, sum, and digit.
    * No extra arrays, vectors, or data structures are required.
    */


    int subtractProductAndSum(int n) {
        
        int product = 1; //initialized with 1 because product can't be multiplied with 0
        int sum = 0;//initialized with 0 because sum can be added

        while(n > 0){
            int digit = n % 10; //find the last digit
            product *= digit; //find product
            sum += digit; //add last digit

            n /= 10;// Remove the last digit from n because it is processed
        }
        
        //Return the final output
        return product - sum;
    }
};