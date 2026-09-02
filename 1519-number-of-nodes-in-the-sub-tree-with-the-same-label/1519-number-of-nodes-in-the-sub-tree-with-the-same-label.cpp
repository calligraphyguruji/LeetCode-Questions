class Solution {
public:
    void DFS(unordered_map<int, vector<int>>& adj, int curr, int parent, vector<int>& result, string& labels, vector<int>& count){

        char myLabel = labels[curr];

        int count_before = count[myLabel - 'a'];//this counts no. of same labels before visiting curr node

        //explore neighs of curr
        count[myLabel - 'a'] += 1;
        
        for(int& v : adj[curr]){
            
            if(v == parent) continue; //skip

            DFS(adj, v, curr, result, labels, count);
        }

        int count_after = count[myLabel - 'a'];//this counts no. of same labels after visiting curr node

        result[curr] = count_after - count_before;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //1.) Build Graph using Adjacency list
        unordered_map<int, vector<int>> adj;

        for(auto& vec : edges){
            int u = vec[0]; //edges[i] = [a,b] => index 0 = u
            int v = vec[1]; // index 1 = v

            //make undirected graph connections
            adj[u].push_back(v); // u ----> v
            adj[v].push_back(u); // v ----> u
        }


        //2.) Declare & Initialize result, count
        vector<int> result(n, 0);
        vector<int> count(26, 0);


        //func. call to DFS
        int curr = 0; //start node = 0
        int par = -1; //parent of start node = -1

        DFS(adj, curr, par, result, labels, count);


        //finally return the output
        return result;
    }
};