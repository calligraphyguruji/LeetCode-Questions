class Solution {
public:
    //Method-2 : Bottoum-Up Approach

    //Time Complexity = O(n)
    //Space Complexity = O(n)

    int numTrees(int n) {
        //make dp array
        vector<int>dp(n+1, 0) ; //initialize with 0

        //base-case :
        dp[0] = dp[1] = 1 ; // for 1 node or 0 node , ans = 1

        //fill remaining 
        // i = no. nodes = n
        for(int i=2 ; i<= n ; i++){
             //choose root for every i
             for(int j=1 ; j<= i ; j++){
                dp[i] += dp[j-1]* dp[i-j] ;
             }
        }

        //return dp[n] = no. of unique BSTs for n nodes
        return dp[n] ;
    }
};