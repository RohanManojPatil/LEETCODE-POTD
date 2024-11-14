
*******************************LEETCODE POTD*************************
*	               T.C = O(log max(quantities))						                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool DistributionPossible(int capacity, vector<int>& quantities, int availableStores)
    {
        for(auto &product : quantities)
        {
            availableStores -= (product + capacity - 1) / capacity;
            if(availableStores<0)
            {
                return false;
            }
        }

        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1;
        int end = *max_element(quantities.begin(), quantities.end());
        int result = 0;

        while(start<=end)
        {
            int mid = start + (end - start) / 2;
            if(DistributionPossible(mid, quantities, n))
            {
                result = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return result;
    }
};