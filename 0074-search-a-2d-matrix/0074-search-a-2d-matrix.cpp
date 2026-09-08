class Solution {
public:
    bool searchInRow(vector<vector<int>>&mat,int target,int row){
        int n = mat[0].size() ; //cols
        int st = 0 , end = n-1 ;

        while(st <= end){
            int mid = st + (end-st)/2 ;
            //check
            if(target > mat[row][mid]){
                //move right
                st = mid+1 ;
            }
            else if(target < mat[row][mid]){
                //move right
                end = mid-1 ;
            }
            else{ //target == mat[row][mid]
                return true ; //found
            }
        }

        return false ; //not found after checking

    }
    //Time Complexity = O(log(m*n)) = O(logm + logn)
    //Space Complexity = O(1) => because no extra array or something
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        //Step 1 : Binary Search on total rows(select correct row)
        int m = mat.size() ; //rows
        int n = mat[0].size() ; //cols
        
        int startRow = 0, endRow = m-1 ;

        while(startRow <= endRow){
            int midRow = startRow + (endRow-startRow)/2 ;

            //check for target
            if(target >= mat[midRow][0] && target <= mat[midRow][n-1]){
                //found correct row
                //Step 2 : Binary Search on this row
                return searchInRow(mat, target, midRow) ;
            }
            else if(target > mat[midRow][n-1]){
                //move downward
                startRow = midRow + 1 ;
            }
            else{ //target <= mat[midRow][0]
                //move upward
                endRow = midRow-1 ;
            }
        }
        //very important condition
        return false ; //if not found then 
    }
};