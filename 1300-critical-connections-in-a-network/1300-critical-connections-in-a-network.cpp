class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build adjacency list
        vector<vector<int>> graph(n);
        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        // Arrays for Tarjan's algorithm
        vector<int> disc(n, -1);    // Discovery time
        vector<int> low(n, -1);     // Lowest discovery time reachable
        vector<vector<int>> result; // Store critical connections
        int time = 0;               // Global timer
        
        // DFS function
        function<void(int, int)> dfs = [&](int u, int parent) {
            disc[u] = low[u] = time++;
            
            for (int v : graph[u]) {
                // Skip the parent edge
                if (v == parent) continue;
                
                if (disc[v] == -1) {
                    // v is not visited
                    dfs(v, u);
                    
                    // Update low value for u
                    low[u] = min(low[u], low[v]);
                    
                    // If low[v] > disc[u], then u-v is a bridge
                    if (low[v] > disc[u]) {
                        result.push_back({u, v});
                    }
                } else {
                    // v is already visited (back edge)
                    low[u] = min(low[u], disc[v]);
                }
            }
        };
        
        // Run DFS for all nodes (in case the graph is not connected)
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) dfs(i, -1);
        }
        
        return result;
    }
};
