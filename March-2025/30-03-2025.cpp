*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int j = 0;
        int i = j;
        int n = s.length();
        unordered_map<char, int> lastOccurence;
        vector<int> ans;

        for(int i = 0; i<n; i++)
        {
            char ch = s[i];
            lastOccurence[ch] = i;
        }

        while(i<n)
        {
            int last = lastOccurence[s[i]];

            for(j = i+1; j<=last; j++)
            {
                last = max(last, lastOccurence[s[j]]);
            }

            ans.push_back(j-i);

            i = j;
        }

        return ans;
    }
};