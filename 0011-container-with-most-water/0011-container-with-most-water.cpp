class Solution {
public:
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