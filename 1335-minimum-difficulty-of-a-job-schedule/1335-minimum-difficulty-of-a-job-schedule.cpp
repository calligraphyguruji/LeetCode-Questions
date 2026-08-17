class Solution {
public:
    //Method : Top-Down Approach(Recursion + Memoization)
    
    //Time-Complexity = O(n*n * d) => n = number of jobs, d = days
    // There are O(n * d) Dp states
    // for each state, the for loop can run up to O(n) times.


    //Space Complexity = O(n * d) =>
    // Dp table : O(n * d)

    int dp[301][11] ; //memoization table
    int solve(vector<int>& jd, int n, int idx, int d){
        //base-case
        if(d == 1){
            int maxD = jd[idx] ;

            for(int i=idx ; i<n ; i++){
                maxD = max(maxD, jd[i]) ;
            }

            return maxD ;
        }

        //check memoization table
        if(dp[idx][d] != -1){ //means solved before
            return dp[idx][d] ;
        }

        int maxD = jd[idx] ;
        int finalRes = INT_MAX ; //because this should be min so we initialize with just opposite 


        //start with 1 task on one day, then ....
        //atmost finish n-d tasks on single day

        for(int i=idx ; i <= n-d ; i++){
            maxD = max(maxD, jd[i]) ;

            int result = maxD + solve(jd, n, i+1, d-1) ;

            finalRes = min(finalRes, result) ;
        }


        //finally return the min finalRes
        return dp[idx][d] = finalRes ;



    }
    int minDifficulty(vector<int>& jd, int d) {
        
        int n = jd.size() ;

        memset(dp, -1, sizeof(dp)) ;//fill with -1

        //edge-case : if impossible to schedule then return -1
        if(n < d){
            return -1 ;
        }

        else{ //if we can solve then
            return solve(jd, n, 0, d) ;
        }
    }
};
