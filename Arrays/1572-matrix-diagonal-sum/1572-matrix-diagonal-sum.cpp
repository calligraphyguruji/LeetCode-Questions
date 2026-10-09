class Solution {
public:
    //Approach : Matrix Traversal (Primary and Secondary Diagonal Sum)

    //Time Complexity = O(m * n) => m = row size, n = column size
    /* Two nested loops are used.
    * First loop goes upto m elements.
    * Second loop goes upto n elements.
    */

    //Space Complexity =  O(1) =>
    /* No extra data structure used to store.
    * Only a few variables are used.
    */

    
    int diagonalSum(vector<vector<int>>& mat) {
        
        int m = mat.size(); //row size
        int n = mat[0].size(); //col size

        int sum = 0;//to store the output
        
        //traverse in the matrix
        for(int i = 0; i < m; i++){
            
            for(int j = 0; j < n; j++){
                
                //primary diagonal
                if(i == j){//check diagonal condition
                    sum += mat[i][j];
                }

                //secondary diagonal
                if(i + j == n-1){
                    sum += mat[i][j];
                }
            }
        }

        //remove duplicate center element for odd-sized matrices
        if(m % 2 != 0){ //odd
            sum -= mat[m/2][n/2];
        }

        //finally return the output
        return sum;
    }
};