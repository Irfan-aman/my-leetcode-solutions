class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                long long gcd = __gcd(nums[i], nums[j]);
                gcd = gcd * gcd;
                ans = max(ans, (1ll * nums[i] * nums[j]) / gcd);
            }
        }
        return ans;
    }
};