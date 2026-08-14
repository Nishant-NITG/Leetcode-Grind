class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequencies
        vector<int> freq(128, 0);
        for (char c : s) {
            freq[c]++;
        }
        
        // Step 2: Store characters with their frequencies
        vector<pair<char, int>> chars;
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                chars.push_back({(char)i, freq[i]});
            }
        }
        
        // Step 3: Sort by frequency (descending)
        sort(chars.begin(), chars.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        
        // Step 4: Build result
        string result;
        for (auto& p : chars) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};