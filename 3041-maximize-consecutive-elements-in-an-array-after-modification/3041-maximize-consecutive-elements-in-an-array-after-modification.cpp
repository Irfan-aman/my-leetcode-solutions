class Solution {
public:
    int n;
    int dp[100001][2];
    int findIdx(int j, int val, vector<int>& nums) {
        int idx = lower_bound(nums.begin() + j, nums.end(), val) - nums.begin();
        if (idx < n && nums[idx] == val)
            return idx;
        return -1;
    }
    int solve(int i, int inc, vector<int>& nums) {
        if (i >= n)
            return 0;
        if (dp[i][inc] != -1)
            return dp[i][inc];
        int currVal = nums[i] + inc;
        int len = 1;
        int j = findIdx(i + 1, currVal + 1, nums);
        if (j != -1) {
            len = max(len, 1 + solve(j, 0, nums));
        }
        j = findIdx(i + 1, currVal, nums);
        if (j != -1) {
            len = max(len, 1 + solve(j, 1, nums));
        }
        return dp[i][inc] = len;
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        int res = 1;
        for (int i = 0; i < n; i++) {
            res = max({res, solve(i, 0, nums), solve(i, 1, nums)});
        }
        return res;
    }
};