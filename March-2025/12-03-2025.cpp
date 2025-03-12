*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCount = 0;
        int negCount = 0;

        for(auto num : nums)
        {
            if(num == 0)
            {
                continue;
            }
            else if(num < 0)
            {
                negCount++;
            }
            else
            {
                posCount++;
            }
        }

        return max(posCount, negCount);
    }
};