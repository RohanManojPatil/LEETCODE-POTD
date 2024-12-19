*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0;
        int n = arr.size();
        int maxi = arr[0];

        for(int i = 0; i<n; i++)
        {
            maxi = max(maxi, arr[i]);
            if(maxi == i)
            {
                chunks++;
            }
        }

        return chunks;
    }
};