class Solution {
public:
    int cheapest;
    int dp[1001][1501];
    vector<int> copies;
    int solve(int n, int budget, vector<vector<int>>& items) {
        if (n == 0) {
            return budget / cheapest;
        }
        if (dp[n][budget] != -1)
            return dp[n][budget];
        int take = 0, not_take = 0;
        if (items[n - 1][1] <= budget) {
            take = 1 + copies[n - 1] +
                   solve(n - 1, budget - items[n - 1][1], items);
            not_take = solve(n - 1, budget, items);
        } else
            not_take = solve(n - 1, budget, items);
        return dp[n][budget] = max(take, not_take);
    }
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        copies.assign(n, 0);
        cheapest = items[0][1];
        for (int i = 0; i < n; i++) {
            cheapest = min(cheapest, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    copies[i]++;
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(n, budget, items);
    }
};