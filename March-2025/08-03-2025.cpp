*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int j = 0;
        int whiteCount = 0;
        int n = blocks.size();

        while(j<k)
        {
            whiteCount = blocks[j] == 'W' ? ++whiteCount : whiteCount;
            j++;
        }
        int mini = whiteCount;

        while(j<n)
        {
            whiteCount = blocks[j-k] == 'W' ? --whiteCount : whiteCount;
            whiteCount = blocks[j] == 'W' ? ++whiteCount : whiteCount;
            j++;

            mini = min(mini, whiteCount);
        }

        return mini;
    }
};