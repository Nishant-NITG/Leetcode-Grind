class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        
        char sToT[256] = {0};
        char tToS[256] = {0};
        
        for (int i = 0; i < s.length(); i++) {
            if (sToT[s[i]] && sToT[s[i]] != t[i]) return false;
            if (tToS[t[i]] && tToS[t[i]] != s[i]) return false;
            
            sToT[s[i]] = t[i];
            tToS[t[i]] = s[i];
        }
        return true;
    }
};