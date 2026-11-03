class Solution {
public:
    //Approach : Greedy — increase every element to the maximum.

    //Time Complexity = O(n) =>
    /* Visiting each elem once by loop, so for n elements = O(n)
    */

    //Space Complexity = O(1) =>
    /* Only a few variables are used.
    * No extra data structure used for storage like(array, stack, queue, etc.)
    */


    int minMoves(vector<int>& nums) {
        //1.) Initialize variables
        int n = nums.size();

        int maxElem = *max_element(nums.begin(), nums.end()); //you can also find by using loop and comparing
        
        int moves = 0; //to store count of min moves
        
        // 2. Add the increments needed for each element.
        for(int num : nums){
            
            moves += maxElem - num;
        }
        
        // 3. Return the minimum total moves.
        return moves;

    }
};