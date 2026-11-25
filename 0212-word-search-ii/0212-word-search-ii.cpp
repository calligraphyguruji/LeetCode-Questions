class Solution {
public:
    //Approach : Trie-Guided DFS with In-Place Backtracking

    //Time Complexity = O(W * L + M * N * 3^L)=>
    /* Trie build: O(W * L), where W = number of words, L = max word length.
     * Grid traversal: M * N starting cells.
     * DFS depth: at most L steps. Branching factor is at most 3 (cannot return to parent cell).
     * Total TC: O(W * L + M * N * 3^L).
    */

    //Space Complexity = O(W * L) =>
    /* Trie storage: O(W * L * 26) nodes in worst case.
     * - Recursion stack: O(L) max recursion depth.
     * - Grid visited state: O(1) auxiliary space (in-place modification using '#').
     * - Total SC: O(W * L) auxiliary space (excluding output array).
    */


    // Trie node structure
    struct TrieNode{
        
        TrieNode* next[26] = {};// Fixed array for 26 lowercase English letters
        string* word{};// Pointer to word in words array (avoids string copy)

    } root ;

    vector<string> ans;
    int m, n;
    
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* curr){
        // Step 4a: Boundary check and visited check
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == '#'){
            return;
        }

        // Step 4b: Check if character exists in Trie branch
        char ch = board[r][c];
        curr = curr->next[ch - 'a'];

        if(curr == NULL){
            return;// Terminate branch immediately if prefix invalid
        }

        // Step 5: Terminal match found; collect word and deduplicate
        if(curr->word){
            ans.push_back(*curr->word);
            curr->word = NULL;// Nullify pointer so same word is not added again
        }

        // Step 6: Mark cell visited in-place
        board[r][c] = '#';

        // Step 7: Recurse into 4 adjacent neighbors (Down, Up, Right, Left)
        dfs(board, r-1, c, curr);
        dfs(board, r+1, c, curr);
        dfs(board, r, c-1, curr);
        dfs(board, r, c+1, curr);


        // Step 8: Backtrack; restore original character
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        //Step 1: Trie Construction
        for(auto& w : words){
            TrieNode* curr = &root;

            for(char ch : w){

                int idx = ch - 'a';

                if(curr->next[idx] == NULL){
                    curr->next[idx] = new TrieNode();
                }

                curr = curr->next[idx];
            }
            curr->word = &w; // Point directly to original word string
        }

        // Step 2: Iterate through every grid cell as potential start
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, i, j, &root);
            }
        }

        //Finally return the output array
        return ans;

    }
};