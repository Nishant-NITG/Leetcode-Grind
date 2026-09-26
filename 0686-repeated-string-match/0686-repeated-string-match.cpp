class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lenA = a.length();
        int lenB = b.length();
        
        // Minimum repetitions needed to cover length of b
        int q = (lenB + lenA - 1) / lenA; // ceil division
        
        string repeated;
        for (int i = 0; i < q; i++) repeated += a;
        
        if (repeated.find(b) != string::npos) return q;
        
        repeated += a;
        if (repeated.find(b) != string::npos) return q + 1;
        
        return -1;
    }
};