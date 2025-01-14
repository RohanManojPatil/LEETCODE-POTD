*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, bool> mp;
        int cnt = 0;
        vector<int> ans;

        for(int i = 0; i<A.size(); i++)
        {
            int x1 = A[i];
            if(mp.find(x1) != mp.end())
            {
                cnt++;
            }
            mp[x1] = true;

            int x2 = B[i];
            if(mp.find(x2) != mp.end())
            {
                cnt++;
            }
            mp[x2] = true;

            ans.push_back(cnt);
        }

        return ans;
    }
};