class Solution {
public:
    int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
        dp[m - 1][n - 1][0] = dp[m - 1][n - 1][1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;
                for (int cameFrom = 0; cameFrom < 2; cameFrom++) {
                    if (grid[i][j] == 0) {
                        dp[i][j][cameFrom] = (dp[i][j + 1][0] + dp[i + 1][j][1]) % MOD;
                    } else if (cameFrom == 0) {
                        dp[i][j][cameFrom] = dp[i + 1][j][1];
                    } else
                        dp[i][j][cameFrom] = dp[i][j + 1][0];
                }
            }
        }
        return dp[0][0][0] % MOD;
    }
};