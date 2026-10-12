class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;
    int maxSum(vector<int>& nums, int k) {
        vector<int> count(32, 0);
        for (int num : nums) {
            for (int b = 0; b < 32; b++) {
                if (num & (1 << b)) { // b bit is set
                    count[b]++;
                }
            }
        }
        ll res = 0;
        while (k--) {
            ll curr = 0;
            for (int b = 0; b < 32; b++) {
                if (count[b]) {
                    curr |= (1 << b);
                    count[b]--;
                }
            }
            res = (res + curr * curr) % MOD;
        }
        return res;
    }
};