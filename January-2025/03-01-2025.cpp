*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        int numOfWays = 0;

        for(int i = 1; i<n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i = 0; i<n-1; i++)
        {
            long long leftSum = prefixSum[i], rightSum;

            if(i == n-2)
            {
                rightSum = nums[n-1];
            }
            else
            {
                rightSum = prefixSum[n-1] - prefixSum[i];
            }
    
            if(leftSum >= rightSum)
            {
                numOfWays++;
            }
        }

        return numOfWays;
    }
};