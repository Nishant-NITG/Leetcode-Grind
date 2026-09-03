class Solution {
public:
    string reverseWords(string s) {

        // 1. Remove extra spaces in-place
        int write = 0;
        int n = s.size();

        for (int read = 0; read < n; ) {

            // Skip spaces
            while (read < n && s[read] == ' ')
                read++;

            if (read >= n)
                break;

            // Add one space before every word except the first
            if (write > 0)
                s[write++] = ' ';

            // Copy the word
            while (read < n && s[read] != ' ') {
                s[write++] = s[read++];
            }
        }

        // Remove unused characters
        s.resize(write);

        // 2. Reverse entire string
        reverse(s.begin(), s.end());

        // 3. Reverse each word
        int start = 0;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};