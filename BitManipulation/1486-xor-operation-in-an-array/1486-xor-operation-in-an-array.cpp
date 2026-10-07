class Solution {
public:
    int xorOperation(int n, int start) {

        int ans = 0; //to store the output
        
        vector<int> nums(n);

        //fill n numbers from 0 to n-1
        for(int i = 0; i < n; i++){
            nums[i] = start + 2 * i;
            
            ans = ans ^ nums[i];
            
        }
        
        //finally return the output
        return ans;
        
    }
};