class Solution {
public:
    //Time Complexity = O(V + E)
    //Space Complexity = O(V + E)
    vector<int> topologicalSort(unordered_map<int, vector<int>>& adj, int n, vector<int>& indegree){

        queue<int> q ; //queue for BFS
        vector<int> ans ; //to store ans 
        int count = 0 ;

        //push all nodes in queue having indegree == 0
        for(int i=0 ; i<n ; i++){
            if(indegree[i] == 0){
                ans.push_back(i) ;
                count++ ;
                q.push(i) ;
            }
        }

        //4.) Start BFS
        while(!q.empty() ){
            int u = q.front() ;
            q.pop() ;
            //traverse in neighbours
            for(int &v : adj[u]){
                
                indegree[v]-- ; //decrease indegree of neighbours

                if(indegree[v] == 0){
                    ans.push_back(v) ;
                    count++ ;
                    q.push(v) ;
                }
            }
        }

        //if count == n(numCourses) => then completed all the courses.
        if(count == n){
            return ans ;
        }

        else{ //count != n => cycle detected.
            return {} ; //empty array
        }

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Step-1 : Build the graph
        unordered_map<int, vector<int>> adj ;

        //Step-2 : Compute Indegree
        vector<int> indegree(numCourses,0) ;

        // Build adjacency list and calculate indegree of each course
        for(auto &vec : prerequisites){
            int a = vec[0] ;
            int b = vec[1] ;

            //direction : b----->a
            adj[b].push_back(a) ;

            indegree[a]++ ; //inc. indegree of 'a' cause arrow coming into a

        }

        //Detect cycle using topological sort
        return topologicalSort(adj, numCourses, indegree) ;
    }
};