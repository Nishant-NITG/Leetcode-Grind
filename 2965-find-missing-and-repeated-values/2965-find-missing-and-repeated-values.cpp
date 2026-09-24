class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;
        
        // Expected sum of 1..N
        long long expectedSum = (long long)N * (N + 1) / 2;
        // Expected sum of squares of 1..N
        long long expectedSqSum = (long long)N * (N + 1) * (2 * N + 1) / 6;
        
        long long actualSum = 0, actualSqSum = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                actualSum += grid[i][j];
                actualSqSum += (long long)grid[i][j] * grid[i][j];
            }
        }
        
        // Let a = repeated, b = missing
        // actualSum - expectedSum = a - b
        // actualSqSum - expectedSqSum = a² - b² = (a - b)(a + b)
        long long diff = actualSum - expectedSum;           // a - b
        long long sqDiff = actualSqSum - expectedSqSum;     // a² - b²
        
        long long sum = sqDiff / diff;                      // a + b
        
        int a = (int)((diff + sum) / 2);  // repeated
        int b = (int)((sum - diff) / 2);  // missing
        
        return {a, b};
    }
};