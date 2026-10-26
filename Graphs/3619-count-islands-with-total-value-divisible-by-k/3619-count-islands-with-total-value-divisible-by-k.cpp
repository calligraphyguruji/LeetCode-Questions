class Solution {
public:

    //Step-2: Define DFS
    long long DFS(vector<vector<int>>& grid, int i, int j){

        int m = grid.size();
        int n = grid[0].size();

        //2.a) Check if current cell is out of bound
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0){
            return 0;
        }

        //2.b)otherwise , store current cell in sum
        long long sum = grid[i][j];

        //2.c) mark current cell visited
        grid[i][j] = 0;

        //Step-3: Explore all 4 directions
        sum += DFS(grid, i-1, j); //up
        sum += DFS(grid, i+1, j); //down
        sum += DFS(grid, i, j-1); //left
        sum += DFS(grid, i, j+1); //right

        //3.b)
        return sum;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        
        //Step-1: Initialize variables
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        //Step-4: Traverse the grid
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                if(grid[i][j] > 0){

                    long long islandSum = DFS(grid, i, j);
            
                    if(islandSum % k == 0){
                        count++;
                    }
                }
            }
        }

        //Step-5: Return the result output
        return count;

    }
};