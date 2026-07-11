class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;      // Boundary between 0s and 1s
        int mid = 0;      // Current element being examined
        int high = nums.size() - 1;  // Boundary between 2s and unprocessed
        
        // Invariant:
        // [0, low)   → all 0s
        // [low, mid) → all 1s  
        // [mid, high] → unprocessed elements
        // (high, n-1] → all 2s
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap 0 to the beginning of the 1s region
                // Both low and mid advance because:
                // 1. We placed a 0 at low, so 0s region expands
                // 2. The element at mid (from low) is already processed
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                // 1 belongs in the middle, just skip it
                mid++;
            }
            else { // nums[mid] == 2
                // Swap 2 to the end of the array
                // Only high decreases because the element swapped from
                // high needs to be processed (could be 0, 1, or 2)
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};