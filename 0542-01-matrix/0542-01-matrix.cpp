class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        // Stores shortest distance of each cell from nearest 0
        // Initialize with -1 meaning "not visited yet"
        vector<vector<int>> dist(m, vector<int>(n, -1));

        queue<pair<int,int>> q;

        // Step 1:
        // Push ALL 0s into queue first
        // Because distance of 0 from nearest 0 is obviously 0
        // These will act as starting points of Multi-Source BFS
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {

                    dist[i][j] = 0;

                    // Start BFS from every 0 simultaneously
                    q.push({i, j});
                }
            }
        }

        // Direction arrays for:
        // Up, Right, Down, Left
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Standard BFS
        while(!q.empty()) {

            auto [r, c] = q.front();
            q.pop();

            // Explore all 4 neighboring cells
            for(int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Check:
                // 1. Neighbor is inside matrix
                // 2. Neighbor is not visited before
                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   dist[nr][nc] == -1) {

                    // Neighbor is exactly 1 step farther
                    // than current cell
                    dist[nr][nc] = dist[r][c] + 1;

                    // Push neighbor for further BFS expansion
                    q.push({nr, nc});
                }
            }
        }

        // Final matrix containing shortest distances
        return dist;
    }
};