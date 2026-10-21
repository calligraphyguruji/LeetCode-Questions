class Solution {
public:
    //Approach : Sorting + Two Pointers

    //Time Complexity = O(n²) =>
    /* Sorting: sort(nums.begin(), nums.end()) takes O(n log n) time.
    * Outer Loop: Runs at most n - 2 times → O(n).
    * Inner While Loop (Two Pointers): left and right move toward each other, taking at most O(n) time for each fixed i.
    * Skipping Duplicates: Takes O(n) per outer iteration in total, already included in the two-pointer traversal.
    * Total: O(n log n) + O(n × n) = O(n²).
    */

    //Space Complexity = O(log n) Auxiliary Space =>
    /* Two Pointers: left and right require O(1) space.
    * Other Variables: i, n, and sum require O(1) space.
    * Sorting: C++ std::sort() typically uses O(log n) auxiliary stack space.
    * Output Vector: ans can store up to O(n²) unique triplets.
    * Total Auxiliary Space: O(log n) including sorting, but excluding output.
    * Total Space Including Output: O(n²) in the worst case.
    */


    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> ans; //to store the output

        //1.) sort the array first
        sort(nums.begin(), nums.end());

        //2.) traverse in nums from i = 0 to n - 3 and 
        //fix first element nums[i]

        for(int i = 0; i <= n-3; i++){          
            
            //Skip duplicate first elements
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }

            //Now, we need to find two other elements whose sum equals - nums[i].
            int left = i+1;
            int right = n-1;

            while(left < right){
            
                int sum = nums[i] + nums[left] + nums[right];

                //Case-1: if sum > 0 => move to left because we need a smaller sum
                if(sum > 0){
                    right--;
                }

                //Case-2: if sum < 0 => move to right because we need a greater sum
                else if(sum < 0){
                    left++;
                }

                //Case-3: if sum == 0 => return i, left, right in an array
                else{
                    //Store triplet values (not indices)
                    ans.push_back({nums[i], nums[left], nums[right]});

                    //Move both pointers to find next triplets
                    left++;
                    right--;

                    // Skip duplicate values at left
                    while(left < right && nums[left] == nums[left-1]){
                        left++;
                    }

                    // Skip duplicate values at right
                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }

                }
            }

    }

        //finally return the output
        return ans;
    }
};