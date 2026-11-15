class Solution {
public:
    //Approach : Brute Force(Direction simulation using Visited)

    //Time Complexity = O(m * n) =>
    /* The for loop runs m * n times.
    * Each cell is visited exactly once.
    * Checking boundaries and changing directions takes O(1) time.
    */

    //Space Complexity = O(m * n) =>
    /* `visited` matrix stores m * n boolean values : O(m * n)
    * `directions` stores 4 pairs -> O(1)
    */

    vector<pair<int, int>> directions{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };// Right -> Down -> Left -> Up
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(); //row size
        int n = matrix[0].size(); //column size
        vector<int> ans; //to store the output

        //1.) Start from (0, 0) facing right
        vector<vector<bool>> visited(m, vector<bool>(n, false)); 

        int row = 0, col = 0;
        int direction = 0;// 0 => Right      

        //2.) Traverse all matrix elements
        for(int i = 0; i < m * n; i++){
            
            //3.) Add current element to ans
            ans.push_back(matrix[row][col]);

            //4.) Mark current cell as visited
            visited[row][col] = true;

            //5.) Calc. new position 
            int newRow = row + directions[direction].first;
            int newCol = col + directions[direction].second;

            //6.) Cehck boundaries and visited cells
            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || visited[newRow][newCol]){

                //Change directioin clockwise
                direction = (direction + 1) % 4;

                //Calc. new position in new Direction
                newRow = row + directions[direction].first;
                newCol = col + directions[direction].second;

            }

            //7.) Update current position
            row = newRow;
            col = newCol;
        }

        //8.) Return the output
        return ans;

    }
};