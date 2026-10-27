class Solution {
public:
    
    //Approach : Greedy-Construction

    //Time Complexity = O(m * n) =>
    /* Initialize the grid → O(m × n)
    * First row traversal → O(n)
    * Last column traversal → O(m)
    * Total → O(m × n + m + n) = O(m × n)
    */

    //Space Complexity = O(m * n) =>
    /* The vector<string> stores m × n characters.
    * Auxiliary space, excluding the returned grid, is O(1).
    */

    vector<string> createGrid(int m, int n) {
        
        //Step-1: Initialize grid
        vector<string> grid(m, string(n, '#'));//size m * n filled with #

        //Step-2: Create horizontal path => only in first row
        for(int j = 0; j < n; j++){
            grid[0][j] = '.';//free cell 
        }

        //Step-3: Create vertical path => only in last column
        for(int i = 0; i < m; i++){
            grid[i][n-1] = '.';//free cell
        }

        //Step-5: Return grid
        return grid;
    }
};