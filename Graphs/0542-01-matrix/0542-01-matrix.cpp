class Solution {
public:
    vector<vector<int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}} ;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //1.) initialize variables
        int n = mat.size() ;
        int m = mat[0].size() ;

        queue<pair<int,int>> q ;
        vector<vector<int>> ans(n,vector<int>(m, -1)) ;

        //2.) push coord of all the 0s
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0 ;//dist = 0
                    q.push({i,j}) ;
                }
            }
        }


        //3.) perfrom BFS
        while(!q.empty() ){
            pair<int,int> p = q.front() ;
            q.pop() ;

            int i = p.first ;
            int j = p.second ;
            //visit all four neighs : up,down,right,left
            for(auto &dir : directions){
                int new_i = i + dir[0] ;
                int new_j = j + dir[1] ;

                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && ans[new_i][new_j] == -1){
                    
                    ans[new_i][new_j] = ans[i][j] + 1 ;
                    q.push({new_i,new_j}) ;
                }
            }
        }
        //4.) return the ans
        return ans;
    }
};