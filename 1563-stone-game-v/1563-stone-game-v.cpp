class Solution {
public:
    vector<int> pref;
    int dp[501][501];
    int solve(int l, int r, vector<int>& stoneValue) {
        if (l >= r) {
            return 0;
        }
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        for (int mid = l; mid < r; mid++) {
            int left = pref[mid] - ((l >= 1) ? pref[l - 1] : 0);
            int right = pref[r] - pref[mid];
            if (left < right) {
                ans = max(ans, left + solve(l, mid, stoneValue));
            } else if (left > right) {
                ans = max(ans, right + solve(mid + 1, r, stoneValue));
            } else {
                ans = max(ans, max(left + solve(l, mid, stoneValue),
                                   right + solve(mid + 1, r, stoneValue)));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        pref.push_back(stoneValue[0]);
        for (int i = 1; i < n; i++) {
            pref.push_back(pref.back() + stoneValue[i]);
        }
        return solve(0, n - 1, stoneValue);
    }
};