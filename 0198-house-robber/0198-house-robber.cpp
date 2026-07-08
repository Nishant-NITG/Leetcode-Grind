class Solution {
private:
    int solve(int idx, vector<int>& nums, vector<int>& memo) {
        // Base case: no houses left
        if (idx < 0) return 0;
        
        // Base case: only one house
        if (idx == 0) return nums[0];
        
        // If already computed, return cached result
        if (memo[idx] != -1) return memo[idx];
        
        // Option 1: Skip current house
        int skip = solve(idx - 1, nums, memo);
        
        // Option 2: Take current house (must skip previous)
        int take = solve(idx - 2, nums, memo) + nums[idx];
        
        // Store and return the maximum
        return memo[idx] = max(skip, take);
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> memo(n, -1);
        return solve(n - 1, nums, memo);
    }
};