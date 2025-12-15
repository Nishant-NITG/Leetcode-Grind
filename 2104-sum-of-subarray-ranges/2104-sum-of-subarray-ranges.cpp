class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> psm(n), nsm(n), pgm(n), ngm(n);
        stack<int> st;

        // -------- MINIMUM --------

        // Previous Smaller
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            psm[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Smaller or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nsm[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // -------- MAXIMUM --------

        // Previous Greater
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            pgm[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Greater or Equal
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            ngm[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // -------- CALCULATE --------

        long long sumMin = 0, sumMax = 0;

        for (int i = 0; i < n; i++) {
            long long leftMin = i - psm[i];
            long long rightMin = nsm[i] - i;
            sumMin += nums[i] * leftMin * rightMin;

            long long leftMax = i - pgm[i];
            long long rightMax = ngm[i] - i;
            sumMax += nums[i] * leftMax * rightMax;
        }

        return sumMax - sumMin;
    }
};
