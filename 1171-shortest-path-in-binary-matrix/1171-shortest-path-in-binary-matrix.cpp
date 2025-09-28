class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

         if (grid[0][0] == 1 || grid[n-1][n-1] == 1) {
            return -1;
        }
         if (n == 1) return 1;

        vector<vector<int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        int pathLength = 1;



        while(!q.empty())
{
    int level=q.size();
    pathLength++;

    for(int i=0;i<level;i++)
    {
        auto[row,col]=q.front();
        q.pop();

        for(auto& dir:directions)
        {
            int newRow = row + dir[0];
            int newCol = col + dir[1];

            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && 
                grid[newRow][newCol] == 0)
            {
                if(newRow==n-1 && newCol==n-1)
                {
                    return pathLength;
                }
                grid[newRow][newCol] = 1;
                q.push({newRow, newCol});
            }
        }
    }
}


return -1;

        }
        
};