class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int dp[1001][1001];
    int solve(int n, int k, int i) {
        if (k == 0)
            return 1;
        if (i >= n)
            return 0;
        if (dp[k][i] != -1)
            return dp[k][i];
        ll skip = solve(n, k, i + 1);
        ll take = 0;
        for (int j = i + 1; j <= n - 1; j++) {
            take += solve(n, k - 1, j);
        }
        return dp[k][i] = (skip + take) % MOD;
    }
    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k, 0) % MOD;
    }
};