class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        
        //1.) 
        int k = -1;
        int n = nums.size();

        //2.) traverse the nums array
        for(int i = 0; i < n; i++){

            if(nums[i] != i){//3.) find misplaced elem
                
                //4.) calc. misplaced elements
                if(k == -1){
                    k = nums[i];
                }
                else{
                    k &= nums[i];
                }
            }
        }
       

        //5.) Return the answer
        return k == -1 ? 0 : k;       
    }
};