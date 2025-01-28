*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    int n, m;

    bool valid(int row, int col, vector<vector<int>> &grid)
    {
        if(row>=0 && row<n && col>=0 && col<m && grid[row][col] > 0)
        {
            return true;
        }

        return false;
    }
    int dfs(int row, int col, vector<vector<int>>& grid)
    {
        int val = 0;
        int temp = grid[row][col];
        grid[row][col] = -1;

        for(int i = 0; i<4; i++)
        {
            int newX = row + x[i];
            int newY = col + y[i];

            if(valid(newX, newY, grid))
            {
                val += dfs(newX, newY, grid);
            }
        }

        return val + temp;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxi = 0;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] > 0)
                {
                    maxi = max(maxi, dfs(i, j, grid));
                }
            }
        }

        return maxi;
    }
};