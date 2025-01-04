*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, -1);

        // Record the first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }

        int count = 0;

        // Check for each character
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] != -1 && first[c] < last[c]) {
                unordered_set<char> uniqueChars;
                for (int i = first[c] + 1; i < last[c]; i++) {
                    uniqueChars.insert(s[i]);
                }
                count += uniqueChars.size();
            }
        }

        return count;
    }
};
