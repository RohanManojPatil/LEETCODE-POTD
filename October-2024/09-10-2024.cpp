
*******************************LEETCODE POTD*************************
*	               T.C = O(n)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int minAddToMakeValid(string s) {
        // Counters for unmatched parentheses
        int unmatchedOpen = 0, unmatchedClose = 0;

        for (char ch : s) {
            if (ch == '(') {
                // Increment unmatched open parentheses
                unmatchedOpen++;
            } 
            else if (unmatchedOpen > 0) {
                // Match an open parenthesis with this closing one
                unmatchedOpen--;
            } 
            else {
                // No open parenthesis to match, so this is an unmatched close
                unmatchedClose++;
            }
        }

        // The total number of unmatched parentheses that need to be added
        return unmatchedOpen + unmatchedClose;
    }
};
