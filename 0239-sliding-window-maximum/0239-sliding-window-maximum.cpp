class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;      // stores indices
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            // Remove indices that are no longer inside the window
            while(!dq.empty() &&
                  dq.front() <= i - k) {

                dq.pop_front();
            }

            // Remove smaller elements from the back
            // They can never become maximum again
            while(!dq.empty() &&
                  nums[dq.back()] < nums[i]) {

                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // Window is complete
            if(i >= k - 1) {

                // Front always stores maximum element
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};