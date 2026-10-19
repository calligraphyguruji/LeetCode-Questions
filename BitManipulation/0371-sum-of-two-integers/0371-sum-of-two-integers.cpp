class Solution {
public:
    int getSum(int a, int b) {
        
        //if b == 0 stop
        while(b != 0){

            //calc. carry
            unsigned int carry = (unsigned int)(a & b) << 1;

            //calc. sum and assign to a
            a = a ^ b;

            //update b with carry
            b = static_cast<int>(carry);
        }

        //finally return the sum
        return a;
    }
};