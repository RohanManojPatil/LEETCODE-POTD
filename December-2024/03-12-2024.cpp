*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        int spaceIndex = 0; // Pointer for the spaces vector
        string result = ""; // Resultant string

        for (int i = 0; i < n; i++) {
            // Insert a space if the current index matches
            if (spaceIndex < spaces.size() && spaces[spaceIndex] == i) {
                result.push_back(' ');
                spaceIndex++;
            }
            result.push_back(s[i]); // Add the current character
        }

        return result;
    }
};
