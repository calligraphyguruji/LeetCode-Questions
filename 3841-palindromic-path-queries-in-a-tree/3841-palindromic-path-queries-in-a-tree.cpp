class Solution {
public:
    //DISCLAIMER ! : NOT FOR BEGINNERS

    //Approach : Heavy-Light Decomposition + Segment Tree + Bitmask(XOR)

    //Time Complexity = O(n + q * log²(n)) =>
    /* 1. Build adjacency list: O(n).
    2. Calculate subtree sizes and heavy children: O(n).
    3. Heavy-Light Decomposition: O(n).
    4. Initialize segment tree: O(n\log n) in this implementation because each node is inserted using a point update.
    5. Update operation: O(\log n).
    6. Path query: O(\log^2 n).
    7. Palindrome check: O(1).
    */
 
    //Space Complexity = O(n + q) =>
    /* 1. Adjacency list: O(n).
    2. HLD arrays: O(n).
    3. Segment tree: O(n).
    4. DFS recursion stack: O(n) in the worst case.
    5. Answer array: O(q).
    */

    

    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtreeSize;
    vector<int> segTree;
    int timer = 0;

    //Step-1: Calculate the subtree sizes and heavy child
    void dfs(int u, int p){
        
        parent[u] = p;
        subtreeSize[u] = 1;
        int maxSize = 0;

        for(int v : adj[u]){
            if(v == p) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u);

            subtreeSize[u] += subtreeSize[v];

            if(subtreeSize[v] > maxSize){
                maxSize = subtreeSize[v];
                heavy[u] = v;
            }
        }
    }

    //Step-2: Decompose tree into heavy chains
    void decompose(int u, int h){
        
        head[u] = h;
        pos[u] = timer++;

        if(heavy[u] != -1){
            decompose(heavy[u], h);
        }

        for(int v : adj[u]){
            if(v != parent[u] && v != heavy[u]){
                decompose(v, v);
            }
        }
    }

    //Step-3: Update Segment Tree
    void update(int node, int start, int end, int idx, int val){
        
        if(start == end){
            segTree[node] = val;
            return;
        }
        
        int mid = start + (end - start)/2;

        if(idx <= mid){
            update(2*node, start, mid, idx, val);
        }
        else{
            update(2*node +1, mid+1, end, idx, val);
        }

        segTree[node] = segTree[2*node] ^ segTree[2*node + 1];
    }

    //Step-4: Query XOR over a segment
    int query(int node, int start, int end, int l, int r){
        
        if(r < start || end < l) return 0;

        if(l <= start && end <= r){
            return segTree[node];
        }

        int mid = start + (end - start)/2;

        return query(2* node, start, mid, l, r) ^
                query(2* node +1, mid+1, end, l, r);
    }

    //Step-5: Calculate XOR along the path u --> v
    int pathQuery(int u, int v, int n){
        
        int mask = 0;

        while(head[u] != head[v]){
            if(depth[head[u]] < depth[head[v]]){
                swap(u, v);
            }

            mask ^= query(1, 0, n-1, pos[head[u]], pos[u]);

            u = parent[head[u]];
        }
        
        if(depth[u] > depth[v]){
            swap(u, v);
        }

        mask ^= query(1, 0, n-1, pos[u], pos[v]);

        return mask;
    }
    
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        
        //Step-6: Initialize data structures
        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtreeSize.assign(n, 0);
        segTree.assign(4*n, 0);
        timer = 0;


        //Step-7: Build adjacency list
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            //make connection of undirected graph 
            adj[u].push_back(v); //u--->v
            adj[v].push_back(u); //v--->u
        }

        //Step-8: Apply Heavy-Light Decomposition
        dfs(0, -1);
        decompose(0, 0);

        //Step-9: Initialize segment tree with char bitmasks
        for(int i = 0; i < n; i++){

            int mask = 1 << (s[i] - 'a');
            update(1, 0, n-1, pos[i], mask);
        }

        vector<bool>ans;
        //Step-10: Process queries
        for(string& q : queries){

            stringstream ss(q);
            string type;
            ss >> type;

            if(type == "update"){
                int u;
                char c;
                ss >> u >> c;

                s[u] = c;

                int mask = 1 << (c - 'a');
                update(1, 0, n-1, pos[u], mask);
            }
            else{ //query u v
                int u, v;
                ss >> u >> v;

                int mask =  pathQuery(u, v, n);

                //Step-11: Check palindrome condition
                bool isPalindrome = (mask == 0 || (mask & (mask -1 )) == 0);
                ans.push_back(isPalindrome);
            }
        }

        //Step-12: return the boolean ans array
        return ans;
    }
};