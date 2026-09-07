class Solution {
public:
    //Method : DFS Approach

    // Time Complexity = O(P * V) => V = vertices/nodes
    // Space Complexity = O(P * V)
    // Auxiliary Space = O(V)
    // where P = number of paths from source to target


    void DFS(vector<vector<int>>& graph, int src, int tar, vector<vector<int>>& result, vector<int>& temp){
        //push source into current path
        temp.push_back(src);

        if(src == tar){ //don't check further just push in result
            result.push_back(temp);
        }
        else{
            //explore neighs of src
            for(int& v : graph[src]){
                DFS(graph, v, tar, result, temp);
            }
        }
        
        temp.pop_back();//now pop also to insert next path

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        int src = 0;
        int tar = n-1;

        vector<vector<int>> result; //to store all paths/result
        vector<int> temp; //to store current path
       
       //func. call to DFS
        DFS(graph, src, tar, result, temp);


       //finally return all paths
       return result;
    }
};