class Solution {
public:
    //Time Complexity = O(n²)
    //Space Complexity = O(n²)
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans ; //vector ans to store a , b
        unordered_set<int> s ;
        int n = grid.size() ;
        int a, b ; 
        int expSum = 0 , actualSum = 0 ;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                actualSum += grid[i][j] ;
                //if repeating element found in grid
                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j] ;
                    ans.push_back(a) ;//push (a) in ans vector
                }
                //if not found 
                s.insert(grid[i][j]) ; 
                //again insert element in set to check
            }
        }

        expSum = (n*n)*(n*n + 1)/2 ;
        b = expSum + a - actualSum ;
        ans.push_back(b) ;//push (b) in ans vector

        return ans ; //return (a,b) ans vector 
    }
};