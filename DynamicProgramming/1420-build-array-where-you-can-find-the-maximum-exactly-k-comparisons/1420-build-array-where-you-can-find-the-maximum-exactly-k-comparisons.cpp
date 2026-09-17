class Solution {
public:
    //Method-1 : Top-Down Approach(Recursion + Memoization)
    //Time Complexity = O(n * m * m * k)
    //Space Complexity = O(n * m * k)
    int N, M, K ;
    int dp[51][51][101] ;
    int MOD = 1e9 + 7 ;

    int solve(int idx, int searchCost, int maxSoFar){
        //base-case
        if(idx == N){
            if(searchCost == K){
                return 1 ;
            }
            return 0 ;
        }
        
        //check memoization array
        if(dp[idx][searchCost][maxSoFar] != -1){
            return dp[idx][searchCost][maxSoFar] ;
        }

        long long result = 0 ;

        //for loop till m : try options from 1 to m
        for(int i=1 ; i<= M ; i++){
            if(i > maxSoFar){
                result = (result + solve(idx+1, searchCost+1, i)) % MOD ;
            }
            else{
                result = (result + solve(idx+1, searchCost, maxSoFar)) % MOD ;
            }
        }

        //Return the result 
        return dp[idx][searchCost][maxSoFar] = result % MOD ;



    }
    int numOfArrays(int n, int m, int k) {
        N = n ;
        M = m ;
        K = k ;
        
        memset(dp, -1, sizeof(dp)) ; //fill memoization array with -1
        return solve(0, 0, 0) ;
    }
};