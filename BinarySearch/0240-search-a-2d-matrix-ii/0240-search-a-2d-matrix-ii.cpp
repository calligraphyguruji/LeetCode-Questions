class Solution {
public: 
    //Time Complexity = O(n+m)
    //Space Complexity = O(1) => no extra array or data structure used
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size() ; //rows
        int n = mat[0].size() ; //cols

        int r = 0 , c = n-1 ;
        
        while( r < m && c >= 0){
            if(target == mat[r][c]){
                return true ;//found
            }
            else if(target < mat[r][c]){
                c-- ; //move to left col
            }
            else{ //target > mat[r][c]
                r++ ; //move to downward row
            }
        }
        //very important condition if not found
        return false ; //if not found above
    }
};