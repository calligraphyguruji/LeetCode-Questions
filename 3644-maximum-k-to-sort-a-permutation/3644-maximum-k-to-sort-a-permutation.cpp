class Solution {
public:
    //Approach : Bitwise AND of misplaced elements

    //Time Complexity = O(n) =>
    /* Single traversal of the array → O(n).
    * Each comparison and Bitwise AND operation → O(1).
    * Total: O(n).
    */

    //Space Complexity = O(1) =>
    /* Only two extra variables, k and n.
    * No additional arrays or data structures.
    * Total: O(1).
    */
    
    int sortPermutation(vector<int>& nums) {
        
        //1.) Initialize variables
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