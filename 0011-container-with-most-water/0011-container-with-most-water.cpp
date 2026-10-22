class Solution {
public:
    //Approach : Two pointers
     
    //Time Complexity = O(n) =>
    /* Initialization: O(1) — Initialize left, right, and maxWater.
    * While Loop: O(n) — Both pointers move toward each other, with at most n-1 iterations.
    * Area Calculation: O(1) — Calculating width, height, and area takes constant time.
    * Pointer Movement: O(1) — Either left++ or right-- executes per iteration.
    * Total: O(n)
    */

    //Space Complexity = O(1) =>
    /* Two Pointers: O(1) — Only left and right are used.
    * Extra Variables: O(1) — width, currHeight, currArea, and maxWater.
    * No Extra Data Structures: No additional arrays, vectors, or recursion.
    * Total: O(1) auxiliary space.
    */
    int maxArea(vector<int>& height) {
        
        int n = height.size();

        //Step-1: Initialize two pointers
        int left = 0;
        int right = n-1;

        int maxWater = 0;//to store the output

        //Step-2: Traverse height array using two pointers
        while(left < right){
            
            int width = right - left;//because right index is greater hence width should be positive.
            int currHeight = min(height[left], height[right]);

            int currArea = width * currHeight;

            maxWater = max(maxWater, currArea);//update maxWater

            //Step-7 : move pointer where height is minimum
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }


        //finally return the output
        return maxWater;
    }
};