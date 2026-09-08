class Solution {
public:
    //Step-1 : Build DSU arrays/ functions
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){

        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
            return;
        
        //three-Cases
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }

        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }

        else{
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        //edge-case
        if(connections.size() < n-1)
            return -1;

        parent.resize(n);
        rank.resize(n, 0); //initially rank of all is zero

        //single nodes are parent itself
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        //traverse in connections and check parent
        int components = n;

        for(auto& vec : connections){
            
            if(find(vec[0]) != find(vec[1])){ //means parents are diff
                Union(vec[0], vec[1]);

                components--;
            }
        }

        //finally return total no. of operations/edges removal required
        return components-1;
    }
};