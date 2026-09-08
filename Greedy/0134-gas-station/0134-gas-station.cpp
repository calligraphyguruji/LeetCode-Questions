class Solution {
public:
    //Time Complexity = O(n) => cause only once traversing using loop gas array (n elements)
    //Space Complexity = O(1) => no extra data structure(array, stack, queue, map) used.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0 , totalCost = 0 ;


        //Case :  if totalGas > totalCost then possible ans
        int start = 0 , currGas = 0 ;
        
        for(int i=0 ; i<gas.size() ; i++){
            totalGas += gas[i] ;
            totalCost += cost[i] ;

            currGas += (gas[i] - cost[i]) ;

            if(currGas < 0){
                start = i+1 ;
                currGas = 0 ;
            }
        }
        //Case if (totalGas < totalCost) then ans -1
        //else ans = start
        return totalGas < totalCost ? -1 : start ; //cause start is ans
    }
};