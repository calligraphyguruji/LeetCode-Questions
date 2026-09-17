class Solution {
public:
    //Method-1 : Recursion + Memoization
    
    //Time Complexity = O(n * n) =>
    // in solve i = 0,1,2,3,...n-1 =>states : n + n-1 + n-2 + ... = n(n+1)/2 => O(n*n)
    //Space Complexity = O(n * n) =>
    //1.) dp table = O(n * n)
    //2.) recursion stack = O(n)
    int dp[501][501] ;

    int solve(string& s, int i, int j){
        //base-case
        if(i >= j){ //out of bound
            return 0 ; 
        }

        //check memoization table
        if(dp[i][j] != -1){ //means solved before
            return dp[i][j] ; 
        }

        //check i, jth char.
        if(s[i] == s[j]){ //no insertion needed 
            return dp[i][j] = solve(s, i+1, j-1) ; //move both i, j
        }
        //if i, jth char. are not equal then two choices
        int insert_for_i = solve(s, i, j-1) ;

        int insert_for_j = solve(s, i+1, j) ;

        //return min of both
        return dp[i][j] = 1 + min(insert_for_i, insert_for_j) ;
    }
    int minInsertions(string s) {
        int n = s.length() ;

        memset(dp, -1, sizeof(dp)) ; //fill dp array with -1
        
        return solve(s, 0, n-1) ;

    }
};