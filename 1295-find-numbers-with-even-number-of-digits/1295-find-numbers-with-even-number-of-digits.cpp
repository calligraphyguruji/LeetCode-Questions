class Solution {
public:
    //Approach : Digit Counting Using Repeated Division

    //Time Complexity = O(n * d)
    /*
    * n = number of elements in the array.
    * d = number of digits in each number.
    * For every number, we repeatedly divide by 10
    * to count its digits.
    */


    //Space Complexity = O(1) =>
    /* * Only a few variables are used.
    * No extra data structure is required.
    */

    int findNumbers(vector<int>& nums) {
        
        int ans = 0; //to store the output

        //traverse in nums
        for(int i = 0; i < nums.size(); i++){
            
            int num = nums[i];
            int digits = 0;
            
            //count digits
            while(num > 0){
                num /= 10;
                digits++;
            }
            
            if(digits % 2 == 0){ //if even no. of digits
                ans++;
            }
        }
        
        //finally return the output
        return ans;
    }
};