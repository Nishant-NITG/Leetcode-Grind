class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        
        for (int i = 1; i < n; i++) {
            string next = "";
            int count = 1;
            
            for (int j = 1; j <= result.length(); j++) {
                // If same as previous char, increment count
                if (j < result.length() && result[j] == result[j - 1]) {
                    count++;
                } else {
                    // End of a group: append count and char
                    next += to_string(count);
                    next += result[j - 1];
                    count = 1;
                }
            }
            
            result = next;
        }
        
        return result;
    }
};