class Solution {
public:
    //Time Complexity = O(V² * logV)
    //Space Complexity = O(V²)
    int primsAlgo(vector<vector<pair<int, int>> >& adj, int V){

        //1.)Create a min-Heap
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pq ;

        pq.push({0,0}) ;

        //2.)Create a inMST array
        vector<bool> inMST(V, false) ;

        //3.) initialize mstCost
        int mstCost = 0 ;


        //4.) Repeat until priority queue becomes empty
        while( !pq.empty() ){

            //a.) extract the min. edge wt
            auto p = pq.top() ;
            pq.pop() ;

            int wt = p.first ;
            int u = p.second ;
            //b.) check if vertex is already included
            if(inMST[u] == true){
                    continue ;
            }
            else{ //not included inMST            
            inMST[u] = true ; //c.)then include & mark true 
            mstCost += wt ; //d.) add its edge wt to mstCost
            }    
                
            //e.) traverse in neighs of u
            for(auto &temp : adj[u]){
                int v = temp.first ; //neighbour
                int w = temp.second ; //neigh_wt
                    
                if(!inMST[v]){
                    pq.push({w,v}) ;
                }
            }
        }
        
        return mstCost ;

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //1.) Create adjacency list
        int V = points.size() ;
        vector<vector<pair<int,int>> >adj(V) ;

        for(int i=0 ; i<V ; i++){
            for(int j=i+1 ; j<V ; j++){
                int x1 = points[i][0] ;
                int y1 = points[i][1] ;

                int x2 = points[j][0] ;
                int y2 = points[j][1] ;

                int dist = abs(x2-x1) + abs(y2-y1) ;

                adj[i].push_back({j, dist}) ;
                adj[j].push_back({i, dist}) ;
            }
        }


        //2.) func. call to prim's Algorithm
        return primsAlgo(adj, V) ;
    }
};