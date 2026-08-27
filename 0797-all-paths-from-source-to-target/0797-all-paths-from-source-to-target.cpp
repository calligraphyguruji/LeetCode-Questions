class Solution {
public:
    void DFS(vector<vector<int>>& graph, int src, int tar, vector<vector<int>>& result, vector<int>& temp){
        //push source into current path
        temp.push_back(src);

        if(src == tar){
            result.push_back(temp);
        }
        else{
            //explore neighs of src
            for(int& v : graph[src]){
                DFS(graph, v, tar, result, temp);
            }
        }
        
        temp.pop_back();

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        int src = 0;
        int tar = n-1;

        vector<vector<int>> result;
        vector<int> temp;
       
       //func. call to DFS
        DFS(graph, src, tar, result, temp);


       //finally return all paths
       return result;
    }
};