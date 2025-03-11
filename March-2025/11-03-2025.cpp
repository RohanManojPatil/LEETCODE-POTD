*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0, j = 0, n = s.length();
        vector<int> alphaCount(3, 0);
        int count = 0, ans = 0;

        while (j < n) {
            // Expand the window
            alphaCount[s[j] - 'a']++;
            if (alphaCount[s[j] - 'a'] == 1) {
                count++;
            }
            j++;

            // When all three characters are in the window, count valid substrings
            while (count == 3) {
                ans += (n - j + 1);
                
                // Shrink the window
                alphaCount[s[i] - 'a']--;
                if (alphaCount[s[i] - 'a'] == 0) {
                    count--;
                }
                i++;
            }
        }
        return ans;
    }
};
