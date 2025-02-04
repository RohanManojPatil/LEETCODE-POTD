*******************************LEETCODE POTD*************************
*	               T.C = O(N^2)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool check(int start, int end, vector<int> &nums)
    {
        for(int i = start; i<end; i++)
        {
            if(nums[i] >= nums[i+1])
            {
                return false;
            }
        }

        return true;
    }
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;

        for(int i = 0; i<n; i++)
        {
            int sum = 0;

            for(int j = i; j<n; j++)
            {
                if(check(i, j, nums))
                {
                    sum += nums[j];
                    maxSum = max(maxSum, sum);
                }
                else
                {
                    break;
                }
            }
        }

        return maxSum;
    }
};