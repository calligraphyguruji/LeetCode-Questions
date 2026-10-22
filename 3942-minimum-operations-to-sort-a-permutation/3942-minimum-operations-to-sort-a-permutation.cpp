class Solution {
public:
    //Approach : Circular Array + Rotation & Reversal

    //Time Complexity = O(n) =>
    /* Finding the position of 0 → O(n)
    * Checking whether the array is sorted → O(n)
    * Checking increasing circular order → O(n)
    * Checking decreasing circular order → O(n)
    * Calculating minimum operations → O(1)
    * Total: O(n) + O(n) + O(n) + O(n) = O(n)
    */

    //Space Complexity = O(1) =>
    /* Variables n, ans, pos → O(1)
    * Boolean variables isSorted, isIncreasing, isDecreasing → O(1)
    * No additional arrays or data structures.
    */

    int minOperations(vector<int>& nums) {
        
        //Step-1:
        int n = nums.size();
        int ans = INT_MAX;
         
        //find postion of 0
        int pos = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                pos = i;
                break;
            }
        }

        //Step-2: Check if array is already sorted : you can also use is_sorted func.
        /* if(is_sorted(nums.begin(), nums.end())){
                return 0;
            }
        */
        bool isSorted = true;
        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                isSorted = false;
                break;
            }
        }
        if(isSorted){
            return 0;
        }

        //Step-3: check if increasing circular order
        bool isIncreasing = true;
        for(int i = 0; i < n; i++){

            if(nums[(i+1) % n] != (nums[i] + 1)%n ){

                isIncreasing = false;
                break;
            }
        }
        if(isIncreasing){
            //calc. min op using either :
            int onlyLeft = pos;
            int twoReversal = n - pos + 2;
            
            //update ans
            ans = min(ans, min(onlyLeft, twoReversal));
        }

        //Step-4: check if decreasing circular order
        bool isDecreasing = true;
        for(int i = 0; i < n; i++){

            if(nums[(i+1) % n] != (nums[i] -1 + n)% n){
                
                isDecreasing = false;
                break;
            }
        }
        if(isDecreasing){
            //calc. min op using either:
            int reverseRot = n - pos;
            int rotReverse = pos + 2;

            //update ans 
            ans = min(ans, min(reverseRot, rotReverse));
        }

        //Step-5 & 6 : return -1 if impossible else answer
        return ans == INT_MAX ? -1 : ans;
    }
};