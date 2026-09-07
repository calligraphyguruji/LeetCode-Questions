class Solution {
public:
    
    int longestCommonSubsequence(string s1, string s2) {
        //Method-2 : Bottom-Up Approach

        int m = s1.length() ;
        int n = s2.length() ;

        //2d Dp array
        vector<vector<int>> t(m+1, vector<int>(n+1)) ;

        //first row will be zero
        for(int row=0 ; row<m+1 ; row++){
            t[row][0] = 0 ;
        }

        //first column will be zero
        for(int col=0 ; col<n+1 ; col++){
            t[0][col] = 0 ;
        }
        
        // Compute LCS length for every prefix of s1 and s2
        for(int i=1 ; i<m+1 ; i++){
            for(int j=1 ; j<n+1; j++){
                if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1] ;
                }
                else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]) ;
                }
            }
        }

        return t[m][n] ;
        
    }
};