*******************************LEETCODE POTD*************************
*	               T.C = O(N*M)							                * 
*	               							                        * 
*	               S.C = O(N)                                          * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        queue<int> q;

        for(auto edge : edges)
        {
            indegree[edge[1]]++;
        }

        for(int i = 0; i<n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        if(q.size() == 1)
        {
            return q.front();
        }

        return -1;
    }
};