class Solution {
public:
    //Method-3 : Without Using LCS(Palindrome Find Approach)
    int dp[1001][1001] ;
    int solve(string& s, int i, int j){
        //1.) base cases
        if(i > j) return 0 ;
        if(i == j) return 1 ;
        
        //2.) check memoization table
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        //3.) check curr chars.
        if(s[i] == s[j]){
            return dp[i][j] = 2 + solve(s, i+1, j-1) ;
        }

        //4.) if curr chars. are not equal
        else{
            // two choices and choose max.
            return dp[i][j] = max(solve(s, i+1, j), solve(s, i, j-1)) ;
        }
    }
    int longestPalindromeSubseq(string s) {
        
        memset(dp, -1, sizeof(dp)) ; //fill memoization table with -1

        return solve(s, 0, s.length()-1 ) ;
        
    }
};