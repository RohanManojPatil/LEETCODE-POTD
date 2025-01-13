*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int ans = 0;

        for(int i = 0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }

        for(auto & ch : mp)
        {
            if(ch.second%2 == 0)
            {
                ans += 2;
            }
            else
            {
                ans++;
            }    
        }

        return ans;
    }
};