class Solution {
public:
    vector<int> pref;
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        pref.push_back(stoneValue[0]);
        for (int i = 1; i < n; i++) {
            pref.push_back(pref.back() + stoneValue[i]);
        }
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                for (int mid = l; mid < r; mid++) {
                    int left = pref[mid] - ((l >= 1) ? pref[l - 1] : 0);
                    int right = pref[r] - pref[mid];
                    if (left < right) {
                        dp[l][r] = max(dp[l][r], left + dp[l][mid]);
                    } else if (left > right) {
                        dp[l][r] = max(dp[l][r], right + dp[mid+1][r]);
                    } else {
                        dp[l][r] = max(dp[l][r],
                                  max(left + dp[l][mid],
                                      right + dp[mid+1][r]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};