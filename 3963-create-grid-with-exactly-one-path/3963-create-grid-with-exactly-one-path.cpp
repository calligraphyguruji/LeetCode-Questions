class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        //Step-1: 
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