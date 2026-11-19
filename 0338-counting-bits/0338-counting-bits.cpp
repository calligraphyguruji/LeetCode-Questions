class Solution {
public:
    //Approach : Brute Force

    vector<int> countBits(int n) {
        
        vector<int> ans; //to store the output
        
        //1.) Make numbers from 0 to n
        for(int i = 0; i <= n; i++){

            int num = i; // Use a copy to preserve i
            int count = 0; // Reset for each number

            //Repeat until the number becomes zero.
            while(num != 0){
                //Check whether its last binary digit is 1 using remainder by 2.
                //Add that remainder to the count.
                count += num % 2;
                
                num /= 2; //Divide the number by 2, discarding the remainder.
            }
            
            ans.push_back(count);
            
        }

        //Finally return the output
        return ans;

    }
};