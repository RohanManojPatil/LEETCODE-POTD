*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class Solution {
public:
    unordered_map<int, list<int>> adj;

    void dfs1(int node, vector<int> &vis, int &count)
    {
        count++;
        vis[node] = 1;
        for(auto i : adj[node])
        {
            if(!vis[i])
            {
                dfs1(i, vis, count);
            }
        }

        return;
    }
    bool dfs2(int node, vector<int> &vis, int target)
    {
        vis[node] = 1;
        if(adj[node].size() != target-1)
        {
            return false;
        }

        for(auto i : adj[node])
        {
            if(!vis[i])
            {
                if(!dfs2(i, vis, target))
                {
                    return false;
                }
            }
        }

        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis1(n, 0);
        vector<int> vis2(n, 0);
        int temp;
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            if(!vis1[i])
            {
                temp = i;
                int count = 0;
                dfs1(i, vis1, count);
                bool flag = dfs2(i, vis2, count);
                if(flag)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};