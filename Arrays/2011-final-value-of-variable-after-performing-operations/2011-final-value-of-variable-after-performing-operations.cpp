class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int ans = 0;

        for(int i = 0; i < operations.size(); i++){

            for(int j = 0; j < operations[i].size(); j++){

                if(operations[i][j] == '-'){
                    ans--; //decrement
                    break;
                }
                if(operations[i][j] == '+'){
                    ans++;//increment
                    break;
                }
            }
        }

        //finally return the output
        return ans;
    }
};