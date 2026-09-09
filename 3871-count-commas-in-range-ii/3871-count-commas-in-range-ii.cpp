class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        long long start = 1000;
        while (start <= n) {
            res += (n - start + 1);
            start *= 1000;
        }
        return res;
    }
};