class Solution {
public: 
    //Approach :Brian Kernighan’s algorithm(Bit Manipulation)

    int hammingWeight(int n) {
        
        //1.) Initialize: Set count = 0 to track removed set bits.
        int count = 0;

        //2.) Check: Continue while n ≠ 0, because a nonzero number still contains a set bit.
        while(n != 0){
            //3.)Remove: Replace n with n & (n − 1).
            n = n & (n-1);
            count++;//4.Count: Increase count by one, since exactly one set bit was removed.
        }

        //5.) Return: When n = 0, return count.
        return count;

    }
};