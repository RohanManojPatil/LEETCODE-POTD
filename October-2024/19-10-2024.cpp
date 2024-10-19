
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    // Helper function to recursively find the K-th bit
    char findKthBit(int n, int k) {
        // Base case: If n is 1, the string is "0", so the first bit is '0'.
        if (n == 1) return '0';
        
        // Calculate the length of the string at level n.
        int length = (1 << n) - 1;  // 2^n - 1
        
        // If k is exactly the middle bit, it is always '1'.
        int mid = length / 2 + 1;
        if (k == mid) return '1';
        
        // If k is in the first half, recursively find the answer in S_(n-1).
        if (k < mid) {
            return findKthBit(n - 1, k);
        }
        
        // If k is in the second half, we find its corresponding position in the first half,
        // and invert the result. The corresponding position is (length - k + 1).
        char bit = findKthBit(n - 1, length - k + 1);
        
        // Invert the bit ('0' becomes '1', and '1' becomes '0').
        return bit == '0' ? '1' : '0';
    }
};
