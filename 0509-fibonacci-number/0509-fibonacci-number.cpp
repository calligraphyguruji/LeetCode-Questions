class Solution {
public:
    int fib(int n) {

        //Time Complexity = O(2^n)
        //Space Complexityn = O(n) 
        //=> because of recursion stack depth = n
        
        if(n == 0 || n == 1){
            return n ;//if n = 0 , return 0
                      //if n = 1 , return 1
        }
        
        //t(n) = t(n-1) + t(n-2)
        return fib(n-1) + fib(n-2) ;
    }
};