class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        
        //traverse in nums 
        for(int i = 0; i < nums.size(); i++){

            if(i % 10 == nums[i]){ //check condition for smallest index
                return i;
            }
        }
        

        return -1; //if doesn't exist such index
        
    }
};