class Solution {
public:
    //Time Complexity = O(V + E)
    //Space Complexity = O(V + E)
    bool topologicalSortCheck(unordered_map<int, vector<int>>& adj, int n,vector<int>& indegree ){
        //queue to use BFS
        queue<int> q ;

        int count = 0 ;

        //3.) push all nodes having indegree = 0
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                count++ ;
                q.push(i) ;
            }
        }

        //4.) Start BFS
        while(!q.empty()){
            int u = q.front() ;
            q.pop() ;

            //traverse in neighs of u
            for(int &v : adj[u]){
                indegree[v]-- ; //decrease indegree of neighs

                if(indegree[v] == 0){
                    count++ ;
                    q.push(v) ;
                }
                
            }
        }

        //check count
        if(count == n){ //n = numCourses => means all courses are visited => no cycle detected
            return true ;
        }

        else{  //count != n => all courses can't be visited => cycle detected
            return false ;
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //1.) Build the graph
        unordered_map<int, vector<int>> adj ;

        //2.) Compute indegree
        vector<int> indegree(numCourses,0) ;

        for(auto& vec : prerequisites){
            int a = vec[0] ;
            int b = vec[1] ;

            //direction : b ----> a
            adj[b].push_back(a) ;

            indegree[a]++ ; //cause arrow coming into a
        }

        //Detect cycle using topological sort
        return topologicalSortCheck(adj, numCourses, indegree) ;
    }
};