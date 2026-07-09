class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        // Start from the second-last row and work upwards
        // For each element, add the minimum of the two elements directly below it
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // triangle[i+1][j] is directly below (same index)
                // triangle[i+1][j+1] is below-right (next index)
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        // After processing all rows, the top element contains the answer
        return triangle[0][0];
    }
};