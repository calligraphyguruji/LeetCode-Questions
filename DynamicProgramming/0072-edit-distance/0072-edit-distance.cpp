class Solution {
public:
    //Method-1 : Top-Down Memoization(Dynamic Programming)
    //Time Complexity = O(m * n)
    //Space Complexity = O(m * n)
    int m, n ;
    int dp[501][501] ; //dp table
    int solve(string& s1, string& s2, int m, int n){
        //1.)handle basecases
        if(n == 0 || m == 0){
            return m+n ;
        }

        //2.)check memoization table 
        if(dp[m][n] != -1){
            return dp[m][n] ;         
        }

        //3.) compare curr chars. if equal
        if(s1[m-1] == s2[n-1]){
            return dp[m][n] = solve(s1, s2, m-1, n-1) ;
        }

        //4.) if curr chars. are not equal
        else{
            //three choices : insert, delete, replace
            int insertChar = 1 + solve(s1, s2, m, n-1) ;
            int deleteChar = 1 + solve(s1, s2, m-1, n) ;
            int replaceChar = 1 + solve(s1, s2, m-1, n-1) ;

            //5.) Choose the min 
            return dp[m][n] = min({insertChar, deleteChar, replaceChar}) ;
        }

        //if failed to find ans
        return -1 ;
        
    }
    int minDistance(string s1, string s2) {
        m = s1.length() ;
        n = s2.length() ;

        memset(dp, -1, sizeof(dp)) ; //fill dp table with -1

        //func call to solve
        return solve(s1, s2, m, n) ; //start from i = 0 , j = 0 
    }
};