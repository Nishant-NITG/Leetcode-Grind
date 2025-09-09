class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int originalColor, int newColor) {
        int m = image.size();
        int n = image[0].size();
        
        // Boundary checks
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (image[x][y] != originalColor) return;
        
        // Change the color
        image[x][y] = newColor;
        
        // Visit 4-directionally connected pixels
        dfs(image, x + 1, y, originalColor, newColor);
        dfs(image, x - 1, y, originalColor, newColor);
        dfs(image, x, y + 1, originalColor, newColor);
        dfs(image, x, y - 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        
        // Edge case: if the new color is same as original, no need to process
        if (originalColor == color) return image;
        
        dfs(image, sr, sc, originalColor, color);
        return image;
    }
};
