class Solution {
public:
    //Approach : Dijkstra + State Tracking

    //Time Complexity = O(k × (V + E) × log(V × k)) =>
    /* 1. Build Adjacency List: O(V + E) — Store all nodes and directed edges.
    2. Initialize Distance Array: O(V × k) — Each node maintains up to k states.
    3. Dijkstra’s Algorithm:
        * Total states: O(V × k).
        * Each edge can be explored up to k times: O(E × k).
        * Min-heap operations: O(log(V × k)) for a simple-graph bound.
    4. Overall: O(k × (V + E) × log(V × k)).
    */

    //Space Complexity = O(V × k + E × k) =>
    /* 1. Adjacency List: O(V + E) — Stores the directed weighted graph.
    2. Distance Array: O(V × k) — Stores minimum cost for each (node, count) state.
    3. Min-Heap: O(E × k) — Stores pending states in the worst case.
    */


    typedef tuple<long long, int, int> P;
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        //1.) Build adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            //make directed weighted graph connections
            adj[u].push_back({v, w}); //u--->v
        }

        //2.) Initialize distance array
        const long long INF = LLONG_MAX;
        vector<vector<long long>> dist(n, vector<long long>(k+1, INF));

        //dist[node][count] = min cost
        dist[0][1] = 0;//start from node 0, cost = 0, count = 1
        

        //3.) Initialize min-Heap
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, 0, 1}); //{cost, node, count}
        
        //4.) Apply modified Dijkstra's algo
        while(!pq.empty()){

            auto [cost, u, count] = pq.top();
            pq.pop();

            //Skip outdated states
            if(cost > dist[u][count]){
                continue;
            }

            //Step-7: check if destination reached then 
            if(u == n-1){
                return static_cast<int> (cost);//type casting into int
            }

            //Step-5: Explore adjacent nodes(neighbors)
            for(auto& [v,w] : adj[u]){ //neighbors of u
                
                int newCount;

                if(labels[u] == labels[v]){
                    newCount = count + 1;
                }

                else{
                    newCount = 1;
                }
                
                //Step-6: Validate & Update distance
                if(newCount > k){
                    continue;
                }

                long long newCost = cost + w;
         
                if(newCost < dist[v][newCount]){ //edge - relaxation
                    dist[v][newCount] = newCost;
                    pq.push({newCost, v, newCount});
                }
            } 
        }

        
        //if no min cost found then
        return -1;

    }
};