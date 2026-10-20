class Solution {
public:
    //Approach : Two Pointers (Opposite Direction)

    //Time Complexity  = O(n) =>
    /* Two Pointers: Both pointers traverse the array from opposite ends. 
    * Each Iteration: Sum calculation and comparison take O(1) time.
    * Total: At most n - 1 iterations → O(n).
    */

    //Space Complexity = O(1) =>
    /* Two Pointers: start and end require constant space.
    * Other Variables: n and currSum require constant space.
    * Answer Vector: ans stores exactly 2 integers → O(1).
    * Total: O(1).
    */

    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans(2); //size 2 is fixed for two integer indices = [index1, index2]
        
        //Initialize two pointers
        int n = nums.size();

        int start = 0;
        int end = n - 1;

        while(start < end){

            //calc. currSum
            int currSum = nums[start] + nums[end];

            //Case-1: when target is greater
            if(currSum < target){
                start++;//move to right
            }

            //Case-2: when target is lesser
            else if(currSum > target){
                end--; //move to left
            }

            //Case-3 : if currSum == target
            else{
                ans[0] = start+1; //store index1 in ans
                ans[1] = end+1; //store index2 in ans
                break; //because loop will be infinite if not stopped when indices found
            }
        }


        //finally return the output
        return ans;

    }
};