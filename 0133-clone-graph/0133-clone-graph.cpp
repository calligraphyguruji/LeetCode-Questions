/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    //Time Complexity = O(V + E)
    //Space Complexity = O(V + E)



    //map to store node : clone-node
    unordered_map<Node* , Node*> mp ; //global so that don't need to pass in arguments.

    void DFS(Node* node, Node* clone_node){
        //5.)start traversal in neigh one by one
        for(Node* n : node->neighbors){
            //6.) check if neighbor is already cloned
            if(mp.find(n) == mp.end() ){ //clone not present in map
                Node* clone = new Node(n->val) ; //make a new clone
                mp[n] = clone ; //push in map
                clone_node->neighbors.push_back(clone) ; //connect curr clone with new clone
                DFS(n, clone) ; //recursively clone remaining graph
            }
            else{ //if clone already present in map
                clone_node->neighbors.push_back(mp[n]) ;//simply connect with existing clone
            }
        }
    }
    Node* cloneGraph(Node* node) {
        //1.) Handle empty graph
        if(node == NULL){
            return NULL ;
        }

        //2.) Create clone of starting node
        Node* clone_node = new Node(node->val) ;

        //3.) Store original -> clone map
        mp[node] = clone_node ;

        //func. call to DFS
        DFS(node, clone_node) ;


        return clone_node ;//very important to return the clone_node of clone graph.
    }
};