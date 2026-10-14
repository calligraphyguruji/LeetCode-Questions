class Solution {
public:
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