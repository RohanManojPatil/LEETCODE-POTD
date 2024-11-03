
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool rotateString(string s, string goal) {
        int len1 = s.length();
        int len2 = goal.length();
  
        if(len1 != len2)
        {
            return false;
        }

        for(int i = 0; i<len1; i++)
        {
            if(s[i] == goal[0])
            {
                string firstPart = s.substr(i, len1-i);
                string secondPart = s.substr(0, i);
                string target = firstPart + secondPart;

                if(target == goal)
                {
                    return true;
                }
            }
        }

        return false;
    }
};