class Solution {
public:
    //Approach : Bit Manipulation — XOR Cancellation

    //Time Complexity = O(n) =>
    /* Traversing every element once : O(n)
    * XOR takes : O(1)
    */

    //Space Complexity = O(1) =>
    /* Only a few variables are created : O(1)
    * No extra data structures are used for storage.(like arrays, stacks, etc.)
    */

    int singleNumber(vector<int>& nums) {
        
        //1.) Initialize a running result to 0.
        int result = 0;//Zero is useful because 0 ^ a = a.

        //2.) Traverse every number once.
        for(int num : nums){

            //3.) Apply XOR between the running result and the current number.
            result ^= num;
        }

        //4.) Return the result 
        return result;

    }
};