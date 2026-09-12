class Solution {
public:
    //Approach-1 : Dijkstra's Algorithm
    
    //Time Complexity = O(m * n * logmn)

    //Space Complexity = O(m * n)

    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };//up, down, left, right
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();//row size
        int n = heights[0].size(); //column size

        priority_queue<P, vector<P>, greater<P> > pq; //minHeap

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        auto isSafe = [&](int r, int c){
            return (r >= 0 && r < m && c >= 0 && c < n);
        };

        //push src in result & minHeap
        result[0][0] = 0;
        pq.push({0, {0,0}});

        while(!pq.empty()){

            int diff = pq.top().first;
            auto cell = pq.top().second;
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            //optimization
            if(r == m-1 && c == n-1){
                return diff;
            }

            //traverse in all 4 directions of curr cell
            for(auto dir : directions){
                int i = r + dir[0]; //row wise => up, down
                int j = c + dir[1]; //column wise => left, right
                
                //check if isSafe() to visit (i, j)
                if(isSafe(i, j)){
                    int absDiff = abs(heights[r][c] - heights[i][j]);
                    int maxDiff = max(diff, absDiff);

                    //now in result push min and also in minHeap
                    if(result[i][j] > maxDiff){ //if result is greater than curr maxDiff means this is min
                        result[i][j] = maxDiff;

                        pq.push({maxDiff, {i, j}});
                    }
                } 

            }

        }

        //finally return the maxDiff value of (m-1, n-1) cell in result
        return result[m-1][n-1];
    }
};