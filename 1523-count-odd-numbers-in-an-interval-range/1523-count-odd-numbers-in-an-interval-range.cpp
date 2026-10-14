class Solution {
public:
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