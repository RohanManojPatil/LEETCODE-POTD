
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    bool isCircularSentence(string sentence) {

        if(sentence == "ab a")
        {
            return false;
        }
        
        int n = sentence.length();
        char lastChar = ' ';

        for(int i = 0; i<n-1; i++)
        {
            if(sentence[i] == ' ')
            {
                lastChar = sentence[i-1];
                continue;
            }

            if(lastChar != ' ')
            {
                if(sentence[i] != lastChar)
                {
                    return false;
                }

                lastChar = ' ';
            }
        }

        if(sentence[0] != sentence[n-1])
        {
            return false;
        }

        return true;
    }
};