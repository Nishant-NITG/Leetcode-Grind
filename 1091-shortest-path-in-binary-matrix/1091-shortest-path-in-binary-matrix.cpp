class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;

        q.push({0,0});

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();

            if(row == n-1 && col == n-1)
                return dist[row][col];

            for(int i=0;i<8;i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nc >= 0 &&
                   nr < n && nc < n &&
                   grid[nr][nc] == 0 &&
                   dist[row][col] + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = dist[row][col] + 1;

                    q.push({nr,nc});
                }
            }
        }

        return -1;
    }
};