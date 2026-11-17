class Solution {
public:
    // ! DISCLAIMER : BEGINNERS PLEASE STAY AWAY
    
    //Approach : 

    //Time Complexity = =>
    /* 
    */

    //Space Complexity = =>
    /* 
    */


    int minimumChanges(string s, int k) {
        
        int n = s.size();

        const int INF = 1e9;

        //1.) Precompute all proper divisors for each length.
        // Start at 2*d because d must be smaller than the length.
        vector<vector<int>> divisors(n+1);

        for(int d = 1; d <= n / 2; d++){

            for(int len = 2*d; len <= n; len += d){

                divisors[len].push_back(d);
            }
        }

        //2.) Compute the minimum conversion cost of every substring.
        // cost[l][r] = changes needed to make s[l...r] a semi-palindrome.
        vector<vector<int>> cost(n, vector<int>(n, INF));

        for(int len = 2; len <= n; len++){

            for(int l = 0; l + len <= n; l++){

                int r = l + len - 1;

                // Try every valid divisor for this substring's length.
                for(int d : divisors[len]){

                    int changes = 0;

                    // Each offset identifies one group of characters
                    // whose positions are d indices apart.

                    for(int offset = 0; offset < d; offset++){

                        int left = l + offset;
                        int right = left + (len / d - 1) * d;

                        // Make this group palindromic by fixing
                        // each mismatched mirrored pair.
                        while(left < right){

                            if(s[left] != s[right]){
                                
                                changes++;
                            }

                            left += d;
                            right -= d;
                        }
                    }

                    cost[l][r] = min(cost[l][r], changes);

                }
            }
        }

        //3.) Initialize partition DP.
        // dp[p][i] = minimum changes to split the first i characters
        // into exactly p pieces, each of length at least 2.
        vector<vector<int>> dp(k+1, vector<int>(n+1, INF));

        dp[0][0] = 0;

        //4.) Try every valid starting position of the last piece.
        for(int p = 1; p <= k; p++){

            for(int i = 2 * p; i <= n; i++){
                // Earlier pieces need at least 2*(p-1) characters.
                // The last piece s[j...i-1] needs at least 2.
                for(int j = 2 *(p -1); j <= i - 2; j++){

                    if(dp[p-1][j] == INF){
                        
                        continue;
                    }

                    dp[p][i] = min(dp[p][i], dp[p-1][j] + cost[j][i-1]);
                }
            }
        }

        //5.) Return the cost for the entire string in exactly k pieces.
        return dp[k][n];

    }
};