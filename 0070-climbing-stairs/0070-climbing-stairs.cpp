class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = number of ways to reach step i
        vector<int> dp(n + 1);
        
        dp[0] = 1;  // one way to be at ground
        dp[1] = 1;  // one way to reach first step
        
        for (int i = 2; i <= n; i++) {
            // To reach step i:
            // 1. Take 1 step from step (i-1)
            // 2. Take 2 steps from step (i-2)
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        return dp[n];
    }
};