class Solution {
public:
    //Approach : DFS + Graph(connected components)

    //Time Complexity = O(m * (V + E)) =>
    /* */
    //Space Complexity = O(V + E)
    char dfsFindMin(unordered_map<char, vector<char>>& adj, char curr_ch, vector<int>& visited){
        //mark curr_ch true
        visited[curr_ch - 'a'] = 1;

        char minChar = curr_ch;//assume curr_ch is min

        //traverse all neighs of curr_ch
        for(char& v : adj[curr_ch]){
            if(visited[v - 'a'] == 0){
                minChar = min(minChar, dfsFindMin(adj, v, visited));
            }
        }

        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();


        //1.) Build graph using adjacency list
        unordered_map<char, vector<char>> adj;

        for(int i=0; i<n; i++){
            int u = s1[i];
            int v = s2[i];

            //make undirected graph connections : both directions
            adj[u].push_back(v); //u---->v
            adj[v].push_back(u); //v--->u
        }

        //2.) declare result var
        string result;

        //3.) traverse all m elements in baseStr and perform DFS
        for(int i=0; i<m; i++){
            char ch = baseStr[i];

            vector<int> visited(26, 0);//array for 26 alphabets
            //0 == false
            //1 == true

            char minChar = dfsFindMin(adj, ch, visited);

            result.push_back(minChar);
        }

        //5.) finally return output
        return result;
    }
};