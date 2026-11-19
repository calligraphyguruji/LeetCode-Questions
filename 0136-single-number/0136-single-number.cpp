class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        //1.) Initialize a running result to 0.
        int result = 0;

        //2.) Traverse every number once.
        for(int num : nums){

            //3.) Apply XOR between the running result and the current number.
            result ^= num;
        }

        //4.) Return the result 
        return result;

    }
};