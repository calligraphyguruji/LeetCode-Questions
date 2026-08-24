class Solution {
public:
    //Method-2: BFS(Breadth First Search)
    
    //Time Complexity = O(V + E) => V = vertices(nodes), edges = E
    //Space Complexity = O(V + E)

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

        queue<int> q;

        //start BFS from src node
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == dst) return true;

            //else : traverse in neighbors of node
            for(auto& V : map[node]){
                if(!visited[V]){
                    q.push(V);
                    visited[V] = true;
                }
            }
        }
        
        //if in above BFS checks no path found
        return false;
    }
};