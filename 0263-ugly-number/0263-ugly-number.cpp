class Solution {
public:
    //Method-2 : Recursive Division
    //Time Complexity = O(logn) => division at every step.
    //Space Complexity = O(logn) => recursion stack height = logn
    bool isUgly(int n) {
        //base-case
        if(n <= 0){
            return false ;//not an ugly no. because ugly no. starts from 1
        }

        if(n == 1){
            return true ; //we know that 1 is first ugly no.
        }

        //recursively divide by 2, 3, & 5
        if(n % 2 == 0 ){
            return isUgly(n/2);
        }

        if(n % 3 == 0){
            return isUgly(n/3);
        }

        if(n % 5 == 0){
            return isUgly(n/5);
        }

        return false ; //means n has other prime factors other than 2,3,5 => not an ugly no.
    }
};