*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0, W = 1, n = colors.size();

        for(int i = 1; i<=(n-1)+(k-1); i++)
        {
            if(colors[i%n] != colors[(i-1+n)%n])
            {
                W++;
            }
            else
            {
                W = 1;
            }

            if(W>=k)
            {
                ans++;
            }
        }

        return ans;
    }
};