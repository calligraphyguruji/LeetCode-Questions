class Solution {
public:
    //Time Complexity = O(amount x n)
    //Space Complexity = O(amount)
    int coinChange(vector<int>& coins, int amount) {
        //edge case
        if(amount == 0)
            return 0 ;

        //create dp array
        vector<int> dp(amount+1, INT_MAX) ;
        dp[0] = 0 ; //start with 0 

        //fill dp array
        for(int i=1 ; i<=amount ; i++){
            //try every coin
            for(int coin : coins){

                if(coin <= i && dp[i-coin] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i-coin]) ;
                }
            }
         
        }

        //after filling decide answer/result
        if(dp[amount] == INT_MAX)
            return -1 ;

        else{
            return dp[amount] ;
        }     
    }
};