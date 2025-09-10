#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();  // Correct way to get number of columns

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Initialize queue with all zero cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};

        // Fix: use "while (!q.empty())", not "while (q.empty())"
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int newX = x + dirX[d];  // Use square brackets, not parentheses
                int newY = y + dirY[d];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && dist[newX][newY] == -1) {
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return dist;
    }
};
