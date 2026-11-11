class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        //1.) Create an empty stack of indices and set maxArea = 0.
        stack<int> indices;
        int n = heights.size();
        int maxArea = 0;

        //2.) Traverse the histogram
        //this loop will run (n+1) times
        // Because we process n real bars + 1 imaginary bar.
        for(int i = 0; i <= n; i++){ 
            // Imaginary final bar of height 0 finishes pending rectangles.
            int currHeight = (i == n) ? 0 : heights[i];

            // Step 3: Finish taller bars.
            while(!indices.empty() && heights[indices.top()] > currHeight){
                
                int height = heights[indices.top()];
                indices.pop();

                // Step 4: Calculate width and update the maximum area.
                // The rectangle ends at i - 1
                int width = indices.empty() ? i : i - indices.top() - 1;
                
                //Update maxArea 
                maxArea = max(maxArea, height * width);
            }

            // Store the current real bar's index.
            if (i < n) {
                indices.push(i);
            }
        }

        //5.) Return the maximum Area
        return maxArea;

    }
};