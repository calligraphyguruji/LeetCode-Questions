class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp){
        //base-case
        if(i < 0 || i >= m || j < 0 || j >= n){ //out of bound
            return 0 ;
        }

        //if reached to destination return 1 path found
        if(i == m-1 && j == n-1){
            return 1 ;
        }
        
        //check memoization table
        if(dp[i][j] != -1){ //means solved before 
            return dp[i][j] ; //just return that state don't solve again
        }
        int right = solve(i, j+1, m, n, dp) ;
        int down = solve(i+1, j, m, n, dp) ;

        return dp[i][j] = right + down ;


    }
    int uniquePaths(int m, int n) {
        
        //2d dp vector
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1)) ;


        return solve(0, 0, m, n, dp) ;
    }
};