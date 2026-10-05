class Solution {
public:
    //Approach : Brute Force(Nested Loop)

    //Time Complexity = O(N²) =>
    /*Outer loop → N
    * Inner loop → up to N
    * Therefore → N × N = O(N²)
    */

    //Space Complexity = O(1) =>
    /* only countPairs and loop variables are used.
    * No extra data structures are used.
    */


    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();

        int countPairs = 0;//to store the output

        //traverse in nums
        for(int i = 0; i < n; i++){

            for(int j = i+1; j < n; j++){ //i < j because j = i+1
                
                if(nums[i] == nums[j]){ //check condition
                    countPairs++;
                }
            }
        }


        //return output
        return countPairs;


    }
};