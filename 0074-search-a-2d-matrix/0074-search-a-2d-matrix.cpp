class Solution {
public:
    //Approach : Binary Search in 2D matrix using Two pointers

    //Time Complexity = O(log(m * n)) =>
    /* Total elements in the matrix = m × n.
    * Binary Search reduces the search space by half in each iteration.
    * Therefore, TC = O(log(m × n)).
    */

    //Space Complexity = O(1) => 
    /* Only a few variables (m, n, start, end, mid, row, col) are used.
    * No extra data structures are created.
    * Therefore, SC = O(1).
    */

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        //Step-1: Initialize two pointers => both pointers are pointing to indices
        int start = 0;
        int end = m * n - 1;


        //Step-2: Traverse in matrix using two pointers
        while(start <= end){
            
            int mid = start + (end - start)/2;//mid index

            //Convert 1D index into 2D
            int row = mid / n;
            int col = mid % n;

            //Compare matrix[row][col] with target

            //Case 1 : if target is equal to curr matrix value
            if(matrix[row][col] == target){
                return true;//found
            }
            
            //Case 2: if target is greater than curr matrix value
            else if(matrix[row][col] < target){
                start = mid+1; //move to right for greater values
            }

            //Case 3: if target is smaller than curr matrix value
            else{ 
                end = mid-1;
            }

        }

        //if target is not found in above search
        return false;

    }
};