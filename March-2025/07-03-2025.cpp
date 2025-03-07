*******************************LEETCODE POTD*************************
*	               T.C = O(Rlog(log(R)) + R-L)							                * 
*	               							                        * 
*	               S.C = O(R)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right+1, true);
        isPrime[1] = false;
        isPrime[0] = false;
        int minDiff = INT_MAX;
        int first = -1, second = -1, prev = -1;

        for(long long i = 2; i<right+1; i++)
        {
            for(long long j = i; j*i<=right+1; j++)
            {
                isPrime[j*i] = false;
            }
        }

        for(int i = 2; i<=right; i++)
        {
            if(isPrime[i] && i >= left && i <= right)
            {
                if(prev != -1 && i-prev < minDiff)
                {
                    minDiff = i-prev;
                    first = prev;
                    second = i;
                }

                prev = i;
            }
        }

        return {first, second};
    }
};