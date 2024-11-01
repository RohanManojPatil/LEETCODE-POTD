
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    string makeFancyString(string s) {
        unordered_map<int, int> presence;
        int n = s.length();
        string ans = "";

        if(n<3)
        {
            return s;
        }

        int j = 0;

        while(j<3)
        {
            int incomingElement = s[j++];
            presence[incomingElement]++;

            if(presence[incomingElement] != 3)
            {
                ans.push_back(incomingElement);
            }
        }

        while(j<n)
        {
            int outgoingElement = s[j-3];
            presence[outgoingElement]--;

            int incomingElement = s[j++];
            presence[incomingElement]++;

            if(presence[incomingElement] != 3)
            {
                ans.push_back(incomingElement);
            }
        }

        return ans;
    }
};