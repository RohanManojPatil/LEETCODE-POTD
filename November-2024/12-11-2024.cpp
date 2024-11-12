
*******************************LEETCODE POTD*************************
*	               T.C = O(N LogN + Q LogN)							                * 
*	               							                        * 
*	               S.C = O(N + N)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        map<int, int> prefixMaximum;
        int n = items.size();
        int maxi = 0;
        vector<int> ans;

        for(int i = 0; i<n; i++)
        {
            int currentPrice = items[i][0];
            maxi = max(maxi, items[i][1]);
            prefixMaximum[currentPrice] = maxi;
        }

        for(int i = 0; i<queries.size(); i++)
        {
            int q = queries[i];
            auto it = prefixMaximum.upper_bound(q);
            if(it != prefixMaximum.begin())
            {
                it--;
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};