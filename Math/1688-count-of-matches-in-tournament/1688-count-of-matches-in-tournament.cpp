class Solution {
public:
    //Approach : Mathematical Formula

    //Time Complexity = O(1) =>
    /* We perform only one subtraction: n - 1.
    * The number of operations remains constant regardless of the input value of n.
    */

    
    //Space Complexity = O(1) =>
    /* We don’t use any additional variables, arrays, loops, or data structures.
    * The algorithm requires constant extra space.
    */

    int numberOfMatches(int n) {
        
        int matches = 0;
               
        while(n > 1){
            
            //check no. of teams is even
            if(n % 2 == 0){

                matches += n/2;
                n = n/2;
            }

            //check no. of teams is odd
            else{
            
                matches += (n-1)/2;
                n = (n-1)/2 + 1;
            }
            
        }
        
        //finally return the number of matches
        return matches;
    }
};