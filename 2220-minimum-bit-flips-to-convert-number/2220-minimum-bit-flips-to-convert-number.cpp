class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR gives 1 where bits differ, 0 where they're same
        int diff = start ^ goal;
        
        // Count the number of 1s in diff (set bits)
        int flips = 0;
        while (diff > 0) {
            diff = diff & (diff - 1);  // Remove rightmost set bit
            flips++;
        }
        
        return flips;
    }
};