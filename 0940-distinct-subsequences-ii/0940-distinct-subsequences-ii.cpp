class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> prev;
    int dp[2001];
    int solve(int n) {
        if (n == 0) {
            return 1;
        }
        if (dp[n] != -1)
            return dp[n];
        long long total = (2LL * solve(n - 1)) % MOD;
        if (prev[n] != 0) {
            int duplicate = solve(prev[n] - 1);
            total = (total - duplicate + MOD) % MOD;
        }
        return dp[n] = total % MOD;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        prev.assign(n + 1, 0);
        vector<int> lastSeen(26, 0);
        for (int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';
            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }
        memset(dp, -1, sizeof(dp));
        return (solve(n) - 1 + MOD) % MOD;
    }
};