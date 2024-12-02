*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(1)                                            * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length();
        int pos = 1, i = 0;

        while(i<n)
        {
            int j = i;
            string temp = "";

            while(true)
            {
                char ch = sentence[j++];
                if(ch == ' ' || j == n+1)
                {
                    break;
                }

                temp.push_back(ch);

                if(temp == searchWord)
                {
                    return pos;
                }
            }

            pos++;
            i = j;
        }

        return -1;
    }
};