class Solution {
public:
    int reverseBits(int n) {
        
        int ans = 0;

        for(int i = 0; i < 32; i++){

            int bit = n & 1; // Extract the last bit.

            ans = (ans << 1) | bit; // Make room and append it.

            n >>= 1; // Remove the processed bit.

        }

        return ans;
    }
};