class Solution {
public:
    // Approach: Floyd's Cycle Detection (Slow-Fast Pointers)

    int findDuplicate(vector<int>& nums) {
        
        //Step-1 : Initialize variables
        int hare = nums[0];
        int tortoise = nums[0];

        //Step-2: Detect the cycle
        do{
            tortoise = nums[tortoise]; //move 1 step
            hare = nums[nums[hare]]; //move 2 steps
        }while(tortoise != hare);
        
        //Step-3 : Find the entry point of cycle
        tortoise = nums[0];
        
        //when hare = tortoise loop stops that is the entry point of cycle
        while(tortoise != hare){
            tortoise = nums[tortoise]; //move 1 step
            hare = nums[hare]; //move 1 step
        }
        

        //Step -4 : Duplicate Number(Return the entry point of cycle)
        //either retun tortoise or hare. both indicate the same index
        return hare;
          
    }
};