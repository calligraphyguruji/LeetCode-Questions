/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    //DISCLAIMER : NOT FOR BEGINNERS  

    //Approach : Preorder DFS with Null Markers

    //Time Complexity = O(n)

    //Space Complexity = O(n)

    void encode(TreeNode* root, vector<string>& tokens){

        //2.) Record missing children
        if(root == NULL){
            tokens.push_back("#");
            return;
        }
        
        //Preorder Sequence : Root -> Left -> Right
        //3.) Record current node's value
        tokens.push_back(to_string(root->val));//First Process Root

        //Process Left Subtree
        encode(root->left, tokens);
        
        //Process Right Subtree
        encode(root->right, tokens);
    }

    TreeNode* decode(vector<string>& tokens, int& position){
        // Step 2: Read one token and move the shared position.
        string token = tokens[position++];

        // Step 3: A "#" represents an empty subtree.
        if(token == "#"){
            return NULL;
        }

        // Step 4: Create the node and reconstruct its children.
        TreeNode* root = new TreeNode(stoi(token)); //stoi = used for converting string to integer
        root->left = decode(tokens, position);
        root->right = decode(tokens, position);

        //Step 5 : Return the completed tree
        return root;

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        //1.) Initialize an empty string array tokens
        vector<string> tokens;

        //2-4.) Collect tokens using preorder traversal
        encode(root, tokens);

        //5.) Join tokens using commas
        string result;

        for(string& token : tokens){

            if(!result.empty()){
                
                result += ',';
            }

            result += token;
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // Step 1: Split the string and initialize the position.
        vector<string> tokens;
        stringstream input(data);
        string token;

        while(getline(input, token, ',')){
            
            tokens.push_back(token);
        }
        
        int position = 0;
        
        //Step 2 - 5.) Reconstruct and return the tree
        return decode(tokens, position);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));