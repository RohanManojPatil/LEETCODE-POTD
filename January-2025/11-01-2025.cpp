*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k)
        {
            return false;
        }

        unordered_map<char, int> freq;
        int oddCount = 0;

        for(int i = 0; i<s.length(); i++)
        {
            freq[s[i]]++;
        }

        for(auto &p : freq)
        {
            if(p.second % 2 != 0)
            {
                oddCount++;
            }
        }

        return oddCount <= k;
    }
};