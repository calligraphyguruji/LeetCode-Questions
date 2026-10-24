class Solution {
public:
    int smallestEvenMultiple(int n) {
        
        if(n % 2 != 0){//if n is odd
            n *= 2;//then smallest even will be found after muliplying two
        }
        else{ //if n is even 
            n *= 1;//then number itself is smallest even multiple.
        }

        return n;
    }
};