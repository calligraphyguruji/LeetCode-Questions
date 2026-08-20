class Solution {
public:
    bool isUgly(int n) {
        //base-case
        if(n <= 0){
            return false ;//not an ugly no. because ugly no. starts from 1
        }

        //check iteratively by division
        while(n % 2 == 0 ){
            n /= 2 ;
        }

        while(n % 3 == 0){
            n /= 3 ;
        }

        while(n % 5 == 0){
            n /= 5 ;
        }

        return n == 1 ; //return true when n = 1 means after dividing we got quotient of n = 1 => means ugly no.
    }
};