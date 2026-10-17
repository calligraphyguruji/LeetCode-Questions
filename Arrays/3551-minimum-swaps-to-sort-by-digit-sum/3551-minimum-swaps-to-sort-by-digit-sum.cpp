class Solution {
public:
    //Approach : Sorting + Cycle detection

    //Time Complexity = O(n logn) => O(n logn) + O(n) + O(n)
    /* 1. Calculate digit sums: Each number has at most 10 digits because nums[i] <= 10^9. Therefore, digitSum() takes O(1) time per number.
    2. Sorting: Sorting n elements takes O(n log n) time. The comparator calculates digit sums in O(1) time.
    3. Create index map: Iterating through nums takes O(n) time on average.
    4. Cycle detection: Each element is visited at most once, taking O(n) time.
    */

    //Space Complexity = O(n) =>
    /* 1. Sorted array: Stores n elements → O(n).
    2. Unordered map: Stores the original index of each element → O(n).
    3. Visited array: Tracks whether each element has been visited → O(n).
    */


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