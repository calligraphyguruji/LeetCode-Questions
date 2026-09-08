class Solution {
public:
    //Time Complexity = O(m x n) => for traversing in matrix
    //Space Complexity = O(1) => no extra array, vector used.
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false ;//to mark true when found '0'
        int m = matrix.size() ; //row size
        int n = matrix[0].size() ; //col size

        //set markers in first row and first col
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) firstRow = true ;
                    if(j == 0) firstCol = true ;
                    matrix[0][j] = 0 ; //replace '0' with first element of that row
                    matrix[i][0] = 0 ; //replace '0' with first element of that col
                }
            }
        }

        //Replace inner matrix
        for(int i=1 ; i<m ; i++){
            for(int j=1 ; j<n ; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0 ;
                }//for any element if any of row and col value is '0' then replace it with zero 
            }
        }

        //last remaining first row and first col checks 
        if(firstRow){ //if '0' in firstRow
            for(int j=0 ; j<n ; j++){
                matrix[0][j] = 0 ; //replace all elements of first row with '0'
            }
        }
        if(firstCol){
            for(int i=0 ; i<m ; i++){ //if '0' in firstCol
                matrix[i][0] = 0 ; //replace all elements of first col with '0'
            }
        }       

    }
};