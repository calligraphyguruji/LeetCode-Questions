class Solution {
public:
    //Approach : 

    //Time Complexity = O(n) =>
    /* Traverse n elements to calculate sum and minElem → O(n)
    * Calculate minimum moves using the formula → O(1)
    */

    //Space Complexity = O(1) =>
    /* Only a few variables(n, sum, minElem, minMoves) are used.
    * No extra data structures used for storage.
    */


    int minMoves(vector<int>& nums) {
        
        //1.) Initialize variables
        int n = nums.size();
        long long sum = 0; //long long -> preventing integer overflow
        int minElem = nums[0];

        //2.) Traverse the array find sum & minElem
        for(int i = 0; i < n; i++){
            
            sum += nums[i];

            if(nums[i] < minElem){
                
                minElem = nums[i];
            }
        }

        //3.) Calc. min moves
        long long minMoves = sum - n * minElem;//long long -> preventing integer overflow

        //finally return the answer
        return (int)minMoves;//type casting into integer
    }
};