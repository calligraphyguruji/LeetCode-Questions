class Solution {
public:
    int result;
    int DFS(unordered_map<int, vector<int>>& adj, int curr, int parent, string& s){
        int longest = 0;
        int secondLongest = 0;

        //traverse all children of curr
        for(int& child : adj[curr]){
            
            if(child == parent) continue;

            int childLongest = DFS(adj, child, curr, s);

            if(s[child] == s[curr]) continue;

            if(childLongest > longest){
                secondLongest = longest;
                longest = childLongest;
            }

            else if(childLongest > secondLongest){
                secondLongest = childLongest;
            }
        }

        //Case-1 : if ans found in left/right child subtree 
        int left_right_child_ans = longest + secondLongest + 1;

        //Case-2 : including root choose one from multiple paths
        int choose_one = 1 + max(longest, secondLongest);

        //Case-3 : only root, if both child have same char.
        int only_root = 1;

        result = max(result, left_right_child_ans);

        //return only max(Case-2 or Case-3)
        return max(choose_one, only_root);

    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        result = 0;
        //1.) Build Graph using adjacency list
        unordered_map<int, vector<int>> adj;

        //populate the graph : make edge connections
        for(int i=1; i<n; i++){
            int u = i;
            int v = parent[i];

            //make undirected graph connections
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //func. call to DFS
        int curr = 0;
        int par = -1; //parent of 0 is -1

        DFS(adj, curr, par, s);

        //finally return the longest path length
        return result;
        
    }
};