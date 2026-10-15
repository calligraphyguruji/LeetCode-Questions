class Solution {
public:
    //Method-1 : Top-Down Approach(Recursion + Memoization)
    
    //Time Complexity = O(n)
    //Space Complexity = O(n)
    
    int n ; 
    vector<vector<int>> dp ; //declaration of memoization dp

    int solve(int i, int buy, vector<int>& prices){
       //base-case
       if(i == n){
            return 0 ;
       }

       //check memoization table
       if(dp[i][buy] != -1){
            return dp[i][buy] ;
       }
       
       //check condition and then buy, sell
       int profit = 0 ;
       if(buy){
            int buyNow = -prices[i] + solve(i+1, 0, prices) ;
            int skipNow = 0 + solve(i+1, 1, prices) ;

            profit = max(buyNow, skipNow) ;
       }
       else{ //sell
            int sellNow = prices[i] + solve(i+1, 1, prices) ;
            int skip = 0 + solve(i+1, 0, prices) ;

            profit = max(sellNow, skip) ;
       }
       
       //finally return the total profit
       return dp[i][buy] = profit ;

    }
    int maxProfit(vector<int>& prices) {
        n = prices.size() ;

        dp = vector<vector<int>>(n, vector<int>(2, -1)) ; //fill dp array with -1

        return solve(0, 1, prices) ; //function call to solve
    }
};