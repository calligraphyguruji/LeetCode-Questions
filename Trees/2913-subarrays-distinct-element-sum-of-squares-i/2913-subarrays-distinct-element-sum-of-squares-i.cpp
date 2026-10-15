class Solution {
public:
    int sumCounts(vector<int>& nums) {
        
        int n = nums.size();

        int ans = 0; //to store the output

        
        for(int i = 0; i < n; i++){
           
           unordered_set<int> set; //to check distinct values

           for(int j = i; j < n; j++){

                set.insert(nums[j]); //insert the current element
                int distinct = set.size(); //count distinct values
                ans += distinct * distinct; //add the square
           } 
        }


        return ans;
    }
};