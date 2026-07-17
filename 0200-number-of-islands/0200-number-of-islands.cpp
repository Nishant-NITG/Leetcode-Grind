class Solution {
public:
    // ============================================================
    // STEP 1: Define grid dimensions and direction vectors
    // ============================================================
    int m, n;
    int dr[4] = {-1, 0, 1, 0};  // Up, Right, Down, Left
    int dc[4] = {0, 1, 0, -1};  // Up, Right, Down, Left
    
    // ============================================================
    // STEP 2: DFS to mark all land cells in an island
    // ============================================================
    void dfs(int r, int c, vector<vector<char>>& grid) {
        // Base case: if out of bounds or water, stop
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0') {
            return;
        }
        
        // Mark this cell as visited by changing to '0' (sink the land)
        // This prevents counting it again in future scans
        grid[r][c] = '0';
        
        // Explore all 4 directions
        // This goes deep before coming back (DFS)
        dfs(r - 1, c, grid);  // Up
        dfs(r + 1, c, grid);  // Down
        dfs(r, c - 1, grid);  // Left
        dfs(r, c + 1, grid);  // Right
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // ============================================================
        // STEP 3: Initialize dimensions
        // ============================================================
        m = grid.size();
        n = grid[0].size();
        
        // ============================================================
        // STEP 4: Scan all cells and count islands
        // ============================================================
        int islands = 0;
        
        // Scan every cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If we find a land cell, it's the start of a new island
                if (grid[i][j] == '1') {
                    islands++;  // Count this new island
                    
                    // Mark the entire island as visited
                    // This removes all '1's connected to this cell
                    dfs(i, j, grid);
                }
            }
        }
        
        return islands;
    }
};