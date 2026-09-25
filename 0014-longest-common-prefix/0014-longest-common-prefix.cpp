class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Compare each character of the first string against all others
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            
            for (int j = 1; j < strs.size(); j++) {
                // If string j is too short or char doesn't match, we're done
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};