class Solution {
public:
    //Method-3 : Bit Manipulation (Optimal Solution)
    
    //Time Coplexity = O(1)
    //Space Complexity = O(1)
    bool isPowerOfFour(int n) {
        //base-case
        if(n <= 0) return false ; //because any power of can't be zero or negative
        
        // Check two conditions:
        // 1. n is a power of 2. => (n & (n-1)) == 0
        // 2. n - 1 is divisible by 3, which identifies powers of 4. 
        if( (n&(n-1)) == 0 && (n-1)%3 == 0){
            return true ;
        }
        else{
            return false ;
        }
    }
};