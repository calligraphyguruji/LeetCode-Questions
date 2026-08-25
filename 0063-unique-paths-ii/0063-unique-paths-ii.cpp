class Solution {
public:
    //Method-2 : Bottom-up Approach
    
    //Time Complexity = O(m * n)
    //Space Complexity = O(m * n)
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> dp(m, vector<int>(n)) ;

        dp[0][0] = 1 ;//given in testcase if src == dst then 1 way to reach

        //fill 0th row in dp
        for(int j=0 ; j<n ; j++){
            if(j > 0 && grid[0][j-1] == 1){ //check in left if obstacle found
                dp[0][j] = 0 ;
                grid[0][j] = 1 ; //update grid obstacle so that we can't reach any cell in the right
            }
            else if(grid[0][j] == 1){
                dp[0][j] = 0 ;
            }
            else{ //if no obstacle then 
                dp[0][j] = 1 ; // 1 path found
            }
        }

        //fill 0th column in dp
        for(int i=0 ; i<m ; i++){
            if(i > 0 && grid[i-1][0] == 1){ //check in upside if obstacle found
                dp[i][0] = 0 ;
                grid[i][0] = 1 ; //update grid obstacle so that we can't reach any cell in the downside
            }
            else if(grid[i][0] == 1){
                dp[i][0] = 0 ;
            }
            else{ //if no obstacle then
                dp[i][0] = 1 ; // 1 path found
            }
        }

        //fill remaining cells in dp
        for(int i=1 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                if(grid[i][j] == 1){
                    dp[i][j] = 0 ;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] ;
                }
            }
        }

        //return total no. of ways to reach [m-1][n-1]
        return dp[m-1][n-1] ;
    }
};