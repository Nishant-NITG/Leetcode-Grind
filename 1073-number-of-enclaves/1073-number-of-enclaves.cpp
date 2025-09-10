#include <vector>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Remove border-connected lands
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, m, n);
            if (grid[i][n - 1] == 1)
                dfs(grid, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1)
                dfs(grid, 0, j, m, n);
            if (grid[m - 1][j] == 1)
                dfs(grid, m - 1, j, m, n);
        }

        // Step 2: Count remaining land cells
        int enclaveCount = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    enclaveCount++;

        return enclaveCount;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
            return;

        grid[x][y] = 0;  
        dfs(grid, x + 1, y, m, n);
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x, y + 1, m, n);
        dfs(grid, x, y - 1, m, n);
    }
};
