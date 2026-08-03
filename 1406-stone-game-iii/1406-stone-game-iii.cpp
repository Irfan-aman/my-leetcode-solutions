class Solution {
public:
    int dp[500001];
    int solve(int i, int n, vector<int>& stoneValue) {
        if (i >= n)
            return 0;
        if (i == n - 1)
            return stoneValue[n - 1];
        if (i == n - 2) {
            if ((stoneValue[i] < 0 && stoneValue[i + 1] < 0) ||
                (stoneValue[i] > 0 && stoneValue[i + 1] < 0))
                return stoneValue[i] - stoneValue[i + 1];
            return stoneValue[n - 2] + stoneValue[n - 1];
        }
        if (dp[i] != -1)
            return dp[i];
        int take1 = stoneValue[i] - solve(i + 1, n, stoneValue);
        int take2 =
            stoneValue[i] + stoneValue[i + 1] - solve(i + 2, n, stoneValue);
        int take3 = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] -
                    solve(i + 3, n, stoneValue);
        return dp[i] = max(max(take1, take2), take3);
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        int diff = solve(0, n, stoneValue);
        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};