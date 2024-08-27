class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Adjacency list to store the graph
        unordered_map<int, list<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob}); // Add reverse edge since it's undirected
        }
        
        // Distance (probability) array
        vector<double> dist(n, 0.0); // Start with 0 probability for all nodes
        dist[start_node] = 1.0; // Probability of starting node is 1
        
        // Max heap to prioritize paths with higher probabilities
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node}); // Start with the starting node

        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();
            
            // If we reach the destination node, return the probability
            if (node == end_node) return currProb;
            
            // Explore neighbors
            for (auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;
                
                // Calculate the new probability if we take this path
                double newProb = currProb * edgeProb;
                
                // If this path provides a higher probability, update and push to the queue
                if (newProb > dist[nextNode]) {
                    dist[nextNode] = newProb;
                    pq.push({newProb, nextNode});
                }
            }
        }
        
        // If we never reach the end node, return 0
        return 0.0;
    }
};
