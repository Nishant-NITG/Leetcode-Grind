class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // Empty subarray has sum 0
        
        int count = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            // If (prefixSum - goal) exists in map, it means there are subarrays
            // ending at current position with sum = goal
            if (prefixSumCount.find(prefixSum - goal) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - goal];
            }
            
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
};