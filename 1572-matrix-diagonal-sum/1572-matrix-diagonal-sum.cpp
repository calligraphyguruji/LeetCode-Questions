class Solution {
public:
    //Approach : Direct Diagonal Traversal

    //Time Complexity = O(n) =>
    /* A single loop traverses the matrix diagonals which goes upto n elments.
    * Each iteration accesses two diagonal elements.
    */

    //Space Complexity =  O(1) =>
    /* No extra data structure used to store.
    * Only a few variables are used.
    */


    int diagonalSum(vector<vector<int>>& mat) {
        
        int n = mat.size(); //row size

        int sum = 0;//to store the output
        
        //traverse in the matrix row wise
        for(int i = 0; i < n; i++){           
                
            //primary diagonal
            sum += mat[i][i];

            //secondary diagonal            
            sum += mat[i][n - 1 - i];
            
        }

        //remove duplicate center element for odd-sized matrices
        if(n % 2 != 0){ //odd
            sum -= mat[n/2][n/2];
        }

        //finally return the output
        return sum;
    }
};