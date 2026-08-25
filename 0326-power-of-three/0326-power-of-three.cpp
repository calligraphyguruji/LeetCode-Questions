class Solution {
public:
    //Method-2 : Iterative 
    // Time Complexity = O(log₃ n) => because at every step divided into 3 parts
    // Space Complexity = O(1)
    bool isPowerOfThree(int n) {
        //base-case
        if(n <= 0) return false ; //because any power of 3 can't be zero
        
        while(n % 3 == 0){ //check if remainder is zero then
            n /= 3 ; //repeatedly divide by 3
        }


        return n == 1 ;//returns true when n == 1, because above loop stops when n = 1, if it is a power of three.
    }
};