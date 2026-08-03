class Solution {
public:
    vector<int> dp;
    int n;
    int solve(int i, vector<int>& stoneValue) {
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
            ans = max(ans, sum - solve(i + j + 1, stoneValue));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n + 1, -1);
        int diff = solve(0, stoneValue);
        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};