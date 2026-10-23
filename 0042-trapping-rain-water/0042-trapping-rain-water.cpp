class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();

        //Step-1: Initialize two pointers
        int left = 0;
        int right = n-1;
         
        //Step-2: Initialize maximum heights
        int leftMax = 0;
        int rightMax = 0;

        int totalWater = 0;
        
        //Step-3: Traverse the array using two pointers
        while(left < right){
            
            //Case-1: if left bar is smaller
            if(height[left] <= height[right]){

                //update leftMax
                leftMax = max(leftMax, height[left]);

                //Calc. total trapped water
                totalWater += leftMax - height[left];

                //move left pointer
                left++;
            }
            //Case-2: if right bar is smaller
            else{

                //update leftMax
                rightMax = max(rightMax, height[right]);

                //Calc. total trapped water
                totalWater += rightMax - height[right];

                //move right pointer
                right--;
            }
            
        }

        //Finally return the totalWater trapped
        return totalWater;
    }
};