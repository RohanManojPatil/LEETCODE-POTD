
*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    string compressedString(string word) {
        int n = word.length();
        string ans = "";

        for(int i = 0; i<n; i++)
        {
            char ch = word[i];
            int cnt = 1;
            int j = i+1;

            while(j < n && word[j] == ch && cnt < 9)
            {
                j++;
                cnt++;
            }
            
            if(cnt>9)
            {
                cnt--;
            }
            
            i = j-1;
            ans.push_back(cnt + '0');
            ans.push_back(ch);
        }

        return ans;
    }
};