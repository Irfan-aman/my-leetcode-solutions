class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        vector<int> inc(m), dec(m);

        for (int i = 0; i < m; i++) {
            inc[i] = i;
            dec[i] = m - 1 - i;
        }

        for (int len = 3; len <= n; len++) {

            vector<int> newInc(m), newDec(m);

            long long pref = 0;
            for (int i = 0; i < m; i++) {
                newInc[i] = pref;
                pref += dec[i];
                if (pref >= MOD) pref %= MOD;
            }

            long long suff = 0;
            for (int i = m - 1; i >= 0; i--) {
                newDec[i] = suff;
                suff += inc[i];
                if (suff >= MOD) suff %= MOD;
            }

            inc.swap(newInc);
            dec.swap(newDec);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            ans += inc[i];
            ans += dec[i];
            ans %= MOD;
        }

        return ans;
    }
};