class Solution {
public:
    string minWindow(string s, string t) {
        // Build frequency map for characters in t
        unordered_map<char, int> required;
        for (char c : t) {
            required[c]++;
        }
        
        int need = required.size();  // Number of distinct characters needed
        unordered_map<char, int> window_freq;
        int formed = 0;  // Number of distinct characters satisfied in current window
        
        int left = 0;
        int min_len = INT_MAX;
        int min_start = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // Phase 1: Expand the window to the right
            char c = s[right];
            if (required.find(c) != required.end()) {
                window_freq[c]++;
                // If this character now meets the requirement, increment formed
                if (window_freq[c] == required[c]) {
                    formed++;
                }
            }
            
            // Phase 2: Contract from the left while the window is valid
            while (formed == need && left <= right) {
                // Update the minimum window
                int current_len = right - left + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    min_start = left;
                }
                
                // Try to shrink from the left
                char left_char = s[left];
                if (required.find(left_char) != required.end()) {
                    // If we're about to lose a character that was exactly meeting the requirement
                    if (window_freq[left_char] == required[left_char]) {
                        formed--;
                    }
                    window_freq[left_char]--;
                }
                left++;
            }
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};