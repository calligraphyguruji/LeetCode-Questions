class Solution {
public:
   //Approach : DSU (Disjoint Set Union / Union-Find) + Sorting by Node Values

   //Time Complexity = O(n * logn) => 
   /* map / sorting values → O(n log n)
    * DSU operations → approximately O(n α(n))
    * Overall → O(n log n)
   */

   
   //Space Complexity = O(n) =>
   /* 
   */

   // ! DISCLAIMER : Try this question at your own risk.

   //Step-1 : Make DSU functions/methods
    vector<int> parent;
    vector<int> rank;

    int find(int x){ //finds parent
        if(x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) //means lie in same set
            return;
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[y_parent] = x_parent; 
            rank[x_parent] += 1;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        
        //Step-2
        parent.resize(n);
        rank.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        //Step-3 : Build Graph
        unordered_map<int, vector<int>> adj;

        for(auto& vec : edges){
            int u = vec[0];//edges[i] = [a,b] => index 0 is u, index 1 is v
            int v = vec[1];

            //make connections
            adj[u].push_back(v); //u--->v
            adj[v].push_back(u); //v--->u
        }

        //Step-4 : Make a map (val -> nodes)
        map<int, vector<int>> val_to_nodes;

        for(int i=0; i<n; i++){
            int value = vals[i];

            val_to_nodes[value].push_back(i); //index is value => nodes(i)
        }

        //Step-5 : traverse in map & check nodes of same value
        int result = n;

        vector<bool> is_active(n, false);
        
        for(auto& it : val_to_nodes){
            vector<int>& nodes = it.second; 

            //Step-5(a): check nodes adjacency
            for(int& u : nodes){
                
                for(int& v : adj[u]){
                    //Step-5(b) : if node is active
                    if(is_active[v]){
                        
                        //Step-5(c) : then connect(Union)
                        Union(u, v);
                    }
                }
                //make current u node active : visited
                is_active[u] = true;
            }

            //Step-5(d) : ask parents
            vector<int> your_parents;

            for(int& u : nodes){
                int parent_who = find(u); //find func. gives parent

                your_parents.push_back(parent_who);
            }

            //Step-5(e) : check same parent nodes
            sort(your_parents.begin(), your_parents.end());

            int sz = your_parents.size();

            for(int j=0; j<sz; j++){
                long long count = 0;

                int curr_parent = your_parents[j];

                while(j < sz && your_parents[j] == curr_parent){
                    count++;
                    j++;
                }
                j--;

                int formula = (count * (count-1)/2);
                result += formula;
            }
        }

        //finally return total result
        return result;
    }
};