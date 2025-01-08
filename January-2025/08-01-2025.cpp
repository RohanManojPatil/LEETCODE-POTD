*******************************LEETCODE POTD*************************
*	               T.C = O(N^2 * M)							                * 
*	               							                        * 
*	               S.C = O(1)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                string str1 = words[i];
                string str2 = words[j];

                if(i != j && str2.find(str1) == 0 && str2.rfind(str1) == str2.length() - str1.length())
                {
                    count++;
                }
            }
        }

        return count;
    }
};