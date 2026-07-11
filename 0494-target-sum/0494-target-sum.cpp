class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int num : nums) total += num;
        
        // Check if target is achievable
        if ((total + target) % 2 != 0) return 0;
        
        int P = (total + target) / 2;  // Sum of numbers with '+'
        
        // If P is invalid, impossible
        if (P < 0 || P > total) return 0;
        
        // Perfect Sum DP
        vector<int> dp(P + 1, 0);
        dp[0] = 1;  // Empty subset
        
        for (int num : nums) {
            for (int s = P; s >= num; s--) {
                dp[s] = dp[s] + dp[s - num];
            }
        }
        
        return dp[P];
    }
};