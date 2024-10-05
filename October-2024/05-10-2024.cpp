
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();

        // If s1 is longer than s2, s1 cannot be a permutation of any substring of s2
        if (len1 > len2) {
            return false;
        }

        // Frequency vectors for characters in s1 and the current window of s2
        vector<int> patternFreq(26, 0);
        vector<int> windowFreq(26, 0);
        int uniqueChars = 0, matchingChars = 0;

        // Count the frequency of characters in s1
        for (int i = 0; i < len1; i++) {
            int index = s1[i] - 'a';
            patternFreq[index]++;
            if (patternFreq[index] == 1) {  // Count unique characters in s1
                uniqueChars++;
            }
        }

        // Check the first window of length len1 in s2
        for (int i = 0; i < len1; i++) {
            int index = s2[i] - 'a';
            windowFreq[index]++;
            if (windowFreq[index] == patternFreq[index]) {
                matchingChars++;
            }
        }

        // If the first window matches, return true
        if (matchingChars == uniqueChars) {
            return true;
        }

        // Slide the window over the remaining part of s2
        for (int i = len1; i < len2; i++) {
            // Remove the character going out of the window
            int outgoingIndex = s2[i - len1] - 'a';
            if (windowFreq[outgoingIndex] == patternFreq[outgoingIndex]) {
                matchingChars--;
            }
            windowFreq[outgoingIndex]--;

            // Add the new character coming into the window
            int incomingIndex = s2[i] - 'a';
            windowFreq[incomingIndex]++;
            if (windowFreq[incomingIndex] == patternFreq[incomingIndex]) {
                matchingChars++;
            }

            // If at any point the window matches, return true
            if (matchingChars == uniqueChars) {
                return true;
            }
        }

        // If no matching window is found, return false
        return false;
    }
};
