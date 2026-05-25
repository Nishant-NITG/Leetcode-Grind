class Solution {
public:

    void dfs(vector<vector<int>>& image,
             int r,
             int c,
             int oldColor,
             int newColor) {

        int rows = image.size();
        int cols = image[0].size();

        // Boundary check
        if(r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }

        // If color doesn't match original color
        if(image[r][c] != oldColor) {
            return;
        }

        // Change color
        image[r][c] = newColor;

        // Visit 4 directions

        dfs(image, r-1, c, oldColor, newColor); // up
        dfs(image, r+1, c, oldColor, newColor); // down
        dfs(image, r, c-1, oldColor, newColor); // left
        dfs(image, r, c+1, oldColor, newColor); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        // Original color
        int oldColor = image[sr][sc];

        // If color already same
        if(oldColor == color) {
            return image;
        }

        // Start DFS
        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};