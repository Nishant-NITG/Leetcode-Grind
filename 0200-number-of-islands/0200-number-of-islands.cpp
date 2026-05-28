class Solution {
public:

    void dfs(int row,int col,vector<vector<char>>&grid)
    {
        int m=grid.size();
        int n=grid[0].size();

        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0')
        {
            return;
        }

        grid[row][col]='0';

        dfs(row + 1, col, grid);
        dfs(row - 1, col, grid);
        dfs(row, col + 1, grid);
        dfs(row, col - 1, grid);
    }




















    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        int islands=0;

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')

                {
                    islands++;

                    dfs(i,j,grid);
                }
            }
        }
        return islands;
    }
};