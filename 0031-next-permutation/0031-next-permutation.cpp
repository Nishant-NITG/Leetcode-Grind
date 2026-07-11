class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the pivot - the rightmost element that's smaller than the one to its right
        // This is the first place where we can increase the number
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        // Step 2: If no pivot exists, array is in descending order (last permutation)
        // Next permutation is the first one (ascending order)
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: Find the smallest element to the right of pivot that's greater than nums[pivot]
        // Since the suffix is in descending order, the rightmost element > nums[pivot] works
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        
        // Step 4: Reverse the suffix (elements after pivot)
        // This gives us the smallest possible arrangement after the swap
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};