class Solution {
public:
    //Approach : Brute Force / Nested Loop

    //Time Complexity = O(n²) =>
    /* Outer loop runs n times.
    * For each element, the inner loop may scan up to n elements.
    * break can make it faster in practice, but worst case remains O(n²).
    */

    //Space Complexity = O(n) =>
    /* ans stores n elements → O(n).
    * No other significant extra space.
    */


    vector<int> finalPrices(vector<int>& prices) {
        
        int n = prices.size();

        vector<int> ans(n);//to store the output : final prices
        
        //traverse in the prices array using loop
        for(int i = 0; i < n; i++){

            //initially no discount 
            ans[i] = prices[i];
            
            //check condition for discount
            for(int j = i+1; j < n; j++){
                
                if(prices[j] <= prices[i]){
                
                    ans[i] = prices[i] - prices[j];//store final price after discount
                    break;
                }
            }
            
        }

        //finally return the output
        return ans;
    }
};