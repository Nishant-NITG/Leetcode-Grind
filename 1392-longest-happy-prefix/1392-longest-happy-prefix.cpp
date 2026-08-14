class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        // Build LPS array
        int len = 0;  // Length of previous longest prefix suffix
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Last value is the length of longest happy prefix
        int happyLen = lps[n - 1];
        return s.substr(0, happyLen);
    }
};