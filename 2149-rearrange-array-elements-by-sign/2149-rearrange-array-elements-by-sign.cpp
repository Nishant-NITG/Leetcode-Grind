class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        // Positive numbers go to even indices (0, 2, 4, ...)
        // Negative numbers go to odd indices (1, 3, 5, ...)
        int posIndex = 0;
        int negIndex = 1;
        
        for (int num : nums) {
            if (num > 0) {
                // Place positive at next even index
                result[posIndex] = num;
                posIndex += 2;
            } else {
                // Place negative at next odd index
                result[negIndex] = num;
                negIndex += 2;
            }
        }
        
        return result;
    }
};