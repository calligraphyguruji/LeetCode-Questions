class Solution {
public:
    //Time Complexity = O(n²) + O(nlogn) 
    //Space Complexity = O(n²)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() ;

        vector<vector<int>> ans ; //to store ans triplets
        
        //Step 1 : to sort the data
        sort(nums.begin(), nums.end()) ;

        for(int i=0 ; i<n ; i++){
            //optimization to does not repeat same ans
            if(i > 0 && nums[i] == nums[i-1]){
                continue ; //same i then go to next value
            }
            int j = i+1 , k = n-1 ;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k] ;

                if(sum < 0){
                    j++ ;
                }
                else if(sum > 0){
                    k-- ;
                }
                else { //sum == 0
                    ans.push_back({nums[i],nums[j],nums[k]}) ;
                    j++ ; k-- ;

                    //optimization of j (does not repeat)
                    while(j < k && nums[j] == nums[j-1]){
                        j++ ; //j++ until unique value
                    }
                }
            }
        }

         return ans ;
    }
};