class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        
        // Step 1: Build LCS DP table
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Step 2: Reconstruct SCS
        int i = m, j = n;
        string result = "";
        
        while (i > 0 && j > 0) {
            if (str1[i-1] == str2[j-1]) {
                // Characters match - part of LCS
                result.push_back(str1[i-1]);
                i--;
                j--;
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                // Moving up gives better LCS
                result.push_back(str1[i-1]);
                i--;
            } else {
                // Moving left gives better LCS
                result.push_back(str2[j-1]);
                j--;
            }
        }
        
        // Add remaining characters
        while (i > 0) {
            result.push_back(str1[i-1]);
            i--;
        }
        while (j > 0) {
            result.push_back(str2[j-1]);
            j--;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};