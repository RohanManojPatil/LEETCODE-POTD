*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(1)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int n = matrix.size();
        int negativeCount = 0;
        int mini = INT_MAX;

        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<n; j++)
            {
                sum += abs(matrix[i][j]);

                if(matrix[i][j] < 0)
                {
                    negativeCount++;
                }

                mini = min(mini, abs(matrix[i][j]));
            }
        }

        if(negativeCount%2 == 0)
        {
            return sum;
        }

        sum -= 2*mini;

        return sum;
    }
};