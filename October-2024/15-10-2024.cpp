
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    long long minimumSteps(string s) {
        long long i = 0;
        long long j = s.length() - 1;
        long long steps = 0;

        while (i < j) {
            // Move `i` to the first '1' from the left
            while (i < j && s[i] == '0') {
                i++;
            }
            // Move `j` to the first '0' from the right
            while (i < j && s[j] == '1') {
                j--;
            }

            // If valid `i` and `j`, calculate the steps
            if (i < j) {
                steps += (j - i); // Swap positions
                i++;
                j--;
            }
        }

        return steps;
    }
};

