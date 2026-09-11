class Solution {
public:
    //Approach-1 : BFS(Breadth First Search) 

    //Time Complexity = O(n * n)
    //Space Complexity = O(n * n)

    //directions vector : all 8 directions 
    vector<vector<int>> directions{ {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(); //row size
        int n = grid[0].size(); //column size

        //1.) base-case
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1){
            return -1;
        }

        //4.(b) check isSafe to visit
        auto isSafe = [&](int r, int c){
            return (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 0);
        };

        //2.) queue for BFS
        queue<pair<int,int>> q; //pair because storing coordinate pairs

        q.push({0,0}); //push sourc coord.
        grid[0][0] = 1; //mark visited

        //3.)initialize count
        int count = 0;

        //4.) 
        while(!q.empty()){
            int N = q.size(); //curr level size

            while(N--){ //traverse in curr level
                auto curr = q.front();//pair
                q.pop();

                int row = curr.first;//because curr is pair so first, second
                int col = curr.second;

                //check if destination reached
                if(row == m-1 && col == n-1){
                    return count+1;
                }

                //push neighbors of curr in all 8 directions only if isSafe
                for(auto dir : directions){
                    int i = row + dir[0];  
                    int j = col + dir[1]; 

                    if(isSafe(i, j)){
                        q.push({i, j});
                        grid[i][j] = 1; //mark visited
                    }

                }

            }
            count++;//curr level finished update count
        }

        //if impossible to find path in above
        return -1;
    }
};