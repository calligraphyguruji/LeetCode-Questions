class Solution {
public:
    void DFS(vector<vector<int>>& rooms, int src, vector<bool>& visited){
        //mark source in visited true : because room 0 is unlocked
        visited[src] = true;
        
        //traverse in neighbors of source
        for(int &node : rooms[src]){
            if(!visited[node]){
                DFS(rooms, node, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        //func. call to DFS
        DFS(rooms, 0, visited);

        //check in visited : if all true => true , else => false
        for(bool x : visited){
            if(x == false){//any room x : false
                return false;
            }

        }
        
        return true;
    }
};