*******************************LEETCODE POTD*************************
*	               T.C = O(N)							                * 
*	               							                        * 
*	               S.C = O(N)                                           * 
*	                                                                * 
*********************************************************************
class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);  // n+1 to handle 1-based indexing
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);  // Path compression
        }
        return parent[node];
    }

    bool Union(int u, int v) {
        int node1 = find(u);
        int node2 = find(v);
        if (node1 == node2) {
            return false;
        }
        if (rank[node1] < rank[node2]) {
            parent[node1] = node2;
        } 
        else if (rank[node1] > rank[node2]) {
            parent[node2] = node1;
        } 
        else {
            parent[node2] = node1;
            rank[node1]++;  // Increase rank only when merging equal ranks
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int temp1, temp2;
        DSU d(n);
        
        for (auto& edge : edges) {
            int src = edge[0];
            int dest = edge[1];

            if (!d.Union(src, dest)) {
                temp1 = src;
                temp2 = dest;  // Redundant edge found
            }
        }
        
        return {temp1, temp2}; // Should never reach here
    }
};
