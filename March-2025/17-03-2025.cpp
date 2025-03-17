*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int oddPairCount = 0;
        unordered_map<int, int> mp;

        for(auto num : nums)
        {
            mp[num]++;

            if(mp[num]&1)
            {
                oddPairCount++;
            }
            else
            {
                oddPairCount--;
            }
        }

        return oddPairCount == 0 ? true : false;
    }
};