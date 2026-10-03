class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>> & adj, vector<bool>& visited, int& ans){
        //mark current node visited
        visited[node] = true;

        //start DFS from city 1 to n (connected component)
        for(auto [next, dist] : adj[node]){
            
            ans = min(ans, dist);

            if(!visited[next]){// Visit unvisited city
                dfs(next, adj, visited, ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        
        int ans = INT_MAX; //because we want min. so initialize with max

        //1.) Build adjacency list
        vector<vector<pair<int, int>>> adj(n+1);
        //Here unordered_map<int, int> is wrong because each city needs multiple edges.

        for(auto& v : roads){
            int a = v[0];
            int b = v[1];
            int dist = v[2];

            //make undirected or bidirectional connection
            adj[a].push_back({b, dist});
            adj[b].push_back({a, dist});
        }
        
        //3.)
        vector<bool> visited(n+1, false);

        //2.) start DFS from city 1
        dfs(1, adj, visited, ans);

        //6.) finally return the output
        return ans;
    }
};