class Solution {
public:
    int n, m;
    int dp[1001][1001];
    int matchAndExploreChar(string& s, string& t, int i, int j) {
        if (j >= m)
            return 1;
        if (i >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] != t[j]) {
            return dp[i][j] = matchAndExploreChar(s, t, i + 1, j);
        } else {
            return dp[i][j] = matchAndExploreChar(s, t, i + 1, j + 1) +
                              matchAndExploreChar(s, t, i + 1, j);
        }
    }
    int numDistinct(string s, string t) {
        n = s.size();
        m = t.size();
        memset(dp, -1, sizeof(dp));
        return matchAndExploreChar(s, t, 0, 0);
    }
};