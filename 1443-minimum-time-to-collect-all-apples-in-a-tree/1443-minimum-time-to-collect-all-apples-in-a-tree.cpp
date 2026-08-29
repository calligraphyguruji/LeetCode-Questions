class Solution {
public:
    //Method : DFS Traversal

    //Time Complexity = O(V + E) =>
    /* V = number of vertices
    * E = number of edges
    * Building adjacency list → O(E)
    */
    //Space Complexity = O(V + E)


    int DFS(unordered_map<int, vector<int>>& adj, int curr, int parent, vector<bool>& hasApple){
        //initialize time
        int time = 0;

        //traverse in children of curr
        for(int &child : adj[curr]){
            if(child == parent) continue;//skip 

            int time_from_child = DFS(adj, child, curr, hasApple);

            if(time_from_child > 0 || hasApple[child]){
                time += 2 + time_from_child; 
            }
        }

        //finally return total time
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        //1.) Build graph adjacency (using unordered_map)
        unordered_map<int, vector<int>> adj;

        for(auto& vec : edges){
            int u = vec[0];  //edges[i] = [u,v] 
            int v = vec[1];

            //make undirected graph connections 
            adj[u].push_back(v); //u--->v
            adj[v].push_back(u);
        }


        //func. call to DFS
        int st = 0;
        int parent = -1; //parent of root = -1

        return DFS(adj, st, parent, hasApple);
    }
};