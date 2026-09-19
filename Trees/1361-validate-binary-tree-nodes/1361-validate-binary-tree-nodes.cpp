class Solution {
public:
       
    //5.) perform dfs
    void dfs(int node, vector<bool>& visited, vector<int>& leftChild, vector<int>& rightChild){
        //base-case
        if(node == -1 || visited[node]){
            return;
        }

        visited[node] = true; //mark current node visited
        
        //left
        dfs(leftChild[node], visited, leftChild, rightChild);
        
        //right
        dfs(rightChild[node], visited, leftChild, rightChild);

    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
         
        //1.)
        vector<int> parent(n, 0);
        
        vector<bool> visited(n, false);

        //2.) traverse in leftChild, rightChild and store parents
        for(int i=0; i<n; i++){

            if(leftChild[i] != -1){
                parent[leftChild[i]]++;
            }
            if(rightChild[i] != -1){
                parent[rightChild[i]]++;
            }

        }
         
        int root = -1;
        for(int i=0; i<n; i++){
            //3.) check if more than one parent
            if(parent[i] > 1){
                return false;
            }

            //4.) find the root node
            if(parent[i] == 0){
                if(root != -1){
                    return false;
                }
                root = i;
            }
        }

        //if no root
        if(root == -1){
            return false;
        }

        //func. call to dfs
        dfs(root, visited, leftChild, rightChild);


        //6.) check if a node is visited again
        int count = 0;

        for(int i=0; i<n; i++){
            if(visited[i]){
                count++;
            }
        }

        //7.) if(count == n) return true; else{ return false;}
        return count == n;        

    }
};