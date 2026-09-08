class Solution {
public:
         //Time Complexity = O(m*n)
         //Space Complexity = O(m*n) => for ans vector
         //Auxiliary Space = O(1)
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size() ; //rows
        int n = mat[0].size() ; //cols

        int srow = 0 , scol = 0 ; //startingRow ,startingCol
        int erow = m-1 , ecol = n-1 ;//endingRow, endingCol

        vector<int>ans ; //to store ans and return ans in vector form

        while(srow <= erow && scol <= ecol){
            //top :
            for(int j=scol ; j<= ecol ; j++){
                ans.push_back(mat[srow][j]) ;
            }
            //right : 
            for(int i=srow+1 ; i<= erow ; i++){
                ans.push_back(mat[i][ecol]) ;
            }
            //bottom :
            for(int j=ecol-1 ; j>= scol ; j--){
                if(srow == erow){ //handle edge case 
                    break ; //break when repeating value start
                }
                ans.push_back(mat[erow][j]) ;
            }
            //left : 
            for(int i=erow-1 ; i>= srow+1 ; i--){
                if(scol == ecol){ //handle edge case
                    break ;//break when repeating value start
                }
                ans.push_back(mat[i][scol]) ;
            }

            srow++ ; scol++ ; //increment for next iteration
            erow-- ; ecol-- ; //decrement for next iteration
        }
        return ans ; //return ans vector 
    }
};