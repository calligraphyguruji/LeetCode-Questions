class Solution {
public:
    //Time Complexity = O( ) =>
    /* 
    */

    //Space Complexity = O( ) =>
    /* 
    */


    int countTriples(int n) {
        
        int count = 0; //to store the output
       
        for(int a = 1; a <= n; a++){

            for(int b = 1; b <= n; b++){

                int target = a*a + b*b;

                int st = 1;
                int end = n;

                while(st <= end){

                    int mid = st + (end-st)/2;

                    if(mid * mid < target){
                        st = mid+1;
                    }

                    else if(mid * mid > target){
                        end = mid-1;
                    }

                    else{ //mid * mid == target
                        count++;
                        break;
                    }
                }
            }
        }
        //finally return the output
        return count;
    }
};