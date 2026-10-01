class Solution {
public:
    //Optimal Approach : Frequency Counting

    //Time Complexity = O(n) =>
    /* Count frequencies → O(N)
    * Prefix sum → O(100), which is constant
    * Build answer → O(n)
    */

    //Space Complexity = O(n) =>
    /* We create: vector<int> ans;
    * The answer array stores n elements.
    * freq array → O(100), effectively constant
    */

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    
        int n = nums.size();

        vector<int> freq(101, 0);//because the values are limited to 0–100.

        //count the frequency of each number
        for(int num : nums){
            freq[num]++;
        }

        //convert freq into prefix count
        for(int i = 1; i <= 100; i++){
            freq[i] += freq[i-1];
        }

        vector<int> ans; //to store output

        //find how many numbers are smaller
        for(int num : nums){
            
            if(num == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(freq[num-1]);
            }
        }
        
        //finally return the output
        return ans;
    }
};