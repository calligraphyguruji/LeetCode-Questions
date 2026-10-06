class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> ans(n); //to store the output

        for(int i = 0; i < n; i++){
            
            int num = i + 1;//current number

            //check divisibility of 3 and 5
            if(num % 3 == 0 && num % 5 == 0){
                ans[i] = "FizzBuzz";
            }

            //if only divisible by 3
            else if(num % 3 == 0){
                ans[i] = "Fizz";
            }

            //if only divisibly by 5
            else if(num % 5 == 0){
                ans[i] = "Buzz";
            }
            
            //if none of the conditions are true
            else{
                ans[i] = to_string(num);
            }
        }

        //finally return the output
        return ans;
        
    }
};