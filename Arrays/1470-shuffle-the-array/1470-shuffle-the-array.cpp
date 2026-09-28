class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        //1.) Define all the necessary arrays
        vector<int> ans; //to store the output array
         
        vector<int> x; //to store x1,x2,x3,x4

        vector<int> y; //to store y1,y2,y3,y4

        //2.) insert all x values till n in x array
        for(int i=0; i < n; i++){
            x.push_back(nums[i]);
        }
        
        //Remember : Since nums have 2*n size
        //3.) insert all remaining values in y array
        for(int i=n; i < 2*n; i++){
            y.push_back(nums[i]);
        }
        
        //4.) Now insert alternate values from x and y in ans array
        for(int i=0; i<n; i++){
            ans.push_back(x[i]);
            ans.push_back(y[i]);
        }

        //5.) finally return the output       
        return ans;
    }
};