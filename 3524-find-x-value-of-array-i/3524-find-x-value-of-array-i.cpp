class Solution {
public:
    typedef long long ll;
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> res(k, 0), prev(k, 0);
        for (int i = 0; i < n; i++) {
            vector<ll> curr(k, 0);
            curr[nums[i] % k]++;
            for (int oldRem = 0; oldRem <= k - 1; oldRem++) {
                int newRem = ((ll)oldRem * nums[i]) % k;
                curr[newRem] += prev[oldRem];
            }
            prev = curr;
            for (int x = 0; x <= k - 1; x++) {
                res[x] += prev[x];
            }
        }
        return res;
    }
};