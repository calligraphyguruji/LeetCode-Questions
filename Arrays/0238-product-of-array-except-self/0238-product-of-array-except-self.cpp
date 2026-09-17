class Solution {
public:
    //Time Complexity = O(n)
    //Auxiliary Space = O(1) 
    //Space Complexity = O(1)
    //Required Output Array S.C. = O(n )
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
    vector<int> ans(n, 1);
    
    // Prefix into ans
    for(int i = 1; i < n; i++){
        ans[i] = ans[i-1] * nums[i-1];
    }
    
    int suffix = 1;
    
    for(int i = n-2; i >= 0; i--){
        suffix *= nums[i+1];
        ans[i] *= suffix;   // multiply individual element
    }
    
    return ans;   // return vector
     
    }
};