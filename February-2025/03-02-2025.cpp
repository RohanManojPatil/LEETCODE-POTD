*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;

        for(int i = 0; i<n; i++)
        {
            int len = 1;
            for(int j = i; j<n-1; j++)
            {
                if(nums[j] < nums[j+1])
                {
                    len++;
                    maxi = max(maxi, len);
                }
                else
                {
                    break;
                }
            }
        }

        for(int i = 0; i<n; i++)
        {
            int len = 1;
            for(int j = i; j<n-1; j++)
            {
                if(nums[j] > nums[j+1])
                {
                    len++;
                    maxi = max(maxi, len);
                }
                else
                {
                    break;
                }
            }
        }

        return maxi;
    }
};