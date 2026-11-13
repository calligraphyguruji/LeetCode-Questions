class Trie {
public:
    
    struct Node{
        
        Node* children[26] = {};// All child pointers start as nullptr.
        bool isEndOfWord = false;
    };
    
    Node* root;

    Trie() {

        root = new Node();
    }
    
    void insert(string word) {

        Node* curr = root;

        for(char ch : word){

            int idx = ch - 'a';// 'a' → 0, 'b' → 1, ..., 'z' → 25

            // Create a node if this char's path does not exist.
            if(curr->children[idx] == NULL){

                curr->children[idx] = new Node();
            }

            //Move curr to the new Node for this char
            curr = curr->children[idx];
        }
        // The complete word ends at this node.
        curr->isEndOfWord = true;
        
    }
    
    bool search(string word) {
        
        Node* curr = root;

        for(char ch : word){

            int idx = ch - 'a';

            // A missing char means the word does not exist.
            if(curr->children[idx] == NULL){

                return false;
            }

            //Move curr to this char
            curr = curr->children[idx];
        }
        // The path must end at a complete inserted word.
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
         Node* curr = root;

        for(char ch : prefix){

            int idx = ch - 'a';

            // A missing char means the word does not exist.
            if(curr->children[idx] == NULL){

                return false;
            }

            //Move curr to this char
            curr = curr->children[idx];
        }
        // Every letter in the prefix was found.
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */