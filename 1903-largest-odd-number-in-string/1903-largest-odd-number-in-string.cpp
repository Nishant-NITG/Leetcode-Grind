class Solution {
public:
    string largestOddNumber(string num) {
        // Find the rightmost position where we have an odd digit
        // This gives us the farthest we can extend while keeping the number odd
        int rightmostOdd = -1;
        
        for (int i = num.length() - 1; i >= 0; i--) {
            // Convert char to int and check if odd
            // We check from right to left to find the longest possible substring
            if ((num[i] - '0') % 2 == 1) {
                rightmostOdd = i;
                break;
            }
        }
        
        // If no odd digit exists, no valid substring exists
        if (rightmostOdd == -1) return "";
        
        // Return from start to rightmost odd digit inclusive
        // This is the largest because it has the maximum possible digits
        return num.substr(0, rightmostOdd + 1);
    }
};