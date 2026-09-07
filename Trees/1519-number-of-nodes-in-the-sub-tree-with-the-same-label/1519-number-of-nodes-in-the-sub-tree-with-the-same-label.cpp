class Solution {
public:
    //Approach : DFS + Frequency Counting (Subtree DFS)

    //Time Complexity = O(n * 26) = O(n) => O(n) + O(n) + O(26n)
    /* Build adjacency list: O(n)
    * Tree has n - 1 edges.
    * Each edge is inserted twice → 2(n-1) → O(n).
    * DFS traversal: O(n)
    * Every node is visited exactly once.
    * Every edge is explored at most twice.
    * Frequency counting: O(26 × n)
    * For every node, we may process 26 lowercase characters.
    * 26 is constant → O(n).
    */

    //Space Complexity = O(n * 26) = O(n) => O(n) + O(n) + O(n) + O(1)
    /* Adjacency list: O(n)
    * Stores n - 1 edges → 2(n-1) entries.
    * Result array: O(n)
    * Stores answer for each node.
    * DFS recursion stack: O(n)
    * Worst case: tree is a straight chain → recursion depth n.
    * Frequency array: O(26) = O(1)
    * Only 26 lowercase letters.
    */

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