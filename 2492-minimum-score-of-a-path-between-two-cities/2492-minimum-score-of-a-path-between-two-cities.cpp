class Solution {
public:
    //Approach : DFS-Connected Component Traversal

    //Time Complexity: O(n + E) =>
    /* n = number of cities
    * E = number of roads
    1. Building the adjacency list: O(E)
    2. DFS: O(n + E)
    * Each city is visited at most once → O(n)
    * Each road is examined at most twice → O(E)
    * So : O(E) + O(n + E) = O(n + E)
    */

    //Space Complexity: O(n + E) =>
    /* We use:
    1. Adjacency list
        * Stores both directions of every road.
        * O(n + E)
    2. Visited array
        * One boolean for every city.
        * O(n)
    3. Stack
        * In the worst case, it can contain up to n cities.
        * O(n)
    */


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