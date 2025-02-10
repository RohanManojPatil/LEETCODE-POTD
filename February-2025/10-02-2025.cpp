*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    string clearDigits(string s) {
        vector<int> digit;
        vector<int> character;

        // Collect indices of digits and characters
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                digit.push_back(i);
            } else {
                character.push_back(i);
            }
        }

        // Removing characters for each digit
        for (int i = 0; i < digit.size(); i++) {
            for (int j = character.size() - 1; j >= 0; j--) {
                if (character[j] != -1 && character[j] < digit[i]) {
                    character[j] = -1;
                    break;
                }
            }
        }

        // Construct the final string
        string ans = "";
        for (int i = 0; i < character.size(); i++) {
            if (character[i] != -1) {
                ans.push_back(s[character[i]]);
            }
        }

        return ans;
    }
};
