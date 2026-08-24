class Solution {
public:
    //Method-2 : BFS(Breadth First Search)

    //Time Complexity = O(V + E)
    /* V = number of rooms(Vertices)
    * E = total number of keys across all rooms(Edges)
    */

    //Space Complexity = O(V + E)
    void BFS(vector<vector<int>>& rooms, int src, vector<bool>& visited){
    
        queue<int>q ;

        //start BFS from src
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            //traverse in neighbors of node
            for(auto& V : rooms[node]){
                if(!visited[V]){ //not visited
                    q.push(V);
                    visited[V] = true;
                }
            }
        }

        
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        //func. call to BFS
        BFS(rooms, 0, visited);

        //check in visited : if all true => true , else => false
        for(bool x : visited){
            if(x == false){//any room x : false
                return false;
            }

        }
        
        return true;
    }
};