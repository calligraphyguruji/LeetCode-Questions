class Solution {
public:
    //Approach : 2D Array Traversal + Row Sum

    //Time Complexity = O(m * n) =>
    /* Outer loop runs m times → one time for each customer/row.
    * Inner loop runs n times → one time for each bank account in that row.
    */

    //Space Complexity = O(1) =>
    /* We only create a few variables:
    * We don’t create another array/vector proportional to the input size
    * Therefore: SC = O(1)
    */

    int maximumWealth(vector<vector<int>>& accounts) {
        
        int m = accounts.size(); //row size
        int n = accounts[0].size(); //column size
        int maxWealth = 0;

        //traverse in the 2d matrix to find the maxWealth
        //maxWealth is the complete row sum of any row
        for(int i = 0; i < m; i++){
            
            int wealth = 0;

            for(int j = 0; j < n; j++){
                wealth += accounts[i][j];
            }

            //update maxWealth
            maxWealth = max(maxWealth, wealth);
        }

        //finally return the output
        return maxWealth;

    }
};