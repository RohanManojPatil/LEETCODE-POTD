*******************************LEETCODE POTD*************************
*	               T.C = O(Len1 + Len2)							                * 
*	               							                        * 
*	               S.C = O(26)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Step 1: Build the maximum frequency map for all words in words2
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
                maxFreq[ch - 'a'] = max(maxFreq[ch - 'a'], freq[ch - 'a']);
            }
        }

        // Step 2: Filter words in words1 that satisfy the maximum frequency map
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
