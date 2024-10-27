
*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(N*M)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    int solve(int row, int col, vector<vector<int>>& matrix)
    {
        if(row>=n || col>=m)
        {
            return 0;
        }
        if(matrix[row][col] == 0)
        {
            return 0;
        }
        if(dp[row][col] != -1)
        {
            return dp[row][col];
        }
        
        int right = solve(row, col+1, matrix);
        int diagonal = solve(row+1, col+1, matrix);
        int down = solve(row+1, col, matrix);

        dp[row][col] = 1 + min(right, min(diagonal, down));

        return dp[row][col];
    }
    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int ans = 0;
        dp.resize(n, vector<int>(m, -1));

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(matrix[i][j] == 1)
                {
                    
                }
            }
        }

        return ans;
    }
};