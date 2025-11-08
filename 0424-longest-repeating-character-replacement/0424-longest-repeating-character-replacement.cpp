class Solution {
public:
    int characterReplacement(string s, int k) {
    int left = 0, right = 0, maxCount = 0, maxLength = 0;
    unordered_map<char, int> freq;

    while (right < s.size()) {
        freq[s[right]]++;
        maxCount = max(maxCount, freq[s[right]]);

        while ((right - left + 1) - maxCount > k) {
            freq[s[left]]--;
            left++;
        }

        maxLength = max(maxLength, right - left + 1);
        right++;
    }
    return maxLength;
}

};