class Solution {
public:
    //Approach : Brute Force (Running XOR)

    //Time Complexity = O(n) =>
    /* Running a loop from 0 to n-1 => n times
    */

    //Space Complexity = O(n) =>
    /* Extra nums array used of size n
    */

    int xorOperation(int n, int start) {

        int ans = 0; //to store the output
        
        vector<int> nums(n);

        //fill n numbers from 0 to n-1
        for(int i = 0; i < n; i++){
            nums[i] = start + 2 * i; //given
            
            ans = ans ^ nums[i]; //take XOR
            
        }
        
        //finally return the output
        return ans;
        
    }
};