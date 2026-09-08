class Solution {
public: 
     //Time Complexity = O(n!) => 
     //choices for Queens :
     // i=0 ,n choices
     // i=1, (n-1) choices
     // i=2, (n-2) choices
     // i=3, (n-3) choices
     // ...   .... ......
     // T(n) = n*(n-1)*(n-2)*(n-3)......*3*2*1 = n!
    bool isSafe(vector<string> &board, int row, int col, int n){
        //horizontal check
        for(int j=0 ; j<n ; j++){
            if(board[row][j] == 'Q'){
                return false ;//if any queen is placed at row,j
            }
        }
        //vertical check
        for(int i=0 ; i<n ; i++){
            if(board[i][col] == 'Q'){
                return false ;
            }
        }
        //Diagonal check
        //(i) left diagonal : r-1,c-1 ; r-2,c-2 ....
        for(int i=row, j=col ; i>=0 && j>=0 ; i--, j--){
            if(board[i][j] == 'Q'){
                return false ;
            }
        }
        //(ii) right diagonal : r-1,c+1 ; r-2,c+2 ...
        for(int i=row, j=col ; i>=0 && j<n ; i--, j++){
            if(board[i][j] == 'Q'){
                return false ;
            }
        }

        //if all the checks can't find queen placed
        return true ; //safe place
      
    }
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        //base case
        if(row == n){
            ans.push_back({board}) ;//store in ans
            return ;
        }
        //queens placement
        for(int j=0 ; j<n ; j++){
            if(isSafe(board,row,j,n)){
                board[row][j] = 'Q' ;//place the queen
                nQueens(board,row+1,n,ans) ;//function call for next ans
                //backtracking
                board[row][j] = '.' ; //empty that queen place for next ans

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //initialize board with string of (....),(....) n x n times
        vector<string>board(n,string(n,'.')) ; 
        vector<vector<string>> ans ; //to store ans
        //function call to nQueens
        nQueens(board, 0, n, ans) ;

        return ans ;//very important to return all the possible combinations

    }
};