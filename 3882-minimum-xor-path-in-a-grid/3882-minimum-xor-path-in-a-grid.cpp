class Solution {
public:

    //Approach : DP + XOR tracking

    //Time Complexity = O(m * n * 1024) =>
    /* 1. Grid Traversal: Two nested loops traverse all m × n cells → O(m × n).
    2. XOR State Traversal: For each cell, we check all 1024 possible XOR values → O(1024).
    3. DP Transitions: Checking the top and left cells and updating the DP state takes O(1) time.
    4. Finding Minimum XOR: We check at most 1024 XOR values at the destination → O(1024).
    */

    //Space Complexity = O(m * n * 1024) =>
    /* 1. 3D DP Array: dp[m][n][1024] stores 1024 Boolean XOR states for each cell → O(m × n × 1024).
    2. Variables: m, n, i, j, x, and newXor require O(1) extra space.
    3. No Recursion: No recursion stack is required → O(1).
    */


    //Constraints : 0 <= grid[i][j] <= 1023​ (given XOR value range)
    int minCost(vector<vector<int>>& grid) {
        
        //Step-1: Initialize DP
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(1024, false)));//3d dp array : dp[i][j][x] (x is XOR value at i, j)
        
        //Step-2: Base-case
        dp[0][0][grid[0][0]] = true;//dp[i][j][x] (x is XOR Value)


        //Step-3: Traverse the grid
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                //Skip starting cell because already processed
                if(i == 0 && j == 0){
                    continue;
                }

                //Step-4: Check top & left cells
                for(int x = 0; x < 1024; x++){
                    
                    int newXOR = x ^ grid[i][j];
             
                    if(i > 0 && dp[i-1][j][x] == true){//top cell
                        
                        dp[i][j][newXOR] = true;
                    }

                    if(j > 0 && dp[i][j-1][x] == true){

                        dp[i][j][newXOR] = true;
                    }
                }
            }
        }


        //Step-5: Iterate through all XOR Values and find minimum
        for(int x = 0; x < 1024; x++){
            
            if(dp[m-1][n-1][x] == true){
                return x;
            }
        }

        
        //finally if no such xor path found
        return -1;
    }
};