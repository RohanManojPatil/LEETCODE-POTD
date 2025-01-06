*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        vector<int> prefixSum(n, 0);
        vector<int> suffixSum(n, 0);
        vector<int> ans;

        if(boxes[0] == '1')
        {
            prefixSum[0] = 1;
        }
        if(boxes[n-1] == '1')
        {
            suffixSum[n-1] = 1;
        }

        for(int i = 1; i<n; i++)
        {
            prefixSum[i] = prefixSum[i-1];
            suffixSum[n-i-1] = suffixSum[n-i];

            if(boxes[i] == '1')
            {
                prefixSum[i]++;
            }
            if(boxes[n-i-1] == '1')
            {
                suffixSum[n-i-1]++;
            }
        }

        for(int i = 1; i<n; i++)
        {
            prefixSum[i] += prefixSum[i-1];
            suffixSum[n-i-1] += suffixSum[n-i];
        }

        for(int i = 0; i<n; i++)
        {
            int left = 0, right = 0;
            if(i > 0)
            {
                left = prefixSum[i-1];
            }
            if(i != n-1)
            {
                right = suffixSum[i+1];
            }

            ans.push_back(left + right);
        }

        return ans;
    }
};