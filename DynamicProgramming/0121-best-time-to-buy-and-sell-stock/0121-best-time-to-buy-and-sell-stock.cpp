class Solution {
public:
    //Approach : Sliding Window / Two Pointers + Greedy

    //Time Complexity = O(n) =>
    /* Initializing pointers takes O(1).
    * The right pointer traverses the array once → O(n).
    * Profit calculation and comparison take O(1) per iteration.
    */

    //Space Complexity = O(1) =>
    /* Only four variables are used: n, left, right, and maxProfit.
    * No additional arrays or data structures are created.
    */


    int maxProfit(vector<int>& prices) {
       
       int n = prices.size();

       //Initialize two pointers
       int left = 0; //buying day
       int right = 1;//selling day

       int maxProfit = 0;

        // Step-2: Traverse using sliding window
        while(right < n){
            
            // Case-1: Profitable transaction
            if(prices[left] < prices[right]){

                int currProfit = prices[right] - prices[left];
                
                maxProfit = max(maxProfit, currProfit);            
 
            }

            //Case-2 : Found a cheaper buying prices
            else{ //prices[left] > prices[right]
                left = right;//because right(buying) is smaller now 
            }

            // Step-3: Move selling pointer forward
            right++;
        }

        // Step-4: Finally Return maximum profit
        return maxProfit;
    }
};