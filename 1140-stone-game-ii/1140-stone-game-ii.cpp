class Solution {
public:
    int n;
    int dp[101][101];
    int suffix[101] = {0};
    int solve(int i, int M) {
        if (i >= n)
            return 0;
        if (dp[i][M] != -1)
            return dp[i][M];
        int result = 0;
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            result = max(result, suffix[i] - solve(x + i, max(M, x)));
        }
        return dp[i][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }
        return solve(0, 1);
    }
};