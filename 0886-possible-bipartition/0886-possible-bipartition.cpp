class Solution {
public:
    bool checkBFSBipartite(unordered_map<int, vector<int>>& adj, int node, vector<int>& color){
        //queue for BFS
        queue<int> q;

        q.push(node);
        color[node] = 1; //1 = Red

        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            //explore neighs of u
            for(int& v : adj[u]){
                if(color[u] == color[v]){ //same color
                    return false;
                }

                if(color[v] == -1){//not colored yet
                    q.push(v);
                    color[v] = 1 - color[u]; //this formula helps : if color[u] = 0 , then color[v] = 1 & vice versa.
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //1.) Build graph adjacency
        unordered_map<int, vector<int>> adj;
        

        for(auto& vec : dislikes){
            int u = vec[0]; 
            int v = vec[1];

            //make connections : bidirectional graph
            adj[u].push_back(v); //u---->v
            adj[v].push_back(u); //v---->u
        }

        //color vector to store : Red, Green
        vector<int> color(n+1, -1); //initially fill with -1
         
        for(int i=1; i<= n; i++){
            if(color[i] == -1){
                if(checkBFSBipartite(adj, i, color) == false){
                    return false;
                }
            }
        }

        //if bipartite != false
        return true;

    }
};