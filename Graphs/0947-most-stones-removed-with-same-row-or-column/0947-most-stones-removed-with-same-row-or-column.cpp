class Solution {
public:
    //Time Complexity = O(n²)
    //Space Complexity = O(n)
    void dfs(vector<vector<int>>& stones, int idx, vector<bool>& vis){

        //mark curr idx true
        vis[idx] = true ;
        
        //check every other stone
        for(int i=0 ; i<stones.size() ; i++){
            int r = stones[idx][0] ;
            int c = stones[idx][1] ;

            //compare curr stone with every node
            if( (vis[i] == false) && (stones[i][0] == r || stones[i][1] == c) ){
                
                dfs(stones, i, vis) ;
            }
        }

    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ;

        //1.) create visited array
        vector<bool> vis(n, false) ;

        //2.) initialize group count 
        int group = 0 ; 

        //3.) traverse all stones
        for(int i=0 ; i<n ; i++){
            
            if(vis[i] == true)
                continue ;

            else{ //explore unvisited stones using DFS
                dfs(stones, i, vis) ;
            }
            group++ ; //after each dfs increase group count
        }



        //7.) Computer answer
        return n - group ;

    }
};