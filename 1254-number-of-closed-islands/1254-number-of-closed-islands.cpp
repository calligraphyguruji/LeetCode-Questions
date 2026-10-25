class Solution {
public:
    //Approach : DFS + Boundary Flood Fill

    //Time Complexity = O(m * n) => m = no. of rows, n = no. of columns
    /* 1. Boundary Traversal: We traverse the first/last rows and columns → O(m + n).
    2. Boundary DFS: Each boundary-connected land cell is visited at most once → O(m × n) in the worst case.
    3. Grid Traversal: We iterate through all m × n cells → O(m × n).
    4. Closed Island DFS: Each remaining land cell is visited at most once → O(m × n) in the worst case.
    */

    //Space Complexity = O(m * n) =>
    /* 1. DFS Recursion Stack: In the worst case, DFS may recursively explore m × n connected land cells → O(m × n).
    2. Visited Array: Not required because we mark visited land directly in the grid (0 → 1) → O(1) extra space.
    3. Variables: Only m, n, i, j, and count are used → O(1).
    */


    //Step-2:
    void dfs(vector<vector<int>>& grid, int i, int j){
        
        int m = grid.size();
        int n = grid[0].size();

        //check out of bound i, j or reached water
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1){
            return;
        }

        //mark current land visited
        grid[i][j] = 1;

        //explore all 4 directions
        dfs(grid, i-1, j); //up
        dfs(grid, i+1, j);//down
        dfs(grid, i, j-1);//left
        dfs(grid, i, j+1);//right
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        //Step-1: Initialize variables
        int m = grid.size(); //row size
        int n = grid[0].size(); //column size

        int count = 0;

        //Step-3 : Remove boundary islands
        //Traverse the first & last rows
        for(int j = 0; j < n; j++){
            
            //first row
            if(grid[0][j] == 0){
                dfs(grid, 0, j);
            }

            //last row
            if(grid[m-1][j] == 0){
                dfs(grid, m-1, j);
            }
        }

        //Traverse First & Last columns
        for(int i = 0; i < m; i++){

            //first column
            if(grid[i][0] == 0){
                dfs(grid, i, 0);
            }

            //last column
            if(grid[i][n-1] == 0){
                dfs(grid, i, n-1);
            }
        }

        //Step-4 : Find and count closed Islands
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){
                
                if(grid[i][j] == 0){ //current land
                    count++;
                
                    dfs(grid, i, j);// Mark the entire closed island as visited
                }
            }
        }


        //Step-5: Finally return the result
        return count;
    }
};