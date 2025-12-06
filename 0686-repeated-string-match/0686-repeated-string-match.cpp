class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;

        // Repeat 'a' until length >= length of 'b'
        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        // Case 1: b fits inside current repeated string
        if (repeated.find(b) != string::npos)
            return count;

        // Case 2: Try one more repetition
        repeated += a;
        if (repeated.find(b) != string::npos)
            return count + 1;

        return -1;
    }
};
