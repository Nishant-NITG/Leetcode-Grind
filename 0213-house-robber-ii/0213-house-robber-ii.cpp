class Solution {
private:
    // Helper function that solves House Robber I on a subarray
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;  // dp[i-2] - money from two houses ago
        int prev1 = 0;  // dp[i-1] - money from one house ago
        
        for (int i = start; i <= end; i++) {
            // At each house, either:
            // 1. Skip it: keep prev1 (best up to previous house)
            // 2. Take it: add nums[i] to prev2 (best up to two houses ago)
            int curr = max(prev1, prev2 + nums[i]);
            
            // Slide window forward for next iteration
            prev2 = prev1;  // What was dp[i-1] becomes dp[i-2]
            prev1 = curr;   // What is dp[i] becomes dp[i-1]
        }
        
        return prev1;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        // Edge cases: no houses or single house
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // In a circle, the first and last houses are adjacent
        // So we have two mutually exclusive scenarios:
        // 1. Don't rob the last house → consider houses 0 to n-2
        // 2. Don't rob the first house → consider houses 1 to n-1
        
        int scenario1 = robLinear(nums, 0, n - 2);  // Exclude last
        int scenario2 = robLinear(nums, 1, n - 1);  // Exclude first
        
        // Take the better of the two scenarios
        return max(scenario1, scenario2);
    }
};