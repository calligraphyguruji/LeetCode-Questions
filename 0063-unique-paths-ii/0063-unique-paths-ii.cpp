class Solution {
public:
    //Method-1 : Top-Down Approach (Recursion + Memoization)

    //Time Complexity = O(m * n)
    //Space Complexity = O(m * n)

    int m , n ; //global m, n so that we don't have to pass in parameters of solve function.
    
    int dp[101][101] ;//memoization dp table

    int solve(int i, int j, vector<vector<int>>& grid){
        //base-case : check out of bound and avoid obstacle
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1){
            return 0 ;
        }

        //if reached to destination return 1 path found
        if(i == m-1 && j == n-1){
            return 1 ;
        }


        //check memoization table : 
        if(dp[i][j] != -1){ //means we have solved before
            return dp[i][j] ; //don't solve again just return the solved
        }

        //choose options :
        int right = solve(i, j+1, grid) ;
        int down = solve(i+1, j, grid) ;

        //return total no. of ways
        return dp[i][j] = right + down ;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        memset(dp, -1, sizeof(dp)) ; //initialize dp table with -1
        
        m = grid.size(); //rows
        n = grid[0].size() ; //columns
        
        return solve(0, 0, grid) ;

    }
};