class Solution {
public:
    //Approach : Transpose + Reverse Each Row

    //Time Complexity = O(n²) =>
    /* Transpose: We swap n(n − 1) / 2 pairs, which takes O(n²) time.
    * Reverse each row: Each row takes O(n) time. For n rows, this takes O(n²) time.
    * Total: O(n²) + O(n²) = O(n²).
    */

    //Space Complexity = O(1) =>
    /* We modify the original matrix directly.
    * Only a few variables and temporary swap storage are needed.
    * auto& row references each existing row; it does not copy it.
    * No additional matrix or array is created.
    */

    void rotate(vector<vector<int>>& matrix) {
        
        //1.) Initialize
        int n = matrix.size(); //row size

        //2.) Transpose the matrix
        //For each row, visit only columns to the right of the diagonal, where col > row.
        for(int row = 0; row < n; row++){

            for(int col = row + 1; col < n; col++){

                swap(matrix[row][col], matrix[col][row]);
            }           
        }

        // Step 3: Reverse each row to complete clockwise rotation.
        for(auto& row : matrix){
            reverse(row.begin(), row.end());
        }
    }
};