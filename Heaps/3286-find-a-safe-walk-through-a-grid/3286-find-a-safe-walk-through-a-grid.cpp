class Solution {
public:
    vector<vector<int>> directions{ {-1,0}, {1, 0}, {0, -1}, {0, 1} };

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        
        int m = grid.size(); //row size
        int n = grid[0].size(); //column size
        
        vector<vector<int>> bestHealth(m, vector<int>(n, -1));// Store the maximum health with which we reach each cell

        queue<tuple<int, int, int>> q; //to store row, column, health

        //calc. health for start cell
        health -= grid[0][0];

        if(health <= 0){
            return false;
        }

        q.push({0, 0, health}); //push start row, column, health
        bestHealth[0][0] = health;

        while(!q.empty()){
            
            auto [row, col, currHealth] = q.front();
            q.pop();

            //check if reached to destination
            if(health >= 1 && row == m-1 && col == n-1){
                return true;
            }

            //otherwise explore all the 4 directions
            for(auto& dir : directions){

                int newRow = row + dir[0];
                int newCol = col + dir[1];

                //check grid boundaries
                if(newRow < 0 || newRow >= m | newCol < 0 | newCol >= n){
                    continue;
                }

                //Reduce health if current health is unsafe
                int newHealth = currHealth - grid[newRow][newCol];

                //Health must remain >= 1
                if(newHealth <= 0){
                    continue;
                }

                //Avoid revisiting if already visited with bestHealth
                if(newHealth <= bestHealth[newRow][newCol]){
                    continue;
                }

                bestHealth[newRow][newCol] = newHealth;

                //push next cell in queue
                q.push({newRow, newCol, newHealth});
            }
        }


        //finally if no valid path found in above checks by BFS
        return false;
    }
};