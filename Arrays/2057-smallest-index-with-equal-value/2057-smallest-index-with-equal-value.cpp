class Solution {
public:
    //Approach : Linear Search

    //Time Complexity = O(n) =>
    /* We traverse the array at most once.
    * which consist upto n elements.
    */


    //Space Complexity = O(1) =>
    /* No extra data structure used for storage.
    * Only a few variables(i) used.
    */


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