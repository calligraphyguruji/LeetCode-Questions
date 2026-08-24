class Solution {
public:
    //Method-1: DFS(Depth First Search)
    
    //Time Complexity = O(V + E) => V = vertices(nodes), edges = E
    //Space Complexity = O(V + E)

    bool DFS(unordered_map<int, vector<int>>& map, int src, int dst, vector<bool>& visited){
        //edge-case/base-case
        if(src == dst) return true;

        //mark source in visited true
        visited[src] = true;

        //traverse in neighbors of source
        for(auto& node : map[src]){
            if(!visited[node]){ //not visited then visit
                if(DFS(map, node, dst, visited) == true){//means path exits
                   return true; 
            }
            }
            
        }

        //if in above checks no path found
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
        //1.) Build graph(using unordered_map Adjacency list)
        unordered_map<int, vector<int>> map ;

        for(auto& edge : edges){
            int u = edge[0] ;
            int v = edge[1] ;

            //birectional graph : 
            map[u].push_back(v);//u--->v
            map[v].push_back(u); //v--->u
        }

        //visited bool array to store if visited or not
        vector<bool>visited(n, false) ;

        //func. call to DFS
        return DFS(map, src, dst, visited);
    }
};