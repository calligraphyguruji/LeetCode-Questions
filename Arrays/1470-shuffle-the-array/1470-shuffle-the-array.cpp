class Solution {
public:
    //Approach : Array Splitting + Two-Array Traversal

    //Time Complexity = O(N) => O(N) + O(N) + O(N) = O(3N) = O(N)
    /* There are 3 loops, but they run one after another:
    1. First loop → copies N elements into x → O(N)
    2. Second loop → copies N elements into y → O(N)
    3. Third loop → adds 2N elements to ans → O(N)
    */

    //Space Complexity = O(N) => O(N) + O(N) + O(2N )= 4N = O(N)
    /* We create 3 vectors:
    * x → N elements
    * y → N elements
    * ans → 2N elements
    */

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