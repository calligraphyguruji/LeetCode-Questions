class Solution {
public:
    //Approach : Brute Force (Linear Traversal)

    //Time Complexity = O(n) =>
    /* only single loop used which can go upto n in worst case. 
    */


    //Space Complexity = O(1) =>
    /* No extra data structure used for storage.
    * Only a few variables used.
    */


    int countOdds(int low, int high) {
        
        int count = 0;
        
        //traverse from low to high
        for(int i = low; i <= high; i++){
            
            if(i % 2 != 0){ //if odd number found
                count++;
            }
        }

        //finally return the output
        return count;
    }
};