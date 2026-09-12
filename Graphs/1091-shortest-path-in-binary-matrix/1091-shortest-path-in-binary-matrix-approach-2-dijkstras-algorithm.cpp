class Solution {
public:
    //Approach-2 : Dijkstra's Algorithm 

    //Time Complexity = O(n * n * logn)
    //Space Complexity = O(n * n)
    
    typedef pair<int, pair<int, int>> P;
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

        //2.) priority_queue for Dijkstra
        priority_queue<P, vector<P>, greater<P> > pq; //pair because storing coordinate pairs

        pq.push({0, {0,0}}); //push source coord.
        
        vector<vector<int>> result(m, vector<int>(n, INT_MAX) );
        result[0][0] = 0; //src to src distance = 0

        //4.) 
        while(!pq.empty()){
            int d = pq.top().first;
            pair<int, int> coord = pq.top().second;
            int r = coord.first;
            int c = coord.second;
            pq.pop();

            //traverse in neighbors of curr coord(r, c)
            for(auto dir : directions){
                int i = r + dir[0];
                int j = c + dir[1];
 
                int dist = 1; //path cost of every cell is same = 1

                //if isSafe to visit , do edge relaxation 
                if(isSafe(i, j) && d + dist < result[i][j]){
                    
                    pq.push({d+dist, {i, j}});
                    result[i][j] = d + dist;
                }
            }

                
        }

        //if impossible to find path
        if(result[m-1][n-1] == INT_MAX){
            return -1;
        }
        else{
            return result[m-1][n-1] + 1;
        }
    }
};
