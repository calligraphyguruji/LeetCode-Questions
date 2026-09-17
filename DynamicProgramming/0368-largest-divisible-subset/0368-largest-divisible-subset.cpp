class Solution {
public:
    //Method : Bottom-Up Approach
    //Time Complexity = O(n * n) => O(n *logn) + O(n * n)
    // 1.) for sorting : O(n *logn)
    // 2.) for nested loops and traversing : O(n * n)
    // 3.) for reconstructing the answer : O(n)


    //Space Complexity = O(n) => O(3n) = O(n) + O(n) + O(n)
    // 1.) dp array : O(n)
    // 2.) prev_idx array : O(n)
    // 3.) ans array : O(n)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() ;
        
        //1.) sort to reduce no. of comparison
        sort(begin(nums), end(nums)) ; //O(n * logn)

        //2.)create dp, prev_idx array 
        vector<int> dp(n, 1) ;
        vector<int> prev_idx(n, -1) ;

        int last_chosen_idx = 0 ;
        int maxL = 1 ;
        
        // Traverse each element and try to extend the divisible subset
        // ending at every previous index j.
        for(int i=1 ; i<n ; i++){ //O(n * n)
            for(int j=0 ; j<i ; j++){
                //check divisibility
                if(nums[i] % nums[j] == 0){
                    //choose and update dp, prev at i
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        prev_idx[i] = j ;
                    }

                    if(dp[i] > maxL){ //if found greater subset then update
                        maxL = dp[i] ;
                        last_chosen_idx = i ;//remember the idx also
                    }
                }
            }
        }

        //Reconstruct the answer : from backside
        vector<int> ans ; 

        while(last_chosen_idx != -1){ //O(n)
            ans.push_back(nums[last_chosen_idx]) ;

            last_chosen_idx = prev_idx[last_chosen_idx] ;
        }

       //Return the answer vector
       return ans ;
    }
};