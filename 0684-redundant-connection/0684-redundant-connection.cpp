class Solution {
public:
    //Time Complexity = O(n²)
    //Space Complexity = O(n)
    bool dfs(unordered_map<int, vector<int>>& adj, int u, int v, vector<bool>& vis ){ //6.) DFS function
        //if u is v
        if(u == v) return true ;

        vis[u] = true ; //mark u = visited
        
        // Traverse all neighbours connected to node u
        for(auto &neigh : adj[u]){
            if(!vis[neigh]){
                if(dfs(adj, neigh, v, vis) ){
                    return true ;
                }
            }
        }

        //if in above check no connection found then
        return false ;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size() ;

        //1.) Create adjacency list
        unordered_map<int, vector<int>> adj ;

        //2.)Process edge one by one
        for(int i=0 ; i<n ; i++){
            int u = edges[i][0] ;
            int v = edges[i][1] ;


            //3.) Initialize visited array
            vector<bool> vis(n+1, false) ;

            //4.) check is (u,v) already connected then return the ans.
            if(adj.find(u) != adj.end() && adj.find(v) != adj.end() &&
               dfs(adj, u, v, vis) ){
                    
                    return edges[i] ;
            }

            else{ //5.) if not connected then insert the edge in adj 
                adj[u].push_back(v) ; // u -----> v
                adj[v].push_back(u) ; // v -----> u (cause undirected)

            }

        }

        
     //if not found any redundant edge then
     return {} ; //empty array

    }
};