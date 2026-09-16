class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(K + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
            dp[0][i] = 1; // for k=0
        for (int k = 1; k <= K; k++) {
            for (int i = n - 1; i >= 0; i--) {
                long long skip = dp[k][i + 1];
                long long take = 0;
                for (int j = i + 1; j <= n - 1; j++) {
                    take += dp[k - 1][j];
                }
                dp[k][i] = (skip + take) % MOD;
            }
        }
        return dp[K][0] % MOD;
    }
};