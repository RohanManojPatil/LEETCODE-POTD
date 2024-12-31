*******************************LEETCODE POTD*************************
*	               T.C = O(n^2) 							                * 
*	               							                        * 
*	               S.C = O(n)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int index, vector<int>& days, vector<int>& costs, vector<int> &Day7, vector<int> &Day30)
    {
        if(index >= n)
        {
            return 0;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }
        
        int path1 = costs[0] + solve(index+1, days, costs, Day7, Day30);
        int path2 = costs[1] + solve(Day7[index], days, costs, Day7, Day30);
        int path3 = costs[2] + solve(Day30[index], days, costs, Day7, Day30);

        return dp[index] = min(path1, min(path2, path3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.resize(n+1, -1);
        vector<int> Day7(n+1, n);
        vector<int> Day30(n+1, n);

        //For 7 Day Pass
        for(int i = 0; i<n; i++)
        {
            int presentDay = days[i];
            
            for(int j = i+1; j<n; j++)
            {
                if(presentDay+7 <= days[j])
                {
                    Day7[i] = j;
                    break;
                }
            }
        }

        //For 30 Day Pass
        for(int i = 0; i<n; i++)
        {
            int presentDay = days[i];
            
            for(int j = i+1; j<n; j++)
            {
                if(presentDay+30 <= days[j])
                {
                    Day30[i] = j;
                    break;
                }
            }
        }

        return solve(0, days, costs, Day7, Day30);
    }
};