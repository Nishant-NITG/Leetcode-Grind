class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task (A-Z)
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }
        
        // Find the maximum frequency and how many tasks have it
        int maxFreq = 0;
        int maxCount = 0;
        for (int f : freq) {
            if (f > maxFreq) {
                maxFreq = f;
                maxCount = 1;
            } else if (f == maxFreq) {
                maxCount++;
            }
        }
        
        // Formula: (maxFreq - 1) gaps of (n + 1) length
        // plus maxCount tasks that have the same max frequency
        int intervals = (maxFreq - 1) * (n + 1) + maxCount;
        
        // We need at least as many intervals as tasks
        return max((int)tasks.size(), intervals);
    }
};