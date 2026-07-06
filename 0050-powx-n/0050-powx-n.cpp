class Solution {
public:
    double myPow(double x, int n) {
        // Handle negative exponents by taking reciprocal
        // We need to be careful with INT_MIN
        if (n < 0) {
            x = 1 / x;
            
        }
        
        return powHelper(x, n);
    }
    
private:
    double powHelper(double x, int n) {
        // BASE CASE: anything to power 0 is 1
        if (n == 0) return 1.0;
        
        // BASE CASE: power 1 is the number itself
        // This prevents one unnecessary recursive call
        if (n == 1) return x;
        
        // RECURSIVE STEP: solve half the problem
        // This is the key optimization - O(log n) instead of O(n)
        // For n=10, we compute x^5, not x^9
        double half = powHelper(x, n / 2);
        
        // COMBINE STEP: use the half result to build the full result
        // If n is even: x^n = (x^(n/2))^2
        // If n is odd: x^n = x * (x^(n/2))^2
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};