class Solution {
public:
    int dp[500][500];
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][i] = piles[i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) { // i<j
                dp[i][j] =
                    max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};