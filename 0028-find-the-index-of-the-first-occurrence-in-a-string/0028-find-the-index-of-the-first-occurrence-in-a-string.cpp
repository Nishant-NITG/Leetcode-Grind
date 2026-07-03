class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        if (m == 0) return 0;
        
        // Build LPS (Longest Proper Prefix which is also Suffix)
        vector<int> lps(m, 0);
        int len = 0;  // length of previous longest prefix suffix
        int i = 1;
        
        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];  // Fall back
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Search using KMP
        int j = 0;  // index for needle
        for (int i = 0; i < n; i++) {
            // If mismatch, use LPS to skip
            while (j > 0 && haystack[i] != needle[j]) {
                j = lps[j - 1];
            }
            
            // If match, advance
            if (haystack[i] == needle[j]) {
                j++;
            }
            
            // Found the pattern
            if (j == m) {
                return i - m + 1;
            }
        }
        
        return -1;
    }
};