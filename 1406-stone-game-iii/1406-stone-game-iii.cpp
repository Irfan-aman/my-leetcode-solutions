class Solution {
public:
    int dp[500001];
    int solve(int i, int n, vector<int>& stoneValue) {
        if (i >= n)
            return 0;
        if (i == n - 1)
            return stoneValue[n - 1];
        if (dp[i] != -1)
            return dp[i];
        int ans = INT_MIN;
        int sum = 0;
        for (int j = 0; j < 3 && i + j < n; j++) {
            sum += stoneValue[i + j];
            ans = max(ans, sum - solve(i + j + 1, n, stoneValue));
        }
        return dp[i] = ans;
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