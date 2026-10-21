class Solution {
public:
    int minOperations(string s) {
        
        //1.) Find length n & Find mn & mx
        int n = s.length();

        int mn = *min_element(s.begin(), s.end());
        int mx = *max_element(s.begin(), s.end());


        //2.) check if s is already sorted : you can also use built-in function :
        /* if(is_sorted(s.begin(), s.end())){
            return 0;
        }
        */
        bool isSorted = true;
        for(int i = 0; i < n-1; i++){
            if(s[i] > s[i+1]){
                isSorted = false;
                break;               
            }
        }
        if(isSorted){
            return 0;
        }

        //3.) check if it's impossible                    
        if(n == 2 ){ 
            return -1;
        }
        
        
        //4.) check if only 1 operation required
        if(s[0] == mn || s[n-1] == mx){
            return 1;
        }

        //5.) check if only 3 operations required
        if(s[0] == mx && s[n-1] == mn){
            // Check whether max and min are unique
            int minCount = count(s.begin(), s.end(), mn);
            int maxCount = count(s.begin(), s.end(), mx);
            
            if(minCount == 1 && maxCount == 1)
                return 3;
        }

        //otherwise : if none of the above condition satisfied then
        return 2;

    }
};