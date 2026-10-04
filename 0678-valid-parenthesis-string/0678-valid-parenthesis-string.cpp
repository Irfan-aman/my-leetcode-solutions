class Solution {
public:
    int n;
    int dp[101][101];
    bool solve(string& s, int i, int open) {
        if (i == s.size()) {
            return open == 0;
        }
        if (dp[i][open] != -1)
            return dp[i][open];
        bool isValid = false;
        if (s[i] == '(') {
            isValid |= solve(s, i + 1, open + 1);
        } else if (s[i] == '*') {
            isValid |= solve(s, i + 1, open + 1);
            isValid |= solve(s, i + 1, open);
            if (open > 0)
                isValid |= solve(s, i + 1, open - 1);
        } else if (s[i] == ')' && open > 0) {
            isValid |= solve(s, i + 1, open - 1);
        }
        return dp[i][open] = isValid;
    }
    bool checkValidString(string s) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0);
    }
};