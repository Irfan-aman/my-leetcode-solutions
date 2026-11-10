class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int climb_1 = costs[i] + 1 + dp[i + 1];
            int climb_2 = 1e9, climb_3 = 1e9;
            if (i + 1 < n)
                climb_2 = costs[i + 1] + 4 + dp[i + 2];
            if (i + 2 < n)
                climb_3 = costs[i + 2] + 9 + dp[i + 3];
            dp[i] = min({climb_1, climb_2, climb_3});
        }
        return dp[0];
    }
};