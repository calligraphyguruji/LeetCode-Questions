class Solution {

    //Approach : Greedy + Math

    //Time Complexity = O(n) =>
    /* Visiting each element once, for n elements = O(n) 
    */

    //Space Complexity = O(1) =>
    /* Only a few variables are used.
    * No extra data structures used for storage. like(array, stack, queue, etc.)
    */

    public int minMoves(int[] nums) {
        
        int n = nums.length;

        //1.) Find max element
        int maxElem = nums[0];

        for(int i = 0; i < n; i++){

            if(nums[i] > maxElem){
                maxElem = nums[i];
            }
        }

        //2.) Count moves to make all elements of array equal to maxElem
        int moves = 0;

        for(int i = 0; i < n; i++){
         
            moves += maxElem - nums[i];
        }

        //Finally return the min moves count
        return moves;
    }
}