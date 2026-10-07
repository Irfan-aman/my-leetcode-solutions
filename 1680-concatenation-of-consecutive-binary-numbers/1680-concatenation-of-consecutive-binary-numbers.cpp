class Solution {
public:
    int MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        if (n == 1)
            return 1;
        long long res = 1;
        for (int i = 2; i <= n; i++) {
            int dig = log2(i) + 1;
            res = ((res << dig) % MOD + i) % MOD;
        }
        return res % MOD;
    }
};