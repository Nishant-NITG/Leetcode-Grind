class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& board,
             int m, int n) {

        // Mark current safe 'O' as visited
        // We use '#' temporarily so we know:
        // "This O should NOT be converted to X"
        board[r][c] = '#';

        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, 1, 0, -1};

        // Explore all 4 directions
        for(int k = 0; k < 4; k++) {

            int nr = r + dr[k];
            int nc = c + dc[k];

            // Check boundaries
            // Also continue DFS only on unvisited 'O'
            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               board[nr][nc] == 'O') {

                dfs(nr, nc, board, m, n);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        // STEP 1:
        // Traverse boundary cells
        // Because ONLY boundary-connected O's are safe
        for(int i = 0; i < m; i++) {

            // Left boundary
            if(board[i][0] == 'O') {
                dfs(i, 0, board, m, n);
            }

            // Right boundary
            if(board[i][n - 1] == 'O') {
                dfs(i, n - 1, board, m, n);
            }
        }

        for(int j = 0; j < n; j++) {

            // Top boundary
            if(board[0][j] == 'O') {
                dfs(0, j, board, m, n);
            }

            // Bottom boundary
            if(board[m - 1][j] == 'O') {
                dfs(m - 1, j, board, m, n);
            }
        }

        // STEP 2:
        // Now process entire board
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                // Remaining O's are surrounded
                // because DFS never reached them
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                // Safe cells marked as '#'
                // convert them back to O
                else if(board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};