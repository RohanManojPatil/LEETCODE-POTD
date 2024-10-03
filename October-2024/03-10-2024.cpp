
*******************************LEETCODE POTD*************************
*	               T.C = O(n)						                * 
*	               							                        * 
*	               S.C = O(n)                                       * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int n = nums.size(); 
        int curr = 0, sum = 0;

        for(auto it : nums)
        {
            sum = (sum+it)%p;
        }

        int target = sum%p;
        if(target == 0)
        {
            return 0;
        }

        int result = n;
        for(int j = 0; j<n; j++)
        {
            curr = (curr+nums[j])%p;
            int remain = (curr-target+p)%p;

            if(mp.find(remain) != mp.end())
            {
                result = min(result, j-mp[remain]);
            }

            mp[curr] = j; 
        }

        return result == n ? -1 : result;
    }
};