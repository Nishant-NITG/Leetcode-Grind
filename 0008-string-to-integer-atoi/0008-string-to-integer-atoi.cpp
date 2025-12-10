class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long ans = 0;               // long to detect overflow
        int i = 0;
        int sign = 1;

        // 1. Skip leading spaces
        while (i < n && s[i] == ' ') i++;

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Overflow check BEFORE adding digit
            if (ans > (LONG_MAX / 10) || 
               (ans == LONG_MAX / 10 && digit > 7)) 
            {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        ans = ans * sign;

        // 5. Clamp to 32-bit range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};
