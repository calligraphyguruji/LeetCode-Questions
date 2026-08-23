class Solution {
public:
    //Method : BFS(Breadth First Search) 
    
    vector<vector<int>>directions{ {-1,0}, {1,0}, {0,-1}, {0,1} };
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size() ;
        int n = maze[0].size() ;

        queue<pair<int,int>> q; // q(i,j)

        //start with 
        q.push({entrance[0], entrance[1]}) ; //(row, column) => index: 0 means row, index: 1 means column

        //mark visited with '+'
        maze[entrance[0]][entrance[1]]= '+';


        int steps = 0;

        //Classic BFS 
        while(!q.empty()){
            int N = q.size() ; //size of each level

            while(N--){
                pair<int, int>temp = q.front();
                q.pop();

                int i = temp.first;
                int j = temp.second;

                //if reached boundary then return steps
                if( (temp != make_pair(entrance[0], entrance[1])) &&
                    (i == 0 || i == m-1 || j == 0 || j == n-1) ){
                        return steps ;
                }


                //explore the neighbors
                for(auto &dir : directions){
                    int new_i = i + dir[0] ; //dir[0] == row
                    int new_j = j + dir[1] ; //dir[1] == column

                    //check if there is wall or out of bound index => if not then push in queue & mark visited
                    if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n &&
                       maze[new_i][new_j] != '+'){
                          q.push(make_pair(new_i, new_j));
                          maze[new_i][new_j] = '+'; //visited marked
                    }
                }
                
            }
            steps++ ; //update steps after each level
        }

        //if in above checks no boundary condition reached
        return -1; //impossible
    }
};