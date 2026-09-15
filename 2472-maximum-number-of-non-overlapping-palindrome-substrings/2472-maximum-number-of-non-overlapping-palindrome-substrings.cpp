class Solution {
public:
    int n;
    int dp[2001][2001];
    bool isPalindrom(string& str, int i, int j) {
        while (i <= j) {
            if (str[i] != str[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(string& s, int k, int i, int j) {
        if (i >= n || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (isPalindrom(s, i, j)) {
            int take = 1 + solve(s, k, j + 1, j + k);
            int grow = solve(s, k, i, j + 1);
            int slide = solve(s, k, i + 1, j + 1);
            return dp[i][j] = max({take, grow, slide});
        } else {
            int grow = solve(s, k, i, j + 1);
            int slide = solve(s, k, i + 1, j + 1);
            return dp[i][j] = max(grow, slide);
        }
    }
    int maxPalindromes(string s, int k) {
        n = s.size();
        if (k == 1)
            return n;
        memset(dp, -1, sizeof(dp));
        return solve(s, k, 0, k - 1);
    }
};