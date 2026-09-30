class Solution {
public:
    //Approach :  Find Maximum + Linear Traversal

    //Time Complexity = O(n) =>
    /* There are 2 loops:
    1. First loop finds the maximum:
        * Runs n times → O(n)
    2. Second loop checks each kid:
        * Runs n times → O(n)
    */

    //Space Complexity = O(n) =>
    /* We create a boolean result array.
    * It stores n boolean values.
    */

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();

        vector<bool> result(n, false); //to store the output array

        //keep a max to check if currrent is greatest
        int maxCandies = candies[0];
        
        //find the max no. of candies
        for(int i = 0; i < n; i++){
            if(candies[i] > maxCandies){
                maxCandies = candies[i];
            }
        }

        //traverse in the candies 
        for(int i = 0; i < n; i++){
            
            //and give extraCandies to each kid one by one
            //check if current kid has greatest candies
            if(candies[i] + extraCandies >= maxCandies){
                result[i] = true;
            }
            else{
                result[i] = false;
            }
        }
        
        //finally return the output
        return result;

    }
};