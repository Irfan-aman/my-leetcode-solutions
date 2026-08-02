class Solution {
public:
    int dp[500][500];
    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];
        if (dp[i][j] != -1)
            return dp[i][j];
        int take_i = piles[i] - solve(i + 1, j, piles);
        int take_j = piles[j] - solve(i, j - 1, piles);
        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, n - 1, piles) > 0;
    }
};