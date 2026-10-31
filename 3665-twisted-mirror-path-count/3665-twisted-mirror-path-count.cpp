class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int m, n;
    int LEFT = 0, UP = 1;
    int dp[501][501][2];
    int dfs(vector<vector<int>>& grid, int i, int j, int cameFrom) {
        if (i >= m || j >= n)
            return 0;
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (dp[i][j][cameFrom] != -1)
            return dp[i][j][cameFrom];
        int total = 0;
        if (grid[i][j] == 0) {
            total = (total + dfs(grid, i, j + 1, LEFT)) % MOD;
            total = (total + dfs(grid, i + 1, j, UP)) % MOD;
        }
        if (grid[i][j] == 1) {
            if (cameFrom == LEFT) {
                total = dfs(grid, i + 1, j, UP) % MOD;
            } else
                total = dfs(grid, i, j + 1, LEFT) % MOD;
        }
        return dp[i][j][cameFrom] = total % MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return (dfs(grid, 0, 0, 0)) % MOD;
    }
};