class Solution {
public:

    //Method-1 : Top-Down Approach(Recursion + Memoization)

    // Time Complexity = O(m^3) => m = k + 2 => k = no. of cuts = size of cuts array
    // Space Complexity = O(m^2)
    int dp[103][103] ; //memoization array

    int solve(int l, int r, vector<int>& cuts){
        //base-case : when length < 2 => we can't cut => cause for cutting we need 3 elements => (0, elem, r) ;
        if(r - l < 2){
            return 0 ;
        }

        //check memoization table 
        if(dp[l][r] != -1){
            return dp[l][r] ;
        }

        int result = INT_MAX ;

        //make cuts in between st & end
        for(int idx = l+1 ; idx <= r-1 ; idx++){
            int cost = (cuts[r] - cuts[l]) + solve(l, idx, cuts) + solve(idx, r, cuts) ;
            //solve left part + solve right part

            //update result with each iteration
            result = min(result, cost) ;
        }


        return dp[l][r] = result ;
    }
    int minCost(int n, vector<int>& cuts) {
        //First sort the cuts array
        sort(begin(cuts), end(cuts)) ;

        //add two extra elements in cuts array (0, n)
        cuts.insert(begin(cuts), 0) ;
        cuts.push_back(n) ;

        memset(dp, -1, sizeof(dp)) ; //fill dp table with -1

        //func. call to solve
        return solve(0, cuts.size()-1, cuts) ;
    }
};