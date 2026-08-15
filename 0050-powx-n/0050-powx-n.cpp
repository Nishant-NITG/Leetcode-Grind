class Solution {
public:
    double myPow(double x, int n) {
        // Use long long to handle INT_MIN safely
        long long exp = n;  // Convert to long long
        
        // Handle negative exponent
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;  // Now safe! long long can hold 2147483648
        }
        
        double result = 1.0;
        double power = x;
        
        while (exp > 0) {
            if (exp % 2 == 1) {        // If current bit is 1
                result = result * power;
            }
            power = power * power;     // Square: x, x^2, x^4, x^8...
            exp = exp / 2;            // Move to next bit
        }
        
        return result;
    }
};