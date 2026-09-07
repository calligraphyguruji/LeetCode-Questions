class Solution {
public:
    // Method-3: Bit Manipulation
    // Time Complexity = O(1)
    // Space Complexity = O(1)

    bool isPowerOfTwo(int n) {
        //base-case
        if(n <= 0) return false;

        return (n & (n - 1)) == 0; //if n == power of two then binary of n & binary of n-1 gives = 0.
    }
};