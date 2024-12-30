*******************************LEETCODE POTD*************************
*	               T.C = O(high)							                * 
*	               							                        * 
*	               S.C = O(high)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> dp;
    int zeroCount, oneCount;

    int solve(int index, int low, int high) {
        if (index > high) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        // Recursively calculate for appending '0' and '1'
        int ans = solve(index + zeroCount, low, high) + solve(index + oneCount, low, high);

        // If the current length is within the valid range, count it
        if (index >= low) {
            ans++;
        }

        return dp[index] = ans % 1000000007; // Take modulo to avoid overflow
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        dp.resize(high + 1, -1); // Resize and initialize DP array
        zeroCount = zero;
        oneCount = one;

        return solve(0, low, high);
    }
};
