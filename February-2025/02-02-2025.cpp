*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool isSorted(int start, int end, vector<int> &nums)
    {
        for(int i = start; i<end; i++)
        {
            if(nums[i] > nums[i+1])
            {
                return false;
            }
        }

        return true;
    }
    bool check(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                return isSorted(0, i, nums) && isSorted(i+1, n-1, nums) && nums[n-1] <= nums[0];
            }
        }

        return true;
    }
};