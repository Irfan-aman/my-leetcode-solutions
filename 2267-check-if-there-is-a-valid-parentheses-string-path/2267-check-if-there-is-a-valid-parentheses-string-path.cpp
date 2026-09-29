class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(' ||
            (m + n - 1) % 2 == 1) {
            return false;
        }
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(m + n)));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int balance = 0; balance <= i + j + 1; balance++) {
                    if (i == m - 1 && j == n - 1) {
                        dp[i][j][balance] = (balance == 0);
                        continue;
                    }
                    dp[i][j][balance] = false;
                    if (i + 1 < m) {
                        int newBal =
                            (grid[i + 1][j] == '(' ? balance + 1 : balance - 1);
                        if (newBal >= 0 && dp[i + 1][j][newBal] == true)
                            dp[i][j][balance] = true;
                    }
                    if (j + 1 < n) {
                        int newBal =
                            (grid[i][j + 1] == '(' ? balance + 1 : balance - 1);
                        if (newBal >= 0 && dp[i][j + 1][newBal] == true)
                            dp[i][j][balance] = true;
                    }
                }
            }
        }
        return dp[0][0][1];
    }
};