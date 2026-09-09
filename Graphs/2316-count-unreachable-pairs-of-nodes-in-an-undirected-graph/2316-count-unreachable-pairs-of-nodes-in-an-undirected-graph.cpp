class Solution {
public:
    //Approach : DSU (Disjoint Set Union) + Connected Component Size Counting

    //Time Complexity = O((N + E) × α(N)) =>
    /* N = number of nodes
    * E = number of edges
    * DSU operations → approximately O(α(N))
    * Building component-size map → O(N)
    * Traversing components → O(N)
    * Overall → O((N + E) α(N)) ≈ O(N + E)
    */


    //Space Complexity = O(N) =>
    /* parent → O(N)
    * rank → O(N)
    * unordered_map → O(N)
    */

    //Step-1 : Build DSU arrays, functions
    vector<int> parent;
    vector<int> rank;

    int find(int x){ //finds parent

        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) //same component
            return;//skip
        
        //three cases
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }

        else if(rank[x_parent] > rank[y_parent]){
            parent[x_parent] = y_parent;
        }

        else{
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);

        rank.resize(n, 0); //initial rank of each is zero
        
        //Step-2 : A single node is its own parent
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        //Step-3 : make components : using connections in edges
        for(auto& vec : edges){
            int u = vec[0]; //edges[i] = [a, b] => u = index 0, v = index 1
            int v = vec[1];

            Union(u, v);
        }

        //Step-4 : build a components -> size map
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int father = find(i);
            mp[father]++;
        } 

        //Step-5 : traverse in map & count size , calc. result using formula
        long long result = 0;
        long long remaining = n;

        for(auto& it : mp){

            long long size = it.second; //(father -> size) 
            
            result += size * (remaining - size);

            remaining = remaining - size; //update size after each iteration

        }

        //finally return no. of pairs output
        return result;

    }
};