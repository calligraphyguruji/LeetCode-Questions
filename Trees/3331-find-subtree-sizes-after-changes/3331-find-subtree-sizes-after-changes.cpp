class Solution {
public:

    vector<vector<int>> adj; // Children in the original tree
    vector<int> resultSize; // Final subtree sizes
    vector<int> last; // Latest node for each letter on the DFS path

    void dfs(int currNode, string& s, vector<int>& parent){

        int letter = s[currNode] - 'a';

        // Save the closest same-letter ancestor before updating the path state.
        int nearestAncestor = last[letter];

        // This node is now the latest node with this letter on the current path.
        last[letter] = currNode;

        // Visit children in the original tree.
        for(int child : adj[currNode]){

            dfs(child, s, parent);
        }

        // Restore the previous path state before exploring another branch.
        last[letter] = nearestAncestor;

        // The root has no parent to update.
        if(currNode == 0){
            return;
        }

        // Keep the original parent if no matching ancestor was found.
        int newParent = parent[currNode];

        // Otherwise, reparent this node to its nearest same-letter ancestor.
        if(nearestAncestor != -1){
           
            newParent = nearestAncestor;
        }

        // Record the new parent and add this completed subtree to it.
        parent[currNode] = newParent;
        resultSize[newParent] += resultSize[currNode];
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
        int n = parent.size();

        // Step 1: Build child lists for the original tree.
        adj.assign(n, {});

        for(int node = 1; node < n; node++){

            adj[parent[node]].push_back(node);
        }

        // Every node starts with a subtree size of 1: itself.
        resultSize.assign(n, 1);

        // No matching letter has been seen on the path yet.
        last.assign(26, -1);

        // Steps 2–5: find new parents during DFS and accumulate subtree sizes.
        dfs(0, s, parent);

        return resultSize;
       
    }
};