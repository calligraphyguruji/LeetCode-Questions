class Solution {
public:
    //Method-2 : Bottom-Up Approach
    //Time Complexity = O(m * n)
    //Space Complexity = O(m * n)
    
    int uniquePaths(int m, int n) {
        
        //2d dp vector (m x n size)
        vector<vector<int>> dp(m, vector<int>(n)) ;
        
        dp[0][0] = 1 ; //assumption : source cell => source cell given = 1

        //base-case :
        //fill 0th row
        for(int j = 1 ; j < n ; j++){
            dp[0][j] = 1 ;
        }

        //fill 0th col
        for(int i=1 ; i < m ; i++){
            dp[i][0] = 1 ;
        }
        

        //fill remaining cells of dp

        for(int i= 1 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
            }
        }

        //destination cell
        return dp[m-1][n-1] ;
    }
};