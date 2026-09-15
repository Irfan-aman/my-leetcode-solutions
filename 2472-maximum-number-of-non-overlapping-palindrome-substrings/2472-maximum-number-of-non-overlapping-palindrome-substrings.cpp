class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1)
            return n;
        vector<vector<bool>> palindrome(n + 1, vector<bool>(n + 1, false));
        for (int L = 1; L <= n; L++) {
            for (int i = 0; i + L <= n; i++) {
                int j = i + L - 1;
                if (i == j) {
                    palindrome[i][j] = true;
                } else if (i + 1 == j) {
                    palindrome[i][j] = s[i] == s[j];
                } else {
                    palindrome[i][j] = s[i] == s[j] && palindrome[i + 1][j - 1];
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (palindrome[i][j]) {
                    int take = 1 + (j + k <= n ? dp[j + 1][j + k] : 0);
                    int grow = dp[i][j + 1];
                    int slide = dp[i + 1][j + 1];
                    dp[i][j] = max({take, grow, slide});
                } else {
                    int grow = dp[i][j + 1];
                    int slide = dp[i + 1][j + 1];
                    dp[i][j] = max(grow, slide);
                }
            }
        }
        return dp[0][k - 1];
    }
};