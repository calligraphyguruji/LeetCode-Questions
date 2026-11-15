class Solution {
public:
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

        // Step 2: Reverse each row to complete clockwise rotation.
        for(auto& row : matrix){
            reverse(row.begin(), row.end());
        }
    }
};