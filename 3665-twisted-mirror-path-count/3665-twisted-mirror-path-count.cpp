class Solution {
public:
    //Approach : Dynamic Programming + Direction State

    //Time Complexity = O(m * n) =>
    /* Grid Traversal: Visit all m × n cells → O(m × n).
    * Direction States: Process 2 directions per cell → O(1).
    * DP Updates: Each direction requires constant-time operations → O(1).
    */

    //Space Complexity = O(m * n) =>
    /* * 3D DP Table: Stores m × n × 2 states → O(2 × m × n).
    * Extra Variables: i, j, dir, ways, etc. → O(1).
    */

    const int M = 1e9 + 7; //10^9 + 7

    int uniquePaths(vector<vector<int>>& grid) {
        
        int m = grid.size(); //row size
        int n = grid[0].size(); //column size

        //1.) Initialize DP : 3D DP
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));

        //2.) Intialize Starting Point
        dp[0][0][0] = 1; //dp[i][j][0] => no. of ways to reach (i,j) moving right
        dp[0][0][1] = 0; //dp[i][j][1] => no. of ways to reach (i,j) moving down

        //3.) Traverse the grid
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){

                //Process both directions for each cell
                for(int dir = 0; dir < 2; dir++){

                    int ways = dp[i][j][dir];

                    if(ways == 0) continue;
                    
                    //4.) Handle Mirror Reflection
                    if(grid[i][j] == 1){
                        int newDir = 1 - dir;//Right <-> 

                        int newRow = i + (newDir == 1);
                        int newCol = j + (newDir == 0);

                        //check if newxt cell is within grid boundaries
                        if(newRow < m && newCol < n){

                            //5.)update dp state
                            dp[newRow][newCol][newDir] = (dp[newRow][newCol][newDir] + ways) % M;
                        }
                        
                    }
                    //Handle empty cell
                    else{
                        //move right
                        if(j + 1 < n){
                            dp[i][j+1][0] = (dp[i][j+1][0] + ways) % M;
                        }
                        //move down
                        if(i + 1 < m){
                            dp[i+1][j][1] = (dp[i+1][j][1] + ways) % M;
                        }
                    }                  

                }
            }
        }


        //6.) Return result
        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % M;
    }
};