class Solution {
public:
    //Method-1 : Top-Down Approach (Recursion + Memoization )
    
    //Time Complexity = O(m * n)
    //Space Complexity = O(m * n)
    int m , n ;
    int MOD = 1e9 + 7 ; //10^9 + 7

    typedef long long ll ;
    
    //Memoization 2d vector of pairs
    vector<vector<pair<ll, ll>>> dp ;

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid){
        //base-case
        if(i == m-1 && j == n-1){
            return {grid[i][j], grid[i][j]} ;
        }

        ll maxVal = LLONG_MIN ;
        ll minVal = LLONG_MAX ;
        
        //check memoization 2d vector if solved before 
        if(dp[i][j] != make_pair(LLONG_MIN, LLONG_MAX) ){ //means solved before
            return dp[i][j] ;//don't solve again just return that solution
        }
        //check in Down
        if(i+1 < m){
            auto [downMax, downMin] = solve(i+1, j, grid) ;

            maxVal = max( {maxVal, grid[i][j]*downMax, grid[i][j]*downMin} ) ;
            minVal = min( {minVal, grid[i][j]*downMax, grid[i][j]*downMin} ) ;
        }

        //check for right
        if(j+1 < n){
            auto [rightMax, rightMin] = solve(i, j+1, grid) ;

            maxVal = max( {maxVal, grid[i][j]*rightMax, grid[i][j]*rightMin} ) ;
            minVal = min( {minVal, grid[i][j]*rightMax, grid[i][j]*rightMin} ) ;
        }
        
        //return the pair {maxVal, minVal} 

        return dp[i][j] = {maxVal, minVal} ;
    }
    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size() ;
        n = grid[0].size() ;

        //initialization of 2d memoization vector of pairs
        dp = vector<vector<pair<ll, ll>>>(m, vector<pair<ll, ll>>(n, {LLONG_MIN, LLONG_MAX} )) ; //LLONG_MIN = maxVal, LLONG_MIN = minVal ;

        //func. call to solve
        auto [maxProd, minProd] = solve(0, 0, grid) ;

        if(maxProd < 0){
            return -1 ;
        }
        else{
            return maxProd % MOD ;
        }
    }
};