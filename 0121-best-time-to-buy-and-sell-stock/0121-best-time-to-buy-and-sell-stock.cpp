class Solution {
public:
    //Method-1 : Greedy + Single Pass (One-Pass) Approach

    //Time Complexity = O(n) => visiting all the n elements in prices.
    //Space Complexity = O(1) => no extra data structures used to store.
    int maxProfit(vector<int>& prices) {
       int maxProfit = 0, bestBuy = prices[0] ;
    
    for(int i=1 ; i<prices.size() ; i++){
        
        if(prices[i] > bestBuy){
            
            maxProfit = max(maxProfit, prices[i]-bestBuy) ;
        }
        
        bestBuy = min(bestBuy,prices[i]) ;
        
        
    }
    
    
    return maxProfit ; 
    }
};