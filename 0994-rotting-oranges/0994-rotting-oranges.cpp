class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        // Number of rows
        int rows = grid.size();

        // Number of columns
        int cols = grid[0].size();

        // Queue for BFS
        // Stores coordinates of rotten oranges
        queue<pair<int,int>> q;

        // Count of fresh oranges
        int fresh = 0;

        // Traverse whole grid
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                // If orange is rotten
                if(grid[i][j] == 2) {

                    // Put its position into queue
                    q.push({i,j});
                }

                // If orange is fresh
                else if(grid[i][j] == 1) {

                    // Count fresh oranges
                    fresh++;
                }
            }
        }

        // If no fresh oranges exist already
        if(fresh == 0) {
            return 0;
        }

        // Time taken
        int minutes = 0;

        // Direction arrays
        // Used for:
        // up down left right

        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};

        // BFS starts
        while(!q.empty()) {

            // Number of rotten oranges
            // in current minute
            int size = q.size();

            // To check whether
            // any orange rotted this minute
            bool rottenThisMinute = false;

            // Process all oranges
            // of current level
            for(int i = 0; i < size; i++) {

                // Take front orange
                auto current = q.front();

                // Remove from queue
                q.pop();

                // Extract row
                int r = current.first;

                // Extract column
                int c = current.second;

                // Check all 4 directions
                for(int k = 0; k < 4; k++) {

                    // New row
                    int nr = r + dr[k];

                    // New column
                    int nc = c + dc[k];

                    // Valid cell check
                    // and fresh orange check
                    if(nr >= 0 && nr < rows &&
                       nc >= 0 && nc < cols &&
                       grid[nr][nc] == 1) {

                        // Make orange rotten
                        grid[nr][nc] = 2;

                        // Push into queue
                        // for next minute
                        q.push({nr,nc});

                        // One fresh orange reduced
                        fresh--;

                        // At least one orange rotted
                        rottenThisMinute = true;
                    }
                }
            }

            // Increase time only if
            // some orange rotted
            if(rottenThisMinute) {
                minutes++;
            }
        }

        // If fresh oranges still remain
        // impossible case
        if(fresh > 0) {
            return -1;
        }

        // Return total time
        return minutes;
    }
};


/*
* Traverse entire grid

  * Add all rotten oranges to queue
  * Count fresh oranges

* If fresh oranges = 0

  * Return `0`

* Start BFS using queue

* Process queue level by level

  * One level = one minute

* For every rotten orange

  * Check 4 directions

    * Up
    * Down
    * Left
    * Right

* If neighboring orange is fresh

  * Make it rotten
  * Push into queue
  * Decrease fresh count

* After processing one level

  * Increase minutes

* After BFS ends

  * If fresh oranges still exist

    * Return `-1`

* Else

  * Return total minutes
*/