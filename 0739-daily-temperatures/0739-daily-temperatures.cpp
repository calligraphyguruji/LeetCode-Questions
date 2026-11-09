class Solution {
public:
    //Approach : Monotonic Stack.

    //Time Complexity = O(n) * O(1) = O(n) =>
    /* Initializing the answer array and visiting all n indices takes O(n).
    * Each while iteration takes O(1) and pops one index.
    * Each index is pushed once and popped at most once, so there are at most n pops across the entire scan. That’s amortized O(1) per outer iteration.
    */

    //Space Complexity = O(n) =>
    /* Stack = O(n) auxiliary space. If every temperature is equal, no index gets popped, so the stack holds all n indices.
    * Answer array = O(n) output space. It stores one wait per input temperature.
    * Local variables = O(1) space. Variables such as n, i, and j take a fixed amount of space.
    */

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();

        //1.) Initialize required data structures(array, stack)
        vector<int> ans(n, 0); //to store the output
        stack<int> indices;//empty stack

        //2.) Traverse from left to right
        for(int i = 0; i < n; i++){

            //3.) Compare today with stack top
            //// Resolve earlier days while today's temperature is warmer.
            while(!indices.empty() && temperatures[i] > temperatures[indices.top()]){

                int j = indices.top();
                indices.pop();
                
                ans[j] = i - j;
            }

            //4.) Push today's index
            indices.push(i);
        }

        //5.) Return answer
        return ans;
    }
};