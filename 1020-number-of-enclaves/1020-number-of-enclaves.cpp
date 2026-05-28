class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or sea
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 0)
        {
            return;
        }

        // Mark visited
        grid[row][col] = 0;

        // 4 directions
        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Traverse first and last column
        for(int i = 0; i < m; i++)
        {
            if(grid[i][0] == 1)
                dfs(i, 0, grid);

            if(grid[i][n - 1] == 1)
                dfs(i, n - 1, grid);
        }

        // Traverse first and last row
        for(int j = 0; j < n; j++)
        {
            if(grid[0][j] == 1)
                dfs(0, j, grid);

            if(grid[m - 1][j] == 1)
                dfs(m - 1, j, grid);
        }

        // Count remaining land
        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }

        return count;
    }
};