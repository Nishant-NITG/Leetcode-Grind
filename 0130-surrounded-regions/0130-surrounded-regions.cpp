#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = '#';
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
                board[i][n - 1] = '#';
            }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                board[0][j] = '#';
            }
            if (board[m - 1][j] == 'O') {
                q.push({m - 1, j});
                board[m - 1][j] = '#';
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int newX = x + dirX[d];
                int newY = y + dirY[d];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'O') {
                    board[newX][newY] = '#';
                    q.push({newX, newY});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
