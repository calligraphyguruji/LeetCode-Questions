class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int m = accounts.size(); //row size
        int n = accounts[0].size(); //column size
        int maxWealth = 0;

        //traverse in the 2d matrix to find the maxWealth
        //maxWealth is the complete row sum of any row
        for(int i = 0; i < m; i++){
            
            int wealth = 0;

            for(int j = 0; j < n; j++){
                wealth += accounts[i][j];
            }

            //update maxWealth
            maxWealth = max(maxWealth, wealth);
        }

        //finally return the output
        return maxWealth;

    }
};