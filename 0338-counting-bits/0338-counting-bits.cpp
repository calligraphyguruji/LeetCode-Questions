class Solution {
public:
    //Approach : Brute Force

    //Time Complexity = O(n * logn) =>
    /* The for loop processes every number from 0 to n: n + 1 iterations.
    * For each number, the while loop repeatedly divides it by 2.
    * A number i > 0 requires ⌊log₂ i⌋ + 1 iterations to reach zero.
    * For example: 8 → 4 → 2 → 1 → 0 takes 4 iterations.
    * Each inner iteration performs constant work, so the total time is O(n logn)
    */

    //Space Complexity = O(n) =>
    /* The result vector ans stores n + 1 integers, requiring O(n) space.
    * Variables i, num, and count use O(1) space.
    * There is no recursion or additional data structure.
    * Therefore, auxiliary space is O(1), and space including the output is O(n).
    */

    vector<int> countBits(int n) {
        
        vector<int> ans; //to store the output
        
        //1.) Make numbers from 0 to n
        for(int i = 0; i <= n; i++){

            int num = i; // Use a copy to preserve i
            int count = 0; // Reset for each number

            //Repeat until the number becomes zero.
            while(num != 0){
                //Check whether its last binary digit is 1 using remainder by 2.
                //Add that remainder to the count.
                count += num % 2;
                
                num /= 2; //Divide the number by 2, discarding the remainder.
            }
            
            ans.push_back(count);
            
        }

        //Finally return the output
        return ans;

    }
};