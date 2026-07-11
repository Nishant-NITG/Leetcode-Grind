class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[j] = number of ways to make amount j
        vector<unsigned> dp(amount + 1, 0);
        dp[0] = 1;  // 1 way to make amount 0
        
        for (int coin : coins) {
            // Forward iteration = unlimited coins
            for (int j = coin; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};