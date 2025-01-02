*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    // Helper function to check if a character is a vowel
    bool valid(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        if (n == 0) return {}; // Edge case: empty input
        
        // Prefix sum to count valid words
        vector<int> prefixSum(n, 0);

        // Populate the prefix sum array
        for (int i = 0; i < n; ++i) {
            char firstChar = words[i][0];
            char lastChar = words[i][words[i].size() - 1];
            prefixSum[i] = (i > 0 ? prefixSum[i - 1] : 0);

            if (valid(firstChar) && valid(lastChar)) {
                prefixSum[i]++;
            }
        }

        // Process each query
        vector<int> ans;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            ans.push_back(prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0));
        }

        return ans;
    }
};
