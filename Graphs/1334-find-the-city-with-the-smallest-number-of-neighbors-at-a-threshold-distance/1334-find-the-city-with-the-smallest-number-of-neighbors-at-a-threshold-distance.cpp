class Solution {
public:
    void Dijkstra(int n, unordered_map<int, vector<pair<int,int>> >& adj, vector<int>& res, int src){

        //priority queue : min Heap for BFS
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq ;

        pq.push({0,src}) ; //start with (0,src)
        
        fill(res.begin(), res.end(), INT_MAX) ; 
        res[src] = 0 ; // src to src dist = 0

        while(!pq.empty() ){
            int d = pq.top().first ;
            int u = pq.top().second ;
            pq.pop() ;

            //check for neighbors
            for(auto& p : adj[u]){
                int v = p.first ; 
                int w = p.second ; //wt(u,v)

                //edge relaxation
                if(res[v] > d + w){
                    res[v] = d + w ;
                    pq.push({d+w, v}) ;
                    
                }
            }
        }
        
    }
    int findResultCity(int n, vector<vector<int>>& SPM, int D){
        int resultCity = -1 ;
        int leastReachCount = INT_MAX ;

        //check for every city & count reachable cities
        for(int i=0 ; i<n ; i++){
            int countReach = 0 ;
            for(int j=0 ; j<n ; j++){
                
                if(i != j && SPM[i][j] <= D){
                    countReach++ ;
                }
            }

            //handle edgecase : nodes with same no. of min cities reachable then return which comes last
            if(countReach <= leastReachCount){
                leastReachCount = countReach ;
                resultCity = i ;
            }
        }

        return resultCity ; 
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //Method-1: Using Dijkstra's Algorithm (very lengthy)
        
        //1.) Create Shortest Path Matrix(SPM)
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX)) ;

        //2.)Distance from a city to itself is 0
        for(int i=0 ; i<n ; i++){
            SPM[i][i] = 0 ;
        }

        //3.) Build adjacency list
        unordered_map<int, vector<pair<int,int>> > adj ;

        for(auto &vec : edges){
            int u = vec[0] ;
            int v = vec[1] ;
            int wt = vec[2] ;

            //undirected graph connections :
            adj[u].push_back({v, wt}) ;
            adj[v].push_back({u, wt}) ;
        }

        //4.)Run Dijkstra for every city
        for(int i=0 ; i<n ; i++){
            Dijkstra(n, adj, SPM[i], i) ;
        }


        //7.) Return findResultCity
        return findResultCity(n, SPM, distanceThreshold) ;
        
    }
};