class Solution {
public:
    //Time Complexity = O(n²)
    //Space Complexity = O(n²)
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool> &vis){
        //mark current city = true
        vis[u] = true ;
        //visit in neighs of u
        for(int &v : adj[u]){
            if(!vis[v]){
                dfs(adj, v, vis) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //1.) Build the graph
        int n = isConnected.size() ;

        unordered_map<int, vector<int>> adj ;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j) ;
                    adj[j].push_back(i) ; //undirected graph connections
                }
            }
        }

        //2.) visited array
        vector<bool> vis(n, false) ;

        //4.) traverse all cities => call dfs for every unvisited city
        int countProvince = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                dfs(adj, i, vis) ;
                countProvince++ ;
            }
        }

        return countProvince ;
    }
};