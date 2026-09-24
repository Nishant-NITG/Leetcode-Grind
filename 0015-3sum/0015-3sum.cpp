class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        
        // Sort the array to enable two-pointer approach
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            // Two Sum on the remaining array with target = -nums[i]
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Move past duplicates for both pointers
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else if (sum < target) {
                    // Need a larger sum, move left pointer right
                    left++;
                } else {
                    // Need a smaller sum, move right pointer left
                    right--;
                }
            }
        }
        
        return result;
    }
};