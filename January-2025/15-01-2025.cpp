*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones = __builtin_popcount(num2); // Count of 1-bits required
        int result = 0;

        // Step 1: Try to set the high bits of num1 in result
        for (int i = 31; i >= 0; --i) {
            if ((num1 & (1 << i)) && ones > 0) {
                result |= (1 << i); // Set the i-th bit
                --ones; // Decrease required count
            }
        }

        // Step 2: Set remaining 1-bits from LSB if needed
        for (int i = 0; i < 32 && ones > 0; ++i) {
            if (!(result & (1 << i))) { // If the i-th bit is not set
                result |= (1 << i); // Set the i-th bit
                --ones; // Decrease required count
            }
        }

        return result;
    }
};
