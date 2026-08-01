class Solution {
public:
    int dp[21][21];
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if(j>=i){
                    int take_i = nums[i] - dp[i + 1][j];
                int take_j = nums[j] - dp[i][j - 1];
                dp[i][j] = max(take_i, take_j);
                }
            }
        }
        return dp[0][n - 1] >= 0;
    }
};