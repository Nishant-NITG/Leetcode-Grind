class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for (int x : nums) high += x;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = mid;
                high = mid - 1;   // try smaller maximum sum
            } else {
                low = mid + 1;    // need larger limit
            }
        }
        return ans;
    }

private:
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int subarrays = 1;
        int currentSum = 0;

        for (int x : nums) {
            if (currentSum + x > maxSum) {
                subarrays++;
                currentSum = x;
            } else {
                currentSum += x;
            }
        }
        return subarrays <= k;
    }
};
