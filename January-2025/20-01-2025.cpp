*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(N*M)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, pair<int, int>> cordinates;
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                cordinates[mat[i][j]] = {i, j};
            }
        }

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        for(int i = 0; i<arr.size(); i++)
        {
            int x = cordinates[arr[i]].first;
            int y = cordinates[arr[i]].second;

            row[x]++;
            col[y]++;

            if(row[x] == m || col[y] == n)
            {
                return i;
            }
        }

        return arr.size()-1;
    }
};