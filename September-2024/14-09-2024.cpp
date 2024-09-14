class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0;
        int result = 0;
        int streak = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] > maxVal)
            {
                maxVal = nums[i];
                streak = 0;
                result = 0;
            }

            if(maxVal == nums[i])
            {
                streak++;
            }
            else
            {
                streak = 0;
            }

            result = max(result, streak);
        }

        return result;
    }
};