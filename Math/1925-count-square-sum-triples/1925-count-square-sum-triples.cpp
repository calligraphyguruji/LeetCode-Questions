class Solution {
public:
    //Approach : Binary Search on Answer

    // Time Complexity = O(n² * log n) =>
    /*
    * Two nested loops run O(n^2) times.
    * For each (a, b), binary search takes O(log n).
    * Therefore, O(n² * log n).
    */

    // Space Complexity = O(1) =>
    /*
    * No extra data structures are used.
    * Only a few variables are used.
    */


    int countTriples(int n) {
        
        int count = 0; //to store the output
       
        for(int a = 1; a <= n; a++){

            for(int b = 1; b <= n; b++){

                int target = a*a + b*b;

                int st = 1;
                int end = n;
                //binary search for c
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