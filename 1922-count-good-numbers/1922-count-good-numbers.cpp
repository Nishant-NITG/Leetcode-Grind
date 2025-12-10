class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long x, long long n) {
        long long result = 1;
        while (n > 0) {
            if (n % 2 == 1) result = (result * x) % MOD;
            x = (x * x) % MOD;
            n = n / 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;   // number of even indices
        long long odd  = n / 2;         // number of odd indices

        long long part1 = power(5, even);
        long long part2 = power(4, odd);

        return (part1 * part2) % MOD;
    }
};
