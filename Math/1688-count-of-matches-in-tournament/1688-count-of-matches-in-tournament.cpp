class Solution {
public:
    int numberOfMatches(int n) {
        
        int matches = 0;
               
        while(n > 1){
            
            //check no. of teams is even
            if(n % 2 == 0){

                matches += n/2;
                n = n/2;
            }

            //check no. of teams is odd
            else{
            
                matches += (n-1)/2;
                n = (n-1)/2 + 1;
            }
            
        }
        
        //finally return the number of matches
        return matches;
    }
};