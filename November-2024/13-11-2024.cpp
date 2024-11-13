
*******************************LEETCODE POTD*************************
*	               T.C = O(nlogn + nlogn)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long result = 0;

        for(int i = 0; i<n; i++)
        {
            int index = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]) - nums.begin();
            int x = index - 1;

            index = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]) - nums.begin();
            int y = index - 1;

            result += (y - x);
        }

        return result;
    }
};