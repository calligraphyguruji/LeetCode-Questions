class Solution {
public:
    //Method-1 : Bottom-UP Aproach

    //Time Complexity = O(m * n) => O(m * n) + O(m+n) + O(m+n)
    //1.) Dp table : O(m+1 x n+1)
    //2.) Backtracking to build SCS => O(m+n)
    //3.) Reverse the result = O(m+n)

    //Space Complexity = O(m * n) => O(m * n) + O(m+n)
    //1.) Dp table : O(m+1 x n+1)
    //2.) Result string : O(m+n)

    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.length() ;
        int n = s2.length() ;

        vector<vector<int>> dp(m+1, vector<int>(n+1) ) ; //dp table 2D

        //fill dp table
        for(int i=0 ; i<m+1 ; i++){
            for(int j=0 ; j<n+1 ; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = i+j ;
                }
                else if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }
                else{ //s1[i-1] != s2[j-1]
                    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]) ;
                }
            }
        }

        //string to store result
        string result = "" ;
        int i = m, j = n ;
        while(i > 0 && j > 0){
            if(s1[i-1] == s2[j-1]){
                result.push_back(s1[i-1]) ;
                i-- ; j-- ;
            }

            else{
                if(dp[i-1][j] < dp[i][j-1]){
                    result.push_back(s1[i-1]) ;
                    i-- ;
                }
                else{
                    result.push_back(s2[j-1]) ;
                    j-- ;
                }
            }
        }

        //add remaining chars when anyone i or j is out of bound
        while(i > 0){
            result.push_back(s1[i-1]) ;
            i-- ;
        }

        while(j > 0){
            result.push_back(s2[j-1]) ;
            j-- ;
        }

        //we have stored result in reverse so again reverse 
        reverse(begin(result), end(result)) ;

        return result ;
    }
};