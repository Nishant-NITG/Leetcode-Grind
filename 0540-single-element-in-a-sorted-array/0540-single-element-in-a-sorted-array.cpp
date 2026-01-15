class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // make mid even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                // single element is on the right
                start = mid + 2;
            } else {
                // single element is on the left (or mid)
                end = mid;
            }
        }
        return nums[start];
    }
};
