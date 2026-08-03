class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = stoneValue[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            int ans = INT_MIN;
            int sum = 0;
            for (int j = 0; j < 3 && i + j < n; j++) {
                sum += stoneValue[i + j];
                ans = max(ans, sum - dp[i + j + 1]);
            }
            dp[i] = ans;
        }
        int diff = dp[0];
        if (diff > 0)
            return "Alice";
        else if (diff < 0)
            return "Bob";
        else
            return "Tie";
    }
};