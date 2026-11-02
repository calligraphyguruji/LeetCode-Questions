class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        int n = nums.size();

        //1.) Sort the array
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        //2.) Choose a median or target element
        int median = sorted[n/2]; 
        
        //3.) Start the move counter
        long long moves = 0;//used long long to avoid integer overflow
        
        //4.) Visit every element
        for(int elem : nums){

            moves += abs(elem - median);
        }


        //finally return the answer
        return static_cast<int>(moves); //type cast moves into int
    }
};