*******************************LEETCODE POTD*************************
*	               T.C = O(N^2)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st;

        for(int i = 0; i<n; i++)
        {
            string temp = words[i];
            for(int j = 0; j<n; j++)
            {
                if(i != j)
                {
                    if(words[j].find(temp) != -1)
                    {
                        st.insert(temp);
                    }
                }
            }
        }

        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};