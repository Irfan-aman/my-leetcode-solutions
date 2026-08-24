class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref(n, 0);
        pref[0] = stones[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stones[i];
        }
        vector<int> dp(n + 1, 0);
        dp[n - 1] = pref[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            // int take = pref[i] - dp[i + 1];
            // int skip = dp[i + 1];
            dp[i] = max(pref[i] - dp[i + 1], dp[i + 1]);
        }

        return dp[1];
    }
};