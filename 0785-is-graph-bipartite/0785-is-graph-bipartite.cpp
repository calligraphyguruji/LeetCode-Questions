class Solution {
public:
    //Time Complexity = O(V + E)
    //Space Complexity = O(V)
    bool checkDFS(vector<vector<int>>& adj, int curr, vector<int> &color, int currColor){
        //queue for DFS
        queue<int> q ;
        q.push(curr) ; //start with curr
        color[curr] = currColor ;

        while(!q.empty() ){
            int u = q.front() ;
            q.pop() ;

            //traverse in neighs 
            for(int &v : adj[u]){
                if(color[v] == color[u]) //same color of ajacent nodes
                    return false ;
                
                else if(color[v] == -1){ //uncolored
                    
                    int colorOfV = 1 - currColor ;

                    //recursively perform DFS
                    if(checkDFS(adj, v, color, colorOfV) == false)
                        return false ;

                }

            }
        }

        return true ;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        //1.) make color array
        int V = adj.size() ;
        vector<int> color(V, -1) ;

        //2.) traverse every node
        for(int i=0 ; i<V ; i++){
            if(color[i] == -1){
                if(checkDFS(adj, i, color, 1) == false)
                    return false ;
            }
        }

        //if no false found then
        return true ; 
    }
};