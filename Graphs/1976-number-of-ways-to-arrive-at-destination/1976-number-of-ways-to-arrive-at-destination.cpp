class Solution {
public:
    typedef pair<long long, int> P ;
    int M = 1e9 + 7 ; 
    int countPaths(int n, vector<vector<int>>& roads) {
        //1.) Create graph adjacency list 
        unordered_map<int, vector<pair<int,int>> > adj ;

        for(auto &road : roads){
            int u = road[0] ;
            int v = road[1] ;
            int time = road[2] ;

            //make undirected graph connections
            adj[u].push_back({v,time}) ;
            adj[v].push_back({u,time}) ; 
        }

        //2.) initialize required arrays & minHeap 
        priority_queue<P, vector<P>, greater<P> > pq ; //minHeap

        vector<long long> ans(n, LLONG_MAX) ;

        vector<int> countPath(n, 0) ;
        
        //base case initialization for source node(0)
        pq.push({0,0}) ; //(time, node)
        ans[0] = 0 ;
        countPath[0] = 1 ;

        //3.) Apply Dijkstra's Algorithm

        while(!pq.empty() ){
            long long currTime = pq.top().first ; //pq(time, node)
            int currNode = pq.top().second ;
            pq.pop() ;

            //if a shorter path already found skip process
            if(ans[currNode] > currTime)
                continue ;
            
            //explore all neigbors
            for(auto& vec : adj[currNode]){
                int nbr = vec.first ;
                int roadTime = vec.second ;

                //Case-1 : if found a strictly shorter path 
                if(ans[nbr] > currTime + roadTime){
                    
                    ans[nbr] = currTime + roadTime ;
                    pq.push({ans[nbr], nbr}) ;
                    countPath[nbr] = countPath[currNode] ;
                }

                //Case-2 : if found another path with same time
                else if(ans[nbr] == currTime + roadTime){
                    countPath[nbr] = (countPath[nbr] + countPath[currNode]) % M ;
                }
            }
        }

        //very important to return the countPath to dest = n-1
        return countPath[n-1] ;
        
    }
};