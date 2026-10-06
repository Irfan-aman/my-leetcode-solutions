class Solution {
public:
    int dp[21][21];
    bool solve(string& s, string& p, int i, int j) {
        if (j == p.size()) {
            return i == s.size();
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        bool curr_matches = false;
        if (i < s.size() && (s[i] == p[j] || p[j] == '.'))
            curr_matches = true;
        if (p[j + 1] == '*') {
            bool take = curr_matches && solve(s, p, i + 1, j);
            bool not_take = solve(s, p, i, j + 2);
            return dp[i][j] = (take || not_take);
        } else {
            return dp[i][j] = (curr_matches && solve(s, p, i + 1, j + 1));
        }
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(s, p, 0, 0);
    }
};