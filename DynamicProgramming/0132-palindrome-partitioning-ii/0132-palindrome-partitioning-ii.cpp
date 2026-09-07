class Solution {
public:
    //Method-2 : Bottom-UP Approach

    //Time Complexity = O(n * n)
    //Space Complexity = O(n * n)
    int minCut(string s) {
        int n = s.length() ;

        //Blue-print code for palindrome related
        
        vector<vector<bool>> t(n, vector<bool>(n,false)) ;
        //t[i][j] = true => s[i....j] palindrome
        //t[i][j] = false => s[i...j] not a palindrome


        //Length = 1 substrings and diagonal elements => 0 cuts required 
        for(int i=0 ; i<n ; i++){
            t[i][i] = true ;
        }

        //Length >= 2 substrings
        for(int L=2 ; L <= n ; L++){
            for(int i=0 ; i+L-1 < n ; i++){
                int j = i+L-1 ;

                if(L == 2){
                    t[i][j] = (s[i] == s[j]) ;
                }

                else{ // L > 2
                    t[i][j] = ( (s[i] == s[j]) && t[i+1][j-1]) ;
                }
            }
        }

        //make dp array
        vector<int>dp(n) ;
        //dp[i] = min cuts required to cut s[0...i] into palindrome
        
        //start filling dp array 
        for(int i=0 ; i<n ; i++){
            if(t[0][i] == true ){  //means s[0...i] is palindrome
                dp[i] = 0 ; //zero cuts required
            }
            else{ //means s[0...i] is not a palindrome
                dp[i] = INT_MAX ;

                for(int k=0 ; k<i ; k++){ //start making cuts
                    if(t[k+1][i] == true){
                        dp[i] = min(dp[i], 1 + dp[k]) ;
                    }
                }
            }

        }

        //return the dp[n-1] => s[0....n-1] is palindrome in how many min cuts 

        return dp[n-1] ;

    }
};