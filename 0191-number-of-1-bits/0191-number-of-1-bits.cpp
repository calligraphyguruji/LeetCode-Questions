class Solution {
public: 
    //Approach :Brian Kernighan’s algorithm(Bit Manipulation)

    //Time Complexity = O(b) =>
    /* Let k be the number of set bits in n.
    * Each iteration of n & (n − 1) removes exactly one set bit.
    * Therefore, the loop runs exactly k times: O(k).
    * In the worst case, every binary digit is 1, giving O(log n).
    * For this problem, n has at most 31 bits, so there are at most 31 iterations. With  this fixed limit, TC can also be described as O(1)
    */

    //Space Complexity = O(1) =>
    /* We only use the integer n and a counter.
    * We do not create an array or use recursion.
    * The extra memory stays constant: O(1).
    */

    int hammingWeight(int n) {
        
        //1.) Initialize: Set count = 0 to track removed set bits.
        int count = 0;

        //2.) Check: Continue while n ≠ 0, because a nonzero number still contains a set bit.
        while(n != 0){
            //3.)Remove: Replace n with n & (n − 1).
            n = n & (n-1);//clears the rightmost set bit.
            count++;//4.Count: Increase count by one, since exactly one set bit was removed.
        }

        //5.) Return: When n = 0, return count.
        return count;

    }
};