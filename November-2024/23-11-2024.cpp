*******************************LEETCODE POTD*************************
*	               T.C = O(N * M) 							                * 
*	               							                        * 
*	               S.C = O(N * M)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<vector<char>> rotatedBox;

    void fillStones(int row, int stones, int col)
    {
        for(int i = row; i>=0 && stones > 0; i--)
        {
            rotatedBox[i][col] = '#';
            stones--;
        }
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box[0].size();
        int n = box.size();

        rotatedBox.resize(m, vector<char>(n, '.'));

        for(int i = 0; i<n; i++)
        {
            int stoneCount = 0;
            
            for(int j = 0; j<m; j++)
            {
                if(box[i][j] == '#')
                {
                    stoneCount++;
                }
                else if(box[i][j] == '*')
                {
                    fillStones(j-1, stoneCount, n-i-1);
                    rotatedBox[j][n-i-1] = '*';
                    stoneCount = 0;
                }
            }

            if(stoneCount > 0)
            {
                fillStones(m-1, stoneCount, n-i-1);
            }
        }

        return rotatedBox;
    }
};