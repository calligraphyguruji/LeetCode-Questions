class Solution {
public:
     //Time Complexity = O(9^m) where m = no. of empty cells
     /*Level 1 → 9 choices  
       Level 2 → 9 choices  
            ...  
       Level 81 → 9 choices*/ 
       //total = 9^81 = 9^m

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
        //horizontal check
        for(int j=0 ; j<9 ; j++){
            if(board[row][j] == dig){
                return false ;
            }
        }
        //vertical check
        for(int i=0 ; i<9 ; i++){
            if(board[i][col] == dig){
                return false ;
            }
        }
        //3 x 3 grid check
        int sRow = (row/3)*3 , sCol = (col/3)*3 ;
        for(int i=sRow ; i<=sRow+2 ; i++){
            for(int j=sCol ; j<=sCol+2 ; j++){
                if(board[i][j] == dig)
                    return false ;
            }
        }
        //if not false in all upper conditions
        return true ;//then safe place
    }
    bool helper(vector<vector<char>>& board, int row, int col){
        //base case
        if(row == 9){
            return true ;
        }
        int nextRow = row ;
        int nextCol = col+1 ;
        if(nextCol == 9){
            nextRow = row+1 ;
            nextCol = 0 ;
        }
        //check if place is empty
        if(board[row][col] != '.'){
            return helper(board,nextRow,nextCol) ;
        }
        //place the correct digit if empty place
        for(char dig ='1' ; dig<='9' ; dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig ;
                //call helper for next digit placement
               if(helper(board,nextRow,nextCol)){
                return true ;
               }
               //backtracking
               board[row][col] = '.' ; //empty that place if not correct
            }
        }

        return false ;//if not placed

    }
    void solveSudoku(vector<vector<char>>& board) {
        //function call to helper
        helper(board,0,0) ;
    }
};