class Solution {
public:
    //Approach : Bit Manipulation + DP

    //Time Complexity = O(n) =>
    /* Initializing the array takes O(n).
    * The loop runs n times with O(1) work per iteration.
    * Total: O(n).
    */

    //Space Complexity = O(n) =>
    /* `ans` stores n + 1 integers: O(n).
    * Auxiliary space beyond the output: O(1).
    */

    vector<int> countBits(int n) {
        
        //1.) Initialization: Create an array of length n + 1, initialized to zero. This establishes ans[0] = 0.
        vector<int> ans(n+1, 0); //to store the output
        

        //2.)Traversal: Visit each i from 1 through n.
        for(int i = 1; i <= n; i++){

            //3.)Find the smaller problem: Calculate floor(i / 2), which removes the last binary digit.
            int smaller = i >> 1;//right shift.

            // 4.) Reuse its count and add the last bit (i & 1)
            ans[i] = ans[smaller] + (i & 1);

        }

        //5.) Return the output
        return ans;
        

    }
};