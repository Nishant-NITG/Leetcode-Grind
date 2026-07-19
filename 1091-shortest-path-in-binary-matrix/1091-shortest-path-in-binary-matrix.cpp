class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // ============================================================
        // STEP 1: Check edge cases
        // ============================================================
        int n = grid.size();
        
        // If start or end is blocked, no path exists
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
        
        // ============================================================
        // STEP 2: If single cell grid
        // ============================================================
        if (n == 1) {
            return 1;  // Start is also destination
        }
        
        // ============================================================
        // STEP 3: 8-directional movement vectors
        // ============================================================
        // Order: Up-Left, Up, Up-Right, Left, Right, Down-Left, Down, Down-Right
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // ============================================================
        // STEP 4: BFS initialization
        // ============================================================
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;  // Mark as visited (treat as blocked)
        int distance = 1;  // Distance from start (including start cell)
        
        // ============================================================
        // STEP 5: BFS level-by-level
        // ============================================================
        while (!q.empty()) {
            int size = q.size();  // Number of cells at current distance
            
            // Process all cells that are exactly 'distance' steps away
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                // If we reached destination, return current distance
                if (r == n-1 && c == n-1) {
                    return distance;
                }
                
                // Explore all 8 neighbors
                for (int d = 0; d < 8; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    
                    // Check if neighbor is valid and clear (0)
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1;  // Mark as visited
                        q.push({nr, nc});
                    }
                }
            }
            
            // We've processed one entire level (one step)
            distance++;
        }
        
        // ============================================================
        // STEP 6: If BFS completes without finding destination
        // ============================================================
        return -1;  // No clear path exists
    }
};