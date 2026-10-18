class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int n;
    vector<vector<ll>> pascalTriangle;
    int solve(vector<int> nums) {
        int m = nums.size();
        if (m < 3)
            return 1;
        vector<int> left, right;
        int root = nums[0];
        for (int i = 1; i < m; i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        ll x = solve(left) % MOD;
        ll y = solve(right) % MOD;
        ll z = pascalTriangle[m - 1][left.size()] % MOD;
        ll ans = ((z * x) % MOD) * y % MOD;
        return ans % MOD;
    }
    int numOfWays(vector<int>& nums) {
        n = nums.size();
        if (n == 1 || n == 2)
            return 0;
        pascalTriangle.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            pascalTriangle[i] = vector<ll>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                pascalTriangle[i][j] =
                    (pascalTriangle[i - 1][j] + pascalTriangle[i - 1][j - 1]) %
                    MOD;
            }
        }

        int res = solve(nums);
        return res - 1;
    }
};