class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Create string: s + "#" + rev
        string t = s + "#" + rev;
        int n = t.length();
        
        // Build LPS array
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        
        while (i < n) {
            if (t[i] == t[len]) {
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
        
        // Longest palindromic prefix length
        int palLen = lps[n - 1];
        
        // Add reverse of remaining part to front
        string suffix = s.substr(palLen);
        reverse(suffix.begin(), suffix.end());
        
        return suffix + s;
    }
};