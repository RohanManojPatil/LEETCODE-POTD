*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> temp(n + 1, 0); // Using n+1 to avoid bounds checking
        string result = "";

        // Process the shifts
        for (const vector<int>& shift : shifts) {
            int left = shift[0];
            int right = shift[1];
            int direction = shift[2];

            temp[left] += (direction == 1) ? 1 : -1;
            temp[right + 1] += (direction == 1) ? -1 : 1;
        }

        // Accumulate shifts and build the result string
        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += temp[i];
            int shiftValue = (s[i] - 'a' + cumulativeShift) % 26;
            if (shiftValue < 0) shiftValue += 26; // Handle negative shifts
            result.push_back('a' + shiftValue);
        }

        return result;
    }
};
