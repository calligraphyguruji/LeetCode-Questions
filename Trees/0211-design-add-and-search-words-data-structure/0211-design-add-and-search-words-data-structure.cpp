class WordDictionary {
public:

    struct TrieNode {
        TrieNode* children[26] = {};// All child pointers start as nullptr.
        bool isEnd = false;
    };

    TrieNode* root;

    WordDictionary() {
        // Create the starting node of the trie.
        root = new TrieNode();
    }

    bool dfs(string& word, int idx, TrieNode* curr){

        // All pattern characters have been matched.
        // The current node must also end a saved word.
        if(idx == word.size()){

            return curr->isEnd;
        }

        char ch = word[idx];

        if(ch == '.'){

            // A dot matches exactly one letter.
            // Try every existing child with the remaining pattern.
            for(TrieNode* child : curr->children){

                if(child != NULL && dfs(word, idx+1, child) ){
                    return true;
                }
            }

            // None of the possible letters produced a match.
            return false;
        }

        int letter = ch - 'a';

        // An ordinary letter must have a matching child.
        if(curr->children[letter] == NULL){
            return false;
        }

        // Match the remaining pattern from that child.
        return dfs(word, idx+1, curr->children[letter]);

    }
    
    void addWord(string word) {
        
        TrieNode* curr = root;

        for(char ch : word){

            int idx = ch - 'a';

            // Create a node only when this prefix does not exist.
            if(curr->children[idx] == NULL){

                curr->children[idx] = new TrieNode();
            }

            //Move curr to the new Node for this char
            curr = curr->children[idx];
        }
        // The complete word ends at this node.
        curr->isEnd = true;
    }
    
    bool search(string word) {
        
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */