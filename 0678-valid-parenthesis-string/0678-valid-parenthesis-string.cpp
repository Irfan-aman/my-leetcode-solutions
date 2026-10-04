class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        dp[n][0] = true; // i==n & open==0 => true
        for (int i = n - 1; i >= 0; i--) {
            for (int open = n - 1; open >= 0; open--) {
                bool isValid = false;
                if (s[i] == '*') {
                    isValid |= dp[i + 1][open + 1];
                    isValid |= dp[i + 1][open];
                    if (open > 0)
                        isValid |= dp[i + 1][open - 1];
                } else if (s[i] == '(') {
                    isValid |= dp[i + 1][open + 1];
                } else if (s[i] == ')' && open > 0) {
                    isValid |= dp[i + 1][open - 1];
                }
                dp[i][open] = isValid;
            }
        }
        return dp[0][0];
    }
};