*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = pow(grid.size(), 2);
        int totalSum = (n * (n+1)) / 2;
        unordered_set<int> st;
        int currSum = 0;
        vector<int> ans;

        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j<grid[0].size(); j++)
            {
                if(st.find(grid[i][j]) == st.end())
                {
                    currSum += grid[i][j];
                    st.insert(grid[i][j]);
                }
                else
                {
                    ans.push_back(grid[i][j]);
                }
            }
        }

        ans.push_back(totalSum - currSum);

        return ans;
    }
};