class Solution {
public:
    int myAtoi(string s) {
        // The recursive helper carries all state forward
        return helper(s, 0, 0, 1, false);
    }
    
private:
    int helper(string& s, int i, long long result, int sign, bool started) {
        // BASE CASE 1: Reached end of string
        if (i >= s.length()) {
            return sign * result;
        }
        
        char c = s[i];
        
        // BASE CASE 2: Started reading digits and hit non-digit
        // The number stops here - this is the termination condition
        if (started && !isdigit(c)) {
            return sign * result;
        }
        
        // Handle sign characters (ONLY before any digits)
        if (!started && (c == '+' || c == '-')) {
            sign = (c == '-') ? -1 : 1;
            // Mark as started to prevent another sign later
            return helper(s, i + 1, result, sign, true);
        }
        
        // Handle digit characters
        if (isdigit(c)) {
            int digit = c - '0';
            
            // Overflow check: result > INT_MAX/10 means multiplying by 10
            // will overflow regardless of digit
            if (result > INT_MAX / 10 || 
                (result == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            
            // The recurrence: build number from left to right
            result = result * 10 + digit;
            
            // Mark as started and continue
            return helper(s, i + 1, result, sign, true);
        }
        
        // Handle whitespace (ONLY before any digits)
        if (!started && c == ' ') {
            return helper(s, i + 1, result, sign, false);
        }
        
        // Any other character: if not started, this is invalid
        // If started, we would have hit the base case above
        return 0;
    }
};