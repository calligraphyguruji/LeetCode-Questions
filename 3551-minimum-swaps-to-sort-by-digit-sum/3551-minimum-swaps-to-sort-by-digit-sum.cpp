class Solution {
public:
    //1.) create func. for digit sum
    int digitSum(int num){
        
        int sum = 0;

        while(num > 0){
            int digit = num % 10;
            sum += digit;

            num /= 10;
        }

        return sum;
    }

    bool compare(int a, int b){
        int sumA = digitSum(a);
        int sumB = digitSum(b);
        
        //2.a) smaller digit sum comes first
        if(sumA != sumB){
            return sumA < sumB;
        }
        
        //2.b) if digits are equal
        return a < b; //then smaller no. comes first
    }
    int minSwaps(vector<int>& nums) {
        
        int n = nums.size();

        //2.) create sorted array
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [this](int a, int b) {
            return compare(a, b);
        });

        //3.) Map elements to their correct positions
        unordered_map<int, int> originalIdx;

        for(int i = 0; i < n; i++){
            originalIdx[nums[i]] = i;
        }

        //4.) Detect Cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for(int i = 0; i < n; i++){

            //Skip elements that are visited or already sorted place
            if(visited[i] || sorted[i] == nums[i]){
                visited[i] = true;
                continue;
            }

            int cycleSize = 0;
            int j = i;
            
            //if not visited 
            while(!visited[j]){
                
                visited[j] = true;

                j = originalIdx[sorted[j]];// Find the original position of the target element

                cycleSize++;
            }

            //5. Count swaps
            if(cycleSize > 1){
                swaps += cycleSize - 1;
            }
        }

        //6.) Return the answer
        return swaps;
    }
};