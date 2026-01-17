class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for (int w : weights) high += w;

        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canShip(vector<int>& weights, int days, int capacity) {
        int requiredDays = 1;
        int load = 0;

        for (int w : weights) {
            if (load + w > capacity) {
                requiredDays++;
                load = 0;
            }
            load += w;
        }
        return requiredDays <= days;
    }
};
