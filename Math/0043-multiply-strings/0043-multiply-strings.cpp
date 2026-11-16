class Solution {
public:
    //Approach:

    //Time Complexity = O(m * n) =>
    /* Let m = num1.length() and n = num2.length().
    * The outer loop runs m times.
    * For each outer iteration, the inner loop runs n times.
    * Each pair performs constant-time arithmetic, so multiplication takes O(m × n).
    * Initializing the array, skipping leading zeros, and building the string take O(m + n).
    * Total: O(m × n + m + n) = O(m × n).
    */

    //Space Complexity = O(m + n) =>
    /* The ans array stores m + n integers: O(m + n) auxiliary space.
    * The returned string holds at most m + n characters: O(m + n) output space.
    * Other variables use O(1) space.
    * Total space remains O(m + n).
    */


    string multiply(string num1, string num2) {
       
       // Step 1: Handle zero. 
       //if either num1 or num2 is zero then output will be zero
       if(num1 == "0" || num2 == "0"){

            return "0";
       }

       //Step 2: Initialize the result.
       //Create an ans array of m + n zeros.
       int m = num1.length();
       int n = num2.length();
       vector<int> ans(m + n, 0);//It stores the multiplication columns.

       //Step 3: Traverse digit pairs.
       //Move i from m − 1 to 0. For each i, move j from n − 1 to 0.
       for(int i = m - 1; i >= 0; i--){

        for(int j = n - 1; j >= 0; j--){
            //Step 4: Update the digit and carry.
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            int total = digit1 * digit2 + ans[i + j + 1];//Include contributions already in this column.

            // Store the digit and add the carry to the left.
            ans[i + j + 1] = total % 10; //digit
            ans[i + j] += total / 10; //carry

        }
       }

       // Step 5: Skip leading zeros.
       int start = 0;

       while(start < m + n && ans[start] == 0){

            start++;
       }

       // Convert the result digits into a string.
       string result;
       for(int k = start; k < m + n; k++){

            result += char(ans[k] + '0');
       }

       return result;//Finally 

    }
};