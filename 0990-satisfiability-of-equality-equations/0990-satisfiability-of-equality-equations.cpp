class Solution {
public:
    //Approach : DSU / Union-Find — Equality Constraint + Contradiction Detection

    //Time Complexity = O(n) =>
    /* N = number of equations
    * α = inverse Ackermann function, practically constant.
    */


    //Space Complexity = O(26) = O(1) =>
    /* parent[26] 
    * rank[26]
    */


    //Step-1 : Make all the DSU related functions, vectors.
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x)
            return x;

        else{
            return parent[x] = find(parent[x]);
        }
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent)
            return;

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
    bool equationsPossible(vector<string>& equations) {

        //Step-2
        parent.resize(26);
        rank.resize(26, 0); //initial rank of each is zero

        //single nodes are parent itself
        for(int i=0; i<26; i++){
            parent[i] = i;
        }

        //Step-2(a): traverse in equations & take Union of all the '=' variables
        for(string& s : equations){
            if(s[1] == '='){
                Union(s[0]-'a', s[3]-'a');//s[0] = first var, s[3] = second var
            }
        }

        //Step-2(b): traverse in equations & find parent of '!=' variables
        for(string& s : equations){
            if(s[1] == '!'){
                int first = s[0];
                int second = s[3];

                int parentFirst = find(first-'a');
                int parentSecond = find(second-'a');


                //Step-2(c) : check if != has same parent then false
                if(parentFirst == parentSecond)
                    return false;
            }
        }

        //if in above no false returned then
        return true;
    }
};