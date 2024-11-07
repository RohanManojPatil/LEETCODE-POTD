
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    unordered_map<int, int> setBitCount;
    int maximumSetBit = 0;
    void binaryRepresentation(int num)
    {
        for(int i = 31; i>=0; i--)
        {
            if((num&(1<<i)))
            {
                int number = pow(2, i);
                setBitCount[number]++;
                maximumSetBit = max(maximumSetBit, setBitCount[number]);
            }
        }
    }

    int largestCombination(vector<int>& candidates) {
        int n = candidates.size();

        for(int i = 0; i<n; i++)
        {
            binaryRepresentation(candidates[i]);
        }

        return maximumSetBit;
    }
};