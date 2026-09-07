class Solution {
public:
    //Method-1 : Recursion + Memoization
    //Time Complexity = O(n * n) => O(n * n) + O(n * logn)
    /* There are two state variables:
    i → current index (0 to n-1)
    prev → previous selected index (-1 to n-1)

So the total number of unique states is approximately: n * (n + 1) = n^2

   => Sorting = O(n * logn) but O(n*n) dominates sorting t.c.
 */
    //Space Complexity = O(n * n) => O(n * n) + O(n)
    /* Dp table = O(n * n)
       Recursion Stack = O(n)

    */
    int n ;
 
    int dp[1001][1001] ;

    int LIS(vector<vector<int>>& pairs, int i, int prev){
        //1.) Handle base-case
        if(i >= n) return 0 ; //if i is out of bound

        //2.) check memoization table
        if(prev != -1 && dp[i][prev] != -1){
            return dp[i][prev] ;
        }

        //3.) choice-1 : take curr element
        int take = 0 ;

        if(prev == -1 || pairs[i][0] > pairs[prev][1]){
            take = 1 + LIS(pairs, i+1, i) ;
        }

        //4.) choice-2 : skip curr element
        int skip = LIS(pairs, i+1, prev) ;

        //5.) store the answer
        if(prev != -1){
            dp[i][prev] = max(take, skip) ;
        }

        //6.) return the max of both
        return max(take, skip) ;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size() ;

        memset(dp, -1, sizeof(dp)) ;
        
        //Sort the pairs 
        sort(begin(pairs), end(pairs)) ;
        return LIS(pairs, 0, -1) ; //function call to LIS
    }
};