*******************************LEETCODE POTD*************************
*	               T.C = O(N*2^N)							                * 
*	               							                        * 
*	               S.C = O(N^2)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<string> ans;
    void solve(char prev, int index, string temp, int n)
    {
        if(index >= n)
        {
            ans.push_back(temp);
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(ch != prev)
            {
                temp.push_back(ch);
                solve(ch, index+1, temp, n);
                temp.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string temp = "";
        solve(' ', 0, temp, n);

        return k>ans.size() ? "" : ans[k-1];
    }
};