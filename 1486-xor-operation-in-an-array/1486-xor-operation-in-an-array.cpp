class Solution {
public:
    //Approach : Brute Force (Running XOR)

    //Time Complexity = O(n) =>
    /* Running a loop from 0 to n-1 => n times
    */

    //Space Complexity = O(1) =>
    /* No extra data structures used.
    * Only few variables used.
    */

    int xorOperation(int n, int start) {

        int ans = 0; //to store the output
        
        //fill n numbers from 0 to n-1
        for(int i = 0; i < n; i++){
            int num = start + 2 * i; //given
            
            ans = ans ^ num; //take XOR
            
        }
        
        //finally return the output
        return ans;
        
    }
};