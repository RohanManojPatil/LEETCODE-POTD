
*******************************LEETCODE POTD*************************
*	               T.C = O(2^N)							                * 
*	               							                        * 
*	               S.C = O(N)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int n;
    int solve(int maxOR, int index, vector<int>& nums, int currOR)
    {
        if(index == n)
        {
            if(maxOR == currOR)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        int incl = solve(maxOR, index+1, nums, currOR|nums[index]);
        int excl = solve(maxOR, index+1, nums, currOR);

        return incl + excl;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        int maxOR = 0;
        for(int i = 0; i<n; i++)
        {
            maxOR |= nums[i];
        }

        return solve(maxOR, 0, nums, 0);
    }
};