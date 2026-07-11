class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int numCoins = coins.size();
        int targetAmount = amount;
      
        // dp[i][j] represents the number of ways to make amount j using first i coins
        // Using unsigned to handle potential overflow in intermediate calculations
        unsigned dp[numCoins + 1][targetAmount + 1];
      
        // Initialize all values to 0
        memset(dp, 0, sizeof(dp));
      
        // Base case: there's one way to make amount 0 (use no coins)
        dp[0][0] = 1;
      
        // Fill the dp table
        for (int i = 1; i <= numCoins; ++i) {
            for (int j = 0; j <= targetAmount; ++j) {
                // Option 1: Don't use the current coin
                // Number of ways equals to using first (i-1) coins to make amount j
                dp[i][j] = dp[i - 1][j];
              
                // Option 2: Use the current coin (if possible)
                // We can use coin[i-1] if the remaining amount is non-negative
                if (j >= coins[i - 1]) {
                    // Add the number of ways to make amount (j - coins[i-1]) 
                    // using first i coins (coin can be reused)
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }
      
        // Return the number of ways to make the target amount using all coins
        return dp[numCoins][targetAmount];
    }
};