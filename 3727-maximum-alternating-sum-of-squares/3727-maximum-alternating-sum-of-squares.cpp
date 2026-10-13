class Solution {
public:
    typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(),
             [](const int a, const int b) { return abs(a) > abs(b); });
        ll res = 0;
        int mid = (n % 2 == 0) ? n / 2 - 1 : n / 2;
        for (int i = 0; i <= mid; i++) {
            res += nums[i] * nums[i];
        }
        for (int i = mid + 1; i < n; i++) {
            res -= nums[i] * nums[i];
        }
        return res;
    }
};