*******************************LEETCODE POTD*************************
*	               T.C = O(N*k)							                * 
*	               							                        * 
*	               S.C = O(N*3)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> result;
    int dp[20001][4];

    Solution() {
        memset(dp, -1, sizeof(dp)); // Correct initialization for dp array
    }

    int helper(vector<int>& prefixSum, int i, int count, int k) {
        if (count == 0) {
            return 0;
        }
        if (i + k - 1 >= prefixSum.size()) { // Check for out-of-bounds access
            return INT_MIN;
        }
        if (dp[i][count] != -1) {
            return dp[i][count];
        }

        int take = prefixSum[i + k - 1] - (i > 0 ? prefixSum[i - 1] : 0) + 
                   helper(prefixSum, i + k, count - 1, k); // Compute sum of subarray
        int not_take = helper(prefixSum, i + 1, count, k);

        return dp[i][count] = max(take, not_take);
    }

    void solve(vector<int>& nums, vector<int>& prefixSum, int i, int count, int k) {
        if (count == 0) {
            return;
        }
        if (i + k - 1 >= nums.size()) { // Check for out-of-bounds access
            return;
        }

        int take_i = prefixSum[i + k - 1] - (i > 0 ? prefixSum[i - 1] : 0) + 
                     helper(prefixSum, i + k, count - 1, k);
        int notTake_i = helper(prefixSum, i + 1, count, k);

        if (take_i >= notTake_i) {
            result.push_back(i);
            solve(nums, prefixSum, i + k, count - 1, k);
        } else {
            solve(nums, prefixSum, i + 1, count, k);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        solve(nums, prefixSum, 0, 3, k);

        return result;
    }
};
