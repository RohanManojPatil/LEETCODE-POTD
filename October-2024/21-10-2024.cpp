
*******************************LEETCODE POTD*************************
*	               T.C = O(n*2^n)							                * 
*	               							                        * 
*	               S.C = O(n^2)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    unordered_map<string, bool> usedSubstrings; // To track used substrings
    int maxUniqueSplits = INT_MIN; // To store the maximum count of unique substrings

    // Recursive function to explore all possible unique splits
    void findMaxUniqueSplits(int index, int n, const string& s) {
        if (index == n) { // Base case: when the whole string has been processed
            maxUniqueSplits = std::max(maxUniqueSplits, (int)usedSubstrings.size());
            return;
        }

        string currentSubstring = "";
        for (int j = index; j < n; j++) {
            currentSubstring.push_back(s[j]);
            // If the current substring hasn't been used, try adding it
            if (usedSubstrings.find(currentSubstring) == usedSubstrings.end()) {
                usedSubstrings[currentSubstring] = true;
                findMaxUniqueSplits(j + 1, n, s); // Recur for the remaining substring
                usedSubstrings.erase(currentSubstring); // Backtrack
            }
        }
    }

    int maxUniqueSplit(string s) {
        int n = s.length();
        findMaxUniqueSplits(0, n, s); // Start recursive splitting
        return maxUniqueSplits;
    }
};
