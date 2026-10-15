class Solution {
public:
    //Approach : BFS directly on the grid + health tracking

    //Time Complexity = O(m * n * health) =>
    /* 1. There are m × n cells in the grid.
    2. Each cell can potentially be reached with different health values, from 1 to the initial health.
    3. Therefore, there can be up to m × n × health distinct states.
    4. For each state, BFS explores 4 directions, which takes constant time, O(1).
    */

    //Space Complexity = O(m * n * health) =>
    /* 1. The bestHealth matrix stores one value per cell, requiring O(m × n) space.
    2. The queue stores states containing the row, column, and remaining health.
    3. In the worst case, the queue can contain up to O(m × n × health) states.
    */

    vector<vector<int>> directions{ {-1,0}, {1, 0}, {0, -1}, {0, 1} }; //up, down, left, right

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