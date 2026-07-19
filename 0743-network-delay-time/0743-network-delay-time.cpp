class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // ============================================================
        // STEP 1: Build adjacency list
        // ============================================================
        // Nodes are 1-indexed, so we use size n+1
        vector<vector<pair<int, int>>> adj(n + 1);
        
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        // ============================================================
        // STEP 2: Initialize distances
        // ============================================================
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        // ============================================================
        // STEP 3: Min-heap priority queue
        // ============================================================
        // {time, node} - processed in order of increasing time
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        // ============================================================
        // STEP 4: Dijkstra's algorithm
        // ============================================================
        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();
            
            // Skip stale entries
            if (time > dist[u]) continue;
            
            // Relax all outgoing edges from u
            for (auto [v, w] : adj[u]) {
                int newTime = dist[u] + w;
                if (newTime < dist[v]) {
                    dist[v] = newTime;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // ============================================================
        // STEP 5: Find the maximum distance
        // ============================================================
        int answer = 0;
        for (int i = 1; i <= n; i++) {
            // If any node is unreachable, return -1
            if (dist[i] == INT_MAX) {
                return -1;
            }
            answer = max(answer, dist[i]);
        }
        
        return answer;
    }
};