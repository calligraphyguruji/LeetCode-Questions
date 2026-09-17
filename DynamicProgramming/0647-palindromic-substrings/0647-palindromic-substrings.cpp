class Solution {
public:
    //Method-2 : Recursion + Memoizatin(Top-Down Approach) 

    int dp[1001][1001] ; //memoization table => given max size of string = 1000
    bool check(string& s, int i, int j){
        //base-case
        if(i > j) return true ; //out of bound
        
        //check memoization table 
        if(dp[i][j] != -1){ //means solved
            return dp[i][j] ; 
        }

        if(s[i] == s[j]){
            return dp[i][j] = check(s, i+1, j-1) ;
        }

        return dp[i][j] = false ; //if not found true in above checks then false
    }
    int countSubstrings(string s) {
        int n = s.length() ;

        memset(dp, -1, sizeof(dp)) ; //fill memoization table with -1

        //dp[i][j] == -1 => means (not solved yet)
        //dp[i][j] == 0 => false
        //dp[i][j] == 1 => true

        int count = 0 ; //counts no. of substrings

        for(int i=0 ; i<n ; i++){
            for(int j = i ; j<n ; j++){
                if(check(s, i, j)){
                    count++ ;
                }
            }
        }

        return count ;// return no. of substrings
    }
};