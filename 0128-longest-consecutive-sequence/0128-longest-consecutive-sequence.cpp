class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int longeststreak = 0;

        for (int num : numset) {
            // Check if num is the start of a sequence
            if (numset.find(num - 1) == numset.end()) {
                int currentnum = num;
                int currstreak = 1;

                while (numset.find(currentnum + 1) != numset.end()) {
                    currentnum++;
                    currstreak++;
                }

                longeststreak = max(longeststreak, currstreak);
            }
        }

        return longeststreak;
    }
};
