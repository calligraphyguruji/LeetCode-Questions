class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int st = 0, end = n - 1;

        while(st <= end){

            int mid = st + (end - st) / 2;

            // handle edge cases
            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n-1 && nums[n-1] != nums[n-2]) return nums[mid];

            // main logic
            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1])
                return nums[mid];

            if(mid % 2 == 0){ // mid is even
                if(nums[mid] == nums[mid+1]){ 
                    st = mid + 2; // move right
                }
                else{
                    end = mid - 1; // move left
                }
            }
            else{ // mid is odd
                if(nums[mid] == nums[mid-1]){ 
                    st = mid + 1; // move right
                }
                else{
                    end = mid - 1; // move left
                }
            }
        }

        return -1;
    }
};