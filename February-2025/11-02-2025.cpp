*******************************LEETCODE POTD*************************
*	               T.C = O(N*N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        string temp = "";

        for(int i = 0; i<s.length(); i++)
        {
            temp.push_back(s[i]);
            size_t pos = temp.find(part);

            if(pos != string::npos)
            {
                string str1 = temp.substr(0, pos);
                string str2 = temp.substr(pos+n, temp.length());

                temp = str1 + str2;
            }
        }

        return temp;
    }
};