class Solution {
public:
    //Approach : Hashing (Using Unordered Sets)

    //Time Complexity = O(1) =>
    /* We traverse exactly 9 × 9 = 81 cells.
    * Each hash set lookup and insertion takes O(1) average time.
    * Since the board size is fixed, the overall time complexity is O(1).
    */

    //Space Complexity = O(1) =>
    /* We maintain 9 sets for rows, 9 for columns, and 9 for sub-boxes.
    * Each set stores at most 9 digits.
    * Since the storage requirement is fixed, the overall space complexity is O(1).
    */

    bool isValidSudoku(vector<vector<char>>& board) {
        
        int m = board.size();//row size
        int n = board[0].size();//column size

        //1.) Initialize 3 unordered_set<char>
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        //2.) traverse sudoku board using two nested loops
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){
                 
                //4.)
                int boxIdx = (i/3)*3 + (j/3);
                
                //3.) Skip empty cells
                if(board[i][j] == '.'){
                    continue;
                }

                //5.) check duplicates
                if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || boxes[boxIdx].count(board[i][j])){
                    return false;
                }

                else{ //6. If not duplicates then store curr digit in sets
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[boxIdx].insert(board[i][j]);
                }
            }
        }

        //finally if no false found
        return true;

    }
};