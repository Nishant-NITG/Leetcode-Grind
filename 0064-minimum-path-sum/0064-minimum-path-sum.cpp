class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& grid, 
              vector<vector<int>>& memo) {
        // Base case: reached start
        if (i == 0 && j == 0) {
            return grid[0][0];
        }
        
        // Out of bounds
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        
        // If already computed
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        // Minimum cost = current + min(from above, from left)
        return memo[i][j] = grid[i][j] + 
                            min(solve(i-1, j, grid, memo),
                                solve(i, j-1, grid, memo));
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(m-1, n-1, grid, memo);
    }
};