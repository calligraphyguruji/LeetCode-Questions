class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //1.) Create adjacency list
        unordered_map<int, vector<pair<int, int>>> adj ;

        for(vector<int>& vec : flights){
            
            int u = vec[0] ;
            int v = vec[1] ;
            int cost = vec[2] ;


            //direction : u ----> v
            adj[u].push_back({v, cost}) ;
        }


        //2.) Create distance array
        vector<int> distance(n, INT_MAX) ;

        //3.) BFS queue
        queue<pair<int, int>> q ; //(v, curr_cost) ;

        q.push({src,0}) ;
        distance[src] = 0 ; //src se src ka distance = 0

        //4.)Start counting levels/steps
        int steps = 0 ;

        //5.) BFS and process one level at a time
        while(!q.empty() && steps <= k){
            
            int N = q.size() ; //size of current level

            while(N--){ //6.) extract node & cost
                int u = q.front().first ;
                int d = q.front().second ; //cost
                q.pop() ;



                //7.) explore all neighbours
                for(pair<int,int> &P : adj[u]){
                    int v = P.first ;
                    int cost = P.second ;

                    //8.) Edge Relaxation : check if cheaper path exists
                    if(distance[v] > d+cost){
                        distance[v] = d+cost ;
                        q.push({v, d+cost}) ;
                    }
                }
            }
            //9.)update steps after each level
            steps++ ;
        }


        //10.) return the answer

        if(distance[dst] == INT_MAX){
            return -1 ; //cause still distance is infinity => no path found
        }

        else{ //path found
            
            return distance[dst] ;

        }

    }
};