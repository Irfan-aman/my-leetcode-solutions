class Solution {
public:
    int m, n;
    int dp[101][101][201];
    bool solve(vector<vector<char>>& grid, int i, int j,
               int balance) { // balance= openCount - closeCount
        balance += (grid[i][j] == '(' ? 1 : -1);
        if (balance < 0)
            return false;
        if (balance >= 0 && dp[i][j][balance] != -1) {
            return dp[i][j][balance];
        }
        bool res = false;
        if (i == m - 1 && j == n - 1)
            return balance == 0;
        if ((i + 1 < m && solve(grid, i + 1, j, balance)) ||
            (j + 1 < n && solve(grid, i, j + 1, balance))) {
            return res = true;
        }
        dp[i][j][balance] = (res == true ? 1 : 0);
        return res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(' ||
            (m + n - 1) % 2 == 1) {
            return false;
        }
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, 0, 0);
    }
};