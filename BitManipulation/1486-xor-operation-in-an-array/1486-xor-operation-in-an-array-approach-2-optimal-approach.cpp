class Solution {
public:
    //Approach-2 : Optimal Approach (XOR Pattern / Mathematical Optimization)
  
    //Time Complexity = O(1) =>
    /* No extra loops are used.
    * Only switch cases.
    */

    //Space Complexity = O(1) =>
    /* No extra data structures used.
    * Only few variables used.
    */

    int xorOperation(int n, int start) {

        int ans = 0; //to store the output
        
        int s = start/2;

        // XOR of numbers from s to s+n-1
        int x = s + n-1;
        
        //function
        auto XOR = [](int num){
            switch(num % 4){ 
                case 0 : return num; // Case 0: num % 4 == 0 → XOR = num
                case 1 : return 1; // Case 1: num % 4 == 1 → XOR = 1
                case 2 : return num + 1; // Case 2: num % 4 == 2 → XOR = num + 1
                default : return 0; // Case 3: num % 4 == 3 → XOR = 0
            }
        };

        ans = XOR(s-1) ^ XOR(x);

        // If start is odd, adjust the result
        if(start % 2 != 0){
            ans = ans * 2 + (n % 2);
        }
        else{
            ans = ans * 2;
        }
        
        //finally return the output
        return ans;
        
    }
};