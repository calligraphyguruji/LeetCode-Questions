class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        //1.) Initialize variables
        int n = nums.size();
        long long sum = 0;
        int minElem = nums[0];

        //2.) Traverse the array find sum & minElem
        for(int i = 0; i < n; i++){
            
            sum += nums[i];

            if(nums[i] < minElem){
                
                minElem = nums[i];
            }
        }

        //3.) Calc. min moves
        long long minMoves = sum - n * minElem;

        //finally return the answer
        return (int)minMoves;//type casting into integer
    }
};