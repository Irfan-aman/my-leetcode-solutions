class Solution {
public:
    typedef long long ll;
    ll b;
    int n;
    int MOD = 1e9 + 7;
    ll findPower(ll a, ll base) {
        if (base == 0)
            return 1;
        ll half = findPower(a, base / 2) % MOD;
        ll result = half * half % MOD;
        if (base % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result % MOD;
    }
    bool check(vector<int>& nums, int k) {
        unordered_map<ll, int> mp;
        ll remove = findPower(b, k - 1);
        int i = 0, j = 0;
        ll hash = 0;
        while (j < n) {
            hash = (hash * b + nums[j]) % MOD;
            if (j - i + 1 == k) {
                mp[hash]++;
                hash = (hash - nums[i] * remove % MOD + MOD) % MOD;
                i++;
            }
            j++;
        }
        for (auto& it : mp) {
            if (it.second == 1)
                return true;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        b = *max_element(nums.begin(), nums.end()) + 1;
        n = nums.size();
        int res = n;
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid)) {
                res = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return res;
    }
};