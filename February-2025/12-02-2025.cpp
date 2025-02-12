*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(N*M)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int sumOfDigits(int number)
    {
        int sum = 0;
        while(number > 0)
        {
            int digit = number % 10;
            number = number / 10;
            sum += digit;
        }

        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mp;

        for(int i = 0; i<nums.size(); i++)
        {
            int sum = sumOfDigits(nums[i]);
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = nums[i];
            }
            else
            {
                int temp = nums[i] + mp[sum];
                ans = max(ans, temp);
                if(nums[i] > mp[sum])
                {
                    mp[sum] = nums[i];
                }
            }
        }

        return ans;
    }
};