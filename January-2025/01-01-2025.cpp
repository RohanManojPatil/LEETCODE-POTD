*******************************LEETCODE POTD*************************
*	               T.C = O(N) + O(N)							                * 
*	               							                        * 
*	               S.C = O(N) + O(N)                                         * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int> zeros(n, 0);
        vector<int> ones(n, 0);
        int maxScore = 0;

        if(s[0] == '0')
        {
            zeros[0] = 1;
        }
        if(s[n-1] == '1')
        {
            ones[n-1] = 1;
        }

        for(int i = 1; i<n; i++)
        {
            zeros[i] = zeros[i-1];
            ones[n-i-1] = ones[n-i];

            if(s[i] == '0')
            {
                zeros[i] = zeros[i-1] + 1;
            }
            if(s[n-i-1] == '1')
            {
                ones[n-i-1] = ones[n-i] + 1;
            }
        }

        for(int i = 1; i<n; i++)
        {
            maxScore = max(maxScore, ones[i] + zeros[i-1]);
        }

        return maxScore;
    }
};