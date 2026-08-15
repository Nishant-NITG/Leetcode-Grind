class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Step 1: XOR all numbers
        int xorAll = 0;
        for (int num : nums) {
            xorAll ^= num;
        }
        
        // Step 2: Get rightmost set bit (SAFE VERSION)
        // Cast to unsigned to avoid overflow
        unsigned int diffBit = xorAll & -(unsigned int)xorAll;
        // OR use: unsigned int diffBit = xorAll & -xorAll;  // with proper casting
        
        // Step 3: Partition
        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & diffBit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }
        
        return {num1, num2};
    }
};