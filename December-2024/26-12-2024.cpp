*******************************LEETCODE POTD*************************
*	               T.C = O(N * totalSum)							                * 
*	               							                        * 
*	               S.C = O(N * totalSum)                                           * 
*	                                                                * 
*********************************************************************
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
};

class Solution {
public:
    
    unordered_map<pair<int, int>, int, pair_hash> dp;
    int solve(int index, vector<int>& nums, int target, int currSum, int n)
    {
        if(index >= n)
        {
            return currSum == target ? 1 : 0;
        }
        if(dp.find({currSum, index}) != dp.end())
        {
            return dp[{currSum, index}];
        }
        
        int positive = solve(index+1, nums, target, currSum+nums[index], n);
        int negative = solve(index+1, nums, target, currSum-nums[index], n);

        cout << positive + negative << endl;

        return dp[{currSum, index}] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(0, nums, target, 0, n);
    }
};