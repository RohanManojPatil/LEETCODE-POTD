*******************************LEETCODE POTD*************************
*	               T.C = O(N^2)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
        {
            return true;
        }

        int n = s2.length();
        string temp = s2;

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                swap(temp[i], temp[j]);

                if(temp == s1)
                {
                    return true;
                }

                swap(temp[i], temp[j]);
            }
        }

        return false;
    }
};