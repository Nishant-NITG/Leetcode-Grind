class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // ============================================================
        // STEP 1: Initialize distances
        // ============================================================
        // dist[i] = cheapest price to reach city i
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        // ============================================================
        // STEP 2: Bellman-Ford with stop constraint
        // ============================================================
        // We need at most k stops, which means k+1 edges maximum
        // Each iteration allows one more edge in the path
        for (int i = 0; i <= k; i++) {
            // KEY INSIGHT: Create a copy of current distances
            // This prevents using paths with more than i edges
            // Without this copy, we might use paths with i+1 edges
            vector<int> temp = dist;
            
            // Relax all edges
            for (auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int w = flight[2];
                
                // If we can reach u AND going through u gives a cheaper path to v
                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    // Update temp[v] with the cheaper path
                    temp[v] = dist[u] + w;
                }
            }
            
            // Update distances for the next iteration
            dist = temp;
        }
        
        // ============================================================
        // STEP 3: Return result
        // ============================================================
        // If dist[dst] is still INF, no path with ≤ k stops exists
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};