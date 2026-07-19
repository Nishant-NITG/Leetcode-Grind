class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // ============================================================
        // STEP 1: Get dimensions
        // ============================================================
        int m = heights.size();
        int n = heights[0].size();
        
        // ============================================================
        // STEP 2: Initialize distance matrix
        // ============================================================
        // dist[i][j] = minimum effort to reach cell (i,j)
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        
        // ============================================================
        // STEP 3: Priority queue (min-heap)
        // ============================================================
        // {effort, row, col} - processed in order of increasing effort
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        
        // ============================================================
        // STEP 4: Direction vectors (4-directional)
        // ============================================================
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        
        // ============================================================
        // STEP 5: Modified Dijkstra (Minimax)
        // ============================================================
        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();
            
            // If we reached destination, return the effort
            if (r == m - 1 && c == n - 1) {
                return effort;
            }
            
            // Skip stale entries (if we already found a better path)
            if (effort > dist[r][c]) continue;
            
            // Explore all 4 neighbors
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                // Check bounds
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Calculate height difference
                    int diff = abs(heights[r][c] - heights[nr][nc]);
                    
                    // New effort is the maximum of path effort and current edge
                    int newEffort = max(effort, diff);
                    
                    // If we found a better path to neighbor
                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, nr, nc});
                    }
                }
            }
        }
        
        // ============================================================
        // STEP 6: Return result
        // ============================================================
        return dist[m-1][n-1];
    }
};