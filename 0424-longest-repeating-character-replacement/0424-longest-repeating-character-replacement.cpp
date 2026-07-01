class Solution {
public:
    int characterReplacement(string s, int k) {
        // Frequency array for 26 uppercase letters
        vector<int> freq(26, 0);
        
        int left = 0;          // Left boundary of current window
        int max_freq = 0;      // Maximum frequency of any character in window
        int max_len = 0;       // Track the longest valid window found
        
        for (int right = 0; right < s.length(); right++) {
            // Add the new character to the window
            int idx = s[right] - 'A';
            freq[idx]++;
            
           
            max_freq = max(max_freq, freq[idx]);
            
            
            while ((right - left + 1) - max_freq > k) {
                // Remove the left character from the window
                int left_idx = s[left] - 'A';
                freq[left_idx]--;
                left++;
                
               
            }
            
            int current_len = right - left + 1;
            max_len = max(max_len, current_len);
        }
        
        return max_len;
    }
};