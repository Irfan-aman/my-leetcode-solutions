class Solution {
public:
    long long countCommas(long long n) {
        if (n < 1000)
            return 0;
        long long res = 0;
        if (n < 1000000) {
            return n - 999;
        } else {
            res += (1e6 - 1e3 );
            if (n < 1e9) {
                res += (n - 1e6 +1) * 2;
            } else {
                res += (1e9 - 1e6 ) * 2;
                if (n < 1e12) {
                    res += (n - 1e9 + 1) * 3;
                } else {
                    res += (1e12 - 1e9) * 3;
                    if (n < 1e15) {
                        res += (n - 1e12 + 1) * 4;
                    } else {
                        res += (1e15 - 1e12 ) * 4 + 5;
                    }
                }
            }
        }
        return res;
    }
};