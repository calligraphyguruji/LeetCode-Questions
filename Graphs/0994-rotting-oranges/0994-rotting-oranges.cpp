class Solution {
public:
    //Time Complexity = O((m × n) × (m × n)) = O((mn)²) 
    //Space Complexity = O(m x n) => dfs recursion stack depth
    int rows, cols ; //global variable to avoid using in function parameters
    
    vector<vector<int>> directions = {{-1,0},{1,0},{0,1},{0,-1}} ;

    void dfs(vector<vector<int>> &grid,vector<vector<int>> &days,int r, int c, int currTime ){
        //boundary conditions 
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            grid[r][c] == 0 || currTime >= days[r][c]){
            
            return ; //simply return from dfs
        }

        //initialize currTime
        days[r][c] = currTime ;
       
       //move in all four directions(up,down,right,left) 
       for(auto &dir : directions){
        dfs(grid, days, r + dir[0], c + dir[1], currTime + 1);
        //update r , c values, and currTime by each iteration.
       }

    }
    int orangesRotting(vector<vector<int>>& grid ) {
        rows = grid.size() ;
        cols = grid[0].size() ;

        vector<vector<int>> days(rows,vector<int>(cols,INT_MAX)) ; //INT_MAX = infinity
        //traverse in the grid and start DFS
        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<cols ; j++){
                if(grid[i][j] == 2){ //'2' means rotten orange
                    dfs(grid,days,i,j,0) ; //then do DFS
                }
            }
        }
        int ans = 0 ; //

        for(int i=0 ; i<rows ; i++){
            for(int j=0 ; j<cols ; j++){
                //if fresh orange or never get rotten
                if(grid[i][j] == 1 && days[i][j] == INT_MAX){
                    return -1 ; 
                }

                //track days if rotten
                if(days[i][j] != INT_MAX){
                   ans = max(ans, days[i][j]) ;
                }

            }
        }

        return ans ; //very important to return ans
    }
};