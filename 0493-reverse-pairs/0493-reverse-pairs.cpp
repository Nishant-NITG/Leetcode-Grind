class Solution {
public:
    long long mergeAndCount(vector<int>& nums, int left, int mid, int right) {
        long long count = 0;

        int j = mid + 1;

        // Count reverse pairs
        for (int i = left; i <= mid; i++) {
            while (j <= right && 
                  (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }

        // Normal merge
        vector<int> temp;
        int i = left;
        j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
            temp.push_back(nums[i++]);

        while (j <= right)
            temp.push_back(nums[j++]);

        for (int k = left; k <= right; k++)
            nums[k] = temp[k - left];

        return count;
    }

    long long mergeSort(vector<int>& nums, int left, int right) {
        long long count = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            count += mergeSort(nums, left, mid);
            count += mergeSort(nums, mid + 1, right);
            count += mergeAndCount(nums, left, mid, right);
        }

        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
