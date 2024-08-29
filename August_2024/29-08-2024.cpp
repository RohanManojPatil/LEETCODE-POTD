class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int node)
    {
        if(parent[node] != node)
        {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    void Union(int u, int v)
    {
        int node1 = find(u);
        int node2 = find(v);

        if(node1 != node2)
        {
            if(rank[node1] > rank[node2])
            {
                parent[node2] = parent[node1];
            }
            else if(rank[node1] < rank[node2])
            {
                parent[node1] = parent[node2];
            }
            else
            {
                parent[node2] = parent[node1];
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), groups = 0;
        parent.resize(n);
        rank.resize(n);

        for(int i = 0; i<n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i = 0; i<n; i++)
        {
            for(int j = i+1; j<n; j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    Union(i, j);
                }
            }
        }

        for(int i = 0; i<n; i++)
        {
            if(parent[i] == i)
            {
                groups++;
            }
        }

        return n-groups;
    }
};