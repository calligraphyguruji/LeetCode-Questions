class Solution {
public:
    //Time Complexity = O(n * n * n) =>
    /* 3 Nested Loops are used for a, b, c.
    * Check every possibility of a, b, c.
    */

    //Space Complexity = O(1) =>
    /* No extra data structures are used.
    * Only few variables are used.
    */


    int countTriples(int n) {
        
        int count = 0; //to store the output
       
        //check every possiblity of a, b, c
        for(int a = 1; a <= n; a++){
            
            for(int b = 1; b <= n; b++){

                for(int c = 1; c <= n; c++){

                    if(a*a + b*b == c*c){
                        count++;
                    }
                }
            }
        }
        
        //finally return the output
        return count;
    }
};